#include <iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;
class User;
class Admin;
void Login();
void Menu();
void Admin_menu();
void Enter();

class User
{
public:
    User()
    {}
    User(string login, string name, string surname, string password, string phone, string adress)
    {
        this->login = login;
        this->password = password;
        this->name = name;
        this->surname = surname;
        this->phone = phone;
        this->adress = adress;
    }
    string GetLogin()
    {
        return login;
    }

    string GetPass()
    {
        return password;
    }
    string GetName()
    {
        return name;
    }
    string GetSurname()
    {
        return surname;
    }
    string GetPhone()
    {
        return phone;
    }
    string Getadress()
    {
        return adress;
    }

    void SetLogin(string login)
    {
        this->login = login;
    }
    void SetPass(string password)
    {
        this->password = password;
    }
    void SetPhone(string phone)
    {
        this->phone = phone;
    }
    void SetAdress(string adress)
    {
        this->adress = adress;
    }
    void Register();
    void Personal_account();
    friend class Admin;
    friend void Login();
    void Show_category();
    void Test_ansfer();
    void Test_result();
private:
    string login;
    string password;
    string name;
    string surname;
    string phone;
    string adress;

};
User unic;

class Admin
{
public:
    Admin()
    {}
    Admin(string login, string password)
    {
        this->login = login;
        this->password = password;
    }

    string GetLogin()
    {
        return login;
    }

    string GetPass()
    {
        return password;
    }

    void SetPass(string password)
    {
        this->password = password;
    }
    void  UsersList();
    friend void Login();
    void Add_users();
    void Admin_delete_user();
    void Admin_change_user();
    void Show_category();
    void Add_category();
    void Admin_delete_category();
    void Add_test();
    void Show_test();
    void Change_admin_password(Admin& admin);
    void Show_userresult();
    void Show_categoryresult();
 
private:
    string login;
    string password;
};
struct Category
{
    string category;
};
struct Test
{
    string question;
    string answer;
};
struct Result
{
    string category="";
    int result=0;
};
struct Category_result
{
    string user_result = "";
    int result = 0;
};


