#include <iostream>
using namespace std;

int bubbleSort(int a[],int n){
  int flag=1,sum=0;
  while(flag){
    flag=0;
    for(int j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	int tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	flag=1; sum++;
      }
    }
  }
  return sum;
}

int main(){
  int n,a[100];

  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];

  int sum=bubbleSort(a,n);
  
  for(int i=0;i<n-1;i++)
    cout<<a[i]<<" ";
  cout<<a[n-1]<<endl;;
  cout<<sum<<endl;
}
