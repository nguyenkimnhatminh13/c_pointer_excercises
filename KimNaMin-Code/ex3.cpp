#include <iostream>
using namespace std;

struct SinhVien
{
    string hoTen;
    string gioiTinh;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTrungBinh;
};
typedef struct Node
{
    SinhVien data;
    struct Node *next;
};

typedef struct Node * LinkedList; //con tro LinkedList kieu Node
typedef struct Node * PNode; // con tro PNode kieu Node

void Init(LinkedList &h)
{
    h = NULL;
}
bool IsEmpty(LinkedList H)
{
	return (H == NULL);
}

void CreateNode(SinhVien &K)
{
    //PNode Q = new Node;
    cout << "Nhap ten sinh vien: ";
    cin >> K.hoTen;
    cout << "Nhap gioi tinh (Nam/Nu): ";
    cin >> K.gioiTinh;
    cout << "Nhap diem Toan (0~10): ";
    cin >> K.diemToan;
    cout << "Nhap diem Ly (0~10): ";
    cin >> K.diemLy;
    cout << "Nhap diem Hoa (0~10): ";
    cin >> K.diemHoa;
    K.diemTrungBinh = (K.diemToan+K.diemLy+K.diemHoa)/3;
    cout << "diem trung binh: " << K.diemTrungBinh;
    cout << "\n-----\n";
    //Q->data = K;
    //Q->next = NULL;
    //return Q;
}

PNode InsertAfter(LinkedList &h, PNode p,SinhVien k)
{
    PNode Q = new Node;
    Q->data = k;
    if(h == NULL){
        h = Q;
        Q->next = NULL;
    }
    else{
        if(p==NULL) return NULL;
        Q->next = p->next;
        p->next = Q;
    }
    return Q;
}


void Show(LinkedList H)
{
    cout << "Danh Sach" <<endl;
    if(IsEmpty(H))
        printf("Danh sach rong");
    else{
        PNode P;
        P = H;
        while(P != NULL){
            cout << P->data.hoTen << "|| " <<P->data.gioiTinh <<"|| " <<P->data.diemToan<<
            "|| "<<P->data.diemLy << "|| "<<P->data.diemHoa <<"|| "<<P->data.diemTrungBinh<<endl;
            P = P->next;
        }
    }
    cout << "\n-----\n";
}

void writeToFile(FILE *file,LinkedList H)
{
    if(IsEmpty(H))
        printf("Danh sach rong");
    else{
        PNode P;
        P = H;
        while(P != NULL){
            fprintf(file, "%s || %s || %f || %f || %f || %f \n",P->data.hoTen,P->data.gioiTinh,
                    P->data.diemToan,P->data.diemLy,P->data.diemHoa,P->data.diemTrungBinh);
            P = P->next;
        }
    }
    cout << "\n-------------\n";
}

int main()
{
    LinkedList H;
    Init(H);
    SinhVien K1,K2,K3,K4;
    PNode P;

    K1.hoTen = "Nguyen Kim Nhat Minh";
    K1.gioiTinh = "nam";
    K1.diemToan = 9;
    K1.diemLy = 10;
    K1.diemHoa = 9;
    K1.diemTrungBinh = (K1.diemToan+K1.diemLy+K1.diemHoa)/3;

    K2.hoTen = "Hoa Thanh Dat";
    K2.gioiTinh = "nam";
    K2.diemToan = 10;
    K2.diemLy = 9.5;
    K2.diemHoa = 9;
    K2.diemTrungBinh = (K2.diemToan+K2.diemLy+K2.diemHoa)/3;


    K3.hoTen = "Lam Phuong";
    K3.gioiTinh = "nu";
    K3.diemToan = 9.5;
    K3.diemLy = 8;
    K3.diemHoa = 8.5;
    K3.diemTrungBinh = (K3.diemToan+K3.diemLy+K3.diemHoa)/3;

    P = InsertAfter(H,P,K1);
    P = InsertAfter(H,P,K2);
    P = InsertAfter(H,P,K3);

    CreateNode(K4);
    P = InsertAfter(H,P,K4);
    Show(H);

    const char *filePath = "C:/Users/Kim Na Min/Desktop/my_document.txt";
    FILE *file;

    file = fopen(filePath, "w");
    if (!file)
        cout << "Can not open this file" << endl;
    else
        cout << "File is save" << endl;

    writeToFile(file,H);

    fclose(file);
    return 0;
}
