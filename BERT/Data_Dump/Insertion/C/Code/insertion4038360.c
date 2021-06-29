#include<stdio.h>
#include<stdlib.h>

void screen(int[] ,int);

int main()
{
int i,j;//counter
int N,A[100];
int v;
  
scanf("%d",&N);

for(i=0;i<N;i++)
  {
//     printf("//////////1////////\n");
scanf(" %d",&A[i]);
}
//printf("//////////2////////\n");

screen(A,N);
for(i=1;i<N;i++)
  {
v=A[i];
j=i-1;
while(j>=0 && A[j]>v)
  {
A[j+1] = A[j];
j--;
}
A[j+1] = v;
screen(A,N);
}

return 0;
}

void screen(int A[],int N)
{
int i;
for(i=0;i<N;i++)
  {
if(i<N-1)
  {
printf("%d ",A[i]);
}
 else if(i==(N-1))
   {
printf("%d",A[i]);
break;
}
}

printf("\n");
}

