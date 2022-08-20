#include<bits/stdc++.h>
using namespace std;

ofstream fout("out51.txt");
ifstream fin("in51.txt");

vector<float> normalize(vector<float> nums)
{
    float mini = *min_element(nums.begin(), nums.end());
    float maxi = *max_element(nums.begin(), nums.end());
    
    for(int i=0;i<nums.size();i++)
        nums[i] = nums[i] / (maxi - mini);
    return nums;
}

int main()
{
    vector<float> col1, col2;
    int num;
    string s;

    while(getline(fin, s))
    {
        stringstream ss;
        ss << s;
        ss >> num; col1.push_back(num);
        ss >> num; col2.push_back(num);
    }

    col1 = normalize(col1);
    col2 = normalize(col2);

    for(int i=0;i<col1.size();i++)
        fout << col1[i] << " " << col2[i] << endl;

    return 0;
}