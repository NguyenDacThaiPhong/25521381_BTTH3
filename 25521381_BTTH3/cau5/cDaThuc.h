#pragma once

class cDaThuc {
    private:
        int n;           // bậc của đa thức
        double* HeSo;    // mảng hệ số động, kích thước n+1
    public:
        cDaThuc();                          // constructor mặc định 
        cDaThuc(int bac);                   // constructor khởi tạo đa thức bậc n
        ~cDaThuc();                         // destructor 
        void Nhap();                        // nhập 
        void Xuat() const;                  // xuất 
        double TinhGiaTri(double x);        // tính giá trị đa thức tại x
        cDaThuc CongDaThuc(const cDaThuc& dt);  // cộng hai đa thức
        cDaThuc TruDaThuc(const cDaThuc& dt);   // trừ hai đa thức
        cDaThuc(const cDaThuc& other);           // copy constructor - deep copy tránh double free
        cDaThuc& operator=(const cDaThuc& other); // copy assignment - kiểm tra tự gán, deep copy
};