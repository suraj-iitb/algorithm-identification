#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int cnt = 0;
    cin >> N;
    int a[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    int flag = 1;
    int i = 0;
    while(flag){
        flag = 0;
        for(int j = N-1; j > i; j--){
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                cnt++;
            }
            flag = 1;
        }
        i++;
    }
    for(int i=0; i<N; i++){
        if(i-N+1) cout << a[i] << " ";
        else cout <<a[i] << endl;
    }
    cout << cnt  << endl;
    return 0;
}
