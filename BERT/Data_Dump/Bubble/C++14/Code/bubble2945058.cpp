#include <iostream>
using namespace std;
int main(){

  int n,a[100],result=0;

  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n-1;i++) for(int j=n-2;j!=i-1;j--) if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
        result++;
      }
  for(int i=0;i<n-1;i++) cout<<a[i]<<" ";
  cout<<a[n-1]<<endl<<result<<endl;

  return 0;
  
}
