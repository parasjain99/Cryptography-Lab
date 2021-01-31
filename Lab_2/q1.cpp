#include<bits/stdc++.h>
using namespace std;
int a = 15, b, m= 26,x;
int main(){
    cout<<"Enter value of b\n";
    cin>>b;
    b=b%m;
    int inver_a = 0;
    for(int i=0;i<m;i++){
        if((i*a)%26 == 1){
            inver_a = i;  // finding inverse of a by using formula (inv(a)*a)%m =1
            break;
        }
    }
    while(1){
        string plain_text, cipher;
        cout << "To Encrypt text press 1\nTo Decrypt text press 2\nTo exit press 0\n";
        cin >> x;
        if(x==1){
            cout << "Enter plain text\n";
            cin >> plain_text;
            for (int i = 0; i < plain_text.length(); i++){
                int temp = plain_text[i]-'a'; // converting to integral value
                temp = (temp*a + b) %m; //applying formula
                char ch = 'a' + temp; //converting to ascii value
                cipher.push_back(ch);
                  // Generating cipher text by pushing characters
            }
            cout << "Encrypted Message is\n"
                 << cipher << endl;
        }
        else if(x==2){
            cout << "Enter cipher text\n";
            cin >> cipher;
             for (int i = 0; i < cipher.length(); i++){
                int temp = cipher[i]-'a'; // converting to integral value
                temp = ((temp - b + m)*inver_a) %m; //applying formula
                char ch = 'a' + temp; //converting to ascii value
                plain_text.push_back(ch);
                  // Generating cipher text by pushing characters
            }
            cout << "Decrypted Message is\n"
                 << plain_text << endl;
        }
        else break;
    }
    
}