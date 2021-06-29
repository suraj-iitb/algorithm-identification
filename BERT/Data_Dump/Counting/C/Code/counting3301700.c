#include<stdio.h>
#include<stdlib.h>
#define N 20000000
#define K 10000
void CS(int *,int *,int,int);
void show(int *,int);
int main(){
  int n,i,*num,*ans,*p,max=0;
  
  scanf("%d",&n);
  num=(int *)malloc(n*sizeof(int));
  ans=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
  scanf("%d",&num[i]);
  if(max<num[i])
    max=num[i];
}
  max++;
 
   CS(num,ans,n,max);
  show(ans,n);
  return 0;
}
  void CS(int num[],int ans[],int n,int max){
  int i,*C;
  C=(int *)malloc(max*sizeof(int));
  for(i=0;i<max;i++)
    C[i]=0;
  for(i=0;i<n;i++)
    C[num[i]]++;
  for(i=1;i<max;i++)
    C[i]+=C[i-1];

  for(i=n-1;i>=0;i--){

  ans[C[num[i]]-1]=num[i];
  C[num[i]]--;
}
}
  void show(int ans[],int n){

  int i;
  for(i=0;i<n;i++){
  if(i!=0)
    printf(" ");
  printf("%d",ans[i]);
      }
  printf("\n");
}

