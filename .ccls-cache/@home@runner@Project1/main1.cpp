#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
  string file_name;
  fstream file;
cout<<"Enter";
     cin>>file_name;
     file_name +=".txt";
     file.open(file_name, ios::out);
file.close();
       return 0;
       }