#include <iostream>
using namespace std;

int main()
{
   ios::sync_with_stdio(false), cin.tie(0);
   int N;
   int a[102];

   cin >> N;
   for(int i=0; i<N; ++i)cin >> a[i];

   int cnt = 0;

   for(int i=0; i < N; ++i){
      int minj = i;
      for(int j = i+1; j < N; ++j){
         if(a[j] < a[minj])minj = j;
      }
      if(i != minj){
         int t = a[i];
         a[i] = a[minj];
         a[minj] = t;
         ++cnt;
      }
   }
   for(int i=0; i<N; ++i)
      cout << a[i] << (i+1 < N ? ' ' : '\n');
   cout << cnt << endl;
}

