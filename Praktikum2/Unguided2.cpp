#include <iostream>

using namespace std;

int main() {
    int x, y, z;

    cout << "2311102243_SITI MADINA HALIM SIREGAR_S1 IF-11-G" << endl;

    cout << "Masukkan ukuran array tiga dimensi (x y z): ";
    cin >> x >> y >> z;

    int arr[x][y][z];

    cout << "Masukkan elemen-elemen array: " << endl;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cout << "arr[" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "Nilai dari setiap elemen array: " << endl;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cout << "arr[" << i << "][" << j << "][" << k << "]: " << arr[i][j][k] << endl;
            }
        }
    }

    return 0;
}