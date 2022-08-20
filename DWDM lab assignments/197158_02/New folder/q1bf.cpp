#include<bits/stdc++.h>
using namespace std;
int min_support=3;
map<string, vector<string> > input;
vector<string> transcations;
set<pair<int ,vector<string> > > output;
map< vector<string>,int> freq;

bool check(vector<string> temp)
{
	int  cnt=0;
	for(auto i:input)
	{
		bool f=true;
		for(int j=0;j<temp.size();j++)
		{
			if(find(i.second.begin(),i.second.end(),temp [j])!=i.second.end())
			continue;
			else
			{
				f=false;
				break;
			}
		}
		if(f==true)
		cnt++;
	}
	if(cnt>=min_support)
	{
		output.insert({temp.size(),temp});
		freq[temp]+=cnt;
		return true;
		
	}
	return false;
}

void cal(vector<string> &transcations,vector<string> temp,int start,int end,bool & flag)
{
	if(temp.size()>end)
	return;
	else if(temp.size()==end)
	{
		bool b=check(temp);
		if(b==true)
		flag =true;
		
	}
	else
	{
		for(int i=start;i<transcations.size();i++)
		{
			temp.push_back(transcations[i]);
			cal(transcations,temp,i+1,end,flag);
			temp.pop_back();
		}
	}
}
int main()
{
	ofstream of;
	
	of.open("BF_output2.txt");
	srand((unsigned) time(0));
	int t=1+rand()%(20);
	int lower=1;
	int upper=20;
	
	for(int i=1;i<=t;i++)
	{
		of<<"T"<<i<<" ";
		
		int v=1+(rand()%(20));
		
		for(int j=0;j<v;j++)
		{
			
        int num = (rand() % 
           (upper - lower + 1)) + lower;  
           of<<num<<" ";
	
		
	    }    
	of<<endl;
	ifstream inputfile;
	inputfile.open("BF_output2.txt");
	string s,t="";
	ofstream outputfile;
	outputfile.open("BF_output1.txt");
	while(inputfile>>s)
	{
		if(s.size()>=2&&s[0]=='T')
		{
			t=s;
		}
		else
		{
			if(find(input[t].begin(),input[t].end(),s)==input[t].end())
			{
				input[t].push_back(s);
			}
			if(find(transcations.begin(),transcations.end(),s)==transcations.end())
			{
				transcations.push_back(s);
			}
		}
	}
	for(int i=1;i<=transcations.size();i++)
	{
		vector<string> temp;
		bool flag =false;
		cal(transcations,temp,0,i,flag);
		if(flag==false)
		break;
	}
	for(auto i:output)
	{
		outputfile<<i.first<<" ";
		for(int j=0;j<i.second.size();j++)
		{
			outputfile<<"T"<<i.second[j]<<" ";
			
		}
		outputfile<<freq[i.second]<<endl;
	}
	
}
}
