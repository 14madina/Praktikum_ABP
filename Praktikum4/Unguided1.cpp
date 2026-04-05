#include <iostream>
#include <string>

using namespace std;
//2311102243_SITI MADINAH HALIM SIREGAR_SI IF-11-G
struct Node {
    string nama;
    string nim;
    Node *next;
};

Node *head = NULL;

void tambahDepan(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = head;
    head = baru;
}

void tambahBelakang(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    
    if (head == NULL) {
        head = baru;
    } else {
        Node *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = baru;
    }
}

void tambahTengah(string nama, string nim, int posisi) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    
    if (posisi == 1) {
        baru->next = head;
        head = baru;
    } else {
        Node *bantu = head;
        for (int i = 1; i < posisi - 1 && bantu != NULL; ++i) {
            bantu = bantu->next;
        }
        if (bantu != NULL) {
            baru->next = bantu->next;
            bantu->next = baru;
        } else {
            cout << "Posisi tidak valid." << endl;
        }
    }
}

void ubahDepan(string namaBaru, string nimBaru) {
    if (head != NULL) {
        head->nama = namaBaru;
        head->nim = nimBaru;
        cout << "Data (nama lama) telah diganti dengan data (nama baru)" << endl;
    } else {
        cout << "List kosong." << endl;
    }
}

void ubahBelakang(string namaBaru, string nimBaru) {
    if (head != NULL) {
        Node *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->nama = namaBaru;
        tail->nim = nimBaru;
        cout << "Data (nama lama) telah diganti dengan data (nama baru)" << endl;
    } else {
        cout << "List kosong." << endl;
    }
}

void ubahTengah(string namaBaru, string nimBaru, int posisi) {
    if (head != NULL) {
        Node *bantu = head;
        for (int i = 1; i < posisi && bantu != NULL; ++i) {
            bantu = bantu->next;
        }
        if (bantu != NULL) {
            bantu->nama = namaBaru;
            bantu->nim = nimBaru;
            cout << "Data (nama lama) telah diganti dengan data (nama baru)" << endl;
        } else {
            cout << "Posisi tidak valid." << endl;
        }
    } else {
        cout << "List kosong." << endl;
    }
}

void hapusDepan() {
    if (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Data pertama berhasil dihapus" << endl;
    } else {
        cout << "List kosong." << endl;
    }
}

void hapusBelakang() {
    if (head != NULL) {
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node *prev = NULL;
            Node *tail = head;
            while (tail->next != NULL) {
                prev = tail;
                tail = tail->next;
            }
            prev->next = NULL;
            delete tail;
        }
        cout << "Data terakhir berhasil dihapus" << endl;
    } else {
        cout << "List kosong." << endl;
    }
}

void hapusTengah(int posisi) {
    if (head != NULL) {
        if (posisi == 1) {
            hapusDepan();
        } else {
            Node *prev = NULL;
            Node *hapus = head;
            for (int i = 1; i < posisi && hapus != NULL; ++i) {
                prev = hapus;
                hapus = hapus->next;
            }
            if (hapus != NULL) {
                prev->next = hapus->next;
                delete hapus;
                cout << "Data pada posisi " << posisi << " berhasil dihapus" << endl;
            } else {
                cout << "Posisi tidak valid." << endl;
            }
        }
    } else {
        cout << "List kosong." << endl;
    }
}

void hapusList() {
    Node *bantu = head;
    while (head != NULL) {
        bantu = head;
        head = head->next;
        delete bantu;
    }
    cout << "Seluruh data berhasil dihapus" << endl;
}

void tampilkanData() {
    cout << "DATA MAHASISWA" << endl;
    cout << "NAMA\tNIM" << endl;
    Node *bantu = head;
    while (bantu != NULL) {
        cout << bantu->nama << "\t" << bantu->nim << endl;
        bantu = bantu->next;
    }
}

int main() {
    int pilihan;
    string nama, nim;
    int posisi;
    do {
        cout << endl << endl;
        cout << "2311102243_SITI MADINAH HALIM SIREGAR_S1 IF-11-G" << endl;
        cout << " " << endl;
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan " << endl;
        cout << "2. Tambah Belakang " << endl;
        cout << "3. Tambah Tengah " << endl;
        cout << "4. Ubah Depan " << endl;
        cout << "5. Ubah Belakang " << endl;
        cout << "6. Ubah Tengah " << endl;
        cout << "7. Hapus Depan " << endl;
        cout << "8. Hapus Belakang " << endl;
        cout << "9. Hapus Tengah " << endl;
        cout << "10. Hapus List " << endl;
        cout << "11. TAMPILKAN " << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                tambahDepan(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                tambahTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahDepan(nama, nim);
                cout << "Data (nama lama) telah diganti dengan data (nama baru)";
                break;
            case 5:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahBelakang(nama, nim);
                cout << "Data (nama lama) telah diganti dengan data (nama baru)";
                break;
            case 6:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : " ;
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                ubahTengah(nama, nim, posisi);
                cout << "Data (nama lama) telah diganti dengan data (nama baru)";
                break;
            case 7:
                hapusDepan();
                break;
            case 8:
                hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                hapusTengah(posisi);
                break;
            case 10:
                hapusList();
                break;
            case 11:
                tampilkanData();
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);
    return 0;
}
