#include <iostream>
#include <string>

using namespace std;
struct Date {
    string hari;
    int bulan;
    int tahun;
};
class Mahasiswa {

        string nama;
        long long int nim;
        Date H;

    public:
        Mahasiswa(string nama, long long int nim, string hari, int bulan, int tahun) {
            this->nama = nama;
            this->nim = nim;
            H.hari = hari;
            H.bulan = bulan;
            H.tahun = tahun;
        }

        void displayInfo() {
            cout << "Nama: " << nama << endl;
            cout << "nim: " << nim << endl;
            cout << "tanggal lahir: " << H.hari << "/"<< H.bulan << "/" << H.tahun << endl;
        }

        
};

int main() {
    Mahasiswa pertama("SITI",2311102243,"SENIN", 3 , 2005 );
    cout << "Tampil Mahasiswa" << endl;
    pertama.displayInfo();

    return 0;
}