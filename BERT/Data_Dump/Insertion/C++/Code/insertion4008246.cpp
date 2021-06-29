#include <iostream>
#include <stdio.h>
using namespace std;

void resultPrinter(int a[], int n){
    for(int i = 0; i < n; i++){
        if(i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void insertion(int a[], int n){
    for(int i = 1; i < n; i++){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        resultPrinter(a,n);
    }
}


int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    resultPrinter(a,n);
    insertion(a,n);

    return 0;
}


