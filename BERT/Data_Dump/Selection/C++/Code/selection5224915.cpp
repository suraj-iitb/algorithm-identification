#include <iostream>
using namespace std;

int selectionSort(int a[], int n){
    int cnt = 0, minj, v;
    for (int i = 0; i < n-1; i++){
        minj = i;
        for (int j = i; j < n; j++){
            if (a[j] < a[minj]) minj = j;
        }
        if (minj != i){
            v = a[i];
            a[i] = a[minj];
            a[minj] = v;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    const int MAX_SIZE = 100;
    int a[MAX_SIZE], n, cnt;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    cnt = selectionSort(a,n);
    for (int i = 0; i < n; i++){
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n" << cnt << endl;
}
