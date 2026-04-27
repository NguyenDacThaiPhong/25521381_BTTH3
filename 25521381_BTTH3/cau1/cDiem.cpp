#include <bits/stdc++.h>
#include "cDiem.h"
using namespace std;

cDiem::~cDiem() { // destructor
}

cDiem::cDiem(double hoanhdo, double tungdo) { // constructor chứa biến
    x = hoanhdo;
    y = tungdo;
}

cDiem::cDiem() { // constructor
    x = 0;
    y = 0;
}

void cDiem::Nhap() {
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
}

void cDiem::Xuat() {
    cout << "(" << x << ", " << y << ")" << endl;
}

double cDiem::KhoangCach(cDiem D) {  // tính khoảng cách
    return sqrt((x - D.x)*(x - D.x) + (y - D.y)*(y - D.y));
}
void cDiem::PhongToThuNho(double HeSo) {  // phóng to thu nhỏ
    x *= HeSo;
    y *= HeSo;
}

void cDiem::Quay(double goc) {  // Quay điểm
    double rad = goc * M_PI / 180.0; // đổi sang radian
    double xo = x;
    double yo = y;

    x = xo*cos(rad) - yo*sin(rad);
    y = xo*sin(rad) + yo*cos(rad);
}

void cDiem::TinhTien(double dx, double dy) { // tịnh tiến
    x += dx;
    y += dy;
}

