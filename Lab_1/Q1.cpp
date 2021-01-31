#include<bits/stdc++.h>
using namespace std;


int main(){
    string s,out, out1;
    cout<<"Enter String\n";
    getline(cin,s); // Input
    for(int i=0;i<s.length();i++){  // Iterating every character
        out.push_back((char)(s[i] ^ 0)); //Taking xor with 0 number and pushing into the output string
        out1.push_back((char)(s[i] ^ '0')); //with '0' character and pushing in output string
    }
    cout<<"XOR with 0 number:\n"<<out<<endl<<"\nXOR with '0' character:\n"<<out1;
    
}