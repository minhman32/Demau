#include <iostream>   
using namespace std;

// Hàm đệ quy đổi số thập phân sang nhị phân, hàm nhận vào 1 số nguyên và in ra dạng nhị phân của nó nên sài void 
void NP(int n) {
    if (n > 1) {          // Nếu n > 1 thì tiếp tục chia cho 2
        NP(n / 2);        // Gọi lại hàm NP với n/2 (đệ quy)
    }
    cout << n % 2;        // In ra phần dư 
}
// Vì đệ quy gọi trước rồi mới in =>in kq tuần từ từ cuối lên đầu

int main()
{
    int n;
    do {
        cout << "Nhap n: ";
        cin >> n;
    } while (n <= 0 || n >= 100);

    cout << "So " << n << " khi doi sang he nhi phan la: ";
    NP(n);   // Gọi hàm đổi sang nhị phân
}
