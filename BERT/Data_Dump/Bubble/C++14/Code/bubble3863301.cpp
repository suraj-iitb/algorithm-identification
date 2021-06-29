#include <bits/stdc++.h>  // ver1.9.4
#define int long long
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define pb push_back
#define mp make_pair
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define Vout(a) rep(i,0,a.size()-1)cout<<a[i]<<' ';cout<<a[a.size()-1]<<endl;
#define INF 9000000000000000000  //  9.0 * 10^18
#define MOD 1000000007  //  10^9 + 7
using namespace std;

signed main() {
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  Vi a(n);
  int ct=0;
  rep(i,0,n) cin >> a[i];
  repeq(i,1,n-1){
    repreq(j,n-1,i){
      if(a[j-1]>a[j]){
        ct++;
        swap(a[j-1],a[j]);
      }
    }
  }
  Vout(a);
  cout << ct << endl;
  return 0;
}

