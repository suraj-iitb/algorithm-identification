#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{

    int N; //?????????????????°
    int i, j, k;
    int key;
    cin >> N;

    int* A = (int*)malloc(sizeof(int)*(N+1));

    for (i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (j = 1; j <= N; j++) {
        k = j - 1;
        key = A[j];
        while (k >= 1 && A[k] > key) {
            A[k + 1] = A[k];
            k = k - 1;
        }
        A[k + 1] = key;


        for (i = 1; i <= N-1; i++) {
            cout << A[i] << " ";
        }
        cout << A[N] << "\n";
    }

 /*   for (i = 1; i <= N; i++) {
        cout << A[i] << " ";
    }*/

}
