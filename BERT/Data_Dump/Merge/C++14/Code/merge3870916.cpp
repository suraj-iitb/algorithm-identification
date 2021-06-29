#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define sortr(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define MAX 500000
#define SENTINEL 2000000000
constexpr int inf = 100000000;

int l[MAX/2+2],r[MAX/2+2];
int cnt;

void merge(int a[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++){
        l[i]=a[left+i];
    }
     for(int i=0;i<n2;i++){
        r[i]=a[mid+i];
    }
    l[n1]=SENTINEL;
    r[n2]=SENTINEL;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(l[i]<=r[j]){
            a[k]=l[i++];
        }else{
            a[k]=r[j++];
        }
    }
}

void mergesort(int a[],int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid,right);
        merge(a,left,mid,right);
    }
}

int main(){
    int a[MAX];
    int n;
    cnt=0;
    cin>>n;
    rep(i,n)cin>>a[i];
    mergesort(a,0,n);
    rep(i,n){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
}










