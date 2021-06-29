#include <stdio.h>
#include <stdlib.h>

int selectionSort(int *ori,int );

int main()
{
  int i,atai,n,ori[100];
  
  scanf("%d",&n);
  if(n<1 || n>100) exit(7);
  for(i=0;i<n;i++){
    scanf("%d",&ori[i]);
  }

  atai=selectionSort(ori,n);

   for(i=0;i<n;i++){
     printf("%d",ori[i]);
     if(i<n-1) printf(" ");
   }
   
   printf("\n");
   
   printf("%d\n",atai);
  
  return 0;
}

int selectionSort(int *ori,int n)
{
  int i,j,count=0,minj,kawari,space,record;

  for(i=0;i<n;i++){
    space=i;
    for(j=i;j<n;j++){
      if(ori[j]<ori[space]){
	space=j;
	record=ori[j];
      }
    }
    if(space!=i){ 
    kawari=ori[i];
     ori[i]=record;
      ori[space]=kawari;
      count++;
    }
  }

  return count;
}

