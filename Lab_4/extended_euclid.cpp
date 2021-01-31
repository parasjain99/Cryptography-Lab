#include <iostream>
using namespace std;
//recursive

#include < iostream >

int d, x, y;
void extendedEuclid(int A, int B)
{
    if (B == 0)
    {
        d = A;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(B, A % B);
        int temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}


int main (){
    int a,b,q,temp,temp1,temp2,temp3;
    cout << "Please input a" << endl;
    cin >> a; 
    cout << "Please input b" << endl;
    cin >> b;
    if (b>a) {
        temp=a; 
        a=b; 
        b=temp;
    }
    int x1=1,y1=0,x2=0,y2=1;
    while (b!=0){
        q = a/b;
        temp1= a%b;
        a=b;
        b=temp1;
        temp2=x1-q*x2;
        x1=x2;
        x2=temp2;
        temp3=y1-q*y2;
        y1=y2;
        y2=temp3;
    }
    cout << "gcd = " << a << endl;
    cout << "x=" << x1 << endl;
    cout << "y=" << y1 << endl;
    return 0;
}