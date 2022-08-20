#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream transactionfile;
     int l=5;
     transactionfile.open("input.txt");
	 while(l--)
	 {
	 	char data[20];
	 	cin.getline(data,20);
	 	transactionfile<<data<<endl;
		 }	
		 transactionfile.close();
		 return 0;
}
