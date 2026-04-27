#include <bits/stdc++.h>
#include "cDaGiac.h"
using namespace std;

cDaGiac::cDaGiac() {
    n = 0;
    dinh = nullptr; // khởi tạo con trỏ 
}

cDaGiac::~cDaGiac() {
    if (dinh != nullptr) {
        delete[] dinh; // dọn rác, trả lại bộ nhớ
    }
}
cDaGiac::cDaGiac(int soDinh) {
    //  Kiểm tra điều kiện hợp lệ (Đa giác phải có từ 3 đỉnh trở lên)
    if (soDinh < 3) {
        n = 0;
        dinh = NULL; // Không tạo mảng nếu số đỉnh vô lý
    } 
    else {
        // Lưu lại số lượng đỉnh
        n = soDinh;
        
        // cấp phát một mảng gồm 'n' đối tượng cDiem
        dinh = new cDiem[n]; 
    }
}

void cDaGiac::Nhap() {   // nhập
    cout << "Nhap so dinh n (n > 2): ";
    do {
        cin >> n;
        if (n < 3) {
            cout << "So dinh khong hop le, vui long nhap lai: ";
        }
    } while (n < 3);
    dinh = new cDiem[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh thu " << i + 1 << ": ";
        dinh[i].Nhap();
        
    }
}

void cDaGiac::Xuat() {    // xuất
    cout << "Da giac tao boi " << n << " diem" << endl;
    for (int i = 0; i < n; i++) {
    cout << "Dinh thu " << i + 1 << ": "; dinh[i].Xuat();
    
    }
}

double cDaGiac::TinhChuVi() {
    if (n < 3) return 0; // Không đủ 3 đỉnh thì không phải đa giác
    
    double chuVi = 0;
    for (int i = 0; i < n; i++) {
        // Khoảng cách từ đỉnh i đến đỉnh i+1. Dùng % n để nếu i = n-1 thì nó nối về 0
        chuVi += dinh[i].KhoangCach(dinh[(i + 1) % n]); 
    }
    return chuVi;
}

double cDaGiac::TinhDienTich() {
    if (n < 3) return 0;
    
    double dienTich = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n; // Đỉnh tiếp theo (khép kín về 0)
        
        double xi = dinh[i].GetX();
        double yi = dinh[i].GetY();
        double x_next = dinh[next].GetX();
        double y_next = dinh[next].GetY();
        
        // Nhân chéo tọa độ
        dienTich += (xi * y_next) - (x_next * yi);
    }
    
    // Lấy trị tuyệt đối và chia đôi
    return fabs(dienTich) / 2.0; 
}

void cDaGiac::TinhTien(double dx, double dy) {  // tịnh tiến
    for (int i = 0; i < n; i++) {
        dinh[i].TinhTien(dx, dy); // Gọi hàm TinhTien của lớp cDiem
    }
}

void cDaGiac::Quay(double goc) {    // quay
    for (int i = 0; i < n; i++) {
        dinh[i].Quay(goc); // Gọi hàm Quay của lớp cDiem
    }
}

void cDaGiac::PhongToThuNho(double HeSo) {  // phóng to hoặc thu nhỏ dựa vào hệ số
    for (int i = 0; i < n; i++) {
        dinh[i].PhongToThuNho(HeSo); // Gọi hàm PhongToThuNho của lớp cDiem
    }
}

string cDaGiac::KiemTraLoai() {    // kiểm tra đa giác lồi hay lõm
    if (n < 3) return "Khong phai da giac hop le";
    
    bool coReTrai = false;
    bool coRePhai = false;

    for (int i = 0; i < n; i++) {
        // Lấy 3 đỉnh liên tiếp. Dùng % n để tạo vòng lặp khép kín nối đuôi về đầu
        int cur = i;
        int next1 = (i + 1) % n;
        int next2 = (i + 2) % n;

        // Lấy tọa độ
        double x1 = dinh[cur].GetX(),   y1 = dinh[cur].GetY();
        double x2 = dinh[next1].GetX(), y2 = dinh[next1].GetY();
        double x3 = dinh[next2].GetX(), y3 = dinh[next2].GetY();

        // Tính Tích có hướng (Cross Product) của 2 vector tạo bởi 3 điểm này
        double crossProduct = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);

        if (crossProduct > 0) coReTrai = true;
        if (crossProduct < 0) coRePhai = true;

        // Nếu phát hiện vừa có góc rẽ trái, vừa có góc rẽ phải -> Bị lõm
        if (coReTrai && coRePhai) {
            return "Da giac lom";
        }
    }
    
    // Nếu chạy hết vòng lặp mà không bị rẽ ngược hướng -> Đa giác lồi
    return "Da giac loi";
}