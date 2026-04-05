#include <iostream>
#include <iomanip>

using namespace std;
//2311102243_SITI MADINA HALIM SIREGAR
int main (){
    char op;
    float num1, num2;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    cout << "Enter Operator (+,-,*,/): ";
    cin >> op;

    switch (op) {
        case '+':
            cout << "Result: " << num1 + num2;
            break;
        case '-':
            cout << "Result: " << num1 - num2;
            break;
        case '*':
            cout << "Result: " << num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << fixed << setprecision(2) << num1 / num2;
            } else {
                cout << "Error ";
            }
            break;
            default:
            cout << "Error! Operatoe is not correct";
        
    }
    return 0;
}