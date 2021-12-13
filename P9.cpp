//VCT nhập vào một mảng gồm n phần tử nguyên (1 ≤ n ≤ 10,000) và một số nguyên X:
//a)    Những phần tử nào (in ra cả giá trị và vị trí của phần tử đó) là ước số của X?
//b)    Dồn những phần tử là ước số của X về cuối mảng. Sắp xếp các phần tử không phải là ước số của X theo thứ tự tăng dần (giữ nguyên vị trí các phần tử là ước số của X).

#include <iostream>
using namespace std;
#define MAX 100

//Ham hoan doi gia tri cua hai so
void HoanDoi(int& a, int& b)
{
    double temp = a;   //Gan gia tri cua a vao bien phu temp
    a = b;  //Gan gia tri cua b vao a
    b = temp;   //Gan gia tri cua bien phu temp vao b
}

//Ham nhap mang
void NhapMang(int a[], int& n)
{
    do
    {
        cout << "Nhap so phan tu trong mang: "; cin >> n;
        //Neu n <= 0 hoac n > MAX thi so phan tu khong hop le
        if (n > MAX || n <= 0)
        {
            cout << "So phan tu khong hop le, hay nhap lai!" << endl;
            continue;
        }
        cout << "Nhap " << n << " phan tu: ";
        //Dung vong lap for de nhap gia tri cua tung phan tu trong mang
        for (int i = 0; i < n; i++)
            cin >> a[i];
    } while (n > MAX || n <= 0);  //Nhap cho den khi n hop le
}

//Ham xuat mang
void XuatMang(int a[], int n)
{
    //Dung vong lap for de xuat tung gia tri cua mang
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

//Ham kiem tra xem n co phai la uoc cua x khong
bool Uoc(int x, int n)
{
    if (n == 0) return true;    //Neu n = 0 thi tra ve true
    if (x % n == 0) return true; //Neu n chia het cho x thi tra ve true
    return false;
}

//Ham xuat cac uoc cua x va vi tri cua cac uoc do trong mang
void XuatUoc(int a[], int n, int x)
{
    cout << "Gia tri va vi tri cac uoc cua " << x << " la: " << endl;
    for (int i = 0; i < n; i++)
        if (Uoc(x, a[i])) //Neu a[i] la uoc cua x thi xuat ra a[i] va vi tri i + 1
            cout << "Gia tri: " << a[i] << " Vi tri: " << i + 1 << endl;
}

//Ham tim vi tri uoc lon nhat cua x trong mang
int TimUocMax(int a[], int n, int x)
{
    int max = -1;   //Neu khong tim duoc uoc thi tra ve -1
    //Tim vi tri cua uoc dau tien trong mang va gan vi tri do cho max
    for (int i = 0; i < n; i++)
        if (Uoc(x, a[i])) //Neu tim duoc uoc cua x thi tra ve vi tri cua uoc do
        {
            max = i;
            break;
        }
    //Tim vi tri uoc lon nhat cua x trong mang
    for (int i = 0; i < n; i++)
        if (Uoc(x, a[i]) && a[i] > a[max])
            max = i;
    return max;
}

//Ham chuyen cac uoc cua x xuong cuoi mang va sap xep cac uoc do theo thu tu tang dan
void UocCuoiMang(int a[], int n, int x)
{
    while (n--)  //Sau moi lan lap thi giam n di 1 don vi
        if (TimUocMax(a, n + 1, x) != -1)    //Neu tim duoc uoc trong mang a voi n phan tu
            HoanDoi(a[n], a[TimUocMax(a, n + 1, x)]);    //Hoan doi phan tu cuoi a[n] voi uoc lon nhat trong mang
    cout << "Mang sau khi cuyen cac uoc cua " << x << " xuong cuoi va sap xep theo thu tu tang dan la: ";
}

//Ham nhap so nguyen x can xet
void NhapX(int& x)
{
    cout << "Nhap vao so nguyen x can xet: "; cin >> x;
}

int main()
{
    int a[MAX], n, x;
    NhapMang(a, n);
    NhapX(x);

    //Xuat ra gia tri va vi tri cua nhung phan tu la uoc cua x
    XuatUoc(a, n, x);

    //Don nhung phan tu la uoc cua x ve cuoi mang va sap xep cac uoc do theo thu tu tang dan
    UocCuoiMang(a, n, x);
    XuatMang(a, n);
    return 0;
}
