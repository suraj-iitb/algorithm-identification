#include <bits/stdc++.h>
using namespace std;
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FOR1(x,to) for(int x=1;x<(to);x++)

int selectionsort(int n,int a[]){
    int mini,res=0;
    FOR(i,n){
        mini=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mini])mini=j;
        }
        if(a[i]!=a[mini]){
            swap(a[i],a[mini]);
            res++;
        }
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
    int res=selectionsort(n,a);
    FOR(i,n){
        if(i>0) cout<<" ";
        cout<<a[i];
    }
    cout<<endl<<res<<endl;

}

