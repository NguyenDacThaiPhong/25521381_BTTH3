#include <bits/stdc++.h>
#include "cTamGiac.h" 
using namespace std;

cTamGiac::cTamGiac() {}
cTamGiac::~cTamGiac(){}
cTamGiac::cTamGiac(cDiem diemA, cDiem diemB, cDiem diemC) {
    A = diemA;
    B = diemB;
    C = diemC;
}
        
void cTamGiac::Quay(double goc) {  // quay từng điểm một
    A.Quay(goc);
    B.Quay(goc);
    C.Quay(goc);
}
        
void cTamGiac::TinhTien(double dx, double dy) { // mỗi điểm tịnh tiến
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}
        
void cTamGiac::PhongToThuNho(double HeSo) {  // mổi điểm co giãn
    A.PhongToThuNho(HeSo);
    B.PhongToThuNho(HeSo);
    C.PhongToThuNho(HeSo);
}
        
string cTamGiac::KiemTraLoai() {  // kiểm tra loại tam giác
    double a = A.KhoangCach(B);  // tính khoảng cách các điểm để lấy độ dài
    double b = A.KhoangCach(C);
    double c = B.KhoangCach(C);
    double eps = 1e-4; // tránh bị so sánh sai so kết quả có thể không chính xác hoàn toàn
    
    if (a + b <= c || a + c <= b || b + c <= a) {
        return "tam giac khong hop le";
    }

    bool TamGiacCan = (fabs(a - b) < eps || fabs(a - c) < eps || fabs(c - b) < eps);  //cân
    bool TamGiacDeu = (fabs(a - b) < eps && fabs(a - c) < eps); // đều
    bool TamGiacVuong = (fabs(a*a + b*b - c*c) < eps) || (fabs(a*a + c*c - b*b) < eps) || (fabs(c*c + b*b - a*a) < eps); // vuông

    if (TamGiacDeu) return "Tam giac deu";
    else if (TamGiacVuong && TamGiacCan) return "Tam giac vuong can"; 
    else if (TamGiacVuong) return "Tam giac vuong";
    else if (TamGiacCan) return "Tam giac can";
    else return "Tam giac thuong"; // tam giác thường nếu ko thuộc loại nào
}
        
double cTamGiac::TinhChuVi() { // chu vi
    double AB = A.KhoangCach(B);
    double AC = A.KhoangCach(C);
    double BC = B.KhoangCach(C);

    return AB + BC + AC;
}
        
double cTamGiac::TinhDienTich() {  // diện tích
    double AB = A.KhoangCach(B);
    double AC = A.KhoangCach(C);
    double BC = B.KhoangCach(C);

    double p = (AB + AC + BC)/2;
    return sqrt(p*(p-AB)*(p-BC)*(p-AC));


}
        
void cTamGiac::Nhap() {
    cout << "Nhap toa do dienm A: ";
    A.Nhap();
    cout << "Nhap toa do dienm B: ";
    B.Nhap();
    cout << "Nhap toa do dienm C: ";
    C.Nhap();
}

void cTamGiac::Xuat() {
    cout << "Tam giac tao boi 3 diem: " << endl;
    cout << "A: "; A.Xuat();
    cout << "B: "; B.Xuat();
    cout << "C: "; C.Xuat();
}