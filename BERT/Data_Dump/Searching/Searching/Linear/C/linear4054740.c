#include <stdio.h>
int search(int A[],int kazu,int suji);
int main()
{
int i,kazu,suji,A[10000+1],flag,sum=0;
scanf("%d",&kazu);
 for(i=0;i<kazu;i++){
   scanf("%d",&A[i]);
 }
 scanf("%d",&suji);
 for(i=0;i<suji;i++){
   scanf("%d",&flag);
   if(search(A,kazu,flag)) sum++;
 }
printf("%d\n",sum);

return 0;
}

 int search(int A[],int kazu,int flag)
 {
int a=0;
A[kazu]=flag;
while(A[a]!=flag)a++;
return a!=kazu;
 }

