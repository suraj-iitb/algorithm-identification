#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265359
int main(){
    int N; cin>>N;
    int count=0;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    bool flag=1;
    while(flag) {
        flag=0;
        for (int i = N - 1; i > 0; i--) {
            if (v[i - 1] > v[i]) {
                swap(v[i - 1], v[i]);
                count++;
                flag=1;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<v[i]<<" \n"[i==N-1];
    }
    cout<<count<<endl;
    return 0;
}
