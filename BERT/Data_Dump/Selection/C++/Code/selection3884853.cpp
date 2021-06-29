// alds1_2_a bubble sort
#include <iostream>
using namespace std;

int cnt = 0;

void printline(int a[], int n, int cnt){
    // cout << cnt << " > " ;
    for(int i=0; i<n; i++){
        cout << a[i] ;
        if (i != n-1){ cout << " ";}
    }
    cout << endl;
}

void selectionSort(int a[], int n){
    int minj, temp;
    for(int i=0; i<n; i++){
        minj = i;
        for(int j=i; j<n; j++){
            if(a[j] < a[minj]){ minj = j; }
        }
        temp = a[i];
        a[i] = a[minj];
        a[minj] = temp;

        if(i != minj){cnt++;}
    }
    printline(a,n,cnt);
}



int main(){
    int i,n;
    int a[100];

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    selectionSort(a, n);
    
    cout << cnt << endl;
    return 0;
}
