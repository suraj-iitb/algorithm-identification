#include <bits/stdc++.h>
using namespace std;

int selectionSort(int a[], int n){
    int minj, count = 0;
    for(int i = 0; i < n; i++){
        minj = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[minj])
                minj = j;
        }
        swap(a[i],a[minj]);
        if(i != minj)
            count++;
    }
    return count;
}

int main(){
    int n, count, a[1000];
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    count = selectionSort(a,n);

    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n -1)
            cout << " ";
    }
    cout << endl << count << endl;
}
