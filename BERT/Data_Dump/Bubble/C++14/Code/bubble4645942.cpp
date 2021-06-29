#include<iostream>
using namespace std;
int main(){
    int n,count=0;
    cin >> n;
    int l[100];
    for(int i = 0; i<n; i++){
        cin >> l[i];
    }
    for(int i = n-1; i > 0 ; i--){
      for(int j = 0; j<i; j++){
        if (l[j]>l[j+1]){
          l[j] += l[j+1];
          l[j+1] = l[j] - l[j+1];
          l[j] = l[j] -l[j+1];
          count++;
        }   
      }
    }
    for(int k = 0 ; k<n-1 ;k++){
        cout<<l[k]<<" ";
    }
    cout<<l[n-1]<<endl;
    cout<<count<<endl;
}
