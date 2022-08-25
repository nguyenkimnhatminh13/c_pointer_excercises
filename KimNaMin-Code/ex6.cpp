#include <iostream>
using namespace std;

int Max(int a,int b)
{
    if(a >= b){
        return a;
    }
    return b;
    //(a >= b) ? return a : return b;
}
int tinhTong(int A[],int n)
{
    int tong = A[0];
    for(int i = 1;i < n;i++){
        tong = tong + A[i] + Max(0,A[i]-A[i-1]);
    }
    return tong;
}
void Swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int n;
    cout << "Nhap N: ";
    cin >> n;
    int A[n];
    for(int i = 0;i < n;i++){
        cout << "Nhap A[" << i <<"]: ";
        cin >> A[i];
    }
    int maxTong = tinhTong(A,n);
    for(int i = 0;i < n;i++){
        cout << A[i] <<"   ";
    }
    cout << endl;
    cout << "Default Tong: " <<maxTong<<endl;

    for(int i = 0;i < n-1;i++){
        int temp = A[0];
        for(int i = 0;i < n-1;i++){
            Swap(A[i+1], temp);
        }
        A[0] = temp;

        int tongTemp = tinhTong(A,n);
        if(maxTong <= tongTemp){
            maxTong = tongTemp;
            for(int i = 0;i < n;i++){
                cout << A[i] <<"   ";
            }
            cout <<": Tong = " << maxTong << endl;
        }
    }
    //cout << "Max "<< maxTong;
}
