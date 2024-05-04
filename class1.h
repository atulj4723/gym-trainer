#include <iostream>
#include <fstream>
#include <limits>
#include <windows.h>
#include <conio.h>
using namespace std;
class member
{
    int count = 0;
    int found = 0;
    int flag = 0;
    int i = 0;
    int j = 0;
    long long int phone;
    long long int phone1;
    long long int phone2;
    long long int phone3;
    float height;
    float weight;
    float bmi;
    char ip;
    char input;
    string name;
    string gender;
    string file_name, file_name1;
    string password;
    string pass;
    string admin_name;
    string msg;
    string plan2, plan;
    string diet;
    string time;
    string filename, workout;

public:
    void admin()
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||**************ADMIN PANEL**************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\n\t\t\t\tENTER ADMIN NAME[CAPITAL LETTER ONLY] :-";
        cin >> admin_name;
        admin_name = string_validate(admin_name);
        cout << "\n\n\t\t\t\tENTER PASSWORD :-";
        password = password_(); // hide password
        fstream file;
        file.open("pass.txt", ios::in);
        file >> pass >> name;
        file.close();
        if (password == pass && admin_name == name) // confirm admin name and password
        {
            do
            {
                system("cls"); // clear screen
                ip = 0;
                cout << "\n\n\t\t\t\t\t\t===========================================";
                cout << "\n\t\t\t\t\t\t||*************** ADMIN ****************||";
                cout << "\n\t\t\t\t\t\t===========================================";
                cout << "\n\n\t\t\t\t1. CURRENT MEMBERS";
                cout << "\n\n\t\t\t\t2. ADD MEMBER INFORMATION";
                cout << "\n\n\t\t\t\t3. EDIT MEMBER INFORMATION";
                cout << "\n\n\t\t\t\t4. DELETE MEMBER INFORMATION";
                cout << "\n\n\t\t\t\t5. EDIT DIET PLAN";
                cout << "\n\n\t\t\t\t6. EDIT PASSWORD OR ADMIN NAME";
                cout << "\n\n\t\t\t\t7. EXIT";
                cout << "\n\n\t\t\t\tENTER YOUR CHOICE[RANGE[1-7]] : - ";
                ip = int_validate(0, 8); // validation for int
                cout << "\n\t\t\t\t==========================================";
                switch (ip) // swich between option
                {
                case 1:
                    display_information();
                    break;
                case 2:
                    add_member();
                    break;
                case 3:
                    edit_member();
                    break;
                case 4:
                    delete_member();
                    break;
                case 5:
                    edit_diet_plan();
                    break;
                case 6:
                    edit_admin();
                    break;
                case 7:
                    cout << "\n\n\t\t\t\t\t\t==========================================";
                    cout << "\n\t\t\t\t\t\t||***********THANK*YOU!!!!**************||";
                    cout << "\n\t\t\t\t\t\t==========================================";
                    break;
                default:
                    cout << "\n\n\t\t\t\tENTER CORRECT CHOICE!!!";
                }
                cout << "\n\t\t\t\tPRESS ANY KEY TO EXIT";
                getch();
            } while (ip != 7); // run loop until admin enter 7 to exit
        }
        else
        {
            cout << "\n\n\t\t\t\tWRONG CREDENTIAL...!";
        }
        getch();
    }
    void add_member()
    {
        do
        {
            fstream file1;
            file1.open("member.txt", ios::in); // open database file
            count = 0;
            system("cls");
            cout << "\n\n\t\t\t\t\t\t===========================================";
            cout << "\n\t\t\t\t\t\t||***************ADD MEMBER**************||";
            cout << "\n\t\t\t\t\t\t===========================================";
            cout << "\n\n\t\t\t\tENTER NEW MEMBER PHONE NUMBER [DIGIT ONLY]=";
            phone3 = long_long_int_validate(999999999, 10000000000); // check length of number
            while (!file1.eof())
            {
                file1 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
                if (phone3 == phone)
                {
                    cout << "\n\n\t\t\t\tTHIS NO IS ALREADY TAKEN TRY ANOTHER";
                    count = 1; // set count =0 if number already exist in file
                    cout << "\n\t\t\t\tPRESS ANY KEY TO EXIT";
                    getch();
                    break;
                }
            }
            file1.close();    // close database file
        } while (count != 0); // run code until new number get from admin
        phone = phone3;
        cout << "\n\t\t\t\tENTER MEMBER NAME[CAPITAL LETTER] =";
        cin >> name;
        name = string_validate(name); // validation for string string should be in capital letter
        cout << "\n\n\t\t\t\tENTER MEMBERS HEIGHT(Height in M)[Range: 0.5-2.5M] =";
        height = float_validate(0.49, 2.51); // validation for height it should be between 0.5 to 2.5m
        cout << "\n\n\t\t\t\tENTER MEMBERS WEIGHT(Weight in KG)[Range: 1-200KG] =";
        weight = float_validate(0, 201); // validation for weight it should be between 1 to 200kg
        cout << "\n\n\t\t\t\tENETER MEMBERS GENDER(1=MALE/2=FEMALE) =";
        ip = int_validate(0, 3);
        if (ip == '1')
        {
            gender = "MALE"; // set gender = MALE if admin enter 1
        }
        else
        {
            gender = "FEMALE"; // set gender = FEMALE if admin enter 2
        }
        plan = "NON";         // set default diet plan to non
        plan2 = "NON";        // set default workout plan to non
        pass = "NON";         // set default password as non
        bmi1(height, weight); // calculate bmi
        if (bmi < 18.5)
        {
            msg = "GAIN"; // set login time message to user
        }
        else if (bmi < 24.5)
        {
            msg = "MAINTAIN";
        }
        else
        {
            msg = "LOSS";
        }
        fstream file2;
        file2.open("member.txt", ios::app); // add data to database
        file2 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
        file2.close();
    }
    void delete_member()
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||************DELETE MEMBER**************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\n\t\t\t\tENTER NUMBER TO DELETE INFORMATION :-";
        phone2 = long_long_int_validate(999999999, 10000000000);
        cout << "\n\n\t\t\t\tCONFIRM NUMBER :-";
        phone3 = long_long_int_validate(999999999, 10000000000);
        if (phone2 == phone3) // confirm the number
        {
            cout << "\n\n\t\t\t\tENTER PASSWORD :-";
            password = password_();
            fstream file3;
            file3.open("member.txt", ios::in);
            while (!file3.eof())
            {
                file3 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
                if (phone == phone2 && pass == password)
                {
                    found = 1;
                    file3.close();
                    delete_account(phone2);
                    break;
                }
            }
            file3.close();
            if (found != 1)
            {
                cout << "\n\n\t\t\t\tWRONG NUMBER OR PASSWORD..!";
            }
        }
        else
        {
            cout << "\n\n\t\t\t\tNUMBER NOT MATCH..!";
        }
    }
    void edit_member()
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||***********EDIT INFORMATION************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\n\t\t\t\tENTER NUMBER TO EDIT INFORMATION :-";
        phone2 = long_long_int_validate(999999999, 10000000000);
        cout << "\n\n\t\t\t\tCONFIRM NUMBER :-";
        phone3 = long_long_int_validate(999999999, 10000000000);
        if (phone2 == phone3)
        {
            cout << "\n\n\t\t\t\tENTER PASSWORD :-";
            password = password_();
            fstream file4;
            file4.open("member.txt", ios::in);
            while (!file4.eof())
            {
                file4 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
                if (phone == phone2 && pass == password)
                {
                    file4.close();
                    edit_account(phone2);
                    found = 1;
                    break;
                }
            }
            file4.close();
            if (found != 1)
            {
                cout << "\n\n\t\t\t\tWRONG NUMBER OR PASSWORD...!";
            }
        }
        else
        {
            cout << "\n\n\t\t\t\tNUMBER NOT MATCH...!";
        }
    }
    void display_information()
    {
        system("cls");
        phone = 0;
        name = "";
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||*************MEMBER LIST***************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        fstream file5;
        file5.open("edit.txt", ios::in);
        //file5 >> name >> phone >> height >> weight >> gender;
        while (!file5.eof())
        {
            file5 >> name >> phone >> height >> weight >> gender>> pass >> plan >> plan2 >> msg;
            if(phone!=0){
            cout << "\n\t\t\t\tMEMBER WITH " << phone << " THIS PHONE NUMBER HAS EDITED HIS ACCOUNT.";
            cout << "\n\t\t\t\tINFORMATION BEFORE EDIT:";
            cout << "\n\t\t\t\tName :-" << name;
            cout << "\n\t\t\t\tHeight :-" << height;
            cout << "\n\t\t\t\tWeight :-" << weight;
            cout << "\n\t\t\t\tGender :-" << gender;
            }
        }
        file5.close();
        fstream file6;
        file6.open("edit.txt", ios::out);
        file6.close();
        fstream file7;
        file7.open("delete.txt", ios::in);
        //file7 >> phone;
        while (!file7.eof())
        {
            file7 >> phone;
            if(phone!=0){
            cout << "\n\t\t\t\tMEMBER WITH " << phone << " THIS PHONE NUMBER HAS DELETED HIS ACCOUNT.";
            }
        }
        file7.close();
        fstream file8;
        file8.open("delete.txt", ios::out);
        file8.close();
        fstream file9;
        file9.open("member.txt", ios::in);
        cout << "\n\n\t\t\t\t"
             << "NAME"
             << "\t"
             << "PHONE"
             << "\t\t"
             << "HEIGHT"
             << "\t"
             << "WEIGHT"
             << "\t"
             << "GENDER"
             << "\t"
             << "DIET"
             << "\t\t\t"
             << "WORKOUT" << endl;
        file9 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
        while (!file9.eof())
        {
            cout << "\n\n\t\t\t\t" << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << plan << "\t" << plan2 << endl;
            file9 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
        }
        file9.close();
    }
    void edit_plan() // for future scope
    {
        int flag = 0;
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||**************EDIT PLANS***************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\n\t\t\t\t1. EDIT WORKOUT PLAN";
        cout << "\n\n\t\t\t\t2. EDIT DIET PLAN";
        cout << "\n\n\t\t\t\t3. EXIT";
        cout << "\n\n\t\t\t\tENETER YOUR CHOICE:-";
        ip = int_validate(0, 4);
        switch (ip)
        {
        case 1:
            edit_workout_plan();
            break;
        case 2:
            edit_diet_plan();
            break;
        case 3:
            break;
        default:
            cout << "\n\n\t\t\t\tENTER VALID CHOICE...!";
            break;
        }
        cout << "\n\t\t\t\tPRESS ANY KEY TO EXIT";
        getch();
    }
    void edit_diet_plan()
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||************EDIT DIET PLAN*************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\n\t\t\t\t1.WEIGHT GAIN";
        cout << "\n\n\t\t\t\t2.WEIGHT MAINTAIN";
        cout << "\n\n\t\t\t\t3.WEIGHT LOSS";
        cout << "\n\n\t\t\t\tENETER YOUR CHOICE:-";
        ip = int_validate(0, 4);
        switch (ip)
        {
        case 1:
            file_name = file_name + "low";
            break;
        case 2:
            file_name = file_name + "normal";
            break;
        case 3:
            file_name = file_name + "high";
            break;
        default:
            break;
        }
        ip = 0;
        flag = 0;
        cout << "\n\n\t\t\t\t1.VEG ";
        cout << "\n\n\t\t\t\t2.NON_VEG ";
        cout << "\n\n\t\t\t\tENETER YOUR CHOICE:-";
        ip = int_validate(0, 3);
        switch (ip)
        {
        case 1:
            file_name = file_name + "_veg";
            break;
        case 2:
            file_name = file_name + "_nonveg";
            break;
        default:
            break;
        }
        file_name = file_name + ".txt";
        cout << "\n\t\t\t\tCURRENT DIET PLAN";
        cout << "\n\t\t\t\t"
             << "TIME"
             << "\t\t\t"
             << "DIET";
        fstream file10, file11;
        file10.open(file_name, ios::in);
        while (!file10.eof())
        {
            getline(file10, diet);
            if(diet==""){
                break;
            }
            cout << "\n\t\t\t\t"
                 << diet;
        }
        file10.close();
        file11.open("temp.txt", ios::app);
        cout << "\n\t\t\t\tNEW DIET PLAN";
        fstream file12;
        diet = ""; // initialize diet
        i = 0;
        file12.open("time.txt", ios::in);
        while (!file12.eof())
        {
            getline(file12, time);
            cout << "\n\t\t\t\t"
                 << "ENTER DIET FOR " << time;
            if (i == 0)
            {
                getline(cin, diet);
            }
            i++;
            getline(cin, diet);
            file11 << time << diet << endl;
        }
        file11.close();
        file12.close();
        remove(file_name.c_str());
        rename("temp.txt", file_name.c_str());
    }
    void edit_workout_plan()
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||***********EDIT WORKOUT PLAN***********||";
        cout << "\n\t\t\t\t\t\t===========================================";
        int flag = 0;
        string file_name = "";
        string workout;
        int set, repeatition;
        char input;
        cout << "\n\n\t\t\t\t1.WEIGHT GAIN";
        cout << "\n\n\t\t\t\t2.WEIGHT MAINTAIN";
        cout << "\n\n\t\t\t\t3.WEIGHT LOSS";

        cout << "\n\n\t\t\t\tENETER YOUR CHOICE :-";
        int_validate(0, 4);
        switch (ip)
        {
        case 1:
            file_name = file_name + "low";
            break;
        case 2:
            file_name = file_name + "normal";
            break;
        case 3:
            file_name = file_name + "high";
            break;
        default:
            break;
        }
        file_name = file_name + "_workout_gym";
        ip = '0';
        cout << "\n\n\t\t\t\t1.MALE ";
        cout << "\n\n\t\t\t\t2.FEMALE ";
        flag = 0;
        cout << "\n\n\t\t\t\tENETER YOUR CHOICE :-";
        ip = int_validate(0, 3);
        switch (ip)
        {
        case 1:
            file_name = file_name + "_MALE";
            break;
        case 2:
            file_name = file_name + "_FEMALE";
            break;
        default:
            break;
        }
        file_name = file_name + ".txt";
        int a, b;
        string d;
        fstream file20, file21;
        file20.open(file_name, ios::in);
        file20 >> a >> d >> b;
        cout << "\n\t\t\t\tCURRENT WORKOUT PLAN";
        while (!file20.eof())
        {
            cout << "\n\t\t\t\t" << a << "\t" << b << "\t" << d << endl;
            file20 >> a >> d >> b;
        }
        file20.close();
        file21.open("temp.txt", ios::out);
        cout << "\n\t\t\t\tNEW WORKOUT PLAN";
        do
        {
            cout << "\n\t\t\t\tENTER  WORKOUT NAME :-";
            cin >> workout;
            workout = string_validate(workout);
            cout << "\n\t\t\t\tENTER NUMBER OF SET :-";
            set = int_validate(0, 100);
            cout << "\n\t\t\t\tENTER NUMBER OF REPEATITION :-";
            repeatition = int_validate(0, 100);
            ;
            file21 << set << "\t" << workout << "\t" << repeatition << endl;
            cout << "\n\t\t\t\tDO YOU WANT TO CONTINUE[Y/N]:- ";
            cin >> input;
        } while (input != 'N' && input != 'n');
        file21.close();
        remove(file_name.c_str());
        rename("temp.txt", file_name.c_str());
    }
    void edit_admin()
    {
        fstream file13, file14;
        file13.open("pass.txt", ios::in);
        file13 >> pass >> name;
        file13.close();
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||**************ADMIN EDIT***************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\n\t\t\t\tENTER PASSWORD :-";
        password = password_();
        if (pass == password)
        {
            cout << "\n\n\t\t\t\tCURRENT ADMIN NAME :-" << name;
            cout << "\n\n\t\t\t\tCURRENT ADMIN PASSWORD :-" << pass;
            name = "";
            pass = "";
            cout << "\n\n\t\t\t\tNEW ADMIN NAME[CAPITAL LETTER ONLY] :-";
            cin >> name;
            name = string_validate(name);
            cout << "\n\n\t\t\t\tNEW ADMIN PASSWORD :-";
            pass = password_();
            file14.open("pass.txt", ios::out);
            file14 << pass << "\t" << name;
            file14.close();
        }
        else
        {
            cout << "\n\n\t\t\t\tWRONG PASSWORD...!";
        }
    }
    void signin()
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||*************** SIGNIN ****************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        do
        {
            phone = 0;
            cout << "\n\n\t\t\t\tENTER YOUR PHONE NUMBER =";
            phone3 = long_long_int_validate(999999999, 10000000000);
            fstream file15;
            file15.open("member.txt", ios::in);
            while (!file15.eof())
            {
                file15 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
                if (phone3 == phone)
                {
                    cout << "\n\n\t\t\t\tTHIS NO IS ALREADY TAKEN TRY ANOTHER";
                    count = 1;
                    break;
                }
                else
                {
                    count = 0;
                }
            }
            file15.close();
        } while (count != 0);
        phone = phone3;
        cout << "\n\t\t\t\tENTER YOUR NAME[ONLY CAPITAL LETTER] =";
        cin >> name;
        name = string_validate(name);
        cout << "\n\n\t\t\t\tENTER YOUR HEIGHT(Height in M)[RANGE-0.5-2.5] =";
        height = float_validate(0.49, 2.51);
        cout << "\n\n\t\t\t\tENTER YOUR WEIGHT(Weight in KG)[RANGE-1-200] =";
        weight = float_validate(0, 201);
        cout << "\n\n\t\t\t\tENETER YOUR GENDER(1=MALE/2=FEMALE) =";
        ip = int_validate(0, 3);
        if (ip == 1)
        {
            gender = "MALE";
        }
        else
        {
            gender = "FEMALE";
        }
        bmi1(height, weight);
        if (bmi < 18.5)
        {
            msg = "GAIN";
        }
        else if (bmi < 24.5)
        {
            msg = "MAINTAIN";
        }
        else
        {
            msg = "LOSS";
        }
        plan = "NON";
        plan2 = "NON";
        cout << "\n\n\t\t\t\tENETER YOUR PASWORD =";
        pass = password_();
        fstream file16;
        file16.open("member.txt", ios::app);
        file16 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
        file16.close();
        cout << "\n\t\t\t\tPRESS ANY KEY TO EXIT";
        getch();
    }
    void login()
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||*****************LOGIN*******************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\tENTER YOUR PHONE NUMBER =";
        phone1 = long_long_int_validate(999999999, 10000000000);
        cout << "\n\t\t\t\tENTER YOUR PASSWORD =";
        password = password_();
        fstream file17;
        file17.open("member.txt", ios::in);
        while (!file17.eof())
        {
            file17 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
            if (phone1 == phone && password == pass)
            {
                file17.close();
                count = 1;
                login1(phone1);
                break;
            }
        }
        file17.close();
        if (count == 0)
        {
            cout << "\n\t\t\t\t\tTHERE IS NO MEMBER THESE NUMBER....!";
        }
    }
    float bmi1(float height, float weight)
    {
        return (weight / (height * height));
    }
    void edit(long long int phone9)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||**********EDITING INFORMATION**********||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\n\t\t\t\tCONFIRM NUMBER TO EDIT INFORMATION=";
        phone2 = long_long_int_validate(999999999, 10000000000);
        if (phone9 == phone2)
        {
            cout << "\n\n\t\t\t\tENTER PASSWORD :-";
            password = password_();
            fstream file4;
            file4.open("member.txt", ios::in);
            while (!file4.eof())
            {
                file4 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
                if (phone == phone2 && pass == password)
                {
                    file4.close();
                    fstream file14;
                    file4.open("edit.txt",ios::app);
                    file14 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
                    file14.close();
                    edit_account(phone2);
                    found = 1;
                    break;
                }
            }
            file4.close();
            if (found != 1)
            {
                cout << "\n\n\t\t\t\tWRONG NUMBER OR PASSWORD...!";
            }
        }
        else
        {
            cout << "\n\n\t\t\t\tNUMBER NOT MATCH...!";
        }
    }
    void login1(long long int phone4)
    {
        int ip1;
        system("cls");
        fstream file56;
        file56.open("member.txt", ios::in);
        while (!file56.eof())
        {
            file56 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
            if (phone4 == phone)
            {
                break;
            }
        }
        file56.close();
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||***************WELCOME*****************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\n\t\t\t\tWELCOME " << name << endl;
        cout << "\n\n\t\t\t\tYOUR HEIGHT  =" << height << endl;
        cout << "\n\n\t\t\t\tYOUR WEIGHT=" << weight << endl;
        cout << "\n\n\t\t\t\tYOU NEED TO " << msg << " YOUR WEIGHT.";
        cout << "\n\n\t\t\t\tACCORDING TO OUR CALCULATION YOU SHOULD FOLLOW FOLLOWING BELL AND WORKOUT" << endl;
        file_name1 = workout1(plan);
        diet1(plan2, file_name1, phone);
        cout << "\n\n\t\t\t\tDO YOU WANT TO EDIT OR DELETE YOUR INFORMATION [1=EDIT INFORMATION/2=DELETE/3=EDIT PASSWORD/4=EXIT] =";
        ip1 = int_validate(0, 5);
        switch (ip1)
        {
        case 1:
            edit(phone4);
            break;
        case 2:
            delete1(phone4);
            break;
        case 3:
            edit_pass(phone4);
            break;
        case 4:
            cout << "\n\t\t\t\tEXITING...";
            break;
        default:
            cout << "\n\t\t\t\tINVALID INPUT" << endl;
            break;
        }
        cout << "\n\t\t\t\tPRESS ANY KEY TO EXIT";
        getch();
    }
    void delete1(long long int phone9)
    {
        string plan;
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||************DELETE ACCOUNT*************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\tCONFIRM NUMBER TO DELETE INFORMATION =";
        phone2 = long_long_int_validate(999999999, 10000000000);
        if (phone9 == phone2)
        {
            cout << "\n\n\t\t\t\tENTER PASSWORD :-";
            password = password_();
            fstream file3;
            file3.open("member.txt", ios::in);
            while (!file3.eof())
            {
                file3 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
                if (phone == phone2 && pass == password)
                {
                    found = 1;
                    file3.close();
                    fstream file15;
                    file15.open("delete.txt",ios::app);
                    file15<<phone<<endl;
                    file15.close();
                    delete_account(phone2);
                    break;
                }
            }
            file3.close();
            if (found != 1)
            {
                cout << "\n\n\t\t\t\tWRONG NUMBER OR PASSWORD..!";
            }
        }
        else
        {
            cout << "\n\t\t\t\tTHE NUMBER NOT MATCH" << endl;
        }
    }
    void diet1(string filename5, string file_name2, long long int phone6)
    {
        fstream file38;
        long long int phone5;
        count = 0;
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||*****************DIET******************||";
        cout << "\n\t\t\t\t\t\t===========================================";
        bmi1(height, weight);
        if (filename5 == "NON")
        {
            cout << "\n\n\t\t\t\tENTER VEGETARIAN OR NON-VEGETARIAN[1=VEGETARIAN/2=NON-VEGETARIAN]=";
            ip = int_validate(0, 3);
            if (bmi < 18.5)
            {
                filename = "low";
                             }
            else if (bmi < 24.5)
            {
                filename = "normal";
            }
            else
            {
                filename = "high";
            }
            if (ip == 1)
            {
                filename = filename + "_veg";
            }
            else
            {
                filename = filename + "_nonveg";
            }
            filename = filename + ".txt";
            count = 1;
        }
        else
        {
            filename = filename5;
            count = 0;
        }
        fstream file31;
        file31.open(filename, ios::in);
        cout << "\n\t\t\t\t"
             << "TIME"
             << "\t"
             << "DIET";
        while (!file31.eof())
        {
            getline(file31, diet);
            cout << "\n\t\t\t\t"
                 << diet;
        }
        file31.close();
        if (count = 1)
        {
            fstream file5;
            file5.open("member.txt", ios::in);
            fstream file9;
            file9.open("member1.txt", ios::app);
            file5 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
            while (!file5.eof())
            {
                if (phone6 != phone)
                {
                    file9 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
                }
                else
                {
                    plan = file_name2;
                    plan2 = filename;
                    file9 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
                }
                file5 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
            }
            file5.close();
            file9.close();
            remove("member.txt");
            rename("member1.txt", "member.txt");
        }
    }
    string workout1(string file_name3)
    {
        if (file_name3 == "NON")
        {
            bmi1(height, weight);
            cout << "\n\n\t\t\t\t\t\t===========================================";
            cout << "\n\t\t\t\t\t\t||****************WORKOUT****************||";
            cout << "\n\t\t\t\t\t\t===========================================";
            if (bmi < 18.5)
            {
                filename = "low_workout.txt";
            }
            else
            {
                filename = "high_workout.txt";
            }
        }
        else
        {
            filename = file_name3;
        }
        fstream file33;
        file33.open(filename, ios::in);
        while (!file33.eof())
        {
            getline(file33, workout);
            cout << "\n\t\t\t\t"
                 << workout;
        }
        file33.close();
        return filename;
    }
    long long int long_long_int_validate(long long int min, long long int max)
    {
        long long int input;
        while (true)
        {
            cin >> input;
            if (cin.fail() || input <= min || input >= max)
            {
                cout << "\n\n\t\t\t\t Wrong Input !!! \n\n\t\t\t\tEnter Correct Value : - ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                return input;
                break;
            }
        }
    }
    int int_validate(int min, int max)
    {
        int input;
        while (true)
        {
            cin >> input;
            if (cin.fail() || input <= min || input >= max)
            {
                cout << "\n\n\t\t\t\t Wrong Input !!! \n\n\t\t\t\tEnter Correct Value : - ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                return input;
                break;
            }
        }
    }
    float float_validate(float min, float max)
    {
        float input;
        while (true)
        {
            cin >> input;
            if (cin.fail() || input <= min || input >= max)
            {
                cout << "\n\n\t\t\t\t Wrong Input !!! \n\n\t\t\t\tEnter Correct Value : - ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                return input;
                break;
            }
        }
    }
    string string_validate(string input)
    {
        do
        {
            int flag = 0;
            for (int i = 0; i < input.length(); i++)
            {
                if ((int)input[i] < 65 || (int)input[i] > 90)
                {
                    flag = flag + 1;
                    break;
                }
            }
            if (flag > 0)
            {
                cout << "\n\n\t\t\t\t Wrong Input !!! \n\n\t\t\t\tEnter Correct Value : - ";
                cin.clear();
                fflush(stdin);
                cin >> input;
            }
            else
            {
                return input;
                break;
            }
        } while (1);
        return input;
    }
    /* member()
     {
         string fileNames[] = {"delete.txt","edit.txt",high_nonveg.txt", "high_veg.txt", "high_workout.txt", "low_veg.txt", "low_nonveg.txt", "low_workout.txt","member_get_msg.txt", "member.txt", "normal_veg.txt", "normal_nonveg.txt", "plans1.txt", "pass.txt","time.txt"};
         const int numFiles = sizeof(fileNames) / sizeof(fileNames[0]);
         fstream files[numFiles];
         for (int i = 0; i < numFiles; ++i)
         {
             files[i].open(fileNames[i], ios::app);
             files[i].close();
         }
         fstream file57;
         file57.open("pass.txt", ios::in);
         file57 >> pass >> name;
         file57.close();
         if (pass == "")
         {
             fstream file;
             file.open("pass.txt", ios::app);
             cout << "\n\n\t\t\t\tSET ADMIN NAME :-";
             cin >> name;
             name = string_validate(name);
             cout << "\n\n\t\t\t\tSET ADMIN PASS :-";
             cin >> pass;
             file << pass << "\t" << name << endl;
             file.close();
         }
     }*/
    
    string password_()
    {
        char ch;
        int i = 0;
        char pwd[30];
        while ((ch = getch()) != 13)
        {
            pwd[i] = ch;
            cout << "*";
            i++;
        }
        pwd[i] = '\0';
        return pwd;
    }
    void delete_account(long long int phone5)
    {
        fstream file4, file5;
        file4.open("member.txt", ios::in);
        file5.open("member1.txt", ios::app);
        //file4 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
        while (!file4.eof())
        {
            file4 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
            if (phone5 != phone)
            {
                file5 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
            }
            phone=phone5;
        }
        cout << "\n\n\t\t\t\tINFORMATION DELETED SUCCESSFULLY...! " << endl;
        file4.close();
        file5.close();
        remove("member.txt");
        rename("member1.txt", "member.txt");
    }
    void edit_account(long long int phone6)
    {
        fstream file5;
        file5.open("member.txt", ios::in);
        fstream file9;
        file9.open("member1.txt", ios::app);
        file5 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
        while (!file5.eof())
        {
            if (phone6 != phone)
            {
                file9 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
            }
            else
            {
                cout << "\n\n\t\t\t\tENTER NEW NAME =";
                cin >> name;
                name = string_validate(name);
                phone = phone6;
                cout << "\n\n\t\t\t\tENTER NEW HEIGHT(Height in M)[Range: 0.5-2.5M]=";
                height = float_validate(0.49, 2.51);
                cout << "\n\n\t\t\t\tENTER NEW WEIGHT(Weight in KG)[Range: 1-200KG] =";
                weight = float_validate(0, 201);
                cout << "\n\n\t\t\t\tENETER GENDER(1=MALE/2=FEMALE) =";
                ip = int_validate(0, 3);
                if (ip == '1')
                {
                    gender = "MALE";
                }
                else
                {
                    gender = "FEMALE";
                }
                bmi = bmi1(height, weight);
                if (bmi < 18.5)
                {
                    msg = "INCREASE";
                }
                else if (bmi < 24.5)
                {
                    msg = "MAINTAIN";
                }
                else
                {
                    msg = "DECREASE";
                }
                plan="NON";
                plan2="NON";
                file9 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
                cout << "\n\n\t\t\t\tINFORMATION IS EDITED" << endl;
            }
            file5 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
        }
        file5.close();
        file9.close();
        remove("member.txt");
        rename("member1.txt", "member.txt");
    }
    void edit_pass(long long int phone8)
    {   
        system("cls");
        cout << "\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t||**********EDITING INFORMATION**********||";
        cout << "\n\t\t\t\t\t\t===========================================";
        fstream file5;
        file5.open("member.txt", ios::in);
        fstream file9;
        file9.open("member1.txt", ios::app);
        file5 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
        while (!file5.eof())
        {
            if (phone8 != phone)
            {
                file9 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
            }
            else
            {
                cout << "\n\n\t\t\t\tCURRENT PASSWORD =" << pass << endl;
                cout << "\n\n\t\t\t\tNEW PASSWORD =" ;
                pass = password_();
                file9 << name << "\t" << phone << "\t" << height << "\t" << weight << "\t" << gender << "\t" << pass << "\t" << plan << "\t" << plan2 << "\t" << msg << endl;
            }
            file5 >> name >> phone >> height >> weight >> gender >> pass >> plan >> plan2 >> msg;
        }
        file5.close();
        file9.close();
        remove("member.txt");
        rename("member1.txt", "member.txt");
    }
};
