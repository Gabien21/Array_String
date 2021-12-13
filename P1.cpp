//VCT nhập vào một chuỗi, xây dựng các hàm thực hiện:
//a)Chuyển đổi chuỗi sang dạng chữ thường.
//b)Chuyển đổi chuỗi sang dạng chữ hoa.
//c)Chuyển đổi chuỗi sang dạng Title Case (ký tự đầu của mỗi từ là chữ hoa, các ký tự còn lại là chữ thường).

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
    {
        a[n] = ch;
    }
    a[n++] = '\0';  //Them phan tu ket thuc cho chuoi
}

//Ham chuyen chuoi sang dang chu thuong
void ChuyenSangThuong(char a[])
{
    int n = strlen(a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')  //Neu a[i] la chu in thi chuyen sang chu thuong
            a[i] += 32;             //bang cach cong them 32 vao a[i]
    }
    cout << "Chuoi sau khi duoc chuyen sang dang chu thuong la: ";
    cout << a << endl;
}

//Ham chuyen chuoi sang dang chu hoa
void ChuyenSangHoa(char a[])
{
    int n = strlen(a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')  //Neu a[i] la chu thuong thi chuyen sang chu in
            a[i] -= 32;                //bang cach tru 32 vao a[i]
    }
    cout << "Chuoi sau khi duoc chuyen sang dang chu hoa la: ";
    cout << a << endl;
}

//Ham chuyen chuoi sang dang chu Title case
void ChuyenSangTitleCase(char a[])
{
    int n = strlen(a);
    if (a[0] != ' ') //neu ki tu dau tien la chu thuong thi viet hoa ki tu do
        if (a[0] >= 'a' && a[0] <= 'z') a[0] -= 32;
    for (int i = 1; i < n; i++)
    {
        //Viet hoa chu cai dau
        if (a[i] != ' ' && a[i - 1] == ' ' && a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 32;
        //Viet thuong cac chu cai con lai
        else if (a[i] != ' ' && a[i - 1] != ' ' && a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;
    }
    cout << "Chuoi sau khi chuyen sang dang chu title case la: ";
    cout << a << endl;
}

int main()
{
    char a[MAX];
    NhapChuoi(a);
    //Chuyen chuoi sang dang chu thuong
    ChuyenSangThuong(a);

    //Chuyen chuoi sang dang chu hoa
    ChuyenSangHoa(a);

    //Chuyen chuoi sang dang chu Title case
    ChuyenSangTitleCase(a);

    return 0;
}
