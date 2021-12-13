//VCT nhập 2 mảng số a và b có n phần tử, xây dựng các hàm thực hiện:
//a)    Kiểm tra 2 mảng có thứ tự tăng không, nếu không thì sắp tăng cho 2 mảng.
//b)    Trộn hai mảng a và b thành một mảng c có thứ tự tăng dần.
//c)     Xóa tất cả các phần tử trùng nhau của 2 mảng.

#include <iostream>
using namespace std;
#define MAX 1000

//Ham kiem tra mang co thu tu tang dan hay khong
bool TangDan(double a[], int n)
{
    //Vi xet 2 phan tu ke tiep nen i < n - 1
    for (int i = 0; i < n - 1; i++)
        //Neu ton tai a[i] >= a[i+1] thi tra ve false
        if (a[i] >= a[i + 1]) return false;
    return true;    //Nguoc lai, tra ve true
}

//Ham hoan doi gia tri cua hai so
void HoanDoi(double& a, double& b)
{
    double temp = a;   //Gan gia tri cua a vao bien phu temp
    a = b;  //Gan gia tri cua b vao a
    b = temp;   //Gan gia tri cua bien phu temp vao b
}

//Ham sap xep cac gia tri trong mang theo thu tu tang dan
void SapXepTangDan(double a[], int n)
{
    //So sanh a[i] voi tung a[j]
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            //Neu ton tai a[i] < a[j] thi hoan doi vi tri cua hai so
            if (a[i] > a[j]) HoanDoi(a[i], a[j]);
}

//Ham tron mang a, b vao mang c va sap xep theo thu tu tang dan
void TronMangVaXepTang(double a[], int na, double b[], int nb, double c[], int& nc)
{
    nc = 0;
    //Dung vong lap de lan luot gan cac gia tri cua mang a vao mang c
    for (int i = 0; i < na; i++)
        c[nc++] = a[i]; //Sau moi lan gan thi tang so phan tu cua mang c len 1 don vi
    //Tiep tuc dung vong lap de lan luot gan cac gia tri cua mang b vao mang c
    for (int i = 0; i < nb; i++)
        c[nc++] = b[i]; //Sau moi lan gan thi tang so phan tu cua mang c len 1 don vi
    SapXepTangDan(c, nc);    //Sap xep cac phan tu cua mang c theo thu tu tang dan
    cout << "Mang c duoc tron tu mang a va mang b sau do sap xep tang dan la: ";
}

//Dinh nghia ham xoa mot phan tu khi biet vi tri
void XoaPhanTu(double a[], int& n, int viTri)
{
    //Tao vong lap thay doi cac gia tri trong mang voi i tu viTri
    for (int i = viTri; i < n; i++)
        //Gan gia tri cua phan tu sau cho phan tu truoc 
        //Nhu vay ta da cat bo duoc gia tri cua phan tu viTri
        a[i] = a[i + 1];
    n--;    //Vi xoa di mot phan tu nen n giam di mot don vi
}

//Ham xoa phan tu trung cua mang
void XoaPhanTuTrung(double a[], int& na)
{
    for (int i = 0; i < na; i++)
        //Vi mang da duoc sap xep tang dan nen neu 2 phan tu ke tiep nhau ma giong nhau
        //thi xoa di cac phan tu giong nhau do
        if (a[i] == a[i + 1])
            while (a[i] == a[i + 1])
                XoaPhanTu(a, na, i + 1);
    cout << "Mang c sau khi xoa cac phan tu trung la: ";
}

//Ham nhap mang
void NhapMang(double a[], int& n)
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
void XuatMang(double a[], int n)
{
    //Dung vong lap for de xuat tung gia tri cua mang
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    double a[MAX], b[MAX];
    int na, nb;
    cout << "Mang a: " << endl;
    NhapMang(a, na);
    cout << "Mang b: " << endl;
    NhapMang(b, nb);
    //Kiem tra mang a va b co sap xep tang dan hay khong
    if (TangDan(a, na) && TangDan(b, nb))
        cout << "Hai mang tang dan theo thu tu" << endl;
    else    //Neu khong thi sap xep tang dan cho 2 mang
    {
        cout << "Hai mang khong co thu tu tang dan" << endl;
        if (!TangDan(a, na))
            SapXepTangDan(a, na); //Sap xep lai mang a theo thu tu tang dan
        if (!TangDan(b, nb))
            SapXepTangDan(b, nb); //Sap xep lai mang b theo thu tu tang dan
        cout << "Hai mang sau khi duoc sap xep theo thu tu tang dan la: " << endl;
        cout << "Mang a: ";
        XuatMang(a, na);
        cout << "Mang b: ";
        XuatMang(b, nb);
    }

    double c[MAX];
    int nc;
    //Tron mang a, b vao mang c va sap xep theo thu tu tang dan
    TronMangVaXepTang(a, na, b, nb, c, nc);
    XuatMang(c, nc);

    //Xoa cac phan tu trung cua mang
    XoaPhanTuTrung(c, nc);
    XuatMang(c, nc);
    return 0;
}
