#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];

void printArray(){
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
}

void insertionSort(){
    int v,j;
    printArray();
    for(int i = 1; i < n; i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        printArray();
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    insertionSort();

    return 0;
}
