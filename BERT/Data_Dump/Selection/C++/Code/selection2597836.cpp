#include<iostream>
 
using namespace std;

int selectionSort (int A[], int n) {

    int i, j, v, count = 0, minj;

    for (i = 0; i < n; i++) {

        minj = i;

        for (j = i; j < n; j++) {

            if (A[j] < A[minj]) {

                minj = j;

            }

        }

        if (i != minj) {

            v = A[i];
            A[i] = A[minj];
            A[minj] = v;

            count += 1;

        }

    }

    return count;

}

int main () {
  
    int i, n, count, A[100];
  
    cin >> n;
  
    for (i = 0; i < n; i++) {
  
        cin >> A[i];
  
    }
 
    count = selectionSort (A, n);
 
    for (i = 0; i < n; i++) {
 
        cout << A[i];
 
        if (i < n - 1) {
 
            cout << " ";
 
        }
 
    }
 
    cout << endl;
    cout << count << endl;
 
    return 0;
 
}
