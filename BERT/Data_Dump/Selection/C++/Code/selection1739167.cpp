#include <iostream>
using namespace std;

int selectionSort(int a[], int n){
  int sum=0;
  for(int i=0;i<n;i++){
    int minj=i;
    for(int j=i;j<n;j++){
      if(a[j]<a[minj]) minj=j;
    }
    if(i!=minj){
      int tmp=a[i];
      a[i]=a[minj];
      a[minj]=tmp;
      sum++;
    }
  }
  return sum;
}
      

int main(){
  int n,a[100];

  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  
  int sum=selectionSort(a,n);
  
  for(int i=0;i<n-1;i++)
    cout<<a[i]<<" ";
  cout<<a[n-1]<<endl;
  cout<<sum<<endl;
}
