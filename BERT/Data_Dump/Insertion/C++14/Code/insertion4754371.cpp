#include <iostream>
#include <string>
#include<vector>
using namespace std;

static const int MAX = 100;

void printStringnum(int a[],int n){
    for(int i=0;i<n-1;i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] <<"\n";
}

void inserstionSort(int a[],int n){
    int v,j;
    for(int i=1;i<n;i++){
        printStringnum(a,n);
        v = a[i];
        j = i-1;
        while(j>=0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    printStringnum(a,n);
}

int main(){
    int n;

    cin >> n;
    
    int a[MAX];

    for(int i=0;i<n;i++){
    cin >> a[i];
    //cout << a[i];
    }

    inserstionSort(a,n);
    }
