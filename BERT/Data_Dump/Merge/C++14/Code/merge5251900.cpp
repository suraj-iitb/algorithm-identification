#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll oho=0;
void merger(ll a[],ll left[],ll mid,ll right[],ll rsize)
{
    ll i=0,j=0,k=0;
    while(i<mid && j<rsize)
    {
        oho++;
        if(left[i]>right[j]){
             
            a[k]=right[j++];
        }
        else{
           
            a[k]=left[i++];
        }
        k++;
    }
    while(i<mid){
        oho++;
        a[k++]=left[i++];
    }
    while(j<rsize){
        oho++;
        a[k++]=right[j++];
    }
    return;
    
}

void merge(ll a[],ll n)
{
    if(n<2)
        return;
    ll mid=n/2;
    ll left[mid],right[n-mid];
    for(ll i=0;i<mid;i++)
        left[i]=a[i];
    for(ll i=mid;i<n;i++)
        right[i-mid]=a[i];
    
    merge(left,mid);
    merge(right,n-mid);
    
    merger(a,left,mid,right,n-mid);
}

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(auto &i:a)
        cin>>i;
    merge(a,n);
    if(n!=0){
        cout<<a[0];
        for(ll i=1;i<n;i++)
            cout<<" "<<a[i];
    }
    cout<<"\n"<<oho<<"\n";
    return 0;
}

