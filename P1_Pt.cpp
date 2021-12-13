//VCT nhập một chuỗi (mảng ký tự có n phần tử), xây dựng các hàm thực hiện:
//a) Viết hàm kiểm tra một chuỗi có đối xứng hay không? Ví dụ: các chuỗi level,
//radar, dad… là các chuỗi đối xứng.
//b) Viết hàm tìm chuỗi đảo ngược của một chuỗi. Ví dụ: chuỗi “Lap trinh C” có
//chuỗi đảo ngược là “C hnirt paL”

#include <iostream>
using namespace std;
#define MAX 81

//Ham kiem tra xem chuoi co doi xung hay khong
bool ChuoiDoiXung(char a[], int n)
{
    //Ta chi kiem tra so doi xung voi i chay tu 0 den n/2
    for(int i = 0; i <= n/2; i++)
        //Neu ton tai a[i] khac a[n-1-i] thi day khong phai la Chuoi doi xung
        if(a[i] != a[n-1-i]) return false;
    return true;    //Nguoc lai, tra ve true
}

//Ham tim chuoi dao nguoc
void DaoNguocChuoi(char a[], int n, char c[])
{
    //Lan luot gan ky tu cuoi cua chuoi a vao ky tu dau cua chuoi c
    for(int i = 0; i < n; i++)
    {
        c[i] = a[n - 1 - i];
    }
}

//Ham nhap Chuoi
void NhapChuoi(char a[], int& n)
{
    int ch;
    cout << "Nhap chuoi: ";
    for(n = 0; n <= 81 && (ch = getchar()) != '\n'; n++)
    {
        a[n] = ch;
    }
}

//Ham xuat Chuoi
void XuatChuoi(char a[], int n)
{
    //Dung vong lap for de xuat tung gia tri cua Chuoi
    for(int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    char a[MAX];
    int n;
    NhapChuoi(a,n);
    char c[n];

    //Kiem tra chuoi vua nhap co phai la chuoi doi xung khong
    if(ChuoiDoiXung(a,n))
        cout << "Day la chuoi doi xung!" << endl;
    else    
        cout << "Day khong phai la chuoi doi xung!" << endl;

    //Tim chuoi dao nguoc cua chuoi vua nhap
    cout << "Chuoi dao nguoc la: ";
    DaoNguocChuoi(a,n,c);
    XuatChuoi(c,n);
}
