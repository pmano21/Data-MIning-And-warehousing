#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream transactionlist;
	transactionlist.open("input.txt");
	while(transactionlist){
		char data[15];
		transactionlist>>data;
	cout<<data<<endl;
	}
	transactionlist.close();
	return 0;
}
