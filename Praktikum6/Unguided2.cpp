#include <iostream>
#include <stack>

using namespace std;

string balikHuruf(const string& word) {
    string kataTerbalik = "";
    for (int i = word.length() - 1; i >= 0; --i) {
        kataTerbalik += word[i];
    }
    return kataTerbalik;
}

string pembalik2311102243(const string& kalimat) {
    stack<string> stackKata;
    string kata, kalimatTerbalik;
    int start = 0;

    for (int i = 0; i < kalimat.length(); ++i) {
        if (kalimat[i] == ' ') {
            kata = kalimat.substr(start, i - start);
            stackKata.push(balikHuruf(kata));
            start = i + 1;
        }
    }

    kata = kalimat.substr(start, kalimat.length() - start);
    stackKata.push(balikHuruf(kata));

    while (!stackKata.empty()) {
        kalimatTerbalik += stackKata.top() + " ";
        stackKata.pop();
    }

    return kalimatTerbalik;
}

int main() {
    string kalimat;
    cout << "2311102243_SITI MADINAH HALIM SIREGAR_S1 IF-11-G \n";
    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, kalimat);

    string kalimatTerbalik = pembalik2311102243(kalimat);

    cout << "Kalimat terbalik: " << kalimatTerbalik << endl;

    return 0;
}