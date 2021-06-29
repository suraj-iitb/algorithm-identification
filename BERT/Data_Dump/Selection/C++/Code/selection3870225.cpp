#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int *a, int N);
void swap(int *x, int *y);

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    SelectionSort(a,N);

}

void SelectionSort(int *a, int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        swap(a[i],a[minj]);
        if(i != minj) count++;
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
