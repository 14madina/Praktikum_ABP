#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktur data untuk setiap mahasiswa
struct Mahasiswa {
    string nim;
    int nilai;
    Mahasiswa* next;
    Mahasiswa(string nim, int nilai) : nim(nim), nilai(nilai), next(nullptr) {}
};

// Class hash table
class HashMap {
private:
    static const int TABLE_SIZE = 10;
    vector<Mahasiswa*> table;

public:
    HashMap() : table(TABLE_SIZE, nullptr) {}

    // Fungsi hash untuk mengonversi NIM menjadi indeks
    int hashFunc(string nim) {
        int hash_val = 0;
        for (char c : nim) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Menambahkan data mahasiswa baru ke dalam hash table
    void insert(string nim, int nilai) {
        int index = hashFunc(nim);
        Mahasiswa* mahasiswa = new Mahasiswa(nim, nilai);
        if (table[index] == nullptr) {
            table[index] = mahasiswa;
        } else {
            Mahasiswa* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = mahasiswa;
        }
    }

    // Menghapus data mahasiswa berdasarkan NIM
    void remove(string nim) {
        int index = hashFunc(nim);
        Mahasiswa* current = table[index];
        Mahasiswa* prev = nullptr;
        while (current != nullptr) {
            if (current->nim == nim) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Mencari data mahasiswa berdasarkan NIM
    Mahasiswa* searchByNIM(string nim) {
        int index = hashFunc(nim);
        Mahasiswa* current = table[index];
        while (current != nullptr) {
            if (current->nim == nim) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Mencari data mahasiswa berdasarkan rentang nilai (80-90)
    void searchByScoreRange() {
        cout << "Data mahasiswa dengan nilai antara 80-90:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Mahasiswa* current = table[i];
            while (current != nullptr) {
                if (current->nilai >= 80 && current->nilai <= 90) {
                    cout << "NIM: " << current->nim << ", Nilai: " << current->nilai << endl;
                }
                current = current->next;
            }
        }
    }
};

int main() {
    HashMap mahasiswa_map;

    // Menu
    char choice;
    do {
        cout << "<< 2311102243_SITI MADINAH HALIM SIREGAR_S1 IF-11-G >>\n";
        cout << "Menu:\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Cari data mahasiswa berdasarkan NIM\n";
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80-90)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string nim;
                int nilai;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                mahasiswa_map.insert(nim, nilai);
                break;
            }
            case '2': {
                string nim;
                cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
                cin >> nim;
                mahasiswa_map.remove(nim);
                break;
            }
            case '3': {
                string nim;
                cout << "Masukkan NIM mahasiswa yang akan dicari: ";
                cin >> nim;
                Mahasiswa* mahasiswa = mahasiswa_map.searchByNIM(nim);
                if (mahasiswa != nullptr) {
                    cout << "Data mahasiswa ditemukan:\n";
                    cout << "NIM: " << mahasiswa->nim << ", Nilai: " << mahasiswa->nilai << endl;
                } else {
                    cout << "Data mahasiswa tidak ditemukan.\n";
                }
                break;
            }
            case '4':
                mahasiswa_map.searchByScoreRange();
                break;
            case '5':
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != '5');

    return 0;
}
