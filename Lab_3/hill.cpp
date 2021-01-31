#include<bits/stdc++.h>
using namespace std;
//function to find determinant
int deter(vector<vector<int>> & mat, int n){
    // case for order 1
        if (n == 1)
        {
            return mat[0][0];
        }
        //case for order 2 (ad-bc)
        else if (n == 2)
        {
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        }
        else{
        int ans = 0; //final determinant value initialized with 0
        for(int i=0;i<n;i++){

            vector<vector<int>> temp; //matrix excluding first row and ith column
            for(int j=1;j<n;j++){ //starting with 1 to exclude 1st row
                vector<int> v;
                for(int k=0;k<n;k++){
                    if(k!=i) v.push_back(mat[j][k]);
                }
                temp.push_back(v);
            }
            ans+=pow(-1,i) * mat[0][i] * (deter(temp, n-1));
        }
        return ans;
    }
} 
//function to get transpose
vector<vector<int>> trans(vector<vector<int>> &A, int N)
{
    vector<vector<int>> B(N, vector<int>(N));
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            B[i][j] = A[j][i];
    return B;
}
//function to calculate adjoint
vector<vector<int> > adj(vector<vector<int> > &mat, int n){
    vector<vector<int> > ans; //final adjoint matrix
    for(int i=0;i<n;i++){
        vector<int> v; // one row of adjoint matrix
        for(int j=0;j<n;j++){
            int minor=pow(-1,(i+j)); //calculating minor value 
            vector<vector<int> > temp; //matrix excluding ith row and jth column
            for(int k=0;k<n;k++){
                if(k==i) continue; // to exclude ith row
                vector<int> line;
                for(int l=0;l<n;l++){
                    if(l==j) continue; // to exclude jth column
                    line.push_back(mat[k][l]);
                }
                temp.push_back(line);
            }
            minor*=deter(temp, n-1); //determinant value multiplied to get the minor value
            v.push_back(minor);
        }
        ans.push_back(v);
    }
    //taking transpose
    ans = trans(ans,n);
    return ans;
}
//function to multiply matrix with a vector.
vector<int> mult(vector<vector<int> > mat, vector<int> v){
    vector<int> ans;
    int n = v.size();
    //Selecting row
    for(int i=0;i<n;i++){
        int x=0;
        //selecting column
        for(int j=0;j<n;j++){
            x+=v[j]*mat[i][j];
        }
        //It should not exceeed 26
        ans.push_back(x%26);
    }
    return ans;
}
string encrypt(string s, string key){
    //n is the order of matrix
    int n = sqrt(key.length());
    int pos = 0; // to point at the position in the key.
    //creation of the matrix (2d vector)
    vector<vector<int> > mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // Char 'a' is subtracted to place integer values in the key matrix.
            mat[i][j] = key[pos] - 'a'; 
            pos++;
        }
    }
    string msg=""; //string to contain encrypted msg
    for(int i=0;i<s.length();i+=n){
        vector<int> v;
        // It is creating vectors of n length from the plain text.
        for(int j=0;j<n;j++){
            v.push_back(s[i+j]-'a');
        }
        // N length vectors are multiplied by the key matrix
        v = mult(mat,v);
        //creating the cypher text from numaric values.
        for(int i=0;i<v.size();i++){
            msg.push_back(v[i]+'a');
        }
    }
    return msg;
}

string decrypt(string s, string key){
    //n is the order of matrix
    int n = sqrt(key.length());
    int pos = 0; // to point at the position in the key.
    //creation of the matrix (2d vector)
    vector<vector<int>> mat(n, vector<int>(n));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Char 'a' is subtracted to place integer values in the key matrix.
            mat[i][j] = key[pos] - 'a';
            pos++;
        }
    }
    // calculating determinant of key matrix
    int inv_det = deter(mat, n);
    // calculating inverse of the determinant value.
    for(int i=0;i<26;i++){
        if((inv_det*i)%26==1){ // det*det^-1 = 1
            inv_det = i;
            break;
        }
    }
    //calculating adjoint of the key matrix
    mat = adj(mat, n);
    //finding inverse of the key matrix by using k^-1 = |k|^-1 * adj(k) % 26
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            while(mat[i][j]<0) mat[i][j]+=26; // if value is negative
            mat[i][j] = mat[i][j]%26;
            mat[i][j]= (mat[i][j]*inv_det)%26;
        }
    }
    string msg = ""; //this will contain decrypted msg
    for (int i = 0; i < s.length(); i += n){
        vector<int> v; // It is creating vectors of n length from the cipher text.
        for (int j = 0; j < n; j++){
            v.push_back(s[i + j] - 'a');
        }
        // N length vectors are multiplied by the inverse key matrix
        v = mult(mat, v);
        for (int i = 0; i < v.size(); i++)
        {
            //creating the text from numaric values.
            msg.push_back(v[i] + 'a');
            // cout<<msg[i];
        }
    }
    return msg;
}
int main(){
    int x;
    cout << "Enter key\n"; //key
    string key;
    cin >> key;
    // order of the matrix
    int n = sqrt(key.length());
    //repeatedly asking for encryption or decryption until exit
    while (1)
    {
        string plain_text, cipher;
        cout << "To Encrypt text press 1\nTo Decrypt text press 2\nTo exit press 0\n";
        cin >> x;
        //condition for encryption
        if (x == 1)
        {
            cout << "Enter plain text\n";
            cin >> plain_text;
            //adding 'z' at the end of the string so that it's length becomes multiple of 'n' 
            while(plain_text.length() % n!=0) plain_text.push_back('z');
            //encryption function is called.
            cipher = encrypt(plain_text, key);
            cout << "Encrypted Message is\n"
                 << cipher << endl;
        }
        //condition for decryption
        else if (x == 2)
        {
            cout << "Enter cipher text\n";
            cin >> cipher;
            //decryption function called.
            plain_text = decrypt(cipher, key);
            cout << "Decrypted Message is\n"
                 << plain_text << endl;
        }
        else break;
    }
}