#include<iostream>
#include<fstream>
#include<ostream>
using namespace std;
int main()
{
    ifstream inputfile;
    inputfile.open("input.txt");
    string s;
    ofstream outfile;
   outfile.open("output2.txt");
	while(inputfile)
	{
        while(getline(inputfile,s))
		{
            outfile<<s<<endl;
        }
    }
    inputfile.close();
}
