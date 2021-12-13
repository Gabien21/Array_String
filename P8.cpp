//VCT nhập mảng A gồm n < 1000 phần tử nguyên và |A[i]| ≤ 10,000. Viết các hàm thực hiện:
//a)    Trích những phần tử trong A không phải số nguyên tố ra mảng B.
//b)    Sắp giảm các số nguyên trong mảng B.
//c)     Xóa những số nguyên tố trong mảng A.

#include <iostream>
using namespace std;
#define MAX 1000

//Ham kiem tra n co phai la so nguyen to hay khong
bool SoNguyenTo(int n)
{
    if (n <= 1) return false;    //Neu n <= 1 thi n khong phai la so nguyen to
    //So nguyen to la so chi chia het cho 1 va chinh no
    for (int i = 2; i <= n / 2; i++)	//Tao vong lap voi i chay tu 2 den n/2
        if (n % i == 0) return false;	//Neu co gia tri i nao chia het cho n thi tra ve false
    return true;    //Neu khong tim duoc so nao chia het cho n thi tra ve true
}

//Ham hoan doi gia tri cua hai so
void HoanDoi(int& a, int& b)
{
    double temp = a;   //Gan gia tri cua a vao bien phu temp
    a = b;  //Gan gia tri cua b vao a
    b = temp;   //Gan gia tri cua bien phu temp vao b
}

//Ham sap xep cac gia tri trong mang a theo thu tu tang dan
void SapXepGiamDan(int a[], int n)
{
    //So sanh a[i] voi tung a[j]
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            //Neu ton tai a[i] > a[j] thi hoan doi vi tri cua hai so
            if (a[i] < a[j]) HoanDoi(a[i], a[j]);
    cout << "Mang b sau khi sap xep cac phan tu theo thu tu giam dan: ";
}

//Ham trich nhung phan tu khong phai so nguyen to trong mang a vao mang b
void TrichPhanTu(int a[], int na, int b[], int& nb)
{
    nb = 0;
    //Dung vong lap for de xet tung phan tu trong mang a
    for (int i = 0; i < na; i++)
        if (!SoNguyenTo(a[i]))   //Neu phan tu do khong phai la so nguyen to
            b[nb++] = a[i]; //Thi truyen gia tri cua phan tu do vao mang b, 
                            //tang so phan tu cuar mang b len 1 don vi
    cout << "Mang b sau khi duoc truyen cac phan tu khong la so nguyen to: ";
}

//Ham xoa mot phan tu khi biet vi tri
void XoaPhanTu(int a[], int& n, int viTri)
{
    //Tao vong lap thay doi cac gia tri trong mang voi i tu viTri
    for (int i = viTri; i < n; i++)
        //Gan gia tri cua phan tu sau cho phan tu truoc 
        //Nhu vay ta da cat bo duoc gia tri cua phan tu viTri
        a[i] = a[i + 1];
    n--;    //Vi xoa di mot phan tu nen n giam di mot don vi
}

//Ham xoa cac phan tu la so nguyen to trong mang a
void XoaSoNguyenTo(int a[], int& na)
{
    for (int i = na - 1; i >= 0; i--)
        if (SoNguyenTo(a[i]))    //Neu a[i] la so nguyen to thi xoa phan tu do ra khoi mang a
            XoaPhanTu(a, na, i);
    cout << "Mang a sau khi xoas cac phan tu la so nguyen to: ";
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

int main()
{
    int a[MAX], na;
    NhapMang(a, na);
    int b[MAX], nb;

    //Trich phan tu trong a khong phai so nguyen to vao mang b
    TrichPhanTu(a, na, b, nb);
    XuatMang(b, nb);

    //Sap xep mang b giam dan
    SapXepGiamDan(b, nb);
    XuatMang(b, nb);

    //Xoa nhung so nguyen to trong mang a
    XoaSoNguyenTo(a, na);
    XuatMang(a, na);

    return 0;
}
