#include <iostream>

using namespace std;

int main() {
    int n;
    
    cout << "2311102243_SITIMADINA HALIM SIREGAR_S1 IF-11-G" << endl;

    cout << "Masukkan Ukuran Array: ";
    cin >> n;

    int arr[n];

    cout << "Masukkan Eleman Array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int max = arr[0];
    int min = arr[0];
    float Jumlah = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        Jumlah += arr[i];
    }

    float Rata_Rata = Jumlah / n;

    cout << "Nilai Maksimum: " << max << endl;
    cout << "Nilai Minimum: " << min << endl;
    cout << "Nilai Rata-Rata: " << Rata_Rata << endl;

    return 0;
}