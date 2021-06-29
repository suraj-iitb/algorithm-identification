#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
using ll =long long;
using namespace std;


int n;
ll s[500000];
ll c=0;

void merge(ll array[],ll left,ll mid,ll right){
    ll n1=mid-left;
    ll n2=right-mid;
    vector<ll> L(n1+1),R(n2+1);
    rep(i,n1){
        L[i]=array[left+i];
    }
    L[n1]=1000000001;
    rep(i,n2){
        R[i]=array[mid+i];
    }
    R[n2]=1000000001;
    ll i=0;
    ll j=0;
    for(ll k=left;k<right;k++){
        if(L[i]<=R[j]){
            array[k]=L[i];
            i++;
        }else{
            array[k]=R[j];
            j++;
        }
    }
    c+=i+j;
}

void mergeSort(ll array[],ll left,ll right){
    if(left+1<right){
        ll mid=(left+right)/2;
        mergeSort(array,left,mid);
        mergeSort(array,mid,right);
        merge(array,left,mid,right);
    }
}

int main(){
    cin>>n;
    rep(i,n){
        cin>>s[i];
    }
    mergeSort(s,0,n);
    rep(i,n-1){
        cout<<s[i]<<" ";
    }
    cout<<s[n-1]<<endl;
    cout<<c<<endl;
}
