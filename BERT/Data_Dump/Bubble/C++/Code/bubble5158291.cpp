#include<iostream>
using namespace std;

int main()
{
  int n; cin>>n;
  int *p = new int[n];
  for(int i=0; i<n; ++i) cin>>p[i];
  int total=0;
  for(int i=0; i<n-1; ++i)
    for(int j=n-1; j>=i+1; --j){
      if(p[j]<p[j-1]){
        int temp=0;
        temp = p[j]; p[j]=p[j-1]; p[j-1]=temp;
        total++;;
      }
    }
    for(int i=0; i<n-1; ++i) cout<<p[i]<<' '; 
    cout<<p[n-1]<<endl<<total<<endl;
    return 0;
}
