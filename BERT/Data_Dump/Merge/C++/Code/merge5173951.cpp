#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
typedef long long ll;

#define MAX 500000;
int l[250002],r[250002];
int cnt;

void merge(int A[], int n, int left, int mid, int right) {
    int n1=mid-left;
    int n2=right-mid;
    rep(i,n1) l[i]=A[left+i];
    rep(i,n2) r[i]=A[mid+i];
    l[n1]=r[n2]=2000000000;
    int i=0,j=0;
    for(int k=left; k<right; k++) {
        cnt++;
        if(l[i]<=r[j]) {
            A[k]=l[i++];
        } else {
            A[k]=r[j++];
        }
    }
}

void mergesort(int A[], int n, int left, int right) {
    if(left+1<right) {
        int mid=(left+right)/2;
        mergesort(A,n,left,mid);
        mergesort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main()
{
    int A[500000],n;
    cnt=0;
    cin >> n;
    rep(i,n) cin >> A[i];
    mergesort(A,n,0,n);
    rep(i,n) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
