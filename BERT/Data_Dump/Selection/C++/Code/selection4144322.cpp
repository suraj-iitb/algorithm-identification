#include <bits/stdc++.h>
using namespace std;

int selection(int *r, int n);



int main(){
    int n,c;
    int r[1000];
    cin>>n;
    for(int i=0;i<n;i++) cin>>r[i];
    c=selection(r,n);
    for(int j=0;j<n;j++){
        if(j!=n-1)cout<<r[j]<<' ';
        else cout<<r[n-1]<<endl;
    }
    cout<<c<<endl;

    
}




int selection(int *r, int n){
    int minj,tmp;
    int c=0;
    int flag=1;
    for(int i=0;i<n;i++){
        minj=i;
        flag=1;
        for(int j=i;j<n;j++){
            if(r[minj]>r[j]){
                minj=j;
                if(flag){
                    c++;
                    flag=0;
                }
            }
        }
        tmp=r[minj];
        r[minj]=r[i];
        r[i]=tmp;
    }
    return c;
}

