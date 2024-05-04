#include <iostream>
#include <conio.h>
#include<limits>
#include "class1.h"
using namespace std;
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
int main()
{
	member M1;
	int ch;
	do
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\t==========================================";
		cout << "\n\t\t\t\t\t\t||     F I T N E S S  T R A I N E R     ||";
		cout << "\n\t\t\t\t\t\t==========================================";
		cout << "\n\n\t\t\t\t1. ADMIN";
		cout << "\n\n\t\t\t\t2. SIGNIN";
		cout << "\n\n\t\t\t\t3. LOGIN";
		cout << "\n\n\t\t\t\t4. EXIT";
		cout << "\n\n\t\t\t\tENTER YOUR CHOICE : - ";
	    ch=int_validate(0,5);
		cout << "\n\t\t\t\t==========================================";
		switch (ch)
		{
		case 1:
			M1.admin();
			break;
		case 2:
			M1.signin();
			break;
		case 3:
			M1.login();
			break;
		case 4:
			cout << "\n\n\t\t\t\t\t\t==========================================";
			cout << "\n\t\t\t\t\t\t||***********THANK*YOU!!!!**************||";
			cout << "\n\t\t\t\t\t\t==========================================";
			break;
		default:
			cout << "\n\n\t\t\t\tENTER CORRECT CHOICE!!!";
		}
	} while (ch != 4);
	return 0;
}
//WRITE CODE TO ADD 2 NUMBER

