#include <stdio.h>

int main (void)
{
int a[100000],b[50000],A,B,i,C=0;
int min,max,mid;

scanf("%d",&A); 
for(i=0;i<A;i++)
scanf("%d",&a[i]); 

scanf("%d",&B);
for(i=0;i<B;i++){
scanf("%d",&b[i]);

min=0; max=A;
while(min<max){
 mid=(min+max)/2;
  if(a[mid]==b[i]){
    C++;
    break;
   }
  else if(b[i]<a[mid])
    max=mid;
  else
    min=mid+1;
}

}

printf("%d\n",C);
return 0;
}

