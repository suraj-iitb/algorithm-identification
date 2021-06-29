#include<iostream>
using namespace std;
int main(){
    int n,count = 0;
    cin>>n;
    int l[100];
    for(int i = 0; i<n; i++){
        cin>>l[i];
    }
    for(int i = 0; i<n-1; i++){
        int minj = i;
      for(int j = i; j < n; j++){
          if(l[j]<l[minj]) minj = j;
      }
      if(l[minj]==l[i]) continue;
      int min = l[minj];
      l[minj] = l[i];
      l[i] = min;
      count++;
    }
    for(int k= 0; k<n-1; k++){
      cout<<l[k]<<" ";
    }
    cout<<l[n-1]<<endl;
    cout<<count<<endl;
}
