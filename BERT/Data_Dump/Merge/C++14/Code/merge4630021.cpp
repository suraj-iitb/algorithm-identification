//マージソートのプログラム
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vec_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define vec_output(v) for(auto it=v.begin();it!=v.end();it++){if(it!=v.begin())cout<<" ";cout<<*it;}cout<<endl;
#define vec_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
int cnt;

void merge(vector<int> &a,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    vector<int> L(n1+1),R(n2+1);
    for(int i=0;i<n1;i++)L[i]=a[left+i];
    for(int i=0;i<n2;i++)R[i]=a[mid+i];
    int i=0,j=0;
    L[n1]=2000000000,R[n2]=2000000000;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }else{
            a[k]=R[j];
            j++;
        }
    }
}

void mergesort(vector<int> &a,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid,right);
        merge(a,left,mid,right);
    }
}

int main(){
    int n;
    cnt=0;
    cin>>n;
    vector<int> vec(n);
    vec_input(vec);
    mergesort(vec,0,n);
    vec_output(vec);
    cout<<cnt<<endl;
}
