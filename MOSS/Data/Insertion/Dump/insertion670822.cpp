#include<iostream>
using namespace std;

int main(){
  int n,i;
  int a[100];

  cin >> n;
  for(i=0;i<n;i++)cin >> a[i];
  for(i=0;i<n;i++)cout << a[i] << ((i==n-1)?'\n':' ');
  for(int j=1;j<n;j++){
    int key = a[j];
    i = j-1;
    while(i>=0 && a[i]>key){
      a[i+1] = a[i];
      i--;
    }
    a[i+1] = key;
    for(i=0;i<n;i++)cout << a[i] << ((i==n-1)?'\n':' ');
  }
}
