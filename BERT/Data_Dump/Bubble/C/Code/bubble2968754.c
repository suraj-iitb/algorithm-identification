#include<stdio.h>
#include<stdlib.h>
int BubSort(int *,int);
void ShowData(int *,int);

int main(){
  int i,n,N;
  int *P;

  scanf("%d",&n);
  P=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&P[i]);
  }
  N=BubSort(P,n);
  ShowData(P,n);
  printf("%d\n",N);
  return 0;
}

  int BubSort(int *P,int n){
    int i,j,tmp,N=0;
    for(i=0;i<n-1;i++){
      for(j=n-1;j>i;j--){
	if(P[j-1]>P[j]){
	  tmp=P[j];
	  P[j]=P[j-1];
	  P[j-1]=tmp;
	  N++;
	}
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

