#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  int count=0;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(a[j]>a[j+1]){
	count++;
	int temp=a[j];
	a[j]=a[j+1];
	a[j+1]=temp;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i+1==n) printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",count);
  return 0;
}

