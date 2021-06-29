#include<iostream>
using namespace std;

int main(void){

    int x, v, j;
    cin >> x;
    int A[x];
    for (int i = 0; i < x; i++){
        cin >> A[i];
    }

    for (int i = 0; i < x; i++){
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        for (int k = 0; k < x; k++){
            cout << A[k];
            if (k != (x - 1)) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
