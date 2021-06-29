#include <stdio.h>
int main(){int i,j,v,N,p;scanf("%d",&N);
int A[N];
for(p=0;N>p;p++)scanf("%d",&A[p]);
for(p=0;N>p;p++){printf("%d",A[p]);
if(p==N-1)printf("\n");
else printf(" ");}
for(i=1;N>i;i++){v=A[i];
j=i-1;
while(j>=0&&A[j]>v){A[j+1]=A[j];
j--;
A[j+1]=v;}
for(p=0;N>p;p++){printf("%d",A[p]);
if(p==N-1)printf("\n");
else printf(" ");}}
return 0;}
