//VCT nhập vào một số nguyên, xuất số đó ở dạng chuỗi nhưng có dấu “,” ngăn cách hàng triệu, ngàn… 

#include <iostream>
#include <cmath>
using namespace std;
#define MAX 18

//Ham lay chuoi so tu mot so nguyen
void LayChuoi(int a[], int& n, long long x)
{
    n = 0;
    int dem = 0;
    while (x > 0)    //Vong lap tiep tuc cho den khi x = 0;
    {
        if (dem == 3)    //Neu dem = 3 thi them phan tu dau ',' vao mang
        {
            a[n++] = 44;    //So 44 la thu tu cua dau ',' trong ma ASCII
            dem = 0;    //Gan dem = 0
        }
        a[n++] = x % 10;  //Gan chu so hang don vi vao mang
        x /= 10;  //Cat bo chu so hang don vi vua gan
        dem++;  //Tang bien dem them 1 don vi
    }
}

//Ham xuat chuoi them dung dinh dang
void XuatChuoi(int a[], int n)
{
    cout << "Chuoi so sau khi duoc dinh dang lai la: ";
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 44) cout << (char)a[i];  //Neu a[i] = 44 thi xuat ra dau ','
        else cout << a[i];
    }
    cout << endl;
}

//Ham nhap vao so nguyen x
void NhapX(long long& x)
{
    do
    {
        cout << "Nhap so nguyen x (toi da 18 chu so): "; cin >> x;
    } while ((x/pow(10,18) > 1)); //Neu x nhap vao nhieu hon 18 chu so thi nhap lai!
}

int main()
{
    long long x;
    int a[MAX], n;
    NhapX(x);
    LayChuoi(a, n, x);  //Tach tung chu so cua x vao mang a
    XuatChuoi(a, n);    //Xuat chuoi so theo dung dinh dang
}
