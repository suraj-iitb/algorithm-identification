/*
17D8101031C 杉山　祥吾 ID:keisei334 C++
*/

#include <iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  for(int k=0;k<n;k++){
    cout<<a[k];
    if(k!=n-1){
      cout<<" ";
    }
  }
  cout<<"\n";

  for(int i=1;i<n;i++){
    int v=a[i];
    int j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    for(int k=0;k<n;k++){
      cout<<a[k];
      if(k!=n-1){
	cout<<" ";
      }
    }
    cout<<"\n";
  }

  return 0;
}

/*実行結果
6
5 2 4 6 1 3
5 2 4 6 1 3
2 5 4 6 1 3 
2 4 5 6 1 3 
2 4 5 6 1 3 
1 2 4 5 6 3 
1 2 3 4 5 6 

3
1 2 3
1 2 3
1 2 3 
1 2 3 
*/
