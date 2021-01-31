#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cout<<"Enter the key\n";  //key
    string key,new_key="";
    // cin>>permutation;
    getline(cin,key);
    map<char,int> mp;
    for(int i=0;i<key.length();i++){
        if(key[i]==' ') continue;
        if(mp.find(key[i])!=mp.end()) new_key+=key[i];
        mp[key[i]]++;
    }
    for(char ch='a';ch<='z';ch++){
        if (mp.find(ch) != mp.end()) new_key += ch;
        mp[ch]++;
    }
    map<char, char> mapping, rev_mapping; // mapping of characters
    for (int i = 0; i < new_key.length(); i++)
    {
        mapping['a' + i] = new_key[i];
        rev_mapping[new_key[i]] = 'a' + i;
    }
    mapping[' '] = ' ';
    rev_mapping[' '] = ' ';
    cout<<"Key is set\n";
    while(1){
        string plain_text, cipher;
        cout << "To Encrypt text press 1\nTo Decrypt text press 2\nTo exit press 0\n";
        cin >> x;
        if(x==1){
            cout << "Enter plain text\n";
            // cin >> plain_text;
            cin.ignore();
            getline(cin,plain_text);
            for (int i = 0; i < plain_text.length(); i++){
                cipher.push_back(mapping[plain_text[i]]);   // Generating cipher text by pushing mapped characters
            }
            cout << "Encrypted Message is\n"
                 << cipher << endl;
        }
        else if(x==2){
            cout << "Enter cipher text\n";
            // cin >> cipher;
            cin.ignore();
            getline(cin,cipher);
            for (int i = 0; i < cipher.length(); i++){
                plain_text.push_back(rev_mapping[cipher[i]]); // Generating plain text by pushing reverse mapped characters
            }
            cout << "Decrypted Message is\n"
                 << plain_text << endl;
        }
        else break;
    }
}
//the snow lay thick on the steps and the snowflakes driven by the wind looked black in the headlights of the cars