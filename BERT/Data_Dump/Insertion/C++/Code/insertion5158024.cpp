#include<iostream>

int arr[100];
int main()
{
  int n ; std::cin >> n;
  int key;
  for( int i=0; i<n; ++i ) std::cin>>arr[i];
  for(int k=0; k<n-1; ++k) std::cout<<arr[k]<<" ";

  std::cout<<arr[n-1]<<std::endl;
  for(int i=1; i<n; ++i){
    key = arr[i];
    int j=i-1;
    for(j; j>=0&&arr[j]>key; j-- ){
      arr[j+1] = arr[j];
    }
    arr[j+1]=key;
    for(int k=0; k<n-1; k++) std::cout<<arr[k]<<" ";
    std::cout<<arr[n-1]<<std::endl;
  }
  return 0;
}
