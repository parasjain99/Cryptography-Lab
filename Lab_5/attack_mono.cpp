#include <bits/stdc++.h>
using namespace std;

int main()
{
    string relFreq("etaoinshrdlucmwfygpbvkxjqz");
    string s;
    getline(cin,s);
    map<char, int> freq;
    map<char,char> mp;
    map<int,char> rev_freq;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' ') freq[s[i]]++;
    }
    for(auto p:freq){
        rev_freq[p.second] = p.first;
    }
    int i = 0;
    for(auto p:rev_freq){
        mp[p.second] = relFreq[i];
        i++;
    }
    for (int i = 0; i < s.length(); i++){
        if (s[i] == ' ') cout<<' ';
        else cout<<mp[s[i]];
    }

}