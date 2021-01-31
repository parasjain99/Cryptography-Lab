#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cout<<"Enter 26 letter permutation\n";  //key
    string permutation;
    cin>>permutation;
    map<char,char> mapping,rev_mapping;     // mapping of characters
    for(int i=0;i<permutation.length();i++){
        mapping['a'+i]=permutation[i];
        rev_mapping[permutation[i]]='a'+i;
    }
    cout<<"Key is set\n";
    while(1){
        string plain_text, cipher;
        cout << "To Encrypt text press 1\nTo Decrypt text press 2\nTo exit press 0\n";
        cin >> x;
        if(x==1){
            cout << "Enter plain text\n";
            cin >> plain_text;
            for (int i = 0; i < plain_text.length(); i++){
                cipher.push_back(mapping[plain_text[i]]);   // Generating cipher text by pushing mapped characters
            }
            cout << "Encrypted Message is\n"
                 << cipher << endl;
        }
        else if(x==2){
            cout << "Enter cipher text\n";
            cin >> cipher;
            for (int i = 0; i < cipher.length(); i++){
                plain_text.push_back(rev_mapping[cipher[i]]); // Generating plain text by pushing reverse mapped characters
            }
            cout << "Decrypted Message is\n"
                 << plain_text << endl;
        }
        else break;
    }
}