void User::Register()
{
    string login, password, password2, phone, adress, name, surname;
    int povtor = 0;

    cout << "\t---REGISTER--- -> " << endl;
    cout << "Enter login -> ";
    cin >> login;
    cout << "Enter password -> " << endl;
    cin >> password;
    cout << "Enter password again -> " << endl;
    cin >> password2;
    cout << "Enter your name -> " << endl;
    cin >> name;
    cout << "Enter your surname -> " << endl;
    cin >> surname;
    cout << "Enter your phone -> " << endl;
    cin >> phone;
    cout << "Enter your adress ->" << endl;
    cin >> adress;
    vector <User>user_0;
    User user_1;
    ifstream fin;
    fin.open("users.txt");
    if (fin.is_open())
    {
        while (fin >> user_1.login)
        {

            fin >> user_1.password;
            fin >> user_1.name;
            fin >> user_1.surname;
            fin >> user_1.phone;
            fin >> user_1.adress;
            user_0.push_back(user_1);

        }
        for (int i = 0; i < user_0.size(); i++)
        {
            if (user_0[i].login == login)
            {
                ++povtor;
            }
        }
        if (login != "admin" && povtor < 1)
        {
            if (password == password2)
            {
                vector<User>users;
                User user;
                user.login = login;
                user.password = password;
                user.name = name;
                user.surname = surname;
                user.phone = phone;
                user.adress = adress;
                users.push_back(user);

                ofstream fout;
                string new_file;

                fout.open("users.txt", ios::app);
                if (fout.is_open())
                {
                   
                    for (int i = 0; i < users.size(); i++)
                    {
                        fout << users[i].login << "\n" << users[i].password << "\n" << users[i].name << "\n" << users[i].surname << "\n" << users[i].phone << "\n" << users[i].adress << endl;

                    }
                    fout.close();
                }
                else
                {
                    cout << "Error opening file" << endl;
                }
                unic.login = login;
                unic.password = password;
                ofstream fout1;
                new_file = login + ".txt";
                fout1.open(new_file);
                
            }
            else
            {
                cout << "Password don't match" << endl;
                cout << "Try again" << endl;
                Register();
            }
        }
        else
        {
            cout << "You can't register this user login, user with this login already registered" << endl;
            Register();
        }
    }
    else
    {
        cout << "Error opening file" << endl;
        Enter();
    }
    
    Menu();


}
void User::Personal_account()
{
    {
        ifstream fin;
        fin.open("users.txt");
        vector <User> users;
        User user;
        if (fin.is_open())
        {
            while (fin >> user.login)
            {
                fin >> user.password >> user.name >> user.surname >> user.phone >> user.adress;
                users.push_back(user);

            }
            fin.close();
            for (int i = 0; i < users.size(); i++)
            {
                if (unic.login == users[i].login)
                {
                    cout << "\t------Account------" << endl;
                    cout << "\nLogin: " << users[i].login << "\nPassword: " << users[i].password << "\nName: " << users[i].name << "\nSurname: " << users[i].surname << "\nPhone: " << users[i].phone << "\nAdress: " << users[i].adress << endl << endl;
                }
            }
        }
        else
        {
            cout << "Error opening file" << endl;
        }

        Menu();
    }
}
void Enter()
{
    User user;
    int shoose;
    cout << "Choose you want register or login" << endl;
    cout << "If you want register press 1" << endl;
    cout << "If you want login press 2" << endl;
    cin >> shoose;
    switch (shoose)
    {
    case 1:
    {
        user.Register();
        break;
    }
    case 2:
    {
        Login();
        break;
    }
    default:

        cout << "Error of shoose." << endl;
        Enter();
        break;
    }
}
void Login()
{
    User user;
    string login, password;
    cout << "\t---LOGIN--- -> " << endl;
    cout << "Enter login -> ";

    cin >> login;
    cout << "Enter password -> ";
    cin >> password;
    ifstream fin;

    if (login != "admin")
    {
        fin.open("users.txt");
        if (fin.is_open())
        {
            bool flag = false;
            while (fin >> user.login)
            {
                fin >> user.password;

                if (login == user.login && password == user.password)
                {
                    flag = true;
                    unic.login = login;
                    unic.password = password;
                    cout << "Now you're log in" << endl;

                     Menu();
                    break;
                }

            }
            if (flag == false)
            {
                cout << "Login or password is incorect" << endl;
                Login();
            }
        }
        else
        {
            cout << "Error opening file" << endl;

        }
    }
    else
    {
        Admin admin;
        fin.open("admin.txt");
        if (fin.is_open())
        {
            bool flag = false;
            while (!fin.eof())
            {
                fin >> admin.login >> admin.password;
                if (login == admin.login && password == admin.password)
                {
                    flag = true;
                    cout << "Now you're log in" << endl;
                    Admin_menu();
                }

            }
            if (flag == false)
            {
                cout << "Login or password is incorect" << endl;
                Login();
            }
        }
        else
        {
            cout << "Error opening file" << endl;

        }
    }

}
void Menu()
{
    User user;
    int shoose;
    cout << endl << endl;
    cout << "\t-----MENU-----" << endl;
    cout << "1: Show accaunt ->" << endl;
    cout << "2: Show categories  ->" << endl;
    cout << "3: Go test " << endl;
    cout << "4: Show test reslts" << endl;
    cout << "5: Exit" << endl;
    cin >> shoose;
    switch (shoose)
    {
    case 1:
    {
        user.Personal_account();
        break;
    }
  
    case 2:
    {
        user.Show_category();
        break;
    }
    case 3:
    {
        user.Test_ansfer();
        break;
    }
    case 4:
    {
        user.Test_result();
        break;
    }
    case 5:
    {
        Login();
        break;
    }
    default:

        cout << "Error of shoose." << endl;
        /*Returm_menu();*/
        Menu();
        break;
    }
}
void Admin_menu()
{
    Admin admin;
    int shoose;
    cout << endl << endl;
    cout << "\t-----MENU-----" << endl;
    cout << "1: Show all users " << endl;
    cout << "2: Add new user " << endl;
    cout << "3: Delete user" << endl;
    cout << "4: Change user information" << endl;
    cout << "5: Show categories" << endl;
    cout << "6: Add category" << endl;
    cout << "7: Delete category" << endl;
    cout << "8: Add test" << endl;
    cout << "9: Show test" << endl;
    cout << "10: Show some user results" << endl;
    cout << "11: Show users results consist of category" << endl;
    cout << "12: Exit " << endl<<endl;

    cin >> shoose;
    switch (shoose)
    {
    case 1:
    {
        admin.UsersList();
        break;
    }
    case 2:
    {
        admin.Add_users();
        break;
    }
    case 3:
    {
        admin.Admin_delete_user();
        break;
    }
    case 4:
    {
        admin.Admin_change_user();
        break;
    }

    case 5:
    {
         admin.Show_category();
        break;
    }
    case 6:
    {
        admin.Add_category();
        break;
    }
    case 7:
    {
        admin.Admin_delete_category();
        break;
    }
    case 8:
    {
        admin.Add_test();
        break;
    }
    case 9:
    {
         admin.Show_test();
        break;
    }
    case 10:
    {
        admin.Show_userresult();
        break;
    }
    case 11:
    {
        admin.Show_categoryresult();
        break;
    }

    case 12:
    {
        Login();
        break;
    }

    default:

        cout << "Error of shoose." << endl;
        Admin_menu();
        break;
    }
}
void Admin::UsersList()
{
    string str = " ";
    ifstream iffile;
    int id;
    iffile.open("users.txt");
    vector <User> users;
    User user;
    if (iffile.is_open())
    {
        while (iffile >> user.login)
        {

            iffile >> user.password;
            iffile >> user.name;
            iffile >> user.surname;
            iffile >> user.phone;
            iffile >> user.adress;
            users.push_back(user);

        }


        for (int i = 0; i < users.size(); i++)
        {
            cout << "\nLogin: " << users[i].login << "\nPassword: " << users[i].password << "\nName: " << users[i].name << "\nSurname: " << users[i].surname << "\nPhone:" << users[i].phone << "\nAdress: " << users[i].adress << endl;;
            cout << "user id  = " << i + 1 << endl;
            cout << "-------------------------------" << endl << endl;
        }
    }
    else
    {
        cout << "Error of opening file" << endl;
    }
    Admin_menu();
};
void Admin::Add_users()
{

    string login, password, phone, adress, name, surname;
    int povtor = 0;
    cout << "Enter user login -> ";
    cin >> login;
    cout << "Enter user password -> " << endl;
    cin >> password;
    cout << "Enter user name -> " << endl;
    cin >> name;
    cout << "Enter user surname -> " << endl;
    cin >> surname;
    cout << "Enter user phone -> " << endl;
    cin >> phone;
    cout << "Enter user adress ->" << endl;
    cin >> adress;
    vector <User>user_0;
    User user_1;
    Admin admin;
    admin.login = "admin";
    ifstream fin;
    fin.open("users.txt");
    if (fin.is_open())
    {
        while (fin >> user_1.login)
        {
            fin >> user_1.password >> user_1.name >> user_1.surname >> user_1.phone >> user_1.phone;
            user_0.push_back(user_1);

        }
        for (int i = 0; i < user_0.size(); i++)
        {
            if (user_0[i].login == login)
            {
                ++povtor;
            }
        }
        if (login != admin.login && povtor < 1)
        {
            ofstream fout;
            vector<User>users;
            User user;
            user.login = login;
            user.password = password;
            user.name = name;
            user.surname = surname;
            user.phone = phone;
            user.adress = adress;
            users.push_back(user);

            fout.open("users.txt", ofstream::app);
            if (fout.is_open())
            {
                for (int i = 0; i < users.size(); i++)
                {

                    fout << users[i].login << "\n" << users[i].password << "\n" << users[i].name << "\n" << users[i].surname << "\n" << users[i].phone << "\n" << users[i].adress << endl;
                }
                fout.close();
                int choose;
                cout << "1: Add one more user" << endl;
                cout << "2: Return to menu" << endl;
                cin >> choose;
                switch (choose)
                {
                case 1:
                {
                    Add_users();
                    break;
                }
                case 2:
                {
                    Admin_menu();
                    break;
                }
                default:
                    cout << "Enter correct number" << endl;
                    Admin_menu();
                    break;
                }
            }
            else
            {
                cout << "Error opening file" << endl;
            }
            Admin_menu();
        }
        else
        {
            cout << "You can't register this user login, user with this login already registered";
            admin.Add_users();
        }
    }
    else
    {
        cout << "Error opening file" << endl;
    }
};
void Admin::Admin_delete_user()
{
    int id;
    cout << "Enter id user want delete " << endl;
    cin >> id;
    vector <User>user_0;
    User user_1;
    ifstream iffile;
    iffile.open("users.txt");
    if (iffile.is_open())
    {
        while (iffile >> user_1.login)
        {
            iffile >> user_1.password >> user_1.name >> user_1.surname >> user_1.phone >> user_1.adress;
            user_0.push_back(user_1);
        }
        ofstream offile;
        offile.open("users.txt");
        for (int i = 0; i < user_0.size(); i++)
        {
            if (id != i + 1)
            {
                offile << user_0[i].login << "\n" << user_0[i].password << "\n" << user_0[i].name << "\n" << user_0[i].surname << "\n" << user_0[i].phone << "\n" << user_0[i].adress << endl;
            }
        }
    }
    else
    {
        cout << "Error opening file" << endl;
    }
    iffile.close();
    Admin_menu();

}
void Admin::Admin_change_user()
{
    cout << "Admin_change_user" << endl;
    vector <User> user_0;
    User user_1;
    ifstream iffile;
    string str = " ";
    string login, password, phone, adress, name, surname;
    int povtor = 0;
    iffile.open("users.txt");
    if (iffile.is_open())
    {
        while (iffile >> user_1.login)
        {
            iffile >> user_1.password >> user_1.name >> user_1.surname >> user_1.phone >> user_1.adress;
            user_0.push_back(user_1);
        }
    }
    else
    {
        cout << "Error opening file" << endl;
    }
    int id;
    cout << "Enter user id you want to change " << endl;
    cin >> id;
    ofstream offile;
    offile.open("users.txt");
    if (offile.is_open())
    {
        while (!offile.eof())
        {
            if (id <= user_0.size())
            {
                for (int i = 0; i < user_0.size(); )
                {
                    if (id == i + 1)
                    {
                        cout << "Enter user login -> ";
                        cin >> login;
                        cout << "Enter user password -> " << endl;
                        cin >> password;
                        cout << "Enter user name -> " << endl;
                        cin >> name;
                        cout << "Enter user surname -> " << endl;
                        cin >> surname;
                        cout << "Enter user phone -> " << endl;
                        cin >> phone;
                        cout << "Enter user adress ->" << endl;
                        cin >> adress;
                        user_0[i].login = login;
                        user_0[i].password = password;
                        user_0[i].name = name;
                        user_0[i].surname = surname;
                        user_0[i].phone = phone;
                        user_0[i].adress = adress;
                        ++i;
                    }
                    ++i;
                }
            }
            else
            {
                cout << "Error id" << endl;
                Admin_menu();
            }

            for (int i = 0; i < user_0.size(); i++)
            {
                offile << user_0[i].login << "\n" << user_0[i].password << "\n" << user_0[i].name << "\n" << user_0[i].surname << "\n" << user_0[i].phone << "\n" << user_0[i].adress << endl;
            }
            Admin_menu();
        }
        iffile.close();
        offile.close();
        Admin_menu();
    }
    else
    {
        cout << "Error opening file" << endl;
    }
    Admin_menu();
}
void Admin::Show_category()
{
    string str = " ";
    ifstream iffile;
    int id, j = 0;
    iffile.open("category.txt");
    vector <Category> vcategories;
    Category category;
    if (iffile.is_open())
    {
        while (iffile >> category.category)
        {

            vcategories.push_back(category);
            string str = " ";
        }


        for (int i = 0; i < vcategories.size(); i++)
        {
            cout << i + 1<<". ";
            cout << vcategories[i].category << endl;;

            cout << "-------------------------------" << endl;
        }

    }
    Admin_menu();
}
void Admin::Add_category()
{
    string new_category, new_subcategory;

    cout << "Enter category -> " << endl;
    cin >> new_category;
    vector <Category> vcategories;
    Category category;
    category.category = new_category;

    vcategories.push_back(category);
    ofstream fout;
    fout.open("category.txt", ofstream::app);
    if (fout.is_open())
    {

        for (int i = 0; i < vcategories.size(); i++)
        {
            fout << vcategories[i].category << endl;
        }
        ofstream cat_fout;

        string file_category, result_category;
        file_category =  new_category + ".txt";
        result_category = new_category + "answears.txt";
        cat_fout.open(file_category);
        cat_fout.open(result_category);
        
        int choose;
        cout << "1: Add one more category" << endl;
        cout << "2: Return to menu" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            Add_category();
            break;
        }
        case 2:
        {
            Admin_menu();
            break;
        }
        default:
            cout << "Enter correct number" << endl;
            Admin_menu();
            break;
        }
    }
    else
    {
        cout << "Error opening file" << endl;
        Admin_menu();
    }
    fout.close();
}
void Admin::Admin_delete_category()
{
    int id;
    cout << "Enter id category you want delete " << endl;
    cin >> id;
    vector <Category> categories;
    Category category;
    ifstream iffile;
    string str = " ";
    iffile.open("category.txt");
    if (iffile.is_open())
    {
        while (iffile >> category.category)
        {
            categories.push_back(category);
        }
        ofstream offile;
        offile.open("category.txt");
        for (int i = 0; i < categories.size(); i++)
        {
            if (id != i + 1)
            {
                offile << categories[i].category << endl;
            }
        }
    }
    else
    {
        cout << "Error opening file" << endl;
    }
    iffile.close();
    Admin_menu();
}
void Admin::Add_test()
{
    string str = " ";
    ifstream iffile;
    int id, j = 0;
    iffile.open("category.txt");
    vector <Category> vcategories;
    Category category;
    if (iffile.is_open())
    {
        while (iffile >> category.category)
        {
            vcategories.push_back(category);

        }


        for (int i = 0; i < vcategories.size(); i++)
        {
            cout << i + 1 << ". ";
            cout << vcategories[i].category << endl;;

            cout << "-------------------------------" << endl;
        }

    }
    cout << "Choose number of category" << endl;
    int cat_for_test;
    cin >> cat_for_test;
    for (int i = 0; i < vcategories.size(); i++)
    {
        if (cat_for_test == i + 1)
        {
            string name_category = vcategories[i].category;
            string file_category =  name_category + ".txt";
            ofstream fout;
            fout.open(file_category);
            if (fout.is_open())
            {
                vector<Test>tests;
                Test test;
                for (int i = 0; i < 6; i++)
                {
                    cin.ignore();
                    string question, answer;
                    cout << "Enter question" << endl;
                    getline(cin, question);
                    cout << "Enter answer 'y'or 'n'" << endl;
                    getline(cin, answer);
                    test.question = question;
                    test.answer = answer;
                    tests.push_back(test);
                }

                for (int i = 0; i < tests.size(); i++)
                {
                    fout << tests[i].question << "\n" << tests[i].answer << "\n";
                }
            }
            else
            {
                cout << "Error of opening file" << endl;
            }
        }
    }

    Admin_menu();
}
void Admin::Show_test()
{
    string str = " ";
    ifstream iffile;
    int id, j = 0;
    iffile.open("category.txt");
    vector <Category> vcategories;
    Category category;
    if (iffile.is_open())
    {
        while (iffile >> category.category)
        {
            vcategories.push_back(category);

        }

        for (int i = 0; i < vcategories.size(); i++)
        {
            cout << i + 1 << ". ";
            cout << vcategories[i].category << endl;;
            cout << "-------------------------------" << endl;
        }
    }
    cout << "Choose number of category" << endl;
    int cat_for_test;
    cin >> cat_for_test;
    vector<Test>tests;
    Test test;
    for (int i = 0; i < vcategories.size(); i++)
    {
        if (cat_for_test == i + 1)
        {
            string name_category = vcategories[i].category;
            string file_category =  name_category + ".txt";
            ifstream iftest;
            iftest.open(file_category);
            if (iftest.is_open())
            {

                while (!iftest.eof())
                {
                    getline(iftest, test.question);
                    getline(iftest, test.answer);
                    tests.push_back(test);

                }
                cout << "\t-----" << name_category << "-----" << endl;
                for (int i = 0; i < tests.size(); i++)
                {
                    cout << tests[i].question << endl;

                }
            }
            else
            {
                cout << "Error of opening file" << endl;
            }
        }
    }

    Admin_menu();
}
void Admin::Show_userresult()
{
    string useracc, userlog;
    vector<Result> results;
    Result result;
    cout << "Enter user login to look his tests results" << endl;
    cin >> userlog;
    useracc = userlog + ".txt";
    ifstream iffile;
    iffile.open(useracc);
    if (iffile.is_open())
    {
        while (iffile >> result.category)
        {
            iffile >> result.result;
            results.push_back(result);
        }
        cout << "\t--------Tests results "<< userlog<<"--------" << endl;
        for (int i = 0; i < results.size(); i++)
        {
            cout << "Category: " << results[i].category << "\nResult: " << results[i].result << " balls" << endl << endl;

        }
    }
    else
    {
        cout << "Error of opening file " << endl;
    }
    
    int ch;
    cout << "1: Sort user results from the best" << endl;
    cout << "2: Menu" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        int sresult;
        string scategory;
        cout << "\t--------Tests results " << userlog << "--------" << endl;
        for (int i = 0; i < results.size()-1; i++)
        {
            for (int j = 0; j < results.size()-i-1; j++)
            {
                if (results[j].result < results[j + 1].result)
                {
                    scategory = results[j + 1].category;
                    results[j + 1].category = results[j].category;
                    results[j].category = scategory;
                    sresult = results[j + 1].result;
                    results[j + 1].result = results[j].result;
                    results[j].result = sresult;

                }
            }
 
        }
        for (int i = 0; i < results.size(); i++)
        {
            cout << "Category: " << results[i].category << "\nResult: " << results[i].result << " balls" << endl << endl;
        }
       
        
        break;
    }
    case 2:
    {
        Admin_menu();
        break;
    }
    default:
        Admin_menu();
        break;
    }
   iffile.close();
   
   Admin_menu();
}
void Admin::Show_categoryresult()
{
    string name_category;
    cout << "Print name of category to look it tests results" << endl;
    cin >> name_category;
    string category_file;
    vector<Category_result>cresults;
    Category_result cresult;
    category_file = name_category + "answears.txt";
    ifstream iffres;
    iffres.open(category_file);
    if (iffres.is_open())
    {
        while (iffres >> cresult.user_result)
        {
            iffres >> cresult.result;
            cresults.push_back(cresult);
        }
    }
    else
    {
        cout << "Error of opening file" << endl;
    }
    ofstream ofcat;
    ofcat.open(category_file, ios::app);
    if (ofcat.is_open())
    {   
        cout << "\t------------" << name_category <<"------------"<< endl;
        for (int i = 0; i < cresults.size(); i++)
        {
            cout <<"User login: "<< cresults[i].user_result << " - Balls: " << cresults[i].result << "\n";
        }
    }
    else
    {
        cout << "Error of opening file" << endl;
    }
    cout << "1: Sort user results from the best" << endl;
    cout << "2: Menu" << endl;
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        int sresult;
        string name;
        cout << "\t--------Tests results " << name_category << "--------" << endl;
        for (int i = 0; i < cresults.size() - 1; i++)
        {
            for (int j = 0; j < cresults.size() - i - 1; j++)
            {
                if (cresults[j].result < cresults[j + 1].result)
                {
                    name = cresults[j + 1].user_result;
                    cresults[j + 1].user_result = cresults[j].user_result;
                    cresults[j].user_result = name;
                    sresult = cresults[j + 1].result;
                    cresults[j + 1].result = cresults[j].result;
                    cresults[j].result = sresult;

                }
            }


        }
        for (int i = 0; i < cresults.size(); i++)
        {
            cout << "User login: " << cresults[i].user_result << "  Balls: " << cresults[i].result << "\n";

        }
        break;
    }
    case 2:
    {
        Admin_menu();
        break;
    }
    default:
        Admin_menu();
        break;
    }
    
    ofcat.close();
    Admin_menu();
}
void User::Show_category()
{
    string str = " ";
    ifstream iffile;
    int id, j = 0;
    iffile.open("category.txt");
    vector <Category> vcategories;
    Category category;
    if (iffile.is_open())
    {
        while (iffile >> category.category)
        {

            vcategories.push_back(category);
            string str = " ";
        }


        for (int i = 0; i < vcategories.size(); i++)
        {
            cout << i + 1 << ". ";
            cout << vcategories[i].category << endl;;

            cout << "-------------------------------" << endl;
        }

    }
    Menu();
}
void User::Test_ansfer()
{
    ifstream iffile;
    int id, j = 0;
    iffile.open("category.txt");
    vector <Category> vcategories;
    Category categ;
    if (iffile.is_open())
    {
        while (iffile >> categ.category)
        {
            vcategories.push_back(categ);

        }

        for (int i = 0; i < vcategories.size(); i++)
        {
            cout << i + 1 << ". ";
            cout << vcategories[i].category << endl;;
            cout << "-------------------------------" << endl;
        }
    }
    cout << "Choose number of category" << endl;
    int cat_for_test;
    cin >> cat_for_test;
    vector<Test>tests;
    Test test;
    vector<Result> results;
    Result result;
    string useracc;
    useracc= unic.login + ".txt";
    string useranswer;
    int counter = 0;
    int mark;
    for (int i = 0; i < vcategories.size(); i++)
    {
        if (cat_for_test == i + 1)
        {
            string name_category = vcategories[i].category;
            string file_category =  name_category + ".txt";
            ifstream iftest;
            iftest.open(file_category);
            if (iftest.is_open())
            {

                while (!iftest.eof())
                {
                    getline(iftest, test.question);
                    getline(iftest, test.answer);
                    tests.push_back(test);

                }

                for (int i = 0; i < 6; i++)
                {
                    cout << i + 1 << ". " << tests[i].question <<endl;
                    cout << "(Enter 'y' or 'n') => " ;
                    cin >> useranswer;

                    if (useranswer == tests[i].answer)
                    {
                        counter++;
                    }
                    mark = counter*2;
                }
                cout <<"Right aswers: "<<counter<< "\nYour mark: " << mark << endl;
                
            }
            else
            {
                cout << "Error of opening file" << endl;
            }
            iffile.close();
            result.category = name_category;
            result.result = mark;
            results.push_back(result);

            ofstream ofuser;
            ofuser.open(useracc, ios::app);
            if (ofuser.is_open())
            {
                for (int i = 0; i < results.size(); i++)
                { 
                    ofuser << results[i].category << " " << results[i].result<<"\n";
                }
                
            }
            else
            {
                cout << "Error of opening file " << endl;
            }
            ofuser.close();
            string category_file;
            vector<Category_result>cresults;
            Category_result cresult;
            cresult.user_result = unic.login;
            cresult.result = mark;
            cresults.push_back(cresult);
            category_file= name_category+ "answears.txt";
            ofstream ofcat;
            ofcat.open(category_file, ios::app);
            if (ofcat.is_open())
            {
                for (int i = 0; i < cresults.size(); i++)
                {
                    ofcat << cresults[i].user_result << " " << cresults[i].result << "\n";
                }
            }
            else
            {
                cout << "Error of opening file" << endl;
            }
            ofcat.close();
            Menu();
        }
    }

   
}
void User::Test_result()
{
    string useracc;
    vector<Result> results;
    Result result;
    useracc = unic.login + ".txt";
    ifstream iffile;
    iffile.open(useracc);
    if (iffile.is_open())
    {
        while (iffile >> result.category)
        {
            iffile >> result.result;
            results.push_back(result);
        }
        for (int i = 0; i < results.size(); i++)
        {
            cout << "Category: " << results[i].category << "\nResult: " << results[i].result << " balls" << endl << endl;

        }
    }
    else
    {
        cout << "Error of opening file " << endl;
    }

    iffile.close();
    Menu();
}


int main()
{
    Enter();
 

    return 0;
}
