#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n,a[100],cnt=0;
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  bool flag=true;
  while(flag){
   flag = false;
   for(int i=0;i<n-1;i++){
    if(a[i]>a[i+1]){
     swap(a[i],a[i+1]);
     flag=true;
     cnt++;
    }
   }
 }
 for(int i=0;i<n;i++){cout << a[i] ; if(i!=n-1)cout << " ";}
 cout << endl << cnt << endl;
}
