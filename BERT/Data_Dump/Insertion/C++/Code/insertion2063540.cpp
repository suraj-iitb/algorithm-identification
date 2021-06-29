#include <iostream>
using namespace std;
int k;
int cnt[102];
void print(int kj){
    for(int i=0;i<kj-1;i++){
        cout<<cnt[i]<<' ';
    }
    cout<<cnt[kj-1]<<'\n';
}
int main(){
    cin>>k;
    for (int i=0;i<k;++i){
        cin>>cnt[i];
    }
    print(k);
    for (int j=1;j<k;++j){
        int key = cnt[j];
        int idx = j-1;
        while(idx>=0 && key<cnt[idx]){
            cnt[idx+1]=cnt[idx];
            idx--;
        }
        cnt[idx+1]=key;
        print(k);
    }
    return 0;
}
