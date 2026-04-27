#include <bits/stdc++.h>
#include "cTamGiac.h" 
using namespace std;

int main() {
    cTamGiac tg;
    tg.Nhap();
    tg.Xuat();

    cout << "Loai tam giac: " << tg.KiemTraLoai() << endl;
    if (tg.KiemTraLoai() != "tam giac khong hop le") {
        cout << "Chu vi: " << tg.TinhChuVi() << endl;
        cout << "Dien tich: " << tg.TinhDienTich() << endl;
        cTamGiac temp = tg;
        double dx, dy; 
        cout << "Nhap diem tinh tien dx/dy: "; 
        cin >> dx >> dy; temp.TinhTien(dx, dy);
        temp.Xuat();
        temp = tg;
        double heso;
        cout << "Nhap he so phong to/thu nho: ";
        cin >> heso; temp.PhongToThuNho(heso);
        temp.Xuat();
        temp = tg;
        double goc;
        cout << "Nhap goc quay: ";
        cin >> goc; temp.Quay(goc);
        temp.Xuat();
        temp = tg;
    }

}

