#include<stdio.h>
int main(){
 
int A,B,a[100000],b[500],C=0,k,i;
 
scanf("%d",&A);
for(k=0;k<A;k++)
scanf("%d",&a[k]);

scanf("%d",&B);
for(k=0;k<B;k++)
scanf("%d",&b[k]);

for(i=0;i<B;i++){
for(k=0;k<A;k++){
if(a[k]==b[i]){
C++;
break;
}
}
}

printf("%d\n",C);
 
}
