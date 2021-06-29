#include<bits/stdc++.h>
using namespace std;
int selectionSort(int** A,int n){
    int c = 0;
    for(int i = 0 ; i < n ; ++i){
        int minj = i;
        for(int j = i ; j < n ; ++j){
            if((*A)[minj] > (*A)[j]){
                minj = j;
            }
        }
        if(*((*A) + minj)!=*((*A) + i))++c;
        swap(*((*A) + minj),*((*A) + i));
    }
    int k = 0;
    while(1){
        cout << (*A)[k++];
        if(k == n){
            cout << endl;
            break;
        }
        else cout << " ";
    }
    return c;
}
int main(){
    int n;
    cin >> n;
    int* A = new int[n];
    for(int i = 0 ; i < n ; ++i)cin >> A[i];
    cout << selectionSort(&A,n) << endl;
}
