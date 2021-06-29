#include <iostream>
#include <vector>
using namespace std;

void solv(vector<int>& arr){
  for(int i=1;i<arr.size();i++){
      
    for(int k=0;k<arr.size()-1;k++){
      cout<<arr[k]<<" ";
    }
    cout<<arr[arr.size()-1]<<endl;
    
    auto key = arr[i];
    auto j = i - 1;
    while(j>=0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    } 
    arr[j+1] = key;
  }
  
  for(int k=0;k<arr.size()-1;k++){
    cout<<arr[k]<<" ";
  }
  cout<<arr[arr.size()-1]<<endl;
  
}

int main(){
  int n, m;
  vector<int> arr;
  cin>> n;
  for(int i=0;i<n;i++){
    cin>> m;
    arr.push_back(m);
  }
  solv(arr);
  return 0; 
}
