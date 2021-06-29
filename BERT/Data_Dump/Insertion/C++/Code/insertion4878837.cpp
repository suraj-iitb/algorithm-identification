#include <iostream>
using namespace std;
int main(void){
    int n, a[1000]={}, x=0, j, v;
    
    /*入力部*/
    cin>>n;
    while(1){
        if(x==n) break;
        cin>>a[x];
        x++;
    }
    
    /*挿入ソートアルゴリズム*/
    for(int i=1; i<n; i++){
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
        
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
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
}
