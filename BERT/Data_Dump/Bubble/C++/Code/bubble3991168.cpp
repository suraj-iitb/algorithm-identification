#include<iostream>
#include<cstdio>
using namespace std;

int bubbleSort(int a[],int n)
{
  int tot=0;
  bool flag=1;
  for(int i=0;flag;i++)
  {
      flag=0;
      for(int j=n-1;j>=i+1;j--){
          if(a[j]<a[j-1])
          {
              swap(a[j],a[j-1]);
              flag=1;
              tot++;
          }
      }
      
  }
  return tot;
    
}
int main(){
    int a[100],n,tot;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    tot=bubbleSort(a,n);
    for(int i=0;i<n;i++){
        if(i) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<tot<<endl;
    return 0;
}
