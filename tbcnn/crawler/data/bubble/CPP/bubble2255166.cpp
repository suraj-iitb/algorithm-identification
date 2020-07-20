#include <iostream>

using namespace std;

int c=0;

void bubbleSort(int a[],int n){
  bool flag=1;
  while(flag){
    flag=0;
    for(int j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
        int t=a[j];
        a[j]=a[j-1];
        a[j-1]=t;
        c++;
        flag=1;
      }
    }
  }
}
int main(){
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  bubbleSort(a,n);
  for(int i=0;i<n-1;i++){
    cout << a[i] << " ";
  }
  cout << a[n-1] << '\n';
  cout << c <<endl;
}
