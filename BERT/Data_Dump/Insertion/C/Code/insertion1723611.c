#include <stdio.h>
#define N 1000
int main(){
  int i,inputnumber,key,j,k;
  int A[N];
  scanf("%d",&inputnumber);
  for(i=0;i<inputnumber;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<inputnumber;i++){
    for(k=0;k<inputnumber;k++) {
      if(k!=inputnumber-1) printf("%d ",A[k]);
      else printf("%d\n",A[k]);
    }
    key=A[i];
    j=i-1;
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
  }
  for(k=0;k<inputnumber;k++) {
    if(k!=inputnumber-1) printf("%d ",A[k]);
    else printf("%d\n",A[k]);
  }
  return 0;
}
