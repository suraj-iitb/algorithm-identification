#include<iostream>
using namespace std;

int main(){
  
  int arr[150] = {
    0
  };
  
  int n; cin >> n;
  for(int i=0;i<n;i++)cin >> arr[i];
  
  int count = 0;
  for(int i=0;i<n;i++){
    int index = i;
    for(int j=i;j<n;j++){
      if(arr[index]>arr[j])index = j;
    }
    if(index!=i){
      int temp = arr[i];
      arr[i] = arr[index];
      arr[index] = temp;
      count++;
    }
  }
  
  for(int i=0;i<n;i++){
    if(i==n-1)cout << arr[i] << endl;
    else cout << arr[i] << ' ';
  }
  cout << count << endl;
  
  
  return 0;
}
