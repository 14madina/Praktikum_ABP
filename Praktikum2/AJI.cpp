#include <iostream>
#include <limits>

using namespace std;
void rata(int data231102262[], int &a){
    int sum = 0;
    for (int i = 0; i < a; ++i) {
        cout << data231102262[i]<< " ";
        sum += data231102262[i];
    }
    double ratarata = static_cast<double>(sum) / a;

    cout << "\nRata-rata dari array adalah: " << ratarata << endl;
}

int main(){
    int pil,a;
    int data2311102262[100];
    int maks = INT_MIN;
    int min  = INT_MAX;
    char pil1;
    do{
    home:
    system ("cls");
    cout << "1. Masukkan Nilai Array\n";
    cout << "2. Tentukan Nilai Maksimum\n";
    cout << "3. Tentukan Nilai Minimum\n";
    cout << "4. Tentukan Nilai Rata-rata\n";
    cout << "5. Keluar\n";
    cout << "Masukkan Pilihan : ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin  >> pil;

   } while (pil < 1 || pil > 5);
    switch (pil){
    case 1:
        cout << "Masukkan Panjang Array : ";
        cin  >> a;
        for (int i = 0; i < a; i ++){
            cout << "Input Nilai Array ke " << i << " : " ;
            cin  >> data2311102262 [i];
        }
        loop1:
        cout << "Kembali (y) : ";
        cin  >> pil1;
            if (pil1=='y' || pil == 'Y'){
                goto home;
            }else {
                goto loop1;
            }
        break;
    case 2:
        cout << "Menentukan Nilai Maksimum\n";
        cout << "Data Array : ";
        for (int i = 0; i < a; i++) {
            cout << data2311102262[i] << " " ;
            if (data2311102262[i] > maks) {
                maks = data2311102262[i];
            }
        }
        cout << "\nNilai Maksimum dari Array adalah : " << maks << endl;
        loop2:
        cout << "Kembali (y) : ";
        cin  >> pil1;
            if (pil1=='y' || pil == 'Y'){
                goto home;
            }else {
                goto loop2;
            }
    case 3:
        cout << "Menentukan Nilai Minimum\n";
       cout << "Data Array : ";
                for (int i = 0; i < a; i++) {
                    cout << data2311102262[i] << " " ;
                    if (data2311102262[i] < min) {
                        min = data2311102262[i];
                    }
                }
                cout << "\nNilai Minimum dari Array adalah : " << min << endl;
        loop3:
        cout << "Kembali (y) : ";
        cin  >> pil1;
            if (pil1=='y' || pil == 'Y'){
                goto home;
            }else {
                goto loop3;
            }
        break;
    case 4:
        cout << "Nilai Rata-rata\n";
        cout << "Data Array : ";
        rata(data2311102262, a);
    loop4:
        cout << "Kembali (y) : ";
        cin  >> pil1;
            if (pil1=='y' || pil == 'Y'){
                goto home;
            }else {
                goto loop4;
            }
        break;
    case 5:
    cout << "Terimakasih";
    break;
    }
    return 0;
}