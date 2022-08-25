#include <iostream>
using namespace std;

void Sort(int A[],int N)
{
    int k,b;
    for(int i=0;i < N-1;i++){
        k = i;
        b = A[i+1];
        while(k>=0 && b<A[k]){
            A[k+1] = A[k];
            k--;
        }
        A[k+1] = b;
    }
}

int main()
{
    int m,n;
    cout << "nhap m (So ptu mang 1): ";
    cin >> m;
    cout << "nhap n (So ptu mang 2): ";
    cin >> n;

    int mang1[m],mang2[n],mangTong[m+m];
    for(int i = 0;i < m;i++){
        cout << "Nhap gia tri mang1["<<i<<"]: ";
        cin >> mang1[i];
        mangTong[i] = mang1[i];
    }
    for(int i = 0;i < n;i++){
        cout << "Nhap gia tri mang2["<<i<<"]: ";
        cin >> mang2[i];
        mangTong[m+i] = mang2[i];
    }

    Sort(mangTong,m+n);
    cout << "\n";
    for(int i = 0;i < m+n;i++){
        cout << mangTong[i] << "   ";
    }
}
