#include <bits/stdc++.h>
using namespace std;

class Apriori{
    public:
    // to store the input database
    // TODO: try to change this to unordered_set<char> type values so that this can provide the functionality of present-map
    unordered_map<string, unordered_set<string>> transactions;
    // to store the unique items in whole database
    set<string> items;
    // to store presence of particular itemset in a transaction
    unordered_map<string, unordered_set<char>> present;
    // to store the candidates
    unordered_set<string> candidates; 
    // to store the final frequent itemsets
    map<int, vector<string>> output;
    // to store the frequencies of each itemset
    unordered_map<string, unordered_set<string>> freq;
    // to store size of database
    int noOfTrans = 0;
    int minSupport;


    // cosntructor that initialises Apriori object with the database stored in maps
    Apriori(ifstream &in, int minSupp, bool proportion){
        // minSupport = minSupp;
        string s, t = "";
        while(in>>s){
            if(s[0] == 'T'){
                t = s;
                noOfTrans++;
            }else{
                // insert the item in items list of transaction 't'
                transactions[t].insert(s);
                // insert the item in the set of all distinct items in the database
                if(items.find(s) == items.end()){
                    items.insert(s);
                }
                // initialising frequency map with frequencies of 1-itemsets
                freq[s].insert(t);
                // recording if the item is present in particular
                // TODO: try to replace the functionality of this map with transactions map itself
                present[t].insert(s[0]);
            }
        }

        if(proportion){
            minSupport = ceil(noOfTrans*((double)minSupp/100));
        }else{
            minSupport = minSupp;
        }
    }

    // main function that produces the frequent itemsets
    void produceFreqItemSets(){
        // producing 1-itemsets
        for(auto i: items){
            if(freq[i].size()>=minSupport){
                candidates.insert(i);
                output[1].push_back(i);
            }
        }
        int k = 1;

        while(k<=items.size() && !candidates.empty()){
            // cout<<"producing candidates of size: "<<k+1<<endl;
            // taking all k size itemsets into candidates
            unordered_set<string> ret = joining(k);
            candidates = ret;
            k++;
            // cout<<"k = "<<k<<"\tcandidates size = "<<candidates.size()<<endl;
        }
    }
    
    // returns new set of candidates of k size
    unordered_set<string> joining(int k){
        vector<string> list(candidates.begin(), candidates.end());
        unordered_set<string> ret;

        // for each itemset in candidates set, checking if they can be joined and joining the itemsets 
        for(int i = 0; i<list.size(); i++){
            for(int j = i+1; j<list.size(); j++){
                if(list[i].substr(0,k-1)==list[j].substr(0,k-1)){
                    string newCand = list[i].substr(0,k-1) + list[i][k-1] + list[j][k-1];
                    // maintaining lexical order in the itemsets to avoid duplicates
                    sort(newCand.begin(), newCand.end());
                    if(freq.find(newCand)==freq.end())
                        assignFreq(newCand);

                    // cout<<newCand<<" "<<freq[newCand].size()<<endl;
                    bool invalid = pruning(newCand);
                    // cout<<"contains infreq subset: "<<invalid<<endl;
                    if(!invalid && freq[newCand].size()>=minSupport){
                        // cout<<"Inserting the candidate: "<<newCand<<"---------\n"<<endl;
                        output[k].push_back(newCand);
                        // pushing the new candidate to new candidates set
                        ret.insert(newCand);
                    }
                }
            }
        }

        return ret;
    }

    bool pruning(string itemset){
        // checks for all possible k-1 subsets if they are present in output or not
        // cout<<"checking for infrequent subsets in itemset "<<itemset<<endl;
        int n = itemset.size();
        for(int i = 0; i<n; i++){
            string subset = itemset.substr(0, i) + itemset.substr(i+1, n-i-1);
            // cout<<"Current subset: "<<subset<<endl;
            if(candidates.find(subset) == candidates.end()){
                // cout<<"------------\n";
                return true;
            }
        }
        // cout<<"-------------\n";
        return false;
    }

    // checks the frequency of this particular itemset in different transactions
    void assignFreq(string itemset){
        int n = itemset.size();
        for(auto i: present){
            int cnt = 0;
            for(char c: itemset){
                if(i.second.find(c)!=i.second.end()){
                    cnt++;
                }
            }
            if(cnt == n){
                freq[itemset].insert(i.first);
            }
        }
    }

    // print the result to provided output file
    void storeResult(ofstream &out){
        for(auto i: output){
            for(auto j: i.second){
                out<<j<<endl;
            }
        }
    }

};

int main(int argc, char *argv[]){
    ifstream in;
    ofstream out;
    // expects three command line arguments
    // argv[1] - input file path
    // argv[2] - output file path
    // argv[3] - minimum support as a proportional value/absolute count

    in.open(argv[1]);
    out.open(argv[2]);

    // required minimum support for the operation
    int n = 0;
    int minSupp = 0;
    while(argv[3][n]!='\0'){
        if(argv[3][n]!='%'){
            minSupp = minSupp*10 + argv[3][n] - '0';
        }
        n++;
    }
    bool proportion = (argv[3][n-1]=='%'); 

    // creating an object that takes in database and applies apriori algorithm to generate frequent itemsets
    Apriori driver(in, minSupp, proportion);
    // this method of the object is the starting point of the apriori algo that produces 1-itemsets
    driver.produceFreqItemSets();
    driver.storeResult(out);

    return 0;
}