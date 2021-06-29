#include <stdio.h>

int bubbleSort(int *,int );

int main()
{
  int atai,n,i,ori[100];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ori[i]);
  }

  atai= bubbleSort(ori,n);

  for(i=0;i<n-1;i++){
  printf("%d ",ori[i]);
  }
  printf("%d\n",ori[n-1]);
  printf("%d\n",atai);

  return 0;
}

int bubbleSort(int *ori,int n)
{
  int count=0,i,j;
  int kawari; 

  for(i=0;i<n-1;i++){  
    for(j=n-1;j>i;j--){
      if(ori[j]<ori[j-1]){
      kawari=ori[j];
      ori[j]=ori[j-1];
      ori[j-1]=kawari;
      count++;
      }
    }
  }
    
  return count;
}

