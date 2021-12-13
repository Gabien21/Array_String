//VCT nhập một mảng số có n phần tử, xây dựng các hàm thực hiện:
//a)    Viết hàm kiểm tra xem có tồn tại mảng con tăng dần hay giảm dần không. Nếu có thì in mảng con tăng dần dài nhất xuất hiện trong mảng. 
//(nếu có nhiều mảng con cùng dài nhất thì chỉ cần in ra một)
//b)    Viết hàm xóa n phần tử liên tục trong mảng bắt đầu từ một vị trí x cho trước.

#include <iostream>
using namespace std;
#define MAX 1000

//Ham tim mang con duoc sap xep tang dan va co so phan tu nhieu nhat
void MangConMax(double a[], int n)
{
    bool flag = true;
    //Kiem tra xem trong mang co ton tai mang con tang dan hoac giam dan hay khong
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            flag = false;
            break;
        }
    }
    if (flag == true)   //Neu tat cac cac phan tu trong mang deu bang nhau thi thoat khoi ham
    {
        cout << "Mang vua nhap khong ton tai mang con tang dan hoac giam dan!" << endl;
        return;
    }
    int b[100], nb, max = 0;
    for (int i = 0; i < n; i++)  //Lan luot bat dau tai tung phan tu
    {
        int dem = 1, j = i + 1;
        for (; j < n; j++)   //Lan luot so sanh hai phan tu voi nhau
        {
            //Neu phan tu truoc lon hon hoac bang phan tu sau thi dung vong lap
            if (a[j] <= a[j - 1]) break;
            dem++;  //Neu khong thi tang bien dem them 1 
        }
        if (dem > max)   //Neu so luong phan tu > max
        {
            nb = 0;
            max = dem;  //Gan dem cho max
            //Truyen cac gia tri cua mang con trong a vao mang b
            for (int k = i; k < i + max; k++)
                b[nb++] = a[k];
        }
    }
    //Xuat ra mang con duoc sap xep tang dan va co so phan tu nhieu nhat
    cout << "Mang con co nhieu phan tu nhat la: ";
    for (int i = 0; i < nb; i++)
        cout << b[i] << " ";
    cout << endl;
}

//Ham xoa k phan tu tu vi tri xac dinh 
void XoaNhieuPhanTu(double a[], int& n, int viTri, int k)
{
    if (viTri <= 0 && viTri > n)
    {
        cout << "Vi tri khong hop le!";
        return;
    }
    for (int i = viTri - 1; i < n; i++)
        a[i] = a[i + k];    //gan de phan tu sau cho phan tu truoc
    n -= k; //Giam so phan tu cua n di k phan tu
    cout << "Mang sau khi xoa " << k << " phan tu tu vi tri " << viTri << " la: ";
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

//Ham nhap so phan tu va vi tri can xoa
void NhapNvaK(int& n, int& k, int na)
{
    do
    {
        cout << "Nhap so phan tu can xoa: "; 
        cin >> n;
        if (n <= 0 || n > na)
            cout << "So phan tu khong hop le!" << endl;
    } while (n <= 0 || n > na);

    do
    {
        cout << "Nhap vi tri bat dau xoa: "; cin >> k;
        if (k <= 0 || k > na) 
            cout << "So phan tu khong hop le!" << endl;
    } while (k <= 0 || k > na);
}

int main()
{
    double a[MAX];
    int n, x, k;
    NhapMang(a, n);
    //Tim mang con duoc sap xep tang dan va co so phan tu nhieu nhat
    MangConMax(a, n);

    //Xoa x phan tu tu vi tri k xac dinh
    NhapNvaK(x, k, n);
    XoaNhieuPhanTu(a, n, k, x);
    XuatMang(a, n);

    return 0;
}
