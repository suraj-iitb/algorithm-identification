#include<stdio.h>
int linearSearch(int*,int,int);
int main(){

  int i;
  int n,q;
  int count=0,flag=0;

  scanf("%d",&n);
  int data1[n];
  for(i=0;i<n;i++){
    scanf("%d",&data1[i]);
  }
  
  scanf("%d",&q);
  int data2[q];
  for(i=0;i<q;i++){
    scanf("%d",&data2[i]);
  }
  
  for(i=0;i<q;i++){
    if(linearSearch(data1,n,data2[i])==1){
      count++;
    }
  }
  printf("%d\n",count);
  
  return 0;
}
int linearSearch(int *data,int n,int key){

  int i;
  
  for(i=0;i<n;i++){
    if(data[i]==key) return 1;
  }
  return 0;
}

