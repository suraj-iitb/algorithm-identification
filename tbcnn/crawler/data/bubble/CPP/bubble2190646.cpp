#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
  int n;
  int a[111];
  
  scanf(" %d",&n);
  
  for(int i=0;i<n;i++){
    scanf(" %d",&a[i]);
  }

  int cnt=0;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
      if(a[j]>a[j+1]){
	int temp=a[j];
	a[j]=a[j+1];
	a[j+1]=temp;
	cnt++;
      }
    }
  }
  
  for(int i=0;i<n;i++){
    printf("%d",a[i]);
    if(i+1!=n){
      printf(" ");
    }
  }
  
  printf("\n%d\n",cnt);

  return 0;
}
