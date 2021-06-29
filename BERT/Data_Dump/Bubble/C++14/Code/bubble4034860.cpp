#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin>>N;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin>>a[i];

    int cnt=0;
    for(int i=0;i<=N-2;i++){
        for(int j=N-1;j-1>=i;j--){
            if(a[j-1]>a[j]) swap(a[j-1],a[j]),cnt++;
        }
    }
    for(int i=0;i<N;i++){
        cout<<a[i]<<(i==N-1? '\n':' ');
    }
    cout<<cnt<<endl;
    return 0;
}
