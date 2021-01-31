#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int inc_val = 3; //Can take any value from 0-25
    cout<<"Enter Text:\n";
    getline(cin,s);   // Taking input
    string ans;    //output string
    for(int i=0;i<s.length();i++){
        if(s[i]==' ') ans.push_back(' ');  //Adding space as it is
        else if(isupper(s[i])){
            ans.push_back(char((s[i]-'A' + 1 + inc_val)%26 + 'A' - 1)); //Incrementing each uppercase character by 3(Increment value)
        }
        else{
            ans.push_back(char((s[i]-'a' + 1 + inc_val)%26 + 'a' - 1)); //Incrementing Each uppercase character by 3(Increment value)
        }
    }
    cout<<"Cipher Test is\n";
    cout<<ans<<endl;
    cout<<"Enter the cipher text\n";
    string ans1;
    getline(cin,s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            ans1.push_back(' '); //Adding space as it is
        else if (isupper(s[i]))
        {
            ans1.push_back(char((s[i] - 'A' + 1 - inc_val +26) % 26 + 'A' )); //Incrementing each uppercase character by 3(Increment value)
        }
        else
        {
            ans1.push_back(char((s[i] - 'a' + 1 - inc_val +26) % 26 + 'a')); //Incrementing Each uppercase character by 3(Increment value)
        }
    }
    cout << "Original Test is\n";
    cout << ans1 << endl;
}