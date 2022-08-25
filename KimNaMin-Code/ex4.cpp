#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{

    string filename("example_ex4.txt");
    // Khai báo vector để lưu các dòng đọc được
    vector<string> lines;
    vector<char> k;
    string line;

    //Mở file bằng ifstream
    ifstream input_file(filename);
    //Kiểm tra file đã mở thành công chưa
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    //Đọc từng dòng trong
    while (getline(input_file, line)){
        lines.push_back(line);//Lưu từng dòng như một phần tử vào vector lines.
    }
    int oNho = 0x00000;
    int dem = 0;
    char a = 0x0d; char b = 0x0a;
    //cout << "0: ";
    for (const auto &i : lines){
        for(int x = 0;x < i.length();x++){
            k.push_back(i[x]);
            //printf("%x",i[x]);
        }
        k.push_back(a);
        k.push_back(b);
        //printf("%x",a);
        //printf("%x",b);
    }

    printf("%x: ",oNho);
    for (const auto &i : k){
        if(dem < 16){
            printf("%x ",i);
            dem++;
            oNho++;
        }
        else{
            cout << endl;
            printf("%x: ",oNho);
            printf("%x ",i);
            dem = 1;
            oNho++;
        }
    }

    //Đóng file
    input_file.close();
    return 0;
}
