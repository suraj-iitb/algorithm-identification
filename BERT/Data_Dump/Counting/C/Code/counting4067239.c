#include<stdio.h>
#include<stdlib.h>

#define MAX 2000001
#define MIN 10000

int main()

{
 unsigned short *R,*L;
 
 int num[MIN+1];
 int i,j,k;
 scanf("%d",&i);
 
 R=malloc(sizeof(short)*i+1);
 L=malloc(sizeof(short)*i+1);
 
 for(j=0;j<=MIN;j++)
 {
     num[j]=0;
 }
 for(j=0;j<i;j++)
 {
     scanf("%hu",&R[j+1]);
     num[R[j+1]]++;
 }
 for(j=1;j<=MIN;j++)
 {
     num[j]+=num[j-1];
 }
 for(k=1;k<=i;k++)
 {
     L[num[R[k]]]=R[k];
     num[R[k]]--;
 
 }
 
 for(j=1;j<=i;j++)
 {
     if(j>1)printf(" ");
     printf("%d",L[j]);
 }
 
 printf("\n");
    
    return 0;
}

