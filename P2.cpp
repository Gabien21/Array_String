//VCT nhập vào một chuỗi là họ tên của một người (tiếng Việt không dấu), xây dựng các hàm thực hiện:
//a)    Hãy chuẩn hóa chuỗi họ tên này. (xóa các khoảng trắng thừa và ký tự đầu tiên của họ, chữ lót và tên phải viết hoa, các ký tự còn lại viết thường).
//VD: “ NgUyen VaN A “ => “Nguyen Van A”
//b)    Không sử dụng các hàm có sẵn. Viết hàm xóa N ký tự từ vị trí i trong chuỗi S.
//VD: “Nguyen Van A” i = 2 N = 3 (xóa 3 ký tự từ vị trí 2) -> “Nen Van A”

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

//Ham xoa mot ki tu o mot vi tri k
void XoaKiTu(char a[], int k)
{
    int n = strlen(a);  //Lay do dai cua chuoi
    //Cho vong lap chay tu vi tri k
    for (int i = k; i < n; i++)
        a[i] = a[i + 1];    //Gan gia tri cua phan tu sau cho phan tu truoc
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
}

//Ham chuan hoa chuoi ho ten
void ChuanHoaTen(char a[])
{
    int n = strlen(a);  //Lay do dai cua chuoi
    //Dung vong lap while de xoa cac khoang trang o vi tri dau tien chua chuoi
    while (a[0] == ' ')
        XoaKiTu(a, 0);
    //Dung vong lap while de xoa cac khoang trang o vi tri cuoi cung chua chuoi
    while (a[n - 1] == ' ')
        XoaKiTu(a, n - 1);
    //Xoa cac khoang trang du thua giua cac ki tu
    for (int i = 1; i < n; i++)
        if (a[i] == ' ')
            while (a[i + 1] == ' ')
                XoaKiTu(a, i + 1);
    //Chuyen chuoi ho ten sang dang chu title case
    ChuyenSangTitleCase(a);
    cout << "Chuoi ho ten sau khi duoc chuan hoa la: ";
    cout << a << endl;
}

//Ham xoa x ki tu tu mot vi tri trong chuoi
void XoaNKiTuTuViTri(char a[])
{
    int x, viTri;
    cout << "Nhap so phan tu ma ban muon xoa: "; cin >> x;
    cout << "Nhap vi tri ma ban muon bat dau xoa: "; cin >> viTri;
    int n = strlen(a);   //Lay do dai cua chuoi
    //Chay vong lap tu viTri - 1
    for (int i = viTri - 1; i < n; i++)
        a[i] = a[i + x];  //Gan a[i+x] cho a[i] de bo qua x ki tu 
    cout << "Chuoi sau khi cat bo " << x << " phan tu tu vi tri " << viTri << " la: ";
    cout << a;
}

int main()
{
    char a[MAX];
    NhapChuoi(a);

    //Chuan hoa chuoi ho ten vua nhap
    ChuanHoaTen(a);

    //Xoa n ki tu tu k vi tri
    XoaNKiTuTuViTri(a);

    return 0;
}
