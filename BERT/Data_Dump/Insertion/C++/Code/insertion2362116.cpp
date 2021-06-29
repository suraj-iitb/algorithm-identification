#include <iostream>

using namespace std;

void print(int *p,int n){
    for(int i=0;i<n;i++){
        cout << p[i];
        if(i<n-1) cout << " ";
    }
    cout << endl;
}

int main(){
  int n,i,j,v;
  cin >> n;
  int a[n];
  for(i=0;i<n;i++){
      cin >> a[i];
  }
  for(i=0;i<n;i++){
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=v;
    print(a,n);
  }
  return 0;
}
