#pragma once
#include <bits/stdc++.h>
using namespace std;

class cDiem {
    private: 
        double x; // tọa độ x
        double y; // tọa độ y
    public:
        cDiem(); // constructor
        cDiem(double hoanhdo, double tungdo); // constructor chứa biến
        ~cDiem(); // destructor
        void Quay(double goc); // Quay điểm
        void TinhTien(double dx, double dy); // tịnh tiến
        void PhongToThuNho(double HeSo); // phóng to thu nhỏ
        double KhoangCach(cDiem D); // tính khoảng cách
        void Nhap(); // nhập
        void Xuat(); // xuất
    

};