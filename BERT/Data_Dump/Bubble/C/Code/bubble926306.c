#include <stdio.h>



int BubbleSort(int *p,int len){

  int i,j,tmp,c=0;
  for(i=0;i<len;i++){
    for(j=len-1;j>i;j--){
      if(p[j] < p[j-1]){
        tmp = p[j];
        p[j]=p[j-1];
        p[j-1]=tmp;
        c++;
      }
    }
  }
    return c;

}

main(){

    int i,a,c=0;
    int A[100];
    scanf("%d",&a);

    for(i=0;i<a;i++){
      scanf("%d",&A[i]);
    }


    c=BubbleSort(A,a);

    printf("%d",A[0]);

    for(i=1;i<a;i++){
      printf(" %d" ,A[i]);
    }

    printf("\n%d\n",c);

   return 0;
  }
