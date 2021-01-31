#include<bits/stdc++.h>
using namespace std;

vector<string> encrypt(string s,int n){
	cout<<endl;
	vector<string> v(n);
	cout<<"Encrypted: ";
	for(int i=0;i<s.length();i++){
		v[i%n].push_back(s[i]);
	}
	for(int i=0;i<n;i++) cout<<v[i];
	cout<<endl;
	return v;
}

void decrypt(vector<string> a,int n,int l){
	vector<int> b(n,0);
	cout<<"Decrypted: ";
	for(int i=0;i<l;i++){
		cout<<a[i%n][b[i%n]];
		b[i%n]++;
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<endl;
		cout<<"Enter the message: ";
		string s;
		cin>>s;
		int l = s.length();
		cout<<"Enter the no. of levels: ";
		int n;
		cin>>n;
		vector<string> a;
		a = encrypt(s,n);
		decrypt(a,n,l);
	}
}
