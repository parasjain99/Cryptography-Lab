#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

bool miller_robin(int n){
    if (n < 4 and n > 1)
        return true;
    if (n % 2 == 0)
        return false;
    lint k = 0, q = n - 1, a = 2, temp;
    while (q % 2 == 0){
        q /= 2;
        k++;
    }
    temp = pow(a, q);
    if (temp % n == 1 or temp % n == n - 1)
        true;
    for (int j = 0; j < k; j++)
    {
        if ((lint)pow(temp, pow(2, j)) % n == n - 1)
            return true;
    }
    return false;
}

int main(){
    cout << "enter a number\n";
    int n;
    cin >> n;
    if (miller_robin(n))
        cout << "Inconcluseive\n";
    else
        cout << "composite\n";
}