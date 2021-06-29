#include <iostream>
using namespace std;

void printa(int a[100], int n){
    for (int i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}

void insertionSoft(int a[100], int n){
    for (int i = 1; i <= n-1;i++){
        printa(a, n);
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
}
int main(void){
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    insertionSoft(a, n);
    
    printa (a, n);
}

