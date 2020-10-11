#include <stdio.h>


int Seksort(int *p,int len){

  int i,j,tmp,low;
    int c=0;

  for(i=0;i<len;i++){
    low=i;
    for(j=i;j<len;j++){

      if(p[j]<p[low]) low = j;

    }
    if( i != low){

      tmp=p[i];
      p[i]=p[low];
      p[low]=tmp;
      c++;
    }
  }
  return c;


}


main(){
  int i,a,A[100],c=0;

  scanf("%d",&a);



  for(i=0; i <a; i++){
    scanf("%d",&A[i]);

  }

  c=Seksort(A,a);

  printf("%d",A[0]);

  for(i=1; i < a; i++){
    printf(" %d",A[i]);
  }

  printf("\n%d\n",c);

return 0;
}
