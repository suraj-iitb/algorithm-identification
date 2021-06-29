#include<stdio.h>
void swap(int *,int*);
int main(){
  int i,j,n,retu[100],sum=0;
  scanf("%d",&n);
  if(n>100)return 0;
  for(i=0;i<n;i++) scanf("%d",&retu[i]);
  
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(retu[j] < retu[j-1]) {
	swap(&retu[j],&retu[j-1]);
	sum++;
      }
    }
  }
  for(i=0;i<n-1;i++)printf("%d ",retu[i]);
  printf("%d",retu[n-1]);
  printf("\n%d\n",sum);
  return 0;
}

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
