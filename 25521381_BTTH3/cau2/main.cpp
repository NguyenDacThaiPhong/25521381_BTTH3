#include <iostream>
#include "cDaGiac.h" 
using namespace std;

int main() {
    cDaGiac dg;
    dg.Nhap();
    dg.Xuat();

    string loai = dg.KiemTraLoai();
    cout << "\nLoai da giac: " << loai << endl;
    
    if (loai != "Khong phai da giac hop le") {
        cout << "Chu vi: " << dg.TinhChuVi() << endl;
        cout << "Dien tich: " << dg.TinhDienTich() << endl;
        
        double dx, dy; 
        cout << "\nNhap diem tinh tien dx/dy: "; 
        cin >> dx >> dy; 
        dg.TinhTien(dx, dy);
        dg.Xuat();
        
        double heso;
        cout << "\nNhap he so phong to/thu nho: ";
        cin >> heso; 
        dg.PhongToThuNho(heso);
        dg.Xuat();
        
        double goc;
        cout << "\nNhap goc quay: ";
        cin >> goc; 
        dg.Quay(goc);
        dg.Xuat();
    }
    
    return 0;
}