#include <stdio.h>
int main(){
  int A[100];
  int i,j,len,sw,c=0;

  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<len;i++){
    for(j=len-1;i<j;j--){
      if(A[j]<A[j-1]){
	sw=A[j];
	A[j]=A[j-1];
	A[j-1]=sw;
	c++;
      }
    }
    
  }
  for(i=0;i<len;i++){
    printf("%d",A[i]);
    if(i==len-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",c);

  return 0;
}
