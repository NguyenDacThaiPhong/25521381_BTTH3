#pragma once
#include <bits/stdc++.h>
#include "cDiem.h"
using namespace std;

class cTamGiac {
    private:    // 3 điểm của tam giác
        cDiem A; 
        cDiem B;
        cDiem C;
    public:
        cTamGiac();  // constructor
        cTamGiac(cDiem diemA, cDiem diemB, cDiem diemC); // constructor chứa biến
        ~cTamGiac(); // destructor
        void Quay(double goc); // quay tam giác
        void TinhTien(double dx, double dy);  //tịnh tiến
        void PhongToThuNho(double HeSo); // phóng to thu nhỏ
        string KiemTraLoai(); // kiểm tra loại tam giác
        double TinhChuVi(); // tính chu vi
        double TinhDienTich(); // tính diện tích
        void Nhap(); // nhập
        void Xuat(); // xuất

};