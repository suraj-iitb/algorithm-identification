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
void aprint(int A[], int n){
  for(int i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
}

void insertion_sort(int A[], int n){
  for(int i = 0;i < n;i++){
    int temp = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > temp){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = temp;
    aprint(A,n);
  }

}

int main(void){
  int n;
  cin>>n;
  int arr[100];
  for(int i=0;i<n;i++) cin>>arr[i];
  insertion_sort(arr,n);
  return 0;
}

