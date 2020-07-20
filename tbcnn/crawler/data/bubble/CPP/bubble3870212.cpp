// バブルソート
#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int *a, int N);
void swap(int *x, int *y);

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    BubbleSort(a,N);
}

void BubbleSort(int *a, int N){
    int count = 0;
    bool f = true;
    while(f){
        f = false;
        for(int j = N-1; j >= 1; j--){
            if(a[j] < a[j-1]){
                swap(a[j],a[j-1]);
                count ++;
                f = true;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        cout << a[i];
        if(i != N-1) cout << " ";
        else cout << endl;
    }
    cout << count << endl;
}

void swap(int *x, int *y){
    int work = *x;
    *x = *y; *y = work;
}
