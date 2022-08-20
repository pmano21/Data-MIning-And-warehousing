#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	ifstream list;
	list.open("input.txt");
	ofstream items_count;
	items_count.open("output3.txt");
char ch;
    int Frequency[26]={0};
	while(!list.eof())
	{
        list.get(ch);
        if(ch>='a'&&ch<='z')
        Frequency[ch-'a']++;
    }
    for(int i=0;i<26;i++)
    {
    	if(Frequency[i])
    	{
    		items_count<<char('a'+i)<<" "<<Frequency[i]<<endl;
		}
	}
list.close();
	items_count.close();
	return 0;
}
