#include <bits/stdc++.h> 

using namespace std; 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>; 

#define INF 100000000
#define MOD 10007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()

//#define DEBUG

int main_(){
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++)cout<<A[i]<<" \n"[i==N-1];
  for(int i=1;i<N;i++){
    for(int j=i;j>0;j--){
      if(A[j]<A[j-1])swap(A[j],A[j-1]);
      else break;
    }
    for(int j=0;j<N;j++)cout<<A[j]<<" \n"[j==N-1];
  }
  return 0;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  vector<string>test;
  /*
   * input for debug
   */
  for(int i=0;i<test.size();++i){
    stringbuf buf;
    streambuf*out=cout.rdbuf(&buf);
    cout<<test[i]<<flush;
    cout.rdbuf(out);
    streambuf*in=cin.rdbuf(&buf);
    main_();
    cin.rdbuf(in);
    cout<<endl;
  }
#else
  main_();
#endif

  return 0;
}

