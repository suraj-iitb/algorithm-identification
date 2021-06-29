#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, k;
    int a[1000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
        for(k = 0;k < N; k++){
            cout << dec << a[k];
            if( k == N - 1){
                break;
            }else{
                cout << " ";
            }
        }
        cout << endl;
    int v, j;
    for(int i = 1; i < N;i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for(k = 0;k < N; k++){
            cout << dec << a[k];
            if( k == N - 1){
                break;
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
}
