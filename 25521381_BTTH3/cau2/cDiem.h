#pragma once

class cDiem {
    private: 
        double x;
        double y;
    public:
        cDiem();
        cDiem(double hoanhdo, double tungdo);
        ~cDiem();
        void Quay(double goc);
        void TinhTien(double dx, double dy);
        void PhongToThuNho(double HeSo);
        double KhoangCach(cDiem D);
        void Nhap();
        void Xuat();
        double GetX() const;
        double GetY() const;
};