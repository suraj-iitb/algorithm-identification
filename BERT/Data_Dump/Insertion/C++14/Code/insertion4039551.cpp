#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        if(i != n - 1)
            cout << a[i] << " ";
        else
            cout << a[i];
    }
    cout << endl;
}

void insertionSort(int a[],int n){
    int tmp, j;
    for(int i = 1; i < n;i++){
        tmp = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > tmp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
        printArray(a,n);
    }
}

int main(){
    int n,a[200];
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    printArray(a,n);
    insertionSort(a,n);

    return 0;
}
