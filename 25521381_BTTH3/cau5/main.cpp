#include <bits/stdc++.h>
#include "cDaThuc.h"
using namespace std;

int main() {
    cDaThuc p1, p2;

    cout << "=== Nhap da thuc P1 ===\n";
    p1.Nhap();
    cout << "P1 = "; p1.Xuat();

    cout << "\n=== Nhap da thuc P2 ===\n";
    p2.Nhap();
    cout << "P2 = "; p2.Xuat();

    double x;
    cout << "\nNhap x de tinh gia tri: ";
    cin >> x;
    cout << "P1(" << x << ") = " << p1.TinhGiaTri(x) << "\n";
    cout << "P2(" << x << ") = " << p2.TinhGiaTri(x) << "\n";

    cDaThuc tong = p1.CongDaThuc(p2);
    cout << "\nP1 + P2 = "; tong.Xuat();

    cDaThuc hieu = p1.TruDaThuc(p2);
    cout << "P1 - P2 = "; hieu.Xuat();

    return 0;
}