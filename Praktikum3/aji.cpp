#include <iostream>
#include <iomanip>
using namespace std;

struct Data_2311102262
{
    string barang, harga;

    Data_2311102262 *next, *prev;
};
Data_2311102262 *head, *tail, *newnode, *cur, *del, *before, *afternode;
void datadouble(string data[2])
{
    head = new Data_2311102262();
    head->barang = data[0];
    head->harga = data[1];
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}
void removefirst()
{
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
}
void removelast()
{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}
void removemid(int posisi)
{
    int nomor = 1;
    cur = head;
    while (nomor < posisi && cur != NULL)
    {
        cur = cur->next;
        nomor++;
    }
    if (cur != NULL && cur->next != NULL)
    {
        del = cur->next;
        afternode = del->next;
        cur->next = afternode;
        if (afternode != NULL)
        {
            afternode->prev = cur;
        }
        delete del;
    }
    else
    {
        cout << "Posisi tidak valid\n";
    }
}



void changemid(string newproduk, string newharga, int posisi)
{
    cur = head;
    int nomor = 1;
    while (nomor < posisi && cur != NULL)
    {
        cur = cur->next;
        nomor++;
    }
    if (cur != NULL)
    {
        cur->barang = newproduk;
        cur->harga = newharga;
    }
    else
    {
        cout << "Posisi tidak valid\n";
    }
}
void addfirst(string newproduk, string newharga)
{
    newnode = new Data_2311102262();
    newnode->barang = newproduk;
    newnode->harga = newharga;
    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}
