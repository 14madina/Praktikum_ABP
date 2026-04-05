#include <iostream>
using namespace std;

//2311102243_SITI MADINAH HALIM SIREGAR_S1 IF-11-G

struct Mahasiswa {
string nama;
string NIM;
};
struct Node {
Mahasiswa data;
Node* next;
};
Node* front = nullptr;
Node* back = nullptr; 
bool isFull() {

return false;
}
bool isEmpty() {
return (front == nullptr);
}
void enqueueAntrian(Mahasiswa data) {
Node* newNode = new Node();
newNode->data = data;
newNode->next = nullptr;
if (isEmpty()) {
front = back = newNode;
} else {
back->next = newNode;
back = newNode;
}
}
void dequeueAntrian() {
if (isEmpty()) {
cout << "Antrian kosong" << endl;
} else {
Node* temp = front;
front = front->next;
delete temp;
if (front == nullptr) {
back = nullptr;
}
}
}
int countQueue() {
int count = 0;
Node* current = front;
while (current != nullptr) {
count++;
current = current->next;
}
return count;
}
void clearQueue() {
while (!isEmpty()) {
dequeueAntrian();
}
}
void viewQueue() {
cout << "Data antrian teller:" << endl;
Node* current = front;
int i = 1;
while (current != nullptr) {
cout << i << ". Nama: " << current->data.nama << ", NIM: " << current->data.NIM << endl;
current = current->next;
i++;
}
if (i == 1) {
cout << "Antrian kosong" << endl;
}
}
int main() {
Mahasiswa m1 = {"Andi", "2311102234"};
Mahasiswa m2 = {"Maya", "2311102203"};
enqueueAntrian(m1);
enqueueAntrian(m2);
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
dequeueAntrian();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
clearQueue();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
return 0;
}