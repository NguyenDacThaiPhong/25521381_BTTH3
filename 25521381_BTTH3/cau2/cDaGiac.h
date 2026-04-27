#pragma once
#include <string> // Nhớ include string để dùng std::string
#include "cDiem.h"

class cDaGiac {
    private:
        int n;         // Số lượng đỉnh
        cDiem *dinh;   // Con trỏ dùng để cấp phát mảng n đỉnh

    public: 
        cDaGiac();
        cDaGiac(int soDinh); 
        ~cDaGiac();

        void Nhap();
        void Xuat();
        void Quay(double goc);
        void TinhTien(double dx, double dy);
        void PhongToThuNho(double HeSo);
        
        std::string KiemTraLoai(); // kiểm tra loại lồi/lõm
        double TinhChuVi();
        double TinhDienTich();

        
};