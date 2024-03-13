#include<iostream>
#include<fstream>
using namespace std;
class member
{
    string name;
int count=0;
    long long int phone, phone2, phone3;
    float height;
    float weight;
    float bmi;
    char ip;
    string gender;
public:
    long long int phone1;
//void delete1() ;
//void diet() ;
//void workout () ;
//hello
    void signin()
    {   cout<<"\n\n******************SIGNIN*******************";
        
     do{cout<<"Enter your phone number =";
        cin>>phone3;
     fstream file;
     file.open("member.txt", ios::in);
     file>>name>>phone>>height>>weight>>gender;
        while(!file.eof())
        {
            if(phone3==phone) {
                cout<<"This no is already taken try another";
count++;
              
            }else{
              count=0;
            }
            file>>name>>phone>>height>>weight>>gender;
        }
        file.close();}while(count!=0);
     phone=phone3;
cout<<"\nEnter your name =";
        cin>>name;
        cout<<"Enter your height =";
        cin>>height;
        cout<<"Enter your weight =";
        cin>>weight;
        do {
            cout<<"Enter your gender(1=Male/2=Female) =";
            cin>>ip;
        }
        while(ip!='1' && ip!='2');
        if(ip=='1') {
            gender="Male";
        }
        else {
            gender="Female";
        }

        fstream file;
        file.open("member.txt",ios::app);
        file<<name<<"\t"<<phone<<"\t"<<height<<"\t"<<weight<<"\t"<<gender<<endl;
        file.close();
    }
    void login()
    {
        cout<<"\n\n******************LOGIN*******************";
        cout<<"\nEnter your phone no =";
        cin>>phone1;
        fstream file;
        file.open ("member.txt", ios::in) ;
        file>>name>>phone>>height>>weight>>gender;
        while(!file.eof())
        {
            if(phone1==phone) {
                login1();

                break;
            }
            file>>name>>phone>>height>>weight>>gender;
        }
        file.close();
    }
    void bmi1(float height, float weight)
    {
        bmi=weight/(height*height);
    }
    void edit()
    {   cout<<"\nConfirm the number to edit information =";
        cin>>phone2;
        if(phone1==phone2) {
            fstream file;
            file.open("member.txt", ios::in);
            file>>name>>phone>>height>>weight>>gender;
            fstream file1;
            file1.open("member1.txt", ios::app);
            while (!file.eof()) {

                if(phone1!=phone) {
                    file1<<name<<"\t"<<phone<<"\t"<<height<<"\t"<<weight<<"\t"<<gender<<endl;
                }
                else {
                    cout<<"Enter your name =";
                    cin>>name;
                    phone=phone1;
                    cout<<"Enter your height =";
                    cin>>height;
                    cout<<"Enter your weight =";
                    cin>>weight;
                    do {
                        cout<<"Enter your gender(1=Male/2=Female) =";
                        cin>>ip;
                    }
                    while(ip!='1' && ip!='2');
                    if(ip=='1') {
                        gender="Male";
                    }
                    else {
                        gender="Female";
                    }
                    file1<<name<<"\t"<<phone<<"\t"<<height<<"\t"<<weight<<"\t"<<gender<<endl;
                  cout<<"Information is edited"<<endl;
                }
                file>>name>>phone>>height>>weight>>gender;
            }
            file1.close();
            file.close();
            remove ("member.txt");
            rename("member1.txt","member.txt");
        }
        else {
            cout<<"\nNumber not match"<<endl;
        }
    }
    void login1() {

        cout<<"Welcome "<<name<<endl;
        cout<<"Your height is ="<<height<<endl;
        cout<<"Your weight is ="<<weight<<endl;
        cout<<" According to our calculation you should follow following diet and workout"<<endl;
        diet();
        workout();
        do {
            cout<<"\n\nDo you want to edit or delete your information [1=edit/2=delete/3=exit] ="<<endl;
            cin>>ip;
            switch(ip) {
            case '1':
                edit();
                break;
            case '2':
                delete1();
                break;
            case '3':
                cout<<"\nExiting...";
                break;
            default:
                cout<<"\nInvalid input"<<endl;
                break;
            }
        } while (ip!='3');

    }
    void delete1 ()
    {
        cout<<"\nConfirm the number to delete information =";
        cin>>phone2;
        if(phone1==phone2) {
            fstream file, file1;
            file.open("member.txt", ios::in);
            file>>name>>phone>>height>>weight>>gender;
            file1.open("member1.txt", ios::app);
            while (!file.eof()) {
                if(phone2!=phone) {
                    file1<<name<<"\t"<<phone<<"\t"<<height<<"\t"<<weight<<"\t"<<gender<<endl;//file>>name>>phone>>height>>weight>>gender;

                }
                else {
                    cout<<"\nInformation deleted "<<endl;
                }
                file>>name>>phone>>height>>weight>>gender;
            }
            file1.close();
            file.close();
            remove ("member.txt");
            rename("member1.txt","member.txt");
        }
        else {
            cout<<"\nNumber not match";
        }
    }
    void diet() {
        bmi1(height, weight);
        if(bmi<18.5) {
            do {
                cout<<"\nEnter your veg or non-veg[1=veg/2=non-veg]=";
                cin>>ip;
                switch(ip) {
                case '1':
                    cout<<"low weight veg diet";
                    break;
                case '2':
                    cout<<" low weight non veg diet";
                    break;
                default:
                    cout<<"invalid input";
                    break;
                }
            }
            while (ip!='1' && ip!='2');
        }

        else if(bmi>=18.5 && bmi<=24.9) {
            do {
                cout<<"\nEnter your veg or non-veg[1=veg/2=non-veg]=";
                cin>>ip;
                switch(ip) {
                case '1':
                    cout<<"normal weight veg diet";
                    break;
                case '2':
                    cout<<" normal weight non veg diet";
                    break;
                default:
                    cout<<"invalid input";
                    break;
                }
            } while (ip!='1' && ip!='2') ;
        }
        else
        {   do {
                cout<<"\nEnter your veg or non-veg[1=veg/2=non-veg]=";
                cin>>ip;
                switch(ip) {
                case '1':
                    cout<<"high weight veg diet";
                    break;
                case '2':
                    cout<<" high weight non veg diet";
                    break;
                default:
                    cout<<"invalid input";
                    break;
                }
            } while (ip!='1' && ip!='2') ;
        }
    }
    void workout () {
        bmi1(height, weight);
        if(bmi<18.5) {
            do {
                cout<<"\nEnter your where you do workout[1=home/2=gym]=";
                cin>>ip;
                switch(ip) {
                case '1':
                    cout<<"low weight home workout";
                    break;
                case '2':
                    cout<<" low weight gym workout";
                    break;
                default:
                    cout<<"invalid input";
                    break;
                }
            } while (ip!='1' && ip!='2');
        }
        else if(bmi>=18.5 && bmi<=24.9) {
            do {
                cout<<"\nEnter your where you do workout[1=home/2=gym]=";
                cin>>ip;
                switch(ip) {
                case '1':
                    cout<<"normal weight home workout";
                    break;
                case '2':
                    cout<<" normal weight gym workout ";
                    break;
                default:
                    cout<<"invalid input";
                    break;
                }
            } while (ip!='1' && ip!='2') ;
        } else
        {   do {
                cout<<"\nEnter your where you do workout[1=home/2=gym]=";
                cin>>ip;
                switch(ip) {
                case '1':
                    cout<<"high weight home workout";
                    break;
                case '2':
                    cout<<" high weight gym workout";
                    break;
                default:
                    cout<<"invalid input";
                    break;
                }
            } while (ip!='1' && ip!='2') ;
        }
    }
};