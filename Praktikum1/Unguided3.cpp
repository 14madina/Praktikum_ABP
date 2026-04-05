#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> Hewan;

    Hewan["Ayam"] = 4;
    Hewan["Bebek"] = 5;
    Hewan["Kucing"] = 10;

    cout << "2311102243_SITI MADINA HALIM SIREGAR" <<endl;

    cout << "Jumlah Bebek:" << Hewan["Bebek"] <<endl;

    cout << "Semua elemen dalam Hewan:" <<endl;
    for (const auto & pair : Hewan) {
        cout << pair.first <<":" << pair.second <<endl;
    }

    return 0;
}