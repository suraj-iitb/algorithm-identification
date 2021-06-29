#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const static int MAX = 1000;

void showCard(int card[], int n){
    for(int i = 0; i < n - 1; i++){
        cout << card[i] << " ";
    }
    cout << card[n-1] << endl;
}

void insertionSort(int card[], int n){
    int v,j;
    for(int i = 0; i < n ; i++){
        v = card[i];
        j = i - 1;
        while(j >= 0 && card[j] > v){
            card[j+1] = card[j];
            j--;
        }
        card[j+1] = v;
    showCard(card,n);
    }
}

int main(){
    
    int n, card[MAX];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> card[i];
    }
    insertionSort(card,n);

    return 0;
}
