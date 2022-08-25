#include <iostream>
#include <fstream>
using namespace std;

struct SinhVien
{
    string hoTen;
    string gioiTinh;
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTrungBinh;
};
void Swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int indexSpaceFormFront(string a)
{
    int x = 0;
    while(a[x] != ' '){
        x++;
    }
    return x;
}

int indexSpaceFormTail(string a)
{
    int x = a.length();
    while(a[x] != ' '){
        x--;
    }
    return x;
}

void NhapThongTin(SinhVien danhsach[],int n)
{
    for(int i = 0;i < n;i++){
        cout << "Nhap ten sinh vien: ";
        cin >> danhsach[i].hoTen;
        cout << "Nhap gioi tinh (Nam/Nu): ";
        cin >> danhsach[i].gioiTinh;
        cout << "Nhap tuoi: ";
        cin >> danhsach[i].tuoi;
        cout << "Nhap diem Toan (0~10): ";
        cin >> danhsach[i].diemToan;
        cout << "Nhap diem Ly (0~10): ";
        cin >> danhsach[i].diemLy;
        cout << "Nhap diem Hoa (0~10): ";
        cin >> danhsach[i].diemHoa;
        danhsach[i].diemTrungBinh = (danhsach[i].diemToan+danhsach[i].diemLy+danhsach[i].diemHoa)/3;
        cout << "diem trung binh: " << danhsach[i].diemTrungBinh;
        cout << "\n-----\n";
    }
}

void Show(SinhVien danhsach[],int n)
{
    cout << "\n-----\n";
    cout << "Danh Sach" <<endl;
    cout << "---------------------------"<<endl;
    for(int i = 0;i < n;i++){
        cout << "Ho ten: " << danhsach[i].hoTen << endl;
        cout << "Gioi tinh: " << danhsach[i].gioiTinh <<endl;
        cout << "Tuoi: " << danhsach[i].tuoi <<endl;
        cout << "Diem Toan: " << danhsach[i].diemToan <<endl;
        cout << "Diem Ly: " << danhsach[i].diemLy <<endl;
        cout << "Diem Hoa: " << danhsach[i].diemHoa <<endl;
        cout << "Diem Trung Binh: " << danhsach[i].diemTrungBinh<<endl;
        cout << "---------------------------"<<endl;
    }
}

void writeToFile(SinhVien danhsach[],int n)
{
    ofstream myfile;
    myfile.open ("ex3_danhsach.txt");
    for(int i = 0;i < n;i++){
        myfile << "Ho ten: " << danhsach[i].hoTen << endl;
        myfile << "Gioi tinh: " << danhsach[i].gioiTinh <<endl;
        myfile << "Tuoi: " << danhsach[i].tuoi <<endl;
        myfile << "Diem Toan: " << danhsach[i].diemToan <<endl;
        myfile << "Diem Ly: " << danhsach[i].diemLy <<endl;
        myfile << "Diem Hoa: " << danhsach[i].diemHoa <<endl;
        myfile << "Diem Trung Binh: " <<danhsach[i].diemTrungBinh<<endl;
        myfile << "---------------------------"<<endl;
    }
    cout << "File is save" << endl;
    myfile.close();
}
void diemTrungBinh(SinhVien danhsach[],int n)
{
    float tb = 0;
    for(int i = 0;i < n;i++){
        tb = tb + danhsach[i].diemTrungBinh;
    }
    cout <<"Diem trung binh cac Sinh Vien: " << tb/n <<endl;
}

void Sort(SinhVien danhsach[],int n,string flag)
{
    int k; SinhVien b;
    if(flag == "diemtb"){
        for(int i=0;i < n-1;i++){
            k = i;
            b = danhsach[i+1];
            while(k>=0 && b.diemTrungBinh < danhsach[k].diemTrungBinh){
                danhsach[k+1] = danhsach[k];
                k--;
            }
            danhsach[k+1] = b;
        }
    }
    else if(flag == "tuoi"){
        for(int i=0;i < n-1;i++){
            k = i;
            b = danhsach[i+1];
            while(k>=0 && b.tuoi < danhsach[k].tuoi){
                danhsach[k+1] = danhsach[k];
                k--;
            }
            danhsach[k+1] = b;
        }
    }
    else if(flag == "ho"){
        for(int i=0;i < n-1;i++){
            k = i;
            b = danhsach[i+1];
            while(k>=0 && b.hoTen.substr(0,indexSpaceFormFront(b.hoTen)) < danhsach[k].hoTen.substr(0,indexSpaceFormFront(danhsach[k].hoTen))){
                danhsach[k+1] = danhsach[k];
                k--;
            }
            danhsach[k+1] = b;
        }
    }
    else if(flag == "ten"){
        for(int i=0;i < n-1;i++){
            k = i;
            b = danhsach[i+1];
            while(k>=0 && b.hoTen.substr(indexSpaceFormTail(b.hoTen),b.hoTen.length()) < danhsach[k].hoTen.substr(indexSpaceFormTail(danhsach[k].hoTen),b.hoTen.length())){
                danhsach[k+1] = danhsach[k];
                k--;
            }
            danhsach[k+1] = b;
        }
    }
    else
        cout << "flag wrong!" <<endl;
}

int main()
{
    int N;
    cout << "Nhap so luong Sinh Vien N: ";
    cin >> N;
    SinhVien danhsach[N];

    //danh sach mau
    danhsach[0].hoTen = "Nguyen Kim Nhat Minh";
    danhsach[0].gioiTinh = "Nam";
    danhsach[0].tuoi = 18;
    danhsach[0].diemToan = 9;
    danhsach[0].diemLy = 10;
    danhsach[0].diemHoa = 9;
    danhsach[0].diemTrungBinh = (danhsach[0].diemToan+danhsach[0].diemLy+danhsach[0].diemHoa)/3;

    danhsach[1].hoTen = "Hoa Thanh Dat";
    danhsach[1].gioiTinh = "Nam";
    danhsach[1].tuoi = 20;
    danhsach[1].diemToan = 10;
    danhsach[1].diemLy = 9.5;
    danhsach[1].diemHoa = 9;
    danhsach[1].diemTrungBinh = (danhsach[1].diemToan+danhsach[1].diemLy+danhsach[1].diemHoa)/3;


    danhsach[2].hoTen = "Tu Lam Phuong";
    danhsach[2].gioiTinh = "Nu";
    danhsach[2].tuoi = 19;
    danhsach[2].diemToan = 9.5;
    danhsach[2].diemLy = 8;
    danhsach[2].diemHoa = 8.5;
    danhsach[2].diemTrungBinh = (danhsach[2].diemToan+danhsach[2].diemLy+danhsach[2].diemHoa)/3;

    danhsach[3].hoTen = "Nguyen Thai An";
    danhsach[3].gioiTinh = "Nu";
    danhsach[3].tuoi = 17;
    danhsach[3].diemToan = 9;
    danhsach[3].diemLy = 8.5;
    danhsach[3].diemHoa = 6;
    danhsach[3].diemTrungBinh = (danhsach[3].diemToan+danhsach[3].diemLy+danhsach[3].diemHoa)/3;

    //NhapThongTin(danhsach,N);
    Show(danhsach,N);
    diemTrungBinh(danhsach,N);
    Sort(danhsach,N,"ten");
    Show(danhsach,N);
    writeToFile(danhsach,N);
}
