#include <iostream>

using namespace std;

void printArray(int *a, int n) {
    for(int i = 0 ; i < n ; i++) {            
        cout << *a;
        if(i != n -1) {
            cout << " ";
        } else {
            cout << "\n";
        }
        a++;
    }
}

void insertionSort(int a[], int n) {
    int v = 0;
    int j = 0;
    for(int i = 1 ; i < n ; i++) {
        printArray(a, n);
        v = a[i];
        j = i - 1;
        while( j >= 0 && a[j] > v ) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    printArray(a, n);
}

int main(int, char**) {
    int a[1000];
    int l;
    int n;
    cin >> n;
    int i = 0;
    while(cin>>l){
        a[i] = l;
        i++;
    }
    insertionSort(a, n);
}
