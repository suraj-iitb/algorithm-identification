#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int *array = new int[n];
  for(int i=0;i<n;i++){
    cin>>array[i];
  }
  bool flag = 1;
  int count=0;
  while(flag){
    flag = 0;
    for(int j=n-1;j>=1;j--){
      if(array[j] < array[j-1]){
	swap(array[j],array[j-1]);
	flag = 1;
	count++;
      }
    }
  }
  cout<<array[0];
  for(int i=1;i<n;i++)
    cout<<" "<<array[i];
  cout<<'\n'<<count<<endl;
  delete []array;
  return 0;
}
