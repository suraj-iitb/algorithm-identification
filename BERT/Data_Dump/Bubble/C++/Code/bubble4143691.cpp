#include<iostream>
#include <stdio.h>
using namespace std;


int main() {
    int* a;
    int l;
    int j;
    int N;
    int count=0;

    cin >> N;
    a = new int[N];
    for (l = 0; l < N; l++) cin >> a[l];
  
    
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j>i; j--) {
            if (a[j]<a[j-1]) {
                swap(a[j],a[j-1]);
                count++;
            }
        }
   }
        for (int k=0; k<N; k++) {
            cout<<(k!=0?" ":"")<<a[k];
        }
        cout<<endl<<count<<endl;
        delete[] a;
        

    }
