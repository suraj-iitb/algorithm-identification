#include<stdio.h>
#define N 10000
int se(int a,int A[],int b,int B[]);
int main(){
  int a,A[N];
  int b,B[N];
  int i;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&B[i]);
  }
  printf("%d\n",se(a,A,b,B));
  return 0;
}




int se(int a,int A[],int b,int B[]){
  int i,j;
  int c=0;
  for(j=0;j<b;j++){
  for(i=0;i<a;i++) {
    if(A[i]==B[j]){
      c++;
      break;
    }
  }
 }
return c;

}

