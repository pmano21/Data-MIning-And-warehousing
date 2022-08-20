#include<bits/stdc++.h>
using namespace std;

ofstream fout("out53.txt");
ifstream fin("in53.txt");

vector<float> normalize(vector<float> nums)
{
    int n = nums.size();
    float sum = 0; 
    for(int i=0;i<n;i++) sum += nums[i];
    float avg = sum / n;
    float temp = 0; 

    for(int i=0;i<n;i++)
        temp += (nums[i] - avg) / n;
 
    for(int i=0;i<nums.size();i++)
        nums[i] = ( nums[i] - avg ) / temp;
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