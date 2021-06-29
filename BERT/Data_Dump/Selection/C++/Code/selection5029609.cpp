#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;

  int main(){
      int n;
      cin >> n;
      vector<int> a(n);
      rep(i,n)cin >> a[i];

      int count = 0;

      rep(i,n){
          int minj = i;

          for(int j = i;j < n;j++){
              if(a[j] < a[minj]){
                  minj = j;
              }
          }
          int x = a[i];
          a[i] = a[minj];
          a[minj] = x;

          if(minj != i)count++;
      }

      rep(i,n){
          cout << a[i];
          if(i == n - 1)continue;
          cout << " ";
      }
      cout << endl;
      cout << count << endl;
      return 0;
  }
