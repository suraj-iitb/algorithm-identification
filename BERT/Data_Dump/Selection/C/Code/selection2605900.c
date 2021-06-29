#include<stdio.h>
int main()
{
  int A[100];
  int i,j;
  int temp=0;
  int hant_num=0;
  int num,mini;
 
  scanf("%d",&num);
  for(i=0;i<num;i++)
   {
    scanf("%d",&A[i]);
     
     }
   
   for (i=0;i<num;i++)
   {
     mini = i;
     for (j=i;j<num;j++)
    {
     if (A[j] < A[mini]) mini = j;
    }
     if (A[i] > A[mini])
     {
      temp = A[i];
      A[i] = A[mini];
      A[mini] = temp;
      hant_num++;
      }
    }
   for (i=0;i<num;i++)
   {
    printf("%d",A[i]);
     if (i<num-1) printf(" ");
     }
    printf("\n%d\n",hant_num);
   return 0;
}
