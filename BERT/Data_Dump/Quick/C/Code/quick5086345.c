#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char sign;
  int num;
  int f;
}T;

T A[1000001];

int s;

int partition(int p,int r)
{
  int i,j,x;
  T n,m;
  
  x = A[r].num;
  i = p-1;

  for(j = p;j < r;j++){
    if(A[j].num <= x){
      i = i+1;
      m = A[i];
      A[i] = A[j];
      A[j] = m;
    }
   
  } 
      n = A[i+1];
      A[i+1] = A[r];
      A[r] = n;
   
      return i+1;
}

void quickSort(int p,int r)
{
  int q;
  if(p < r){
    q = partition(p,r);
    quickSort(p,q-1);
    quickSort(q+1,r);
  }
}
    
    
 

int main()
{
  int i,j;
 

  scanf("%d",&s);

  for(i = 1;i <= s;i++){
    scanf(" %c%d",&A[i].sign,&A[i].num);
    A[i].f = i;
  }

 
   quickSort(1,s);

   int flag = 0;
   for(i = 2;i < s+1;i++){
     if(A[i-1].num == A[i].num && A[i-1].f > A[i].f){
       flag =1;
       break;
       
     }
   }

   
   if(flag == 0)printf("Stable\n");
   else if(flag == 1) printf("Not stable\n");
   for(i = 1;i <=s;i++){
     printf("%c %d\n",A[i].sign,A[i].num);
   }  
  
  
  return 0;
}

