#include <iostream>
using namespace std;

int main(){
  int n;
  int a[110];
  cin>>n;
  for (int i=0; i<n; ++i) cin>>a[i];
  
  bool flag = true;
  int counter = 0;
  
  for (int j=0; flag; j++){
    flag=false;
    for (int i=n-1; i>=j+1; i--){
      if (a[i]<a[i-1]){
        swap(a[i],a[i-1]);
        flag=true;
        counter++;
      }
    }
  }
  for (int i=0; i<n; ++i){
    if (i) cout << " ";
    cout<<a[i];
  }
  cout<<endl;
  cout<<counter<<endl;
}
      
