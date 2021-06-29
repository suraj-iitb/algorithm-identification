#include<stdio.h>
#define N 100
void show(int,int *);
int main(){
  int i,j,n,key,num[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    show(n,num);
    for(i=1;i<n;i++){
      key=num[i];
      for(j=i-1;j>=0;j--){
	if(key>num[j])
	  break;
	num[j+1]=num[j];
      }
      num[j+1]=key;
      show(n,num);
    }
    return 0;
}
void show(int n,int num[]){
  int i;
  for(i=0;i<n;i++){
    if(i!=0)
      printf(" ");
    printf("%d",num[i]);
  }
  printf("\n");
}
