#include<bits/stdc++.h>
using namespace std;
map<int,int> key;
string en;

void key_gen(int m){
	cout<<"Enter the key: ";
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		key[x]=i;
	}
}

void encrypt(string s,int n,int m){
	int l =s.length();
	vector<vector<char> > v(n,vector<char>(m,'0'));
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(k<l){
				v[i][j]=s[k];
				k++;
			}
			else v[i][j]='z';
		}
	}
	cout<<"Encrypted: ";
	for(int i=0;i<key.size();i++){
		for(int j=0;j<n;j++){
			cout<<v[j][key[i]];
			en.push_back(v[j][key[i]]);
		}
	}
	cout<<endl;
}

// decryption function
void decrypt(string s,int n,int m){
	vector<vector<char> > v(n,vector<char>(m,'0'));
	int k=0;
	for(int i=0;i<key.size();i++){
		for(int j=0;j<n;j++){
			v[j][key[i]]=s[k];
			k++;
		}
	}
	cout<<"Decrypted: ";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<v[i][j];
		}
	}
	cout<<endl;
}

int main(){
	int t;
	cout<<"Enter no. of test cases: ";
	cin>>t;
	while(t--){
		en.clear();
		key.clear();
		cout<<endl;
		string s;
		cout<<"Enter message: ";
		cin>>s;
		int l =s.length();
		int n,m;
		cout<<"Enter the no. of rows and no. of columns: ";
		cin>>n>>m;
		if(m*n<s.length())
			cout<<"Matrix cannot hold the whole string.";
		else{
			key_gen(m);
			encrypt(s,n,m);
			decrypt(en,n,m);
		}
	}
}
