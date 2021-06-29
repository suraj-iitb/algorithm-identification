#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int BubbleSort(int array[], int array_size){
    int i, j;
    int cnt = 0;
    bool flag = 1;

    for(i = 0; flag; i++){
        flag = 0;
        for(j = array_size - 1; j > i; j--){
            if(array[j-1] > array[j]){
                swap(array[j-1], array[j]);
                flag = 1;
                cnt++;
            }
        }
    }
    
    return cnt;
}


int main(){
    int n;
    cin >> n;
    int A[100];
    for(int i = 0;i < n; i++) cin >> A[i];

    
    int cnt = BubbleSort(A, n);
    rep(i,n){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;

}

