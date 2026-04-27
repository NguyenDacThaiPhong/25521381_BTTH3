#include <bits/stdc++.h>
#include "Array.h"

using namespace std;

int main() {
    Array arr;

    //  Nhập và Xuất
    arr.Nhap();
    cout << "Mang vua nhap: ";
    arr.Xuat();

    //  số lần xuất hiện của x
    int x;
    cout << "Nhap so x can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " la: " << arr.SoLanXuatHien(x) << " lan." << endl;

    //  Phần tử lẻ nhỏ nhất 
    int minLe = arr.PhanLeNhoNhat();
    if (minLe == INT_MAX) {
        cout << "Mang khong co phan tu le nao." << endl;
    } else {
        cout << "Phan tu le nho nhat tim duoc: " << minLe << endl;
    }

    // số nguyên tố lớn nhất
    int maxPrime = arr.SoNguyenToLonNhat();
    if (maxPrime == -1) {
        cout << "Mang khong co so nguyen to nao." << endl;
    } else {
        cout << "So nguyen to lon nhat tim duoc: " << maxPrime << endl;
    }

    //  tăng dần và giảm dần
    if (arr.KiemTraTangDan()) {
        cout << "Hien tai: Mang dang tang dan." << endl;
    } else {
        cout << "Hien tai: Mang CHUA tang dan." << endl;
        cout << "Tien hanh sap xep Tang Dan (Insertion Sort):" << endl;
        arr.TangDan();
        arr.Xuat();
    }

    cout << "\nTien hanh sap xep Giam Dan (Selection Sort):" << endl;
    arr.GiamDan();
    arr.Xuat();

    // Tạo mảng ngẫu nhiên
    cout << "Tao mang ngau nhien gom n phan tu (0-99):" << endl;
    arr.TaoMangNgauNhien();
    arr.Xuat();

    return 0;
}