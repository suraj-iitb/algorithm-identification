#include<stdio.h>
#define MAX 100
int swap(int *x,int *y)
{
  int z=*x;
  if(*x==*y)return 0;//同じだったら０
  *x=*y;
  *y=z;
  return 1;//違ったら１
}

//Aに代入された数をnまで並べ替えて、入れ直す
//　　　/交換回数
int bubbleSort(int *A, int n)
{
  int flag=1;
  int i,j;
  int count=0;//交換回数
  for (i=0;flag;i++){
    flag = 0;//一回も交換しない、 つまり既に並んんでいたら０

    for (j = n-1;j>=1;j--){
      if (A[j] < A[j-1])
	{
	  swap(&A[j],&A[j-1]);
	  count++;
	  flag=1;
	}
    }
  }
  return count;
}


int main(){
  int i;
  int A[MAX]; // need
  int n;
  int count;
  
  scanf("%d",&n);//Input
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
 
  count=bubbleSort(A,n);
  
  for(i=0;i<n;i++){//OUTPUT
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}
/*5
1 2 3 4 5を昇順に並べ替える
出力はそれと、交換回数*/

