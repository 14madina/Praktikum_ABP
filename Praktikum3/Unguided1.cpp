#include <iostream>
using namespace std;
//2311102243_SITI MADINA HALIM SIREGAR_S1 IF-11-G
struct Node {
    string nama2311102243;
    int umur;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambahAwal(string nama2311102243, int umur) {
        Node* newNode = new Node;
        newNode->nama2311102243 = nama2311102243;
        newNode->umur = umur;
        newNode->next = head;
        head = newNode;
    }

    void tambahTengah(string nama2311102243, int umur, string namaSebelum) {
        Node* temp = head;
        while (temp != nullptr && temp->nama2311102243 != namaSebelum) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node dengan nama " << namaSebelum << " tidak ditemukan." << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->nama2311102243 = nama2311102243;
        newNode->umur = umur;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void tambahAkhir(string nama2311102243, int umur) {
        Node* newNode = new Node;
        newNode->nama2311102243 = nama2311102243;
        newNode->umur = umur;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void hapus(string nama2311102243) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        if (head->nama2311102243 == nama2311102243) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr && curr->nama2311102243 != nama2311102243) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Node dengan nama " << nama2311102243 << " tidak ditemukan." << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    void ubahData(string nama2311102243, string newNama, int newUmur) {
        Node* temp = head;
        while (temp != nullptr && temp->nama2311102243 != nama2311102243) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node dengan nama " << nama2311102243 << " tidak ditemukan." << endl;
            return;
        }
        temp->nama2311102243 = newNama;
        temp->umur = newUmur;
    }

    void tampilkanData() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama2311102243 << " " << temp->umur << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    linkedList.tambahAwal("Siti", 19); 
    linkedList.tambahAwal("Igor", 20);  
    linkedList.tambahAkhir("John", 19);
    linkedList.tambahAkhir("Jane", 20);
    linkedList.tambahAkhir("Michael", 18);
    linkedList.tambahAkhir("Yusuke", 19);
    linkedList.tambahAkhir("Akechi", 20);
    linkedList.tambahAkhir("Hoshino", 18);
    linkedList.tambahAkhir("Karin", 18);

    linkedList.hapus("Akechi");

    linkedList.ubahData("Michael", "Reyn", 18);

    linkedList.tambahTengah("Futaba", 18, "John");

    linkedList.tampilkanData();

    return 0;
}