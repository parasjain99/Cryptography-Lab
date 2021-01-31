#include<bits/stdc++.h>
using namespace std;

string encrypt(string s, string key){
    string ans = "";
    int len = key.length();
    for(int i=0;i<s.length();i++){
        if (s[i] >= 'a' and s[i] <= 'z'){
            char ch = (((s[i] - 'a') ^ (key[i % len] - 'a')) % 26) + 'a';
            ans += ch;
        }
        else ans += s[i];
    }
    return ans;
}

string decrypt(string s, string key)
{
    string ans = "";
    int len = key.length();
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>='a' and s[i]<='z'){
            char ch = (((s[i] - 'a') ^ (key[i % len] - 'a')) % 26) + 'a';
            ans += ch;
        }
        else ans+=s[i];
        
    }
    return ans;
}

int main(){
    int x;
    cout<<"Enter key\n";  //key
    string key;
    cin>>key;
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    while(1){
        string plain_text, cipher;
        cout << "To Encrypt text press 1\nTo Decrypt text press 2\nTo exit press 0\n";
        cin >> x;
        if(x==1){
            cout << "Enter plain text\n";
            // cin >> plain_text;
            cin.ignore();
            getline(cin,plain_text);
            transform(plain_text.begin(), plain_text.end(), plain_text.begin(), ::tolower);
            cipher = encrypt(plain_text,key);
            cout << "Encrypted Message is\n"
                 << cipher << endl;
        }
        else if(x==2){
            cout << "Enter cipher text\n";
            // cin >> cipher;
            cin.ignore();
            getline(cin,cipher);
            transform(cipher.begin(), cipher.end(), cipher.begin(), ::tolower);
            plain_text = decrypt(cipher,key);
            cout << "Decrypted Message is\n"
                 << plain_text << endl;
        }
        else break;
    }
}