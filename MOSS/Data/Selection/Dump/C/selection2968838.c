#include<stdio.h>
#include<stdlib.h>

int SelSort(int *,int);
void ShowData(int *,int);

int main(){
  int i,n,N;
  int *P;

  scanf("%d",&n);
  P=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&P[i]);
  }
  N=SelSort(P,n);
  ShowData(P,n);
  printf("%d\n",N);
  return 0;
}

int SelSort(int *P,int n){
  int i,j,min,tmp,N=0;
  
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(P[j]<P[min]){
	min=j;
      }
    }
    if(P[i]>P[min]){
      tmp=P[i];
	 P[i]=P[min];
	 P[min]=tmp;
	 N++;
    }
  }
  return N;
    }

void ShowData(int *P,int n){
  int i;
  for(i=0;i<n;i++){
    if(i!=n-1){
      printf("%d ",P[i]);
    }
      else{
	printf("%d",P[i]);
      }
  }
      printf("\n");
}
  
       
    

