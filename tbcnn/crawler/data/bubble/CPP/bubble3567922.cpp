#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
void bubblesort(int *a, int n){
    bool flg = true;
    int cnt = 0;
    int k=0;
    while(flg){
        flg = false;
        for(int j=n-1;j>k;j--){
            if(a[j]<a[j-1]){
                swap(a[j], a[j-1]);
                ++cnt;
                flg = true;
            }
        }
        ++k;
    }
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i!=n-1){
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    cout << cnt << "\n";
}

int main(){
    int n;
    cin >> n;
    int *a = (int *)calloc(n, sizeof(int));
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    bubblesort(a, n);

    return 0;
}
