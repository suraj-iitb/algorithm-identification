#include<stdio.h>
int main(){

int N,k,a[100],m=1,n,tmp,A=0;

scanf("%d",&N);

for(k=0;k<N;k++)
scanf("%d",&a[k]);

for(m=0;m<N;m++){
for(n=N-1;n>m;n--){

if(a[n-1]>a[n]){
tmp=a[n];
a[n]=a[n-1];
a[n-1]=tmp;
A++;
}

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
