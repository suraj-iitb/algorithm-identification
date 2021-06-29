//Insertion Sort
#include<stdio.h>

int length;
int A[1000]={0};

void intput()
{
  int i;
  scanf("%d",&length);
  for(i=1;i<=length;i++)
    scanf("%d",&A[i]);
}

void output()
{
  int i,j;
  for(i=1;i<length;i++){
    printf("%d ",A[i]);
   }
   printf("%d\n",A[i]);
}

void Sort()
{
  int i,j;
  int key;
  for(i=1;i<=length;i++){
    key = A[i];
    for(j=i-1;j>=0;j--){
      if(A[j]<=key){
        A[j+1]=key;
        break;
      }
      
      A[j+1] = A[j];
    }
    output();
  }
}

int main()
{
  intput();
  Sort();
  return 0;
}


