#include <iostream>
using namespace std;
int main(void){
  int n,a[100],ans=0;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n-1;i++){
    for(int j=n-1;j>i;j--){
      if(a[j-1]>a[j]){
	swap(a[j-1],a[j]);
	ans++;
      }
    }
  }
  for(int i=0;i<n-1;i++)
    cout<<a[i]<<" ";
  cout<<a[n-1]<<endl;
  cout<<ans<<endl;
  return 0;
}
