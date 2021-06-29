#include <iostream>
using namespace std;

void printStep(int *a, int n){
    for(int j=0; j<n-1; j++){
        cout << a[j] << " ";
    }
    cout << a[n-1] << "\n";
}

void insertionSort(int *a, int n){
    printStep(a, n);
    
    for(int i=1; i<n; i++){
        int v=a[i];
        int j = i-1;
        
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        printStep(a, n);
    }
}

int main(){
    int n, a[100];
    
    cin >> n;
    
    for(int i=0;i<n; i++){
        cin >> a[i];
    }
    insertionSort(a, n);
}

