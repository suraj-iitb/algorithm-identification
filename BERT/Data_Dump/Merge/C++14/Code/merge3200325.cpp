#include<bits/stdc++.h>

using namespace std;
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007;
#define INF 2000000000
#define int long long
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,j,n) for(int i=j;i<n;i++)
int ll[500000],rr[500000];
long long cnt=0;	
  int a[500000];	

int merge(int l, int m,int r){
  int n1=m-l;
  int n2=r-m;
  lp(i,n1) ll[i]=a[l+i];
  lp(i,n2) rr[i]=a[m+i];
  int i=0,j=0;
  ll[n1]=INF;
  rr[n2]=INF;
  lps(k,l,r){
    if(ll[i]<rr[j]){
      a[k]=ll[i];
      i++;
    }
    else{
      a[k]=rr[j];
      j++;
    }
      cnt++;
  }
  return cnt;
}

int mergesort(int l,int r){
  if(l+1<r){
    int m=(l+r)/2;
    mergesort(l,m);
    mergesort(m,r);
    merge(l,m,r);
  }
  else return 0;
}

signed main(){
  int n;
  cin>>n;
  lp(i,n){
    cin>>a[i];
  }
  mergesort(0,n);
  lp(i,n){
  	if(i!=0) cout<<" ";
  	cout<<a[i];
  }
  cout<<endl;
  cout<<cnt<<endl;
  return 0;
}


