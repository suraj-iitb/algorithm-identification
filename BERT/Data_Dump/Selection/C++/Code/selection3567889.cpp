#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int selectionSort(int*a, int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int minj = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            swap(a[i], a[minj]);
            ++cnt;
        }
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    int* a = (int *)calloc(n, sizeof(int));
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int cnt = selectionSort(a, n);

    for(int i=0;i<n;i++){
        cout << a[i];
        if(i!=n-1){
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    cout << cnt << "\n";
    return 0;
}
