#include<stdio.h>
#define N 100
int main(){
int n,i,j,temp,mini,count=0;
int A[N];

scanf("%d",&n);
for(i=0;i<n;i++) scanf("%d",&A[i]);

for(i=0;i<n-1;i++){
mini=i;
for(j=i+1;j<n;j++){
if(A[j]<A[mini]){
mini=j;
}
}
if(i!=mini){
temp=A[i];
A[i]=A[mini];
A[mini]=temp;
count++;
}
}

for(i=0;i<n;i++){
printf("%d",A[i]);
if(i!=n-1) printf(" ");
}
printf("\n");
printf("%d\n",count);

return 0;
}
