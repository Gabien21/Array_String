//VCT nhập 1 chuỗi tối đa 80 ký tự và xuất menu cho phép lữa chọn để thực hiện các xử lý sau:
//- Cắt bỏ các khoảng trắng nằm cạnh nhau nếu có - chỉ chừa lại 1. (vd: "      Hello,      world    " =>" Hello, world " )
//- Chuyển chữ cái đầu mỗi từ thành hoa và các chữ cái còn lại thành thường. (vd: "CONg nGHE thONG TIN" =>"Cong Nghe Thong Tin")
//- Xóa các từ giống nhau, chỉ giữ lại từ đầu.  (vd: "Messi la Pulga, Messi la Goat, gio thi Messi dang la Hetxiquach" => Messi la Pulga, Goat, gio thi dang Hetxiquach"

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 81

//Ham xoa mot ki tu o mot vi tri k
void XoaKiTu(char a[], int k)
{
    int n = strlen(a);  //Lay do dai cua chuoi
    //Cho vong lap chay tu vi tri k
    for (int i = k; i < n; i++)
        a[i] = a[i + 1];    //Gan gia tri cua phan tu sau cho phan tu truoc
}

//Ham xoa khoang trang thua trong chuoi
void XoaKhoangTrangThua(char a[])
{
    int n = strlen(a);  //Lay do dai cua chuoi
    for (int i = 0; i < n; i++)
        if (a[i] == ' ')
            //Neu ki tu tiep theo la khoang trong thi tiep tuc xoa ki tu do
            while (a[i + 1] == ' ')
            {
                XoaKiTu(a, i + 1);
                n = strlen(a);
            }
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

//Ham tim vi tri cua chuoi con trong chuoi me va bat dau tim tu mot vi tri cho truoc
int TimViTri(char a[], char b[], int key)
{
    int n = strlen(a);
    int m = strlen(b);
    //Bat dau tim tu vi tri key
    for (int i = key; i < n; i++)
        //Tim ki tu trong chuoi a bang ki tu dau tien  trong chuoi b
        if (a[i] == b[0])
            //Lan luot so san cac ki tu con lai trong chuoi b   
            for (int j = 1; j < m; j++)
            {
                if (a[i + j] != b[j])
                    break;
                return i;
            }
    return -1;
}

//Ham xoa x ki tu tu mot vi tri trong chuoi
void XoaXKiTuTuViTri(char a[], int x, int viTri)
{
    int n = strlen(a);
    //Chay vong lap tu viTri - 1
    for (int i = viTri; i < n; i++)
        a[i] = a[i + x];  //Gan a[i+x] cho a[i] de bo qua x ki tu 
    n -= x;
}

//Ham kiem tra xem ki tu co phai la chu cai khong
bool KiemTraChuCai(char x)
{
    //Neu x la chu cai thi tra ve true
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        return true;
    return false;
}

//Ham xoa cac chu giong nhau trong chuoi, chi giu lai chu dau
void XoaChuGiongNhau(char a[])
{
    int n = strlen(a);
    for (int i = 0; i < n;)
    {
        char b[MAX];
        int nb = 0;
        //Tach tung chu vao chuoi b
        if (a[i] != ' ' && a[i - 1] == ' ' || (i == 0 && a[i] != ' '))
        {
            for (int j = i; j < n; j++)
            {
                if (KiemTraChuCai(a[j])) //Neu a[j] la chu cai thi truyen a[j] vao chuoi b
                    b[nb++] = a[j];

                //Khi den chu cai cuoi cung cua chu thi dung vong lap
                if ((a[j] != ' ' && a[j + 1] == ' ') || a[j + 1] == 0)
                {
                    b[nb++] = 0;    //Gan gia tri ket thuc chuoi
                    break;
                }
            }
            //Vong lap thuc hien cho den khi khong tim duoc vi tri cua chuoi b trong chuoi a
            while (TimViTri(a, b, i + 1) >= 0)
                //Xoa chuoi b khi no xuat hien trong a
                XoaXKiTuTuViTri(a, strlen(b), TimViTri(a, b, i + 1));
        }
        if (nb > 0) i += nb;
        else i++;
    }
    XoaKhoangTrangThua(a);
}

//Ham xuat menu va giai quyet cong viec theo yeu cau
void MenuVaLamYeuCau(char a[], int& xuLi)
{
    cout << "Cac xu li dang co la: " << endl;
    cout << "1/ Cat bo khoang trang nam canh nhau neu co" << endl;
    cout << "2/ Chuyen chu cai dau moi tu thanh hoa va cac chu cai con lai viet thuong" << endl;
    cout << "3/ Xoa cac tu giong nhau, chi giu lai tu dau" << endl;
    do
    {
        cout << "Ban muon xu li nao? (1->3) "; cin >> xuLi;
    } while (xuLi < 1 && xuLi > 3);

    if (xuLi == 1)
    {
        XoaKhoangTrangThua(a);
        cout << "Chuoi sau khi xoa cac khoang trang thua la: " << endl;
        cout << a << endl;
    }
    if (xuLi == 2)
    {
        ChuyenSangTitleCase(a);
        cout << "Chuoi sau khi chuyen cac chu cai dau viet hoa va cac chu con lai viet thuong la: " << endl;
        cout << a << endl;
    }
    if (xuLi == 3)
    {
        XoaChuGiongNhau(a);
        cout << "Chuoi sau khi xoa nhung chu giong nhau, chi giu lai chu dau la: " << endl;
        cout << a;
    }
}

//Ham nhap Chuoi
void NhapChuoi(char a[])
{
    int ch, n = 0;
    cout << "Nhap chuoi: ";
    for (n = 0; n < MAX && (ch = getchar()) != '\n'; n++)
        a[n] = ch;
    a[n++] = '\0';  //Them phan tu ket thuc cho chuoi
}

int main()
{
    char a[MAX];
    NhapChuoi(a);
    int xuLi;
    MenuVaLamYeuCau(a, xuLi);   //Xuat menu va giai quyet yeu cau nhap vao
}
