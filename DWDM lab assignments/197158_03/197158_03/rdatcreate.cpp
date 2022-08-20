#include<bits/stdc++.h>
using namespace std;

int main(){    
    ofstream out;
    srand(96423);
    out.open("randomDb.txt");

    int t = rand() % 10;
    int n = rand() % 8;
    for(int i = 0; i < t; i++){
        int m = 0;
        while(m==0){
            m = rand() % n;
        }
        out<<"T"<<i+1<<" ";
        int cnt = 0;
        unordered_set<char> present;
        for(int j = 0; cnt<m; j++){
            char item = (char)(rand() % n + 'a');
            bool absent = present.find(item) == present.end();
            if(absent){
                present.insert(item);
                out<<item<<" ";
                cnt++;
            }
        }
        out<<"\n";
    }
}