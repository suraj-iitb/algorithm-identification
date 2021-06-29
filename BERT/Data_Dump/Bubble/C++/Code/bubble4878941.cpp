#include <iostream>
using namespace std;
int main(void){
    int n, a[100]={}, x=0, j, v, ans=0;
    
    /*入力部*/
    cin>>n;
    while(1){
        if(x==n) break;
        cin>>a[x];
        x++;
    }
    
    /*バブルソートアルゴリズム*/
    int flag=1;
    while(flag){
        flag=0;
        for(j=n-1; j>=1; j--){
            if(a[j]<a[j-1]){
                v=a[j];
                a[j]=a[j-1];
                a[j-1]=v;
                flag=1;
                ans++;
            }
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
