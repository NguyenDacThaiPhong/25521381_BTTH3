#include "NhanVienSX.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

const int NAM_HIEN_TAI = 2026;

void inTieuDe() {
    cout << string(90, '-') << "\n";
    cout << left
         << setw(10) << "Ma NV"
         << setw(25) << "Ho Ten"
         << setw(14) << "Ngay Sinh"
         << right
         << setw(8)  << "So SP"
         << setw(14) << "Don Gia"
         << setw(16) << "Luong"
         << "\n";
    cout << string(90, '-') << "\n";
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> n;

    vector<NhanVienSX> ds(n);

    // 1. Nhap danh sach
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhan vien thu " << (i + 1) << " ---\n";
        ds[i].Nhap();
    }

    // 2. Xuat danh sach
    cout << "\n========== DANH SACH NHAN VIEN SAN XUAT ==========\n";
    inTieuDe();
    for (const auto& nv : ds)
        nv.Xuat();

    // 3. Nhan vien luong thap nhat
    auto minLuong = min_element(ds.begin(), ds.end(),
        [](const NhanVienSX& a, const NhanVienSX& b) {
            return a.TinhLuong() < b.TinhLuong();
        });
    cout << "\nNhan vien co luong THAP NHAT:\n";
    inTieuDe();
    minLuong->Xuat();
        
    // 4. Tong luong
    double tongLuong = 0;
    for (const auto& nv : ds)
        tongLuong += nv.TinhLuong();
    cout << fixed << setprecision(2);
    cout << "\nTong luong cong ty phai tra: " << tongLuong << "\n";

    // 5. Nhan vien tuoi cao nhat
    auto maxTuoi = max_element(ds.begin(), ds.end(),
        [](const NhanVienSX& a, const NhanVienSX& b) {
            return a.getTuoi(NAM_HIEN_TAI) < b.getTuoi(NAM_HIEN_TAI);
        });
    cout << "\nNhan vien co tuoi CAO NHAT ("
         << maxTuoi->getTuoi(NAM_HIEN_TAI) << " tuoi):\n";
    inTieuDe();
    maxTuoi->Xuat();

    // 6. Sap xep tang dan theo luong
    sort(ds.begin(), ds.end(),
        [](const NhanVienSX& a, const NhanVienSX& b) {
            return a.TinhLuong() < b.TinhLuong();
        });
    cout << "\n===== DANH SACH SAP XEP TANG DAN THEO LUONG =====\n";
    inTieuDe();
    for (const auto& nv : ds)
        nv.Xuat();

    return 0;
}
