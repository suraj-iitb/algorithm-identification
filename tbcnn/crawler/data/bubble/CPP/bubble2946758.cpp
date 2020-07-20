#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   for(int i=0;i<(n);++i)
#define SORT(c)    sort((c).begin(),(c).end())
const double EPS = 1e-10;//sample:if((double)>=(double)+EPS)
#define CLR(a) memset((&a), 0 ,sizeof(a))//clear memory
#define dump(x)  cerr << #x << " = " << (x) << endl;//debug
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
//cin,cout release
//std::cin.tie(0);
//ios::sync_with_stdio(false);

int cont = 0;

void bsort(int A[],int n){
  bool flag = 1;
  while(flag){
    flag = 0;
    for(int j = n-1; j >= 1; j--){
      if(A[j] < A[j-1]){
	swap(A[j],A[j-1]);
	flag = 1;
	cont++;
      }
    }
  }
}

int main(void){
  int n, a[100];
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  bsort(a,n);
  for(int i=0;i<n-1;i++)printf("%d ",a[i]);cout<<a[n-1]<<endl;
  cout<<cont<<endl;
  return 0;
}

