#include <iostream>
#define SWAP(a,b) do{int t; t=a, a=b, b=t;}while(0)
using namespace std;

int main()
{
   ios::sync_with_stdio(false), cin.tie(0);
   int N;
   int a[102];

   cin >> N;
   for(int i=0; i<N; ++i)cin >> a[i];

   int cnt = 0;
   bool flag = true;

   for(int i=0; flag; ++i){
      flag = false;
      for(int j = N-1; j > i; --j){
         if(a[j-1] > a[j]){
            SWAP(a[j-1], a[j]);
            ++cnt;
            ++flag;
         }
      }
   }
   for(int i=0; i<N; ++i)
      cout << a[i] << (i+1 < N ? ' ' : '\n');
   cout << cnt << endl;
}

