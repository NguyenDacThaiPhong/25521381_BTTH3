#include <bits/stdc++.h>
#include "cDiem.h"
using namespace std;

cDiem::~cDiem() {
}

cDiem::cDiem(double hoanhdo, double tungdo) {
    x = hoanhdo;
    y = tungdo;
}

cDiem::cDiem() {
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

double cDiem::KhoangCach(cDiem D) {
    return sqrt((x - D.x)*(x - D.x) + (y - D.y)*(y - D.y));
}
void cDiem::PhongToThuNho(double HeSo) {
    x *= HeSo;
    y *= HeSo;
}

void cDiem::Quay(double goc) {
    double rad = goc * M_PI / 180.0;
    double xo = x;
    double yo = y;

    x = xo*cos(rad) - yo*sin(rad);
    y = xo*sin(rad) + yo*cos(rad);
}

void cDiem::TinhTien(double dx, double dy) {
    x += dx;
    y += dy;
}

double cDiem::GetX() const {
    return x;
}

double cDiem::GetY() const {
    return y;
}
