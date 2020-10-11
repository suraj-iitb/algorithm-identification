#include<stdio.h>
void swap(int *,int *);
int sum=0;
int main(){
  int n,i,retu[100],mini,j;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&retu[i]);
  
  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(retu[j] < retu[mini]){
	mini = j;
      }
    }
    if(i!=mini)swap(&retu[i],&retu[mini]);
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
  sum++;
}