void addlast(string newproduk, string newharga)
{
    newnode = new Data_2311102262;
    newnode->barang = newproduk;
    newnode->harga = newharga;
    newnode->next = NULL;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void addmidle(string newproduk, string newharga, int posisi)
{
    newnode = new Data_2311102262();
    newnode->barang = newproduk;
    newnode->harga = newharga;

    cur = head;
    int nomor = 1;
    while (nomor < posisi - 1)
    {
        cur = cur->next;
        nomor++;
    }
    afternode = cur->next;
    newnode->prev = cur;
    newnode->next = afternode;
    cur->next = newnode;
    afternode->prev = newnode;
}

void deletedall()
{
    Data_2311102262 *cur = head;
    while (cur != nullptr)
    {
        Data_2311102262 *next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
    tail = nullptr;
}

void printData_2311102262()
{
    cout << left << setw(20) << "Nama Produk" << setw(10) << "Harga" << endl;
    cur = head;
    while (cur != NULL)
    {
        cout << left << setw(20) << cur->barang << setw(10) << cur->harga << endl;
        cur = cur->next;
    }
}

int main()
{
    string newproduk, newharga, n;
    char k;
    string data1[2] = {"Origyinote", "60.000"};
    datadouble(data1);
    addlast("Somethinc", "150.000");
    addlast("Skintific", "100.000");
    addlast("Wardah", "50.000");
    addlast("Hanasui", "30.000");

    // printData_2311102262();
    int pil, lokasi;

home:
    cout << " Toko Skincare Purwokerto\n";
    cout << "1. Tambah Data\n";
    cout << "2. Hapus Data\n";
    cout << "3. Update Data\n";
    cout << "4. Tambah Data Urutan Tertentu\n";
    cout << "5. Hapus Data Urutan Tertentu\n";
    cout << "6. Hapus Seluruh Data\n";
    cout << "7. Tampilkan Data\n";
    cout << "8. Exit\n";
    cout << "\n Masukkan Pilihan : ";
    cin >> pil;

    switch (pil)
    {
        // tambah data
    case 1:
        cout << "Tambah Data\n";
        cout << "Masukkan Produk Baru : ";
        cin >> newproduk;
        cout << "Masukkan Harga Baru : ";
        cin >> newharga;

        addlast(newproduk, newharga);

        cout << "Data Telah ditambahakan !!!\n";
    loop1:
        cout << "Kembali (y): ";
        cin >> k;
        if (k == 'y' || k == 'Y')
        {
            system("cls");
            goto home;
        }
        else
        {
            system("cls");
            goto loop1;
        }
        break;
    // hapus data
    case 2:
        cout << "Hapus Data\n";
    pilih:
        cout << "Hapus data dari atas / bawah\n";
        cout << "Pilih : ";
        cin >> n;

        if (n == "atas" || n == "Atas")
        {
            removefirst();
            cout << "Berhasil!!\n";
        loop3:
            cout << "Kembali (y): ";
            cin >> k;
            if (k == 'y' || k == 'Y')
            {
                system("cls");
                goto home;
            }
            else
            {
                system("cls");
                goto loop3;
            }
        }
        else if (n == "bawah" || n == "Bawah")
        {
            removelast();
            cout << "Berhasil!!\n";
        loop4:
            cout << "Kembali (y): ";
            cin >> k;
            if (k == 'y' || k == 'Y')
            {
                system("cls");
                goto home;
            }
            else
            {
                system("cls");
                goto loop4;
            }
        }
        else
        {
            system("cls");
            cout << "Input Dengan Benar !!! \n";
            goto pilih;
        }
        break;

    // update data
    case 3:
        cout << "Update Data / Produk\n";
        cout << "Masukkan Produk Baruv  : ";
        cin >> newproduk;
        cout << "Masukkan Harga Baru    : ";
        cin >> newharga;
        cout << "Lokasi yang dirubah    : ";
        cin >> lokasi;

        changemid(newproduk, newharga, lokasi);
    loop5:
        cout << "Kembali (y): ";
        cin >> k;
        if (k == 'y' || k == 'Y')
        {
            system("cls");
            goto home;
        }
        else
        {
            system("cls");
            goto loop5;
        }
        break;

    // Tambah data urutan tertentu
    case 4:
        cout << "Tambah data urutan tertentu\n";
        cout << "Pilih urutan (atas/bawah/tengah) : ";
    pilih2:
        cin >> n;
        if (n == "atas" || n == "Atas")
        {
            cout << "Tambah Data\n";
            cout << "Masukkan Produk Baru : ";
            cin >> newproduk;
            cout << "Masukkan Harga Baru : ";
            cin >> newharga;

            addfirst(newproduk, newharga);
            cout << "Berhasil!!\n";
        loop6:
            cout << "Kembali (y): ";
            cin >> k;
            if (k == 'y' || k == 'Y')
            {
                system("cls");
                goto home;
            }
            else
            {
                system("cls");
                goto loop6;
            }
        }
        else if (n == "bawah" || n == "Bawah")
        {
            cout << "Masukkan Produk Baru : ";
            cin >> newproduk;
            cout << "Masukkan Harga Baru : ";
            cin >> newharga;

            addlast(newproduk, newharga);
        loop7:
            cout << "Kembali (y): ";
            cin >> k;
            if (k == 'y' || k == 'Y')
            {
                system("cls");
                goto home;
            }
            else
            {
                system("cls");
                goto loop7;
            }
        }
        else if (n == "tengah" || n == "Tengah")
        {
            cout << "Masukkan Produk Baru : ";
            cin >> newproduk;
            cout << "Masukkan Harga Baru : ";
            cin >> newharga;
            cout << "Masukkan Lokasi : ";
            cin >> lokasi;
            addmidle(newproduk, newharga, lokasi);
        loop8:
            cout << "Kembali (y): ";
            cin >> k;
            if (k == 'y' || k == 'Y')
            {
                system("cls");
                goto home;
            }
            else
            {
                system("cls");
                goto loop8;
            }
        }
        else
        {
            system("cls");
            cout << "Input Dengan Benar !!! \n";
            goto pilih2;
        }
        break;

    // hapus data urutan tertentu
    case 5:
        cout << "Hapus data urutan tertentu\n";
        cout << "Pilih urutan (atas/bawah/tengah) : ";
    pilih3:
        cin >> n;
        if (n == "atas" || n == "Atas")
        {
            removefirst();
            cout << "Berhasil!!\n";
        loop9:
            cout << "Kembali (y): ";
            cin >> k;
            if (k == 'y' || k == 'Y')
            {
                system("cls");
                goto home;
            }
            else
            {
                system("cls");
                goto loop9;
            }
        }
        else if (n == "bawah" || n == "Bawah")
        {
            removelast();
            cout << "Berhasil!!\n";
        loop10:
            cout << "Kembali (y): ";
            cin >> k;
            if (k == 'y' || k == 'Y')
            {
                system("cls");
                goto home;
            }
            else
            {
                system("cls");
                goto loop10;
            }
        }
        else if (n == "tengah" || n == "Tengah")
    {
        cout << "Tentukan Lokasi : ";
        cin >> lokasi;
        removemid(lokasi);
        cout << "Berhasil!!\n";
    loop11:
            cout << "Kembali (y): ";
            cin >> k;
            if (k == 'y' || k == 'Y')
            {
                system("cls");
                goto home;
            }
            else
            {
                system("cls");
                goto loop11;
            }
        }
        else
        {
            system("cls");
            cout << "Input Dengan Benar !!! \n";
            goto pilih3;
        }

        break;
    // hapus seluruh data
    case 6:
        deletedall();
        cout << "Seluruh data telah dihapus." << endl;
    loop12:
        cout << "Kembali (y): ";
        cin >> k;
        if (k == 'y' || k == 'Y')
        {
            system("cls");
            goto home;
        }
        else
        {
            system("cls");
            goto loop12;
        }
        break;
        break;
    // tampil seluruh data
    case 7:
        printData_2311102262();
    loop2:
        cout << "Kembali (y): ";
        cin >> k;
        if (k == 'y' || k == 'Y')
        {
            system("cls");
            goto home;
        }
        else
        {
            system("cls");
            goto loop2;
        }
        break;
    case 8:
        cout << "Terimakasih";
        break;
    default:
        system("cls");
        goto home;
    }

    return 0;
}