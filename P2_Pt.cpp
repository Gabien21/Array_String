//VCT nhập một mảng số nguyên có n phần tử, xây dựng các hàm thực hiện:
//a) Liệt kê tần suất xuất hiện của các phần tử. Ví dụ với mảng 12 34 12 34 43 12 5
//thì tần suất xuất hiện của các phần tử như trong bảng sau:
//Phần tử    Tần suất
//   12         3
//   34         2
//   43         1
//   5          1
//b) Viết hàm thêm một phần tử có giá trị x vào mảng tại vị trí k.
//c) Viết hàm xóa 1 phần tử tại vị trí k, không sử dụng mảng trung gian.
//d) Viết hàm sắp xếp các phần tử của mảng là số nguyên tố

#include <iostream>
using namespace std;
#define MAX 1000

//Ham kiem tra xem x co trong mang khong
bool KiemTraX(int a[], int n, int x)
{
    //Dung vong lap for de xet den tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
        //Neu tim duoc 1 phan tu co gia tri bang x thi tra ve true
        if(a[i] == x) return true;
    return false;   //Nguoc lai tra ve false
}

//Ham dem so lan xuat hien cua x trong mang
int Dem(int a[], int n, int x)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == x) dem++;    //neu phat hien x trong mang thi tang dem len 1 don vi
    }
    return dem;
}

//Ham liet ke tan suat cua cac phan tu trong mang
void LietKeTanSuat(int a[], int n)
{
    int b[n], k = 0;
    for(int i = 0; i < n; i++)
    {
        if(!KiemTraX(b,k,a[i])) b[k++] = a[i];  //Truyen cac phan tu trong mang a vao mang b
    }
    for(int i = 0; i < k; i++)
    {
        //Xuat ra so lan xuat hien cua tung phan tu
        cout << "Phan tu " << b[i] << " xuat hien " << Dem(a,n,b[i]) << " lan" << endl;
    }
}

//ham them mot phan tu co gia tri x vao viTri cua mang
void ThemPhanTu(int a[], int& n, int x, int viTri)
{
    for(int i = n; i > viTri; i--)
    {
        a[i] = a[i-1];  //gan gia tri cua phan tu truoc cho gia tri cua phan tu sau
    }
    a[viTri] = x;   //Gan gia tri x vao a[viTri]
    n++;    //Tang n them 1 don vi
}

//Dinh nghia ham xoa mot phan tu khi biet vi tri
void XoaPhanTu(int a[], int& n, int viTri)
{
    //Tao vong lap thay doi cac gia tri trong mang voi i tu viTri
    for(int i = viTri; i < n; i++)
    {
        //Gan gia tri cua phan tu sau cho phan tu truoc 
        //Nhu vay ta da cat bo duoc gia tri cua phan tu viTri
        a[i] = a[i+1];
    }
    n--;    //Vi xoa di mot phan tu nen n giam di mot don vi
}

//Ham kiem tra n co phai la so nguyen to hay khong
bool SoNguyenTo(int n)
{
    if(n <= 1) return false;    //Neu n <= 1 thi n khong phai la so nguyen to
	//So nguyen to la so chi chia het cho 1 va chinh no
	for (int i = 2; i <= n/2; i++)	//Tao vong lap voi i chay tu 2 den n/2
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

//Hm sap xep cac so nguyen to tang dan
void SapXepSNTTangDan(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            //Neu a[i] va a[j] la hai so nguyen to thi tien hanh sap xep
            if(SoNguyenTo(a[i])&&SoNguyenTo(a[j]))  
            {
                if(a[i] > a[j]) //Neu a[i] > a[j] thi tien hanh hoan doi gia tri cua 2 phan tu
                    HoanDoi(a[i],a[j]);
            }
        }
    }
}

//Ham nhap mang
void NhapMang(int a[], int& n)
{
    char ans;
    //Hoi nguoi dung co biet truoc so phan tu cua mang hay khong
    cout << "Ban co biet so phan tu khong? (Y/N) "; cin >> ans;
    //Neu nguoi dung biet truoc so phan tu cua mang
    if(ans == 'Y' || ans == 'y')
    {
        do
        {
            cout << "Nhap so phan tu trong mang: "; cin >> n;
            //Neu n <= 0 hoac n > MAX thi so phan tu khong hop le
            if(n > MAX || n <= 0)
            {
                cout << "So phan tu khong hop le, hay nhap lai!" << endl;
                continue;
            }
            cout << "Nhap " << n << " phan tu: ";
            //Dung vong lap for de nhap gia tri cua tung phan tu trong mang
            for(int i = 0; i < n; i++)
                cin >> a[i];
        } while (n > MAX || n <= 0);  //Nhap cho den khi n hop le
    }
    //Neu nguoi dung khong biet truoc so phan tu cua mang
    else if(ans == 'N' || ans == 'n')
    {
        char ans2;
        n = 0;
        do
        {            
            cout << "a[" << n << "] = "; cin >> a[n]; //Lan luot nhap tung phan tu cua mang
            n++;    //Tang n len 1 sau moi lan nhap
            cout << "Ban co muon nhap tiep khong? (Y/N) "; cin >> ans2;
        } while (ans2 == 'Y' || ans2 == 'y');   //Neu nguoi dung muon nhap tiep thi tiep tuc vong lap   
    }
}

//Ham xuat mang
void XuatMang(int a[], int n)
{
    //Dung vong lap for de xuat tung gia tri cua mang
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

//Ham Nhap vi tri va gia tri cua phan tu can them
void NhapViTriVaGiaTri(int& viTri, int& x, int n)
{
    do
    {
        cout << "Nhap vao vi tri can them va gia tri cua vi tri them do: ";
        cin >> viTri >> x;
        if(viTri > n || viTri < 0)
            cout << "Vi tri khong hop le!" << endl;
    } while (viTri > n || viTri < 0);    
}

//ham nhap vi tri cua phan tu can xoa
void NhapViTri(int& viTri, int n)
{
    do
    {
        cout << "Nhap vao vi tri can xoa: ";
        cin >> viTri;
        if(viTri > n || viTri < 0)
            cout << "Vi tri khong hop le!" << endl;
    } while (viTri > n || viTri < 0);    
}

int main()
{
    int a[MAX], n, k, x;
    NhapMang(a,n);

    //Liet ke tan suat cua cac phan tu trong mang
    cout << "Liet ke tan suat cua cac phan tu trong mang: " << endl;
    LietKeTanSuat(a,n);

    //Them phan tu co gia tri x va vi tri k
    NhapViTriVaGiaTri(k,x,n);
    ThemPhanTu(a,n,x,k);
    cout << "Mang sau khi them " << x << " vao vi tri " << k << " la: ";
    XuatMang(a,n);

    //Xoa phan tu o vi tri k
    NhapViTri(k,n);
    XoaPhanTu(a,n,k);
    cout << "Mang sau khi xoa phan tu tai vi tri " << k << " la: ";
    XuatMang(a,n);

    //Sap xep cac so nguyen to trong mang theo thu tu tang dan
    cout << "Sap xep cac so nguyen to trong mang theo thu tu tang dan: ";
    SapXepSNTTangDan(a,n);
    XuatMang(a,n);
}
