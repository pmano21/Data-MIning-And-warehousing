#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
//int min_sup=2;
int M;
float min_sup=35.0;
float min_conf=0.5;
map< set< int >,int > L[101],C[101],mm;
map<set<int>,int> CF,CI,IF,II;

int mx=-1;
vector<vector< int > > transac;
int siz;
int mn_sup;
int NOI;
ifstream fin;
ofstream fout("Rand_File_Output.txt");


int main(){
	
	fin.open("bookex.txt");NOI=5;M=2;
	//fin.open("Rand_Input_file.txt");NOI=25;M=5
	
	siz=0;
	string str;
	while(getline(fin,str))siz++;
	fin.close();
	mn_sup=ceil((min_sup*siz)/100);
	
	fin.open("bookex.txt");NOI=5;
	//fin.open("Rand_Input_file.txt");NOI=25;
	
	while(getline(fin,str)){
		stringstream ss(str);
		string s1,s2;
		ss>>s1;
		vector<int> v;
		v.clear();
		while(ss>>s2){
			s2=s2.substr(1,s2.size()-1);
			int x=stoi(s2);
			v.push_back(x);
			set< int > se;se.insert(x);
			C[1][se]++;
			II[se]=1;mm[se]=0;
		}
		sort(v.begin(),v.end());
		transac.push_back(v);
	}
	int ind=0;
	while(II.size()>0 || IF.size()>0){
		int y=M;
		while(y--){//cout<<"y="<<y<<" ";
			vector<int> t=transac[ind];
			unordered_map<int,int> pres;
			for(int i=0;i<t.size();i++)pres[t[i]]=1;
			//xtfgyhujiko
			for(auto it=IF.begin();it!=IF.end();it++){
				set<int> st=it->first;
				auto sitr=st.begin();
				int flag=0;mm[st]++;
				for(;sitr!=st.end();sitr++){
					if(pres.count(*sitr)==0){
						flag=1;break;
					}
				}
				if(flag==0){
					L[st.size()][st]++;
				}
			}
			for(auto it=II.begin();it!=II.end();it++){
				set<int> st=it->first;
				auto sitr=st.begin();
				int flag=0;mm[st]++;
				for(;sitr!=st.end();sitr++){
					if(pres.count(*sitr)==0){
						flag=1;break;
					}
				}
				if(flag==0){
					L[st.size()][st]++;
				}
			}
			// hjnkml;
			vector<set<int>> rem;
			for(auto it=II.begin();it!=II.end();it++){
				set<int> st=it->first;
				if(L[st.size()][st]>=mn_sup){
					IF[st]=1;
					rem.push_back(st);
					vector<bool> vec(NOI+1,false);
					for(auto itr=st.begin();itr!=st.end();itr++)
						vec[*itr]=true;
					for(int i=1;i<=NOI;i++)
					for(int x=1;x<=NOI;x++){
						if(vec[x]==false){
							set<int> chk,chk1;chk1=st;chk1.insert(x);
							bool f=0;
							for(int y=0;y<st.size();y++){
								chk=st;
								auto anit=chk.begin();advance(anit,y);
								chk.erase(anit);
								chk.insert(x);
								if(CF.count(chk)==1 || IF.count(chk)==1){}
								else {f=1;break;}								
							}
							if(f==0)II[chk1]=1;
						}
						
					}
				}
			}
			for(int r=0;r<rem.size();r++){
				II.erase(rem[r]);
			}
			//biojpknm
			vector<set<int>> rem1;
			for(auto it=IF.begin();it!=IF.end();it++){
				set<int> st=it->first;
				if(mm[st]==siz){
					rem1.push_back(st);
					CF[st]++;
				}
			}
			for(int r=0;r<rem1.size();r++){
				IF.erase(rem1[r]);
			}
			vector<set<int>> rem2;
			for(auto it=II.begin();it!=II.end();it++){
				set<int> st=it->first;
				if(mm[st]==siz){
					rem2.push_back(st);
					CI[st]++;
				}
			}
			for(int r=0;r<rem2.size();r++){
				II.erase(rem2[r]);
			}
			//
			ind=(ind+1)%siz;
		}
	}
	
	fout<<"FREQUENT ITEMSETS:\n";
	for(int i=1;L[i].size()>0;i++){
		fout<<i<<"-itemset"<<endl;
    	for(auto it=L[i].begin();it!=L[i].end();it++){
        		//set< int >:: iterator itr;
        		if(it->second>=mn_sup){
	        		auto itr=it->first.begin();
	        		fout<<"{ ";
	        		for(;itr!=it->first.end();itr++)fout<<"I"<<*itr<<" ";
	        		fout<<"}";
	        		fout<<" -> sup_cnt="<<it->second;
	        		fout<<endl;
				}
    	}
	}
	
	fin.close();
	fout.close();
	return 0;
}



