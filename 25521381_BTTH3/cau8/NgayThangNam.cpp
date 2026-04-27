#include "NgayThangNam.h"
#include <iostream>
#include <iomanip>
using namespace std;

// -- Constructors -------------------------------------------------------------

NgayThangNam::NgayThangNam() : ngay(1), thang(1), nam(2000) {}

NgayThangNam::NgayThangNam(int ng, int th, int n) : ngay(ng), thang(th), nam(n) {}

// -- Getters ------------------------------------------------------------------

int NgayThangNam::getNgay()  const { return ngay; }
int NgayThangNam::getThang() const { return thang; }
int NgayThangNam::getNam()   const { return nam; }

// -- Setters ------------------------------------------------------------------

void NgayThangNam::setNgay(int ng)  { ngay  = ng; }
void NgayThangNam::setThang(int th) { thang = th; }
void NgayThangNam::setNam(int n)    { nam   = n;  }

// -- Nghiep vu ----------------------------------------------------------------

// Tinh tuoi don gian theo nam; chua xu ly truong hop chua qua ngay sinh trong nam
int NgayThangNam::Tuoi(int namHienTai) const {
    return namHienTai - nam;
}

// -- Nhap / Xuat --------------------------------------------------------------

void NgayThangNam::Nhap() {
    cout << "    Nhap ngay  : "; cin >> ngay;
    cout << "    Nhap thang : "; cin >> thang;
    cout << "    Nhap nam   : "; cin >> nam;
}

void NgayThangNam::Xuat() const {
    cout << setfill('0')
         << setw(2) << ngay  << "/"
         << setw(2) << thang << "/"
         << setw(4) << nam
         << setfill(' ');  // khoi phuc setfill mac dinh sau khi in
}