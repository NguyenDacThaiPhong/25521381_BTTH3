#include <bits/stdc++.h>
#include "Array.h"
using namespace std;

//Hàm Hủy
Array::~Array() {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}

// Khởi tạo mặc định (Mảng rỗng)
Array::Array() {
    n = 0;
    arr = nullptr;
}

// khởi tạo có tham số
Array::Array(int kichthuoc) {
    if (kichthuoc < 0) {
        arr = nullptr;
        n = 0;
    } else {
        n = kichthuoc;
        arr = new int[n];
    }
}

// hàm nhập
void Array::Nhap() {
    cout << "Nhap so phan tu: ";
    cin >> n;

    if (arr != nullptr) {
        delete[] arr;  //dọn dẹp mảng cũ nếu có
    }

    arr = new int[n];
    cout << "Nhap cac phan tu cua mang: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// hàm xuất
void Array::Xuat() {
    if (n == 0 || arr == nullptr) {  // kiểm tra rổng
        cout << "Mang rong";
        return;
    } else {
        for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        }
        cout << endl;
    }
}


// tạo mảng ngẫu nhiên
void Array::TaoMangNgauNhien() { 
    if (n <= 0) {
        cout << "Chua nhap so phan tu" << endl;
        return;
    }

    // Cấp phát lại mảng với cùng kích thước n
    if (arr != nullptr) delete[] arr;
    arr = new int[n];

    srand(time(0));  
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // random mảng từ 0-99 với kích thước n
    }
}

// giảm dần mảng
void Array::GiamDan() {  //selection sort
    for (int i = 0; i < n-1; i++) {
        int maxIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }
        swap(arr[i], arr[maxIndex]);
    }

}

//tăng dần mảng
void Array::TangDan() {  //insertion sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//kiểm tra mảng tăng dần
bool Array::KiemTraTangDan() {
    if (arr == nullptr || n == 0) return false;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) return false;
    }
    return true;
}

// số lần xuất hiện của số x
int Array::SoLanXuatHien(int x) {
    if (arr == nullptr || n == 0) return 0;
    int count = 0;
    for (int i = 0; i < n; i++ ) {
        if (arr[i] == x) count++;
    }
    return count;
}

// tìm số lẻ nhỏ nhất
int Array::PhanLeNhoNhat() {
    int minLe = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0 && arr[i] < minLe)
            minLe = arr[i];
    }
    return minLe; // Trả về INT_MAX nếu không có phần tử lẻ
}

//số nguyên tố lớn nhất
int Array::SoNguyenToLonNhat() {
    int maxPrime = -1;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        if (x < 2) continue; //số bé hơn 2 không phải số nguyên tố
        
        bool isPrime = true; //giả sử mọi số đều là số nguyên tố
        
        for (int j = 2; j * j <= x; j++) {  // kiểm tra số nguyên tố
            if (x % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime && x > maxPrime) maxPrime = x;
    }
    return maxPrime;
}