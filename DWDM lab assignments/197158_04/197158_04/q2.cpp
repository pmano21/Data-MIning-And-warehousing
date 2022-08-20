#include<bits/stdc++.h>
#include<fstream>
#include<ostream>
using namespace std;
ifstream fin;
ofstream fout;
void freq(vector<int>v)
{
    for(auto it:v)
    fout<<it<<" ";
    fout<<endl;
}
void mean(vector<int>v)
{
    int m=0;
    for(auto it:v)
    m+=it;
    m/=v.size();
    for(auto it:v)
    fout<<m<<" ";
    fout<<endl;
}
void boun(vector<int>v)
{
    for(int i=0;i<=v.size()/2;i++)
    fout<<v[0]<<" ";
    for(int i=v.size()/2+1;i<v.size();i++)
    fout<<v[v.size()-1]<<" ";
    fout<<endl;
}
int main()
{
    fin.open("input2.cpp");
    fout.open("output2.cpp");
    vector<int>v;
    while(!fin.eof())
    {
        int x;
        fin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    map<int,vector<int>>m;
    for(int i=0;i<20;i++)
    m[i/5].push_back(v[i]);
    fout<<"FREQUENCIES\n\n";
    for(auto it:m)
    freq(it.second);
    fout<<"\nMEANS\n\n";
    for(auto it:m)
    mean(it.second);
    fout<<"\nBOUNDARIES\n\n";
    for(auto it:m)
    boun(it.second);
}