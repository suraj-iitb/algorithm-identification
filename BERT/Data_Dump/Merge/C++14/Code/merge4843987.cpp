#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)
#define sc2(a,b)  scanf("%d %d",&a,&b)

#define X 500000
int gk=2e9;
int l[X/2+2];
int r[X/2+2];
int cnt;

void merge(int a[], int n, int left, int mid, int right) {
    int n1=mid-left;
    int n2=right-mid;
    rep(i,n1) l[i]=a[left+i];
    rep(i,n2) r[i]=a[mid+i];
    l[n1]=r[n2]=gk;
    int i=0, j=0;
    for (int k=left;k<right;k++) {
        cnt++;
        if(l[i]<=r[j]) {
            a[k]=l[i++];
        }else{
            a[k]=r[j++];
        }
    }
}

void mergesort(int a[], int n,int left,int right) {
    if (left+1<right){
        int mid=(left+right)/2;
        mergesort(a,n,left,mid);
        mergesort(a,n,mid,right);
        merge(a,n,left,mid,right);
    }
}
int main(){
    int a[X],n;
    cnt=0;
    sc1(n);
    rep(i,n) sc1(a[i]);

    mergesort(a,n,0,n);
    rep(i,n) {
        if (i) printf(" ");
        printf("%d",a[i]);
    }
    puts("");
    printf("%d\n",cnt);
    return 0;
}

