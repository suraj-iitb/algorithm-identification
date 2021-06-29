#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    int i;
    for(i=0; i<N; i++){
        cin >> a[i];
    }
    int minj, j, cnt;
    cnt = 0;
    for(i=0; i<N-1 ;i++){
        minj = i;
        for(j=minj; j < N; j++){
            if(a[minj] > a[j]) minj =j;
        }
        if(minj != i){
            swap(a[minj] , a[i]);
            cnt++;
        }
    }
    for(i=0; i<N; i++){
        if(i-N+1)cout << a[i] << " ";
        else cout << a[i] << endl;
    }
    cout << cnt << endl;
    
    return 0;
}
