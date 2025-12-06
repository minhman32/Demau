

#include <iostream>
using namespace std;
int main()
{
    int n;
    do {
        cout << "Nhap n: ";
        cin >> n;
    } while (n <= 0 || n >= 50); //kiểm tra điều kiện nhâp
    int t = 0;//PHẢI GÁN GIÁ TRỊ BAN ĐẦU CHO BIẾN IN KẾT QUẢ,kq ban đầu(với tổng)=0
  //Nếu ko gán giá trị thì máy sẽ cho biến 1 giá trị ngẫu nhiên=>chạy sai
    float k = 0.0; //gán k (float)=0.0(float) để máy hiểu giá trị ban đầu bằng float
    for (int i = 1; i <= n; i++) {
        t += i;
        k += 1.0 / i;//vì kiểu dữ liệu k là float nên phép tính với 1 số bất kỳ là float thì mới cho kết quả là float
  
    };
    cout << "\nS= ";
    cout << "\nK= ";
}
