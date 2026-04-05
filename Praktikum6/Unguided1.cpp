#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

string cleanString(const string& str) {
    string cleanedStr;
    for (char c : str) {
        if (isalpha(c)) {
            cleanedStr += tolower(c);
        }
    }
    return cleanedStr;
}

bool isPalindrome(const string& str) {
    string cleanedStr = cleanString(str);
    stack<char> charStack;

    for (char c : cleanedStr) {
        charStack.push(c);
    }

    for (char c : cleanedStr) {
        if (c != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string input;
    
    cout << "2311102243_SITI MADINAH HALIM SIREGAR_S1 IF-11-G \n";
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
