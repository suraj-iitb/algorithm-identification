#include<iostream>
using namespace std;

void printA(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        cout << a[i];
        if(i!=n-1) cout << " ";
    }
    cout << endl;
}

void insertionSort(int a[], int n){
    int i,j,v;
    for(i=1;i<n;i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        printA(a, n);
    }
}

int main(){
    int i,n;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++) cin >> a[i];
    printA(a, n);
    insertionSort(a, n);

    return 0;
}

