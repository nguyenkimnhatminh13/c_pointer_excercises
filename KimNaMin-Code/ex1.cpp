#include <iostream>
using namespace std;

int Fibonacci(int i)
{
    if(i == 1 || i == 2){
        return 1;
    }
    return Fibonacci(i-1) + Fibonacci(i-2);

}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Day so Fibonacci den so thu n: ";
    for(int i = 1;i <= n;i++){
        cout << Fibonacci(i) <<"   ";
    }
    return 0;

}
