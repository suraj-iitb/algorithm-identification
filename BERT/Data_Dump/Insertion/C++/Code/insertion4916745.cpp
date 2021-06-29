#include<iostream>

using namespace std;

void printIntArray(int a[], int number)
{
    for(int i = 0; i < number ; i++){
        cout << a[i];
        if( i != number - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main()
{
    int n,i,j, key;
    string str;
    int A[100] = {};

    cin >> n;
    i = 0;

    for(i=0; i < n; i++){
        cin >> A[i];
    }

    printIntArray(A, n);
    for(int i = 1; i < n;i++ ){
        key = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        printIntArray(A, n);
    }

    return 0;
}
