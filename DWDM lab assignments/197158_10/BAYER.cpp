#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	ifstream inputfile("input.txt"); 
	ofstream outputfile("output.txt");
    string s;
    int level=-1;
    int column=0;
    vector<vector<int>>transactions(12);
    while(inputfile>>s)
    {
        if(s[0]=='T'&&level!=11)
        {
            level++;
            column=0;
        }
        else if(level==12)
		break;       
        else if(column==0)
        {
            if(s[0]=='y')
            {
                transactions[level].push_back(0);
            }
            else if(s[0]=='m')
            {
                transactions[level].push_back(1);
            }
            else
            {
                transactions[level].push_back(2);
            }
            column++;
        }
        else if(column==1)
		{
            if(s[0]=='l')
            {
                transactions[level].push_back(0);
            }
            else if(s[0]=='m')
            {
                transactions[level].push_back(1);
            }
            else 
			transactions[level].push_back(2);
            column++;
        }
        else if(column==2)
		{
            if(s[0]=='n') 
			transactions[level].push_back(0);
            else 
			transactions[level].push_back(1);
            column++;
        }
        else if(column==3)
		{
            if(s[0]=='f') 
			transactions[level].push_back(0);
            else 
			transactions[level].push_back(1);
            column++;
        }
        else if(column==4)
        {
            if(s[0]=='n') 
			transactions[level].push_back(0);
            else 
			transactions[level].push_back(1);
        }
    }
    double n_buys=0;
    for(int i=0;i<12;i++)
    {
        if(transactions[i][4]==1)
        {
            n_buys++;
        }
    }
    vector<int>check{0,1,1,0};
    double p_buys=1;
    double p_dontbuys=1;
    for(int i=0;i<4;i++)
    {
        double c1=0;
        double c2=0;
        for(int j=0;j<12;j++)
        {
            if(transactions[j][i]==check[i]&&transactions[j][4]==1)
            {
                c1++;
            }
            if(transactions[j][i]==check[i]&&transactions[j][4]==0) 
			{
				
				c2++;
			}
        }
        p_buys=p_buys*c1/n_buys;
        p_dontbuys=p_dontbuys*c2/(12-n_buys);
    }
    if(p_buys*n_buys>p_dontbuys*(12-n_buys)) 
	outputfile<<"buys computer";
    else 
	outputfile<<"dont buy computer";
}
