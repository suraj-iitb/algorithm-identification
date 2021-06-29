#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int a[100];
  int mini;
  int temp;
  int cnt=0;

  cin >> n;

  for(int i=0;i < n;i++){
    cin >> a[i];
  }

  for(int i=0;i < n;i++){
    mini = i;
    for(int j=i;j < n;j++){
      if(a[j] < a[mini]){
	mini = j;
      }
    }
    temp = a[mini];
    a[mini] = a[i];
    a[i] = temp;
    if(mini != i) cnt++;
  }
  
  for(int i=0;i < n;i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}
