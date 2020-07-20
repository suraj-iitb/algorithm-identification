#include <bits/stdc++.h>
using namespace std;
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FOR1(x,to) for(int x=1;x<(to);x++)

int bubblesort(int n,int a[]){
    int flag=1,res=0,i=0;
    while(flag){
        flag=0;
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag=1;
                res++;
            }
        }
        i++;
    }
    return res;
}

int main()
{
    int n;cin>>n;
    int a[n];
    FOR(i,n){
        cin>>a[i];
    }
    int res=bubblesort(n,a);
    FOR(i,n){
        if(i>0) cout<<" ";
        cout<<a[i];
    }
    cout<<endl<<res<<endl;

}

