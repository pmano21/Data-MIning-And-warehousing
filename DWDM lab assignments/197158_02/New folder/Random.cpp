#include<bits/stdc++.h>
using namespace std;

int main()
{

	ofstream outputfile;
	
	outputfile.open("random_output.txt");
	
	srand((unsigned) time(0));
	
	int t=1+rand()%(50); 
	
	int l=1;
	int u=5;
	
	
	for(int i=1;i<=t;i++)
	{
		outputfile<<"T"<<i<<" ";
		
		int v=1+(rand()%(10));
		
		for(int j=0;j<v;j++)
		{
			
        int num = (rand() % (u-l+1)) + l;  
           outputfile<<num<<" ";
	
		
	    }    
		outputfile<<endl;
    }
}
