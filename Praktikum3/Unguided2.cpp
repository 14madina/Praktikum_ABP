#include <iostream>
using namespace std;

class Node {
public:
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;
        
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        
        head = newNode;
    }

    void insertAfter(string namaProduk, int harga, string prevNama) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk == prevNama) {
                Node* newNode = new Node;
                newNode->namaProduk = namaProduk;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;
                
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Produk sebelumnya tidak ditemukan." << endl;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        
        Node* temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        
        delete temp;
    }

    bool update(string namaProduk, int harga) {
        Node* current = head;
        
        while (current != nullptr) {
            if (current->namaProduk == namaProduk) {
                current->harga = harga;
                return true;
            }
            current = current->next;
        }
        
        return false;
    }

    bool deleteByName(string namaProduk) {
        Node* current = head;
        
        while (current != nullptr) {
            if (current->namaProduk == namaProduk) {
                if (current == head) {
                    pop();
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete current;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                return true;
            }
            current = current->next;
        }
        
        return false;
    }

    void deleteAll() {
        Node* current = head;
        
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        cout << "Nama Produk\tHarga" << endl;
        Node* current = head;
        
        while (current != nullptr) {
            cout << current->namaProduk << "\t\t" << current->harga << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList list;
    
    list.push("Originote", 60000);
    list.push("Somethinc", 150000);
    list.push("Skintific", 100000);
    list.push("Wardah",  50000);
    list.push("Hanasui", 30000);
    
    while (true) {
        cout << "2311102243_SITI MADINA HALIM SIREGAR_S1 IF-11-G" << endl;
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        
        int choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string namaProduk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin.ignore();
                getline(cin, namaProduk);
                cout << "Masukkan harga produk: ";
                cin >> harga;
                list.push(namaProduk, harga);
                break;
            }
            case 2: {
                string namaProduk;
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin.ignore();
                getline(cin, namaProduk);
                bool deleted = list.deleteByName(namaProduk);
                if (!deleted) {
                    cout << "Produk tidak ditemukan" << endl;
                }
                break;
            }
            case 3: {
                string namaProduk;
                int harga;
                cout << "Masukkan nama produk yang akan diupdate: ";
                cin.ignore();
                getline(cin, namaProduk);
                cout << "Masukkan harga baru: ";
                cin >> harga;
                bool updated = list.update(namaProduk, harga);
                if (!updated) {
                    cout << "Produk tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string namaProduk, prevNama;
                int harga;
                cout << "Masukkan nama produk yang akan ditambahkan: ";
                cin.ignore();
                getline(cin, namaProduk);
                cout << "Masukkan harga produk: ";
                cin >> harga;
                cout << "Masukkan nama produk sebelumnya: ";
                cin.ignore();
                getline(cin, prevNama);
                list.insertAfter(namaProduk, harga, prevNama);
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }
    
    return 0;
}
