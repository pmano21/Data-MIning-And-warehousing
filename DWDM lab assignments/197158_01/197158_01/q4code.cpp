#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inputfile;
    inputfile.open("input.txt");
    ofstream outfile;
	outfile.open("output4.txt");
    char ch;
    vector<int>Freq[26];
    int cnt=0;
	while(!inputfile.eof())
	{
        inputfile.get(ch);
        if(ch>='0'&&ch<='9')
        {
        	cnt=ch-'0';
		}
        if(ch>='a'&&ch<='z')
        {
        	Freq[ch-'a'].push_back(cnt);
		}
    }
    for(int i=0;i<26;i++)
    {
    	if(!Freq[i].empty())
    	{
    		outfile<<char('a'+i)<<" ";
    		for(int j=0;j<Freq[i].size();j++)
    		{
    			outfile<<Freq[i][j]<<" ";
			}
			outfile<<endl;
		}
	}
    inputfile.close();
}
