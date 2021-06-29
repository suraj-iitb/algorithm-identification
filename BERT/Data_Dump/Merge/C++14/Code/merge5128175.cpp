#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;
ll ans = 0;
void merge(int *data,int l,int mid,int r){
  int n1 = mid-l+2;
  int n2 = r-mid+1;
  int L[n1] = {};
  int R[n2] = {};
  for(int i=l;i<=mid;i++){
    L[i-l] = data[i];
  }
  for(int i=mid+1;i<=r;i++){
    R[i-mid-1] = data[i];
  }
  L[n1-1] = INF;
  R[n2-1] = INF;
  int cnt1 = 0,cnt2 = 0;
  for(int i = l;i<=r;i++){
    ans++;
    if(L[cnt1] > R[cnt2]){
      data[i] = R[cnt2++];
    }else{
      data[i] = L[cnt1++];
    }
  }
}
void merge_sort(int* data, int l, int r){
  if(l == r)return;
  ll mid = (l+r)/2;
  merge_sort(data,l,mid);
  merge_sort(data,mid+1,r);
  merge(data,l,mid,r);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  int data[n] = {};
  for(int i=0;i<n;i++){
    cin>>data[i];
  } 
  merge_sort(data,0,n-1);
  for(int i=0;i<n;i++){
    cout<<data[i];
    if(i!=n-1)cout<<" ";
  }
  cout<<endl;
  cout<<ans<<endl;
  return 0;
}

