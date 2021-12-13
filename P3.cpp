//VCT nhập vào một xâu S từ bàn phím gồm các chữ cái HOA/thường, chữ số, và các ký tự khác. 
//Hãy lập xâu S1 nhận được từ xâu S bằng cách sắp xếp lại các ký tự theo thứ tự mã ASCII.

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100

//Ham nhap Chuoi
void NhapChuoi(char a[])
{
    int ch, n = 0;
    cout << "Nhap chuoi: ";
    for (n = 0; n <= MAX && (ch = getchar()) != '\n'; n++)
        a[n] = ch;
    a[n++] = '\0';  //Them phan tu ket thuc cho chuoi
}

//Ham tim vi tri cua ki tu lon nhat trong chuoi theo ma ASCII
int TimKiTuMax(char a[])
{
    int n = strlen(a);  //Lay do dai cua chuoi
    int max = 0;
    //Dung vong lap de xet tung phan tu
    for (int i = 0; i < n; i++)
        //Neu tim duoc a[i] > a[max] thi truyen i vao max
        if (a[i] > a[max])
            max = i;
    return max; //Tra ve gia tri max
}

//Ham xoa mot ki tu o mot vi tri k
void XoaKiTu(char a[], int k)
{
    int n = strlen(a);  //Lay do dai cua chuoi
    //Cho vong lap chay tu vi tri k
    for (int i = k; i < n; i++)
        a[i] = a[i + 1];    //Gan gia tri cua phan tu sau cho phan tu truoc
}

//Xau b nhan duoc tu xau a bang cach xep lai cac ki tu theo thu tu ma ASCII
void SapXepTangDan(char a[], char b[])
{
    int n = strlen(a);  //Lay do dai cua chuoi
    b[n] = '\0';    //Gan gia tri ket thuc cho chuoi
    for (int i = n - 1; i >= 0; i--)
    {
        //Lan luot truyen gia tri max trong xau a vao b[i]
        b[i] = a[TimKiTuMax(a)];
        XoaKiTu(a, TimKiTuMax(a));   //Xoa ki tu max vua tim trong xau a
    }
    cout << "Chuoi sau khi duoc sap xep lai la: ";
    cout << b << endl;
}

int main()
{
    char a[MAX], b[MAX];
    NhapChuoi(a);

    //Truyen vao xau b nhung ki tu cua xau a duoc sap xep theo thu tu tang dan theo ma ASCII
    SapXepTangDan(a, b);

    return 0;
}
