#include <iostream>
#include <string>

using namespace std;
struct MtH {
	char Th[41];
	char mh[12];
	int sl;
	float dg;
};
void Nhap(MtH& mh) {
	cout << "\nNhap ten hang: ";
	cin.getline(mh.Th, 41);
	cout << "\nNhap ma hang: ";
	cin.getline(mh.mh, 12);
	cout << "\nNhap so luong: ";
	cin >> mh.sl;
	cout << "\nNhap don gia: ";
	cin >> mh.dg;
};
void Nhapn(MtH a[], int& n) {
	cout << "Nhap so luong n=";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin mat hang thu " << i + 1;
		Nhap(a[i]);
		cin.ignore();
	}
};
void Xuat(MtH a[], int n) {
	cout << "\n================================\n";
	for (int i = 0; i < n; i++) {
		cout << "\nThong tin mat hang thu " << i + 1;
		cout << "\nTen hang: ";
		cout << a[i].Th;
		cout << "\nMa hang: ";
		cout << a[i].mh;
		cout << "\nso luong: ";
		cout << a[i].sl;
		cout << "\ndon gia: ";
		cout << a[i].dg;
		cout << "\nTri gia don hang: " << a[i].sl * a[i].dg;
		cout << "\n--------------------------";
	}
};
void Them(MtH a[], int& n, char b[])
{
	cout << "\n=======================================";
	cout << "\nnhap ma so hang can them:";
	cin.getline(b, 12);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(b, a[i].mh) == 0) {
			cout << "\nMa so hang da ton tai, khong the them"; return;
		}
	}
	cout << "\nNhap ten hang: ";
	cin.getline(a[n].Th, 41);
	for (int i = 0; i < strlen(b) + 1; i++) a[n].mh[i] = b[i];
	cout << "\nNhap so luong: ";
	cin >> a[n].sl;
	cout << "\nNhap don gia: ";
	cin >> a[n].dg;
	n++;
	cin.ignore();
}
void Tim(MtH a[], int n, char x[])
{
	cout << "\n=======================================";
	cout << "\nnhap ma so hang can tim:";
	int b = 0, vt[30];
	cin.getline(x, 12);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(x, a[i].mh) == 0) {
			vt[b] = i + 1;
			b++;
		}
	}
	if (b == 0) cout << "\nKhong co ma so can tim trong danh sach";
	else {
		cout << "\nMa so xuat hien " << b << " lan";
		cout << "\nTai vi tri ";
		for (int i = 0; i < b; i++)
		{
			cout << vt[i] << " ";
		}
		cout << "trong danh sach";

	}
}
float Trigia(MtH mh) {
	return mh.sl * mh.dg;
}
void Sapxep(MtH a[], int n) {
	MtH t;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (Trigia(a[j]) > Trigia(a[j - 1]))
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
		}
	}
	/*for (int i = 0; i < n - 1; i++) {          // vòng ngoài duyệt từ đầu
		for (int j = 0; j < n - i - 1; j++) {  // vòng trong cũng từ đầu
			if (a[j] > a[j + 1]) {             // nếu sai thứ tự thì hoán đổi
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}*/
}

int main()
{
	MtH a[100];
	int n;
	char x[12];
	char b[12];
	Nhapn(a, n);
	Xuat(a, n);
	Them(a, n, b);
	cout << "\nMang sau khi them:";
	Xuat(a, n);
	Tim(a, n, x);
	Sapxep(a, n);
	cout << "\nDANH SACH SAU SAP XEP THEO TRI GIA";
	Xuat(a, n);
}
