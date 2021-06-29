#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,x;
  vector<int> a;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> x;
    a.push_back(x);
  }

  int v;
  for(int i=1;i<a.size();i++){
     for(int i=0;i<a.size();i++){
      if(i==a.size()-1){
	cout << a[i] << endl;
      }
      else{
	cout << a[i] << " ";
      }
     }
    v=a[i];
    int j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
  }
  for(int i=0;i<a.size();i++){
    if(i==a.size()-1){
      cout << a[i] << endl;
    }
    else{
      cout << a[i] << " ";
    }
  }
}

