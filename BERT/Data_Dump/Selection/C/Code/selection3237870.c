#include<stdio.h>
int main(){
 
int N,k,a[100],m,tmp,A=0,min;
 
scanf("%d",&N);
 
for(k=0;k<N;k++)
scanf("%d",&a[k]);


 
for(m=0;m<=N-1;m++){
 
min=m;
for(k=m;k<=N-1;k++){
if(a[min]>a[k])
   min=k;
}

if(m != min){
tmp=a[m];
a[m]=a[min];
a[min]=tmp;

A++;
}

}
 
for(k=0;k<N;k++){
printf("%d",a[k]);
if(k!=N-1)
printf(" ");
}
 
printf("\n");
printf("%d\n",A);
 
}

