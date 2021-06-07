#include <stdio.h>
int main()
{

int array[10000];
int key[10000];
int i,j,k,N,M,count=0;

scanf("%d", &N);
for(i=0;i<N;i++) {
scanf("%d",&array[i]);
}
scanf("%d", &M);
for(j=0;j<M;j++) {
scanf("%d",&key[j]);
}
for (k=0; k<M;k++){
for(i=0;i<N;i++){
if (array[i] == key[k]){
count++;
break;
}
}
}
printf("%d\n",count);
return 0;
}

