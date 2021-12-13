//VCT nhập vào 2 xâu ký tự S1 và S2. Viết hàm xét xem S1 có xuất hiện bao nhiêu lần trong S2 (hoặc ngược lại S2 xuất hiện bao nhiêu lần trong S1) và tại những vị trí nào?

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

//Ham xuat chuoi
void XuatChuoi(char a[])
{
    int n = strlen(a);  //Lay do dai cua chuoi
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

//Ham xu li yeu cau
void YeuCau(char a[], char b[])
{
    int n = strlen(a);
    int m = strlen(b);
    cout << "Vi tri la: " << endl;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        if (a[i] == b[t])    //Tim phan tu trong chuoi a bang voi phan tu dau tien trong chuoi b
        {
            bool kq = true;
            //So sanh tung phan tu trong chuoi b voi cac phan tu trong chuoi a tu vi tri vua tim duoc
            for (int j = 1; j < m; j++)
                //Neu phan tu trong a khac trong b thi tra ve false va dung vong lap
                if (b[j] != a[i + j])
                {
                    kq = false;
                    break;
                }
            if (kq)  //Neu kq tra ve true thi xuat ra vi tri cua chuoi b trong chuoi a
            {
                cout << "Tu " << i + 1 << " den " << i + m << endl;
                dem++;  //Tang bien dem them 1 don vi
            }
        }
    }
    if (dem > 0) //Neu bien dem > 0 thi xuat ra so lan xuat hien
        cout << "Vay chuoi xuat hien " << dem << " lan" << endl;
    else
        cout << "2 chuoi khong chua nhau!" << endl;
}

//Ham tim vi tri cua chuoi con trong chuoi me
void ViTriCuaChuoiCon(char a[], char b[])
{
    int n = strlen(a);
    int m = strlen(b);
    if (m < n)
        YeuCau(a, b);
    else
        YeuCau(b, a);
}

int main()
{
    char a[MAX], b[MAX];
    cout << "Chuoi a: " << endl;
    NhapChuoi(a);
    cout << "Chuoi b: " << endl;
    NhapChuoi(b);
    ViTriCuaChuoiCon(a, b);
}
