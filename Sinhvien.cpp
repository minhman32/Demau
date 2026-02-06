#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct SinhVien {
    string hoten;
    string masv;
    float dtb;
};

void NhapSV(SinhVien& sv) {
    do {
        cout << "\n Nhap ho ten: ";
        getline(cin, sv.hoten);
    } while (sv.hoten.length() <= 0 || sv.hoten.length() > 31);
    do {
        cout << "\n Nhap ma hoc sinh: ";
        getline(cin, sv.masv);
    } while (sv.masv.length() != 5);
    do {
        cout << "\n Diem trung binh: ";
        cin >> sv.dtb;
    } while (sv.dtb < 0 || sv.dtb > 10);
    cin.ignore();
}

void Nhap(SinhVien lop[], int& n) {
    cout << "Nhap so sv: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << ": ";
        NhapSV(lop[i]);
        cin.ignore();
    }
}

void XuatSV(SinhVien sv) {
    cout << setw(18) << left << sv.masv
        << setw(29) << left << sv.hoten
        << setw(10) << sv.dtb << endl;
}

void Xuat(SinhVien lop[], int n) {
    cout << "\n";
    cout << setw(18) << left << "Ma so sinh vien "
        << setw(29) << left << "Ho ten hoc sinh"
        << setw(10) << "Diem trung binh" << endl;
    for (int i = 0; i < n; i++)
    {
        //cout << "\n Hoc sinh thu " << i + 1;
        XuatSV(lop[i]);
    }
}

void Tim(SinhVien lop[], int n) {
    string x;
    do {
        cout << "\n Nhap ma hoc sinh can tim: ";
        getline(cin, x);
    } while (x.length() != 5);
    int t = -1;
    for (int i = 0; i < n; i++) {
        if (lop[i].masv == x) {
            t = i;
            break;
        }
    }
    if (t != -1) {
        cout << "Tim thay mssv, thong tin sv: ";
        XuatSV(lop[t]);
    }
    else cout << "Khong tim thay";
}

void Timcolc(SinhVien lop[], int n) {
    string x;
    do {
        cout << "\nNhap ma hoc sinh can tim: ";
        getline(cin, x);
    } while (x.length() != 5);
    int t = 0;
    lop[n].masv = x;
    while (lop[t].masv != x) {
        t++;
    }
    if (t < n) {
        cout << "Tim thay ma so, Thong tin be: ";
        XuatSV(lop[t]);
    }
    else cout << "Ko tim thay";
}

void Timkiemnhiphan(SinhVien lop[], int n) {
    int l = 0, r = n - 1, m = (l + r) / 2;
    cin.ignore();
    string x;
    do {
        cout << "\n Nhap ma nhan vien can tim: ";
        getline(cin, x);
    } while (x.length() != 5);
    while (l <= r && lop[m].masv != x) {
        if (lop[m].masv > x) r = m - 1;
        else l = m + 1;
        m = (l + r) / 2;
    }
    if (l > r) cout << "Khong tim thay";
    else {
        cout << "Tim thay ma so, thong tin: ";
        XuatSV(lop[m]);
    }
}

void LCTK(SinhVien lop[], int n) {
    int lc;
    do {
        cout << "\n ===========================";
        cout << "\n Nhap '1': Tim kiem tuan tu khong linh canh";
        cout << "\n Nhap '2': Tim kiem tuan tu co linh canh";
        cout << "\n Nhap '3': Tim kiem nhi phan (voi danh sach da duoc sap xep)";
        cout << "\n Nhap '4': Ket thuc tim kiem, quay lai Menu";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> lc;
        cin.ignore();
        switch (lc) {
        case 1: Tim(lop, n); break;
        case 2: Timcolc(lop, n); break;
        case 3: Timkiemnhiphan(lop, n); break;
        case 4: cout << "Quay lai Menu!\n"; break;
        default: cout << "Lua chon khong hop le!\n";
        }
    } while (lc != 4);
}

void DTBmax(SinhVien lop[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (lop[i].dtb > lop[max].dtb) max = i;
    }
    cout << "\nSinh vien co diem trung binh cao nhat: ";
    XuatSV(lop[max]);
}

