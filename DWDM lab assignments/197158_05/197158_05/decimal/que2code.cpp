#include<bits/stdc++.h>
using namespace std;

ofstream fout("out25.txt");
ifstream fin("in25.txt");

vector<float> normalize(vector<float> nums)
{
    int n = nums.size();
    int p = 0;
    for(int i=0;i<n;i++)
        p = max(p, int(ceil(log10(nums[i]))) );
    for(int i=0;i<n;i++)
        nums[i] = nums[i] / pow(10, p);
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