#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int N; cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    int flag = 1, cnt = 0;
    while(flag){
        flag = 0;
        for(int j = N-1; j >= 1; j--){
            if(v[j] < v[j-1]){
                swap(v[j], v[j-1]);
                cnt++;
                flag = 1;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(i == N-1){
            cout << v[i] << endl;
            break;
        }
        cout << v[i] << " ";
    }
    cout << cnt << endl;
    return 0;
}