void menu() {
    cout << "\n ----------MENU----------\n";
    cout << "-2. Nhap danh sach sinh vien\n";
    cout << "-1. Auto danh sach sinh vien\n";
    cout << "1. Xuat danh sach sinh vien\n";
    cout << "2. Tim sinh vien theo maSV\n";
    cout << "3. Tim sinh vien co DTB lon nhat\n";
    cout << "4. Bo sung them sinh vien\n";
    cout << "5. Xoa sinh vien\n";
    cout << "6. Selection Sort\n";
    cout << "7. Interchange Sort\n";
    cout << "8. Bubble Sort( Tu cuoi day )\n";
    cout << "9. Bubble Sort( Tu dau day )\n";
    cout << "10. InsertionSort\n";
    cout << "11. ShakerSort\n";
    cout << "12. QuickSort\n";
    cout << "13. QuickSort\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

void Autonhap(SinhVien lop[], int& n) {
    n = 5;
    lop[0] = { "Pham Thi B","00001",9.5 };
    lop[1] = { "Pham Thi D","00005",8.5 };
    lop[2] = { "Pham Thi A","00004",8.6 };
    lop[3] = { "Pham Thi C","00003",8.3 };
    lop[4] = { "Pham Thi E","00002",8.2 };
    Xuat(lop, n);
}

void Bosung(SinhVien lop[], int& n) {
    int a;
    cout << "\n Nhap so nhan vien can bo sung vao danh sach: ";
    cin >> a;
    for (int i = n; i < n + a; i++) {
        cout << "\n Nhan vien thu " << i + 1;
        NhapSV(lop[i]);
        cin.ignore();
    }
    n += a;
}

void Xoa(SinhVien lop[], int& n) {
    int a;
    do {
        cout << "\n Nhap stt sinh vien can xoa thong tin (bat dau tu 1): ";
        cin >> a;
        if (a > n) cout << "\n Vi tri xoa khong hop le, bat dau tu 1 den " << n;
    } while (a > n || a <= 0);
    a--;
    for (int i = a; i < n - 1; i++) {
        lop[i] = lop[i + 1];
    }
    n--;
}
void swap(SinhVien& a, SinhVien& b) {
    SinhVien i;
    i = a;
    a = b;
    b = i;
}
void SelectionSort(SinhVien lop[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (lop[j].masv < lop[min].masv)
                min = j;
        swap(lop[i], lop[min]);
    }
    cout << "\nDanh sach sau sap xep";
    Xuat(lop, n);
}
void InterchangeSort(SinhVien lop[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++)
            if (lop[i].masv > lop[j].masv)
                swap(lop[i], lop[j]);
    }
    cout << "\nDanh sach sau sap xep";
    Xuat(lop, n);
}
void BubbleSort(SinhVien lop[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--)
            if (lop[j].masv < lop[j - 1].masv)
                swap(lop[j], lop[j - 1]);
    }
    cout << "\nDanh sach sau sap xep";
    Xuat(lop, n);
}
void BubbleSortTuDauDay(SinhVien lop[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++)
            if (lop[j].masv > lop[j + 1].masv)
                swap(lop[j], lop[j + 1]);
    }
    cout << "\nDanh sach sau sap xep";
    Xuat(lop, n);
}
void InsertionSort(SinhVien lop[], int n) {
    int pos; string x; SinhVien a;
    for (int i = 1; i < n; i++) {
        a = lop[i];
        x = lop[i].masv; pos = i - 1;
        while ((pos >= 0) && lop[pos].masv > x) {
            lop[pos + 1] = lop[pos];
            pos--;
        }
        lop[pos + 1].masv = x;
        lop[pos + 1] = a;
    }
    cout << "\nDanh sach sau sap xep";
    Xuat(lop, n);
}
void ShakerSort(SinhVien lop[], int n) {
    int l = 0; int r = n - 1; int k = n - 1;
    while (l < r) {
        for (int i = r; i > l; i--)
            if (lop[i - 1].masv > lop[i].masv) {
                swap(lop[i - 1], lop[i]); k = i;
            } l = k;
        for (int j = l; j < r; j++)
            if (lop[j].masv > lop[j + 1].masv)
            {
                swap(lop[j], lop[j + 1]); k = j;
            } r = k;
    }  cout << "\nDanh sach sau sap xep";
    Xuat(lop, n);
}
void QuickSort(SinhVien lop[], int l, int r) {
    int i = l, j = r;
    string m = lop[(l + r) / 2].masv;
    do {
        while (lop[i].masv < m)
            i++;

        while (lop[j].masv > m)
            j--;

        if (i <= j) {

            swap(lop[i], lop[j]); i++; j--;
        }
    } while (i < j);
    if (l < j) QuickSort(lop, l, j);
    if (i < r) QuickSort(lop, i, r);
    cout << "\nDanh sach sau sap xep";
}
void merge(SinhVien arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    SinhVien L[1000], R[1000];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].masv <= R[j].masv) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(SinhVien arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int t = 0, chon;
    SinhVien lop[30];
    do {
        menu();
        cin >> chon;
        cin.ignore();
        switch (chon) {
        case -2: Nhap(lop, t); break;
        case -1: Autonhap(lop, t); break;
        case 1: Xuat(lop, t); break;
        case 2: LCTK(lop, t); break;
        case 3: DTBmax(lop, t); break;
        case 4: Bosung(lop, t); break;
        case 5: Xoa(lop, t); break;
        case 6: SelectionSort(lop, t); break;
        case 7: InterchangeSort(lop, t); break;
        case 8: BubbleSort(lop, t); break;
        case 9: BubbleSortTuDauDay(lop, t); break;
        case 10: InsertionSort(lop, t); break;
        case 11: ShakerSort(lop, t); break;
        case 12: { QuickSort(lop, 0, t - 1);  Xuat(lop, t);  break; }
        case 13: { mergeSort(lop, 0, t - 1);  cout << "\nDanh sach sau sap xep"; Xuat(lop, t);  break; }
        case 0: cout << "Thoat chuong trinh!!!\n"; break;
        default: cout << "Lua chon khong hop le!!!\n";
        }
    } while (chon != 0);
    return 0;
}
