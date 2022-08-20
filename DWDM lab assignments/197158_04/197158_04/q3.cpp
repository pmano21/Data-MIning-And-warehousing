#include<bits/stdc++.h>
#include<fstream>
#include<ostream>
using namespace std;
ifstream fin;
ofstream fout;
void mean(vector<int>v)
{
    int x=0;
    for(auto it:v)
    {
        if(it!=-1)
        x+=it;
    }
    x/=v.size();
    for(auto it:v)
    {
        if(it==-1)
        fout<<x<<" ";
        else 
        fout<<it<<" ";
    }
    fout<<endl;
}
int main()
{
    fin.open("input3.cpp");
    fout.open("output3.cpp");
    vector<vector<int>>v;
    //input
    while(!fin.eof())
    {
        string s;
        getline(fin,s);
        vector<int>x;
        bool flag=0;
        string s1="";
        for(auto it:s)
        {
            if(it==' ')
            {
                int y=stoi(s1);
                x.push_back(y);
                s1="";
                continue;
            }
            s1+=it;
        }
        v.push_back(x);
    } 
    for(auto it:v)
    mean(it);
}