
#include <stdio.h>

int main(){
  int n,mini,a,count,A[100],i,j;
  count=0;

  //*ｎの読み込み*//
  scanf("%d",&n);
  //*ｎが制約外errorなら表示*//
  if(n>100||n<1){
    printf("error\n");
  }
  //*数列の読み込み*//
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  //*並び替え*//
  for(i=0;i<n;i++){
    mini=i;
    for(j=i+1;j<n;j++){
      //*最小値を比べる*//
      if(A[j]<A[mini]){
        mini=j;
      }
    }
    a=A[mini];
    A[mini]=A[i];
    A[i]=a;
    if(i!=mini){
      count++;
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d",count);
  printf("\n");
  return 0;
}
