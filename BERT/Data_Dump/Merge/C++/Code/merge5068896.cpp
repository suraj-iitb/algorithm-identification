#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int cnt = 0;

void merge(vector<int> &s, int left, int mid, int right){
    int n1 = mid-left;
    int n2 = right - mid;
    vector<int> l(n1+1);
    vector<int> r(n2+1);
    rep(i,n1){
        l[i] = s[left+i];
    }
    rep(i,n2){
        r[i] = s[mid+i];
    }
    //比較のときオーバーフローしてしまうと比較がうまくいかないことに注意
    l[n1] = INT_MAX; r[n2] = INT_MAX; 
    int li = 0; int ri = 0;
    for(int i=left;i<right;i++){
        if(l[li]<=r[ri]){
            s[i] = l[li];
            li++;
        }else{
            s[i] = r[ri];
            ri++;
        }
        cnt++;
    }
}

void mergesort(vector<int> &s,int left, int right){
    if(left+1<right){
        int mid = (left+right)/2;
        mergesort(s,left,mid);
        mergesort(s,mid,right);
        merge(s,left,mid,right);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> s(n);
    rep(i,n){
        cin>>s[i];
    }
    mergesort(s,0,n);
    rep(i,n){
        cout<<s[i];
        printf("%c", i==n-1 ? '\n' :' ');
    }
    cout<<cnt<<endl;
    return 0;
}
