#include <bits/stdc++.h>
#include "cDaThuc.h"
using namespace std;

cDaThuc::cDaThuc() { // constructor
    n = 0;
    HeSo = new double[1]{0.0};
}

cDaThuc::cDaThuc(int bac) { // constructor chứa biến
    n = (bac < 0) ? 0 : bac;
    HeSo = new double[n + 1]{};   
}

cDaThuc::~cDaThuc() { // destructor
    delete[] HeSo;
    HeSo = nullptr;
}

cDaThuc::cDaThuc(const cDaThuc& other) {  // copy constructor - deep copy tránh double free
    n = other.n;
    HeSo = new double[n + 1];
    for (int i = 0; i <= n; i++)
        HeSo[i] = other.HeSo[i];
}

cDaThuc& cDaThuc::operator=(const cDaThuc& other) { // copy assignment - kiểm tra tự gán, deep copy
    if (this == &other) return *this;   // tránh tự gán
    delete[] HeSo;
    n = other.n;
    HeSo = new double[n + 1];
    for (int i = 0; i <= n; i++)
        HeSo[i] = other.HeSo[i];
    return *this;
}

//
void cDaThuc::Nhap() {
    cout << "Nhap bac da thuc: ";
    cin >> n;
    if (n < 0) n = 0;

    // Cấp phát lại sau khi biết n
    delete[] HeSo;
    HeSo = new double[n + 1]{};

    cout << "Nhap he so (HeSo[i] la he so cua x^i):\n";
    for (int i = n; i >= 0; i--) {
        cout << "  He so bac " << i << ": ";
        cin >> HeSo[i];          // HeSo[i] = hệ số x^i
    }
}

// 
// In dạng: a_n*x^n + ... + a_1*x + a_0
void cDaThuc::Xuat() const {
    bool daPrint = false;
    for (int i = n; i >= 0; i--) {
        if (HeSo[i] == 0.0) continue;   // bỏ số hạng hệ số 0

        // Dấu
        if (daPrint)
            cout << (HeSo[i] > 0 ? " + " : " - ");
        else if (HeSo[i] < 0)
            cout << "-";

        double hs = abs(HeSo[i]);

        if (i == 0)          cout << hs;
        else if (i == 1)     cout << hs << "x";
        else                 cout << hs << "x^" << i;

        daPrint = true;
    }
    if (!daPrint) cout << "0";   // đa thức không (mọi hệ số = 0)
    cout << "\n";
}

// Tính Giá Trị
double cDaThuc::TinhGiaTri(double x) {
    double ketQua = 0;
    for (int i = n; i >= 0; i--) {
        ketQua = ketQua * x + HeSo[i];
    }
    return ketQua;
}

// CongDaThuc
cDaThuc cDaThuc::CongDaThuc(const cDaThuc& dt) {
    int bacLon = max(n, dt.n);
    cDaThuc ketQua(bacLon);

    for (int i = 0; i <= n; i++)
        ketQua.HeSo[i] += HeSo[i];

    for (int i = 0; i <= dt.n; i++)
        ketQua.HeSo[i] += dt.HeSo[i];

        // Cắt bỏ các bậc cao nhất nếu hệ số của nó bằng 0 (áp dụng chuẩn sai số 1e-9)
    while (ketQua.n > 0 && abs(ketQua.HeSo[ketQua.n]) < 1e-9) {
        ketQua.n--;
    }
    return ketQua;
}

//TruDaThuc 
cDaThuc cDaThuc::TruDaThuc(const cDaThuc& dt) {
    int bacLon = max(n, dt.n);
    cDaThuc ketQua(bacLon);

    for (int i = 0; i <= n; i++)
        ketQua.HeSo[i] += HeSo[i];

    for (int i = 0; i <= dt.n; i++)
        ketQua.HeSo[i] -= dt.HeSo[i];

    // Cắt bỏ các bậc cao nhất nếu hệ số của nó bằng 0 (áp dụng chuẩn sai số 1e-9)
    while (ketQua.n > 0 && abs(ketQua.HeSo[ketQua.n]) < 1e-9) {
        ketQua.n--;
    }
    return ketQua;
}