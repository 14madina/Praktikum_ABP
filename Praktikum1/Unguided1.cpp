#include <iostream>

using namespace std;
//2311102243_SITI MADINA HALIM SIREGAR
const double phi = 3.14; 

float hitungluas(float r) {
    return phi * r * r;
}

float hitungkeliling(float r) {
    return 2 * phi * r;
}

int main() {
    float r_2311102243;

    cout << "Input jari-jari: ";
    cin >> r_2311102243;

    float Luas = hitungluas(r_2311102243);
    float Keliling = hitungkeliling(r_2311102243);

    cout << "Luas Lingkaran: " << Luas << endl;
    cout << "Keliling Lingkaran: " << Keliling << endl;

    return 0;
}