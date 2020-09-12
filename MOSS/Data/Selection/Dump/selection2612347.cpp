#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int N; cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    int cnt = 0;
    for(int i = 0; i <= N-1; i++){
        int minV = i;
        for(int j = i; j <= N-1; j++){
            if(v[j] < v[minV]){
                minV = j;
            }
        }
        if(v[i] > v[minV]){   
           swap(v[i], v[minV]);
           cnt++;
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
