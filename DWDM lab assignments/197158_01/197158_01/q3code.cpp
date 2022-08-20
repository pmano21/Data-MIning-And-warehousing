#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream outfile;
   	outfile.open("output3.txt");
    ifstream inputfile;
    inputfile.open("input.txt");
    char ch;
    int Freq[26]={0};
    
	while(!inputfile.eof())
	{
        inputfile.get(ch);
        if(ch>='a'&&ch<='z')
        Freq[ch-'a']++;
    }
    for(int i=0;i<26;i++)
    {
    	if(Freq[i])
    	{
    		outfile<<char('a'+i)<<" "<<Freq[i]<<endl;
		}
	}
    inputfile.close();
}



