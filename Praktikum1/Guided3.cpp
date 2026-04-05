#include <iostream>
using namespace std;
//2311102243_SITI MADINA HALIM SIREGAR
void output_array(int a[], int x){
    for(int i = 0; i < x; i++){
        cout << a[i] << "\n";
    }
}

int main(){
    int x = 5;
    int a[x] = {23, 50, 34, 78, 90};

    output_array(a, x);

    return 0;
}