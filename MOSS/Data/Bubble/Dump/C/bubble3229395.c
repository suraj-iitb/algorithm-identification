#include<stdio.h>

int main(void){
   int a[1000],N,i,j,kari,cnt=0;
   scanf("%d",&N);
   
   for(i=0;i<N;i++)
   scanf("%d",&a[i]);

 for(j=0;j<N;j++){
   for(i=N-1;i>0;i--){
   if(a[i-1]>a[i]){
      kari=a[i-1];
      a[i-1]=a[i];
      a[i]=kari;
      cnt=cnt+1;
   }
   
}
}
for(i=0;i<N;i++){
printf("%d",a[i]);
while(i!=N-1){
putchar(' ');
break;
}
}
putchar('\n');
printf("%d\n",cnt);

   return 0;
}
