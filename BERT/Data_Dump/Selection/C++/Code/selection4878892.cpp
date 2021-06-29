#include <iostream>
using namespace std;
int main(void){
    int n, a[100]={}, x=0, j, v, minj, ans=0;
    
    /*入力部*/
    cin>>n;
    while(1){
        if(x==n) break;
        cin>>a[x];
        x++;
    }
    
    /*選択ソートアルゴリズム*/
    for(int i=0; i<n; i++){
        minj=i;
        for(j=i; j<n; j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(i!=minj){
        v=a[i];
        a[i]=a[minj];
        a[minj]=v;
        ans++;
        }
    }
    
    /*出力部*/
    x=0;
    while(1){
        cout<<a[x];
        if(x<n-1) cout<<' ';
        if(x==n-1){
            cout<<endl;
            break;
        }
        x++;
    }
    cout<<ans<<endl;
}
