#include <iostream>

using namespace std;
//2311102243_SITI MADINA HALIM SIREGAR_S1 IF-11-G
int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Nomor Genap:" << endl;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil:" << endl;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}