#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

void insertionsort(int a[], int n){
  for(int i=0; i < n; i++){
    int v = a[i];
    int j = i-1;
    while(0 <= j && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for(int i=0; i < n; i++){
      if(i)cout << ' ';
      cout << a[i];
    }
    cout << endl;
  }
}



int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0; i < n; i++){
    cin >> a[i];
  }
  insertionsort(a, n);
  return 0;
}
