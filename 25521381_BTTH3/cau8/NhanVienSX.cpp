#include "NhanVienSX.h"
#include <iostream>
#include <iomanip>
using namespace std;
 
// -- Constructors / Destructor ------------------------------------------------
 
NhanVienSX::NhanVienSX()
    : maNV(""), hoten(""), ngaysinh(), SoSp(0), donGia(0) {}
 
NhanVienSX::NhanVienSX(string ma, string ten, NgayThangNam ns, int sp, double dg)
    : maNV(ma), hoten(ten), ngaysinh(ns), SoSp(sp), donGia(dg) {}
 
NhanVienSX::~NhanVienSX() {}
 
// -- Getters ------------------------------------------------------------------
 
string       NhanVienSX::getMaNV()     const { return maNV; }
string       NhanVienSX::getHoten()    const { return hoten; }
NgayThangNam NhanVienSX::getNgaysinh() const { return ngaysinh; }
int          NhanVienSX::getSoSp()     const { return SoSp; }
double       NhanVienSX::getDonGia()   const { return donGia; }
 
// -- Setters ------------------------------------------------------------------
 
void NhanVienSX::setMaNV(string ma)          { maNV     = ma; }
void NhanVienSX::setHoten(string ten)         { hoten    = ten; }
void NhanVienSX::setNgaysinh(NgayThangNam ns) { ngaysinh = ns; }
void NhanVienSX::setSoSp(int sp)              { SoSp     = sp; }
void NhanVienSX::setDonGia(double dg)         { donGia   = dg; }
 
// -- Nghiep vu ----------------------------------------------------------------
 
int NhanVienSX::getTuoi(int namHienTai) const {
    return ngaysinh.Tuoi(namHienTai);  // uy quyen tinh tuoi cho NgayThangNam
}
 
double NhanVienSX::TinhLuong() const {
    return SoSp * donGia;
}
 
// -- Nhap / Xuat --------------------------------------------------------------
 
void NhanVienSX::Nhap() {
    cin.ignore();  // xoa '\n' con trong buffer truoc khi dung getline
    cout << "  Nhap ma nhan vien          : "; getline(cin, maNV);
    cout << "  Nhap ho ten                : "; getline(cin, hoten);
    cout << "  Nhap ngay sinh:\n";
    ngaysinh.Nhap();
    cout << "  Nhap so san pham gia cong  : "; cin >> SoSp;
    cout << "  Nhap don gia mot san pham  : "; cin >> donGia;
}
 
void NhanVienSX::Xuat() const {
    cout << left
         << setw(10) << maNV
         << setw(25) << hoten
         << right;
    ngaysinh.Xuat();  // in ngay sinh theo dinh dang dd/MM/yyyy
    cout << setw(8)  << SoSp
         << setw(14) << fixed << setprecision(2) << donGia
         << setw(16) << fixed << setprecision(2) << TinhLuong()
         << "\n";
}