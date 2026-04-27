#pragma once
 
#include <string>
#include "NgayThangNam.h"
using namespace std;
 
class NhanVienSX {
private:
    string       maNV;
    string       hoten;
    NgayThangNam ngaysinh;  // composition: NhanVienSX "co" mot NgayThangNam
    int          SoSp;      // so san pham da gia cong
    double       donGia;    // don gia mot san pham
 
public:
    // Constructors / Destructor 
    NhanVienSX();
    NhanVienSX(string maNV, string hoten, NgayThangNam ngaysinh, int SoSp, double donGia);
    ~NhanVienSX();
 
    //  Getters & Setters 
    string       getMaNV()     const;   void setMaNV(string ma);
    string       getHoten()    const;   void setHoten(string ten);
    NgayThangNam getNgaysinh() const;   void setNgaysinh(NgayThangNam ns);
    int          getSoSp()     const;   void setSoSp(int soSp);
    double       getDonGia()   const;   void setDonGia(double dg);
 
    // Nghiep vu 
    int    getTuoi(int namHienTai) const;  // uy quyen cho ngaysinh.Tuoi()
    double TinhLuong()             const;  // SoSp * donGia
 
    // Nhap / Xuat 
    void Nhap();
    void Xuat() const;
};
 