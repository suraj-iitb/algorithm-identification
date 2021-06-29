#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int N[MAX], n;

void print(){
    for(int i=0; i<n; i++){
        if(i != 0) cout << " ";
        cout << N[i];
    }
    cout << endl;
}

void insertionsort(){
    for(int i=0; i<n; i++){
        int v = N[i];
        int j = i-1;
        while(j >= 0 && N[j] > v){
            N[j+1] = N[j];
            j--;
        }
        N[j+1] = v;
        print();
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> N[i];
    insertionsort();
    return 0;
}

