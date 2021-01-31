#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lint n,mod,inv=-1;
    cin>>n>>mod;
    for(int i=1;i<mod;i++){
        if((n*i)%mod==1){
            inv = i;
            break;
        }
    }
    cout<<inv<<endl;
}