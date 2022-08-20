#include<bits/stdc++.h>
#include<fstream>
#include<ostream>
using namespace std;
ifstream fin;
ofstream fout;
void method2(vector<int>v)
{
    for(auto it:v)
    {
        if(it==-1)
        fout<<rand()%100<<" ";
        else 
        fout<<it<<" ";
    }
    fout<<endl;
}
void method3(vector<int>v)
{
    for(auto it:v)
    {
        if(it==-1)
        fout<<0<<" ";
        else 
        fout<<it<<" ";
    }
    fout<<endl;
}
int main()
{
    fin.open("input1.cpp");
    fout.open("output1.cpp");
    vector<vector<int>>v;
    //input and method 2
    fout<<"METHOD1\n\n";
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
                if(y==-1)
                flag=1;
                x.push_back(y);
                s1="";
                continue;
            }
            s1+=it;
        }
        /*int y=stoi(s1);
        if(y==-1)
        flag=1;
        x.push_back(y);*/
        v.push_back(x);
        if(flag)
        continue;
        fout<<s<<endl;
    } 
    fout<<endl;
    //filling all unknowns with random value
    //method 2
    fout<<"METHOD2\n\n";
    for(auto it:v)
    method2(it);
    fout<<endl;
    //filling all unknowns with 0
    //method 3
    fout<<"METHOD3\n\n";
    for(auto it:v)
    method3(it);
    fout<<endl;
}