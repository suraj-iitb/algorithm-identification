#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
typedef long long ll;

struct Card {
    char suit;
    int value;
};

struct Card l[50002], r[50002];

void merge(struct Card A[], int n, int left, int mid, int right) {
    int n1=mid-left;
    int n2=right-mid;
    rep(i,n1) l[i]=A[left+i];
    rep(i,n2) r[i]=A[mid+i];
    l[n1].value=r[n2].value=2000000000;
    int i=0,j=0;
    for(int k=left; k<right; k++) {
        if(l[i].value<=r[j].value) {
            A[k]=l[i++];
        } else {
            A[k]=r[j++];
        }
    }
}

void mergesort(struct Card A[], int n, int left, int right) {
    if(left+1<right) {
        int mid=(left+right)/2;
        mergesort(A,n,left,mid);
        mergesort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int partition(struct Card A[], int n, int p, int r) {
    int i,j;
    struct Card t,x;
    x=A[r];
    i=p-1;
    for(j=p;j<r;j++) {
        if(A[j].value<=x.value) {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(struct Card A[], int n, int p, int r) {
    int q;
    if(p<r) {
        q=partition(A,n,p,r);
        quicksort(A,n,p,q-1);
        quicksort(A,n,q+1,r);
    }
}

int main()
{
    int n,v;
    struct Card A[100000],B[100000];
    char S[10];
    int stable=1;
    cin >> n;
    rep(i,n) {
        cin >> S >> v;
        A[i].suit=B[i].suit=S[0];
        A[i].value=B[i].value=v;
    }
    mergesort(A,n,0,n);
    quicksort(B,n,0,n-1);
    rep(i,n) {
        if(A[i].suit!=B[i].suit) stable=0;
    }
    if(stable==1) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    rep(i,n) cout << B[i].suit << " " << B[i].value << endl;
    return 0;
}

