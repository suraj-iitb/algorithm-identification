#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

void selectionSort(int *a, int n){
  int minj;
  int cnt=0;
  for(int i=0;i<n;i++){
    minj=i;
    for(int j=i;j<n;j++){
      if(a[j]<a[minj]) minj=j;
    }
    if(i!=minj){
      std::swap(a[i], a[minj]);
      cnt++;
    }
  }
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl <<cnt << endl;
}

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++)
    cin >> a[i];
  selectionSort(a,n);
  return 0;
}

