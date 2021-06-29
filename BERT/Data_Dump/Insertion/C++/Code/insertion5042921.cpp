#include <iostream>
using namespace std;

void trace(int a[], int N){
    for (int i = 0; i < N; i++){
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

void insertionSort(int a[], int N){
    int v, j;
    for (int i = 1; i < N; i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a, N);
    }
}

int main(){
    int N;
    int a[100];
    
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    trace(a, N);
    insertionSort(a, N);
    
    return 0;
}
