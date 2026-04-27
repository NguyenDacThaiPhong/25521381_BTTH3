#pragma once

class NgayThangNam {
private:
    int ngay;   // ngày
    int thang;  // tháng
    int nam;    // năm

public:
    
    NgayThangNam(); 
    // Constructor mặc định

    NgayThangNam(int ngay, int thang, int nam); 
    // Constructor có tham số để khởi tạo ngày/tháng/năm

   
    int getNgay()  const;  
    // Lấy giá trị ngày

    int getThang() const;  
    // Lấy giá trị tháng

    int getNam()   const;  
    // Lấy giá trị năm

    void setNgay(int ngay); 
    // Gán giá trị mới cho ngày

    void setThang(int thang); 
    // Gán giá trị mới cho tháng

    void setNam(int nam); 
    // Gán giá trị mới cho năm

    
    int Tuoi(int namHienTai) const;   
    // Tính tuổi dựa trên năm hiện tại

    void Nhap(); 
    // Nhập ngày/tháng/năm từ bàn phím

    void Xuat() const; 
    // Xuất ngày/tháng/năm ra màn hình
};