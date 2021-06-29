// instr3.cpp -- reading more than one word with get() & get()
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
void insertionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] < a[j]){
                int temp = a[i];
                for (int k = i; k > j; k--){
                    a[k] = a[k-1];
                }
                a[j] = temp;
            }
        }
        for (int q = 0; q < n; q++){
            if (q != n-1)
                cout << a[q] << " ";
            else
                cout << a[q] << endl;
        }
    }


}
int main(){
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    insertionSort(a,n);
}

