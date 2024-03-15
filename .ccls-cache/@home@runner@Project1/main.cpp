#include<iostream>
#include<string>
#include"class.h"
using namespace std;
int main()
{
	member M1;
	char ch;
	do
	{
cout<<"\n\n***************Fitness**Trainer***************";
		cout<<"\n\n1. SIGNIN";
		cout<<"\n\n2. LOGIN";
		cout<<"\n\n3. EXIT";
		cout<<"\n\nENTER YOUR CHOICE : - ";
		cin>>ch;
    switch(ch)
      {
			case '1':
				M1.signin();
				break;
			case '2':
				M1.login();
				break;
      case '3':
cout<<"\n\n******************THANK*YOU!!!!*******************";	
				break;
        default:
				cout<<"\n\nEnter Correct Choice!!!";
      }
	}while(ch!='3');
	return 0;
}

