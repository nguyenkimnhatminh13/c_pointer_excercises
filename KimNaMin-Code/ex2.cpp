#include <iostream>
#include<cmath>
#include <stack>
using namespace std;

void inBit(stack<int> &s, int n)
{
    while(n > 0){
        s.push(n%2);
        n=n/2;
    }
}

int thapPhan(stack<int> &s)
{
    int tong = 0;
    while(!s.empty()){
        tong = tong + s.top()*pow(2,(s.size()-1));
        s.pop();
    }
    return tong;
}

int main()
{
    stack<int> st;

    int n,dem = 0;
    cout << "Nhap n: ";
    cin >> n;
    inBit(st,n);
    stack<int> st1 = st;
    while(!st.empty()){
        cout << st.top();
        if(st.top() == 1){
            dem++;
        }
        st.pop();
    }
    cout << "\n1) so bit '1': "<< dem;
    cout <<"\n--------------------";
    int b = n & 0b0111;
    cout << "\n2) Bit t4 la 0,In ket qua: "<< b;
    cout <<"\n--------------------";
    int c = n | 0b10000;
    cout << "\n3) Bit t5 la 1,In ket qua: "<< c;
    cout <<"\n--------------------";
    int d = n ^ 0b100;
    cout << "\n4) Dao bit t3, In ket qua: "<< d;
}
