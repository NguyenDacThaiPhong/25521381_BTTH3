#pragma once

class Array {
    private:
        int n;       // Số lượng phần tử
        int* arr;    // Con trỏ quản lý mảng động

    public:
        Array(); //hàm khởi tạo mặc định
        Array(int kichthuoc); // hàm khởi tạo chứa biến
        ~Array(); // hàm hủy

        void TaoMangNgauNhien(); // tạo mảng ngẫu nhiên
        void Nhap(); // nhập
        void Xuat(); // xuất
        
        int SoLanXuatHien(int x); //số lần xuất hiện của số x
        bool KiemTraTangDan(); //kiểm tra tăng dần
        int PhanLeNhoNhat(); // phần tử lẻ nhỏ nhất
        int SoNguyenToLonNhat(); // số nguyên tố lớn nhất
        void TangDan(); // tăng dần
        void GiamDan(); // giảm dần
};