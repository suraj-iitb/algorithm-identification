#include<stdio.h>

int main(){

  int i,j,k=0,key,tmp,num;
  int A[1000];

  //Insertion Sort program

  scanf("%d",&num);

  for(i=0;i<num;i++) scanf("%d",&A[i]);

//for(i=0;i<num;i++) printf("%d ",A[i]);

/*  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      if(A[i]<A[j]){
        tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
      for(k=0;k<num;k++) printf("%d ",A[k]);
      printf("\n");
      }}}
*/

  for(i=0;i<num;i++){
        key = A[i];
  /* insert A[i] into the sorted sequence A[0,...,j-1] */
        j = i - 1;
        while(j >= 0 && A[j] > key){
        A[j+1] = A[j];
        j--;
        A[j+1] = key;
        }
        for(k=0;k<num;k++)
          if(k==num-1) printf("%d",A[num-1]);
        else printf("%d ",A[k]);
        printf("\n");
  }
//for(i=0;i<num;i++) printf("%d ",A[i]);
//printf("\n");

return 0;

}
