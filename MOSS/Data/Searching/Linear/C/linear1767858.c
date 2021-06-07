#include<stdio.h>
#define N 100000
int linearSearch(int* ,int,int);


int main(){

  int A[N],B[N],num1,num2,i,j,k,cnt=0,x;
  scanf("%d",&num1);

  for(i=0;i<num1;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&num2);

  for(i=0;i<num2;i++){
    scanf("%d",&B[i]);
  }

  for(i=0;i<num2;i++){
    x= linearSearch(&A[0],B[i],num1);

   if(x==1)cnt++;
  }


  printf("%d\n",cnt);
  return 0;

}


int linearSearch(int A[],int key,int num){


  int i;
  for(i=0;i<num;i++){

   
    if (A[i]==key)return 1;
  }
return 0;
}
