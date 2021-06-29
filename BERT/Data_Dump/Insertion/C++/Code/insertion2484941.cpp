#include <iostream>

using namespace std;

void output(int a[],int n){
  for(int i=0;i<n;i++){
    if(i) cout << " " << a[i];
    else cout << a[i];
  }
  cout << endl;
}

int main(){
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  output(a,n);
  for(int i=1;i<n;i++){
    int v=a[i];
    int j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    output(a,n);
  }
}
