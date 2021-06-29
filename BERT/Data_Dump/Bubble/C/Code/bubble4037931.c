#include<stdio.h>
int main(){
  int data,i,A[100],check=0,tmp,total=0;
  scanf("%d",&data);
  for(i=0;i<data;i++)scanf("%d",&A[i]);
  while(1){
    for(i=data-1;i>0;--i){
      if(A[i-1] > A[i]){
	tmp = A[i];
	A[i] = A[i-1];
	A[i-1] = tmp;
	check++;
      }
    }
    if(check == 0)break;
    total +=check;
    check = 0;  
  }
  for(i=0;i<data;i++){
    if(i == data-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",total);
  return 0;
}
