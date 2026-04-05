#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR

// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return head == NULL;
}

// Tambah Node di depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Node di belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung jumlah Node dalam list
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    
    return jumlah;
}

// Tambah Node di posisi tertentu
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        
        bantu = head;
        int nomor = 1;
        
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di depan
void hapusDepan() {
    Node *hapus;
    
    if (!isEmpty()) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
        } else {
            delete hapus;
            head = tail = NULL;
            return;
        }
    } else {
        cout << "List kosong!" << endl;
        return;
    }
    
    delete hapus;
}

// Hapus Node di belakang
void hapusBelakang() {
    Node *hapus, *bantu;
    
    if (!isEmpty()) {
        if (head != tail) {
            hapus = tail;
            bantu = head;
            
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            
            tail = bantu;
            tail->next = NULL;
        } else {
            delete hapus;
            head = tail = NULL;
            return;
        }
    } else {
        cout << "List kosong!" << endl;
        return;
    }
    
    delete hapus;
}

// Hapus Node pada posisi tertentu
void hapusTengah(int posisi) {
    Node *bantu, *hapus, *sebelum;
    
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        
        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                sebelum = bantu;
            }
            if (nomor == posisi) {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah data Node di depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node pada posisi tertentu
void ubahTengah(int data, int posisi) {
    Node *bantu;
    
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node di belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus seluruh Node dalam list
void clearList() {
    Node *bantu, *hapus;
    bantu = head;
    
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan isi list
void tampil() {
    Node *bantu = head;
    
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    
    // Bagian kedua kode (Linked List Circular) tidak dimodifikasi karena tidak diminta.
    
    return 0;
}
