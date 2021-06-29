#include<stdio.h>
int main(){

int N,k,a[100],m,n,tmp,A;

scanf("%d",&N);

for(k=0;k<N;k++)
scanf("%d",&a[k]);

for(n=0;n<N;n++){

for(m=n-1;m>=0;m--){

if(a[m]>a[m+1]){
tmp=a[m];
a[m]=a[m+1];
a[m+1]=tmp;
}else break;

}

for(k=0;k<N;k++){
printf("%d",a[k]);
if(k!=N-1)
printf(" ");
}
printf("\n");
}

}
