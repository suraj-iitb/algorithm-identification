#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

void print(int n,vector<int> a){
  cout << a[0];
  for(int i=1;i<n;i++) cout << " " << a[i];
  cout << endl;
}

int main(){
  int n,count=0;
  bool flag = true;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++){
    int minj = i;
    for(int j=i;j<n;j++){
      if(a[j] < a[minj]) minj = j;
    }
    if(minj != i){
      int tmp = a[i];
      a[i] = a[minj];
      a[minj]= tmp;
      count++;
    }
  }
  print(n,a);
  
  cout << count << endl;
  return 0;
}

