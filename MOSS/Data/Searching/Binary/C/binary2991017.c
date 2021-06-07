#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
#define MAX2 50001
int main() {
int i,j;
int left,right,mid;
int n,m,a[MAX],b[MAX2],key,count=0;
scanf("%d",&n);
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
scanf("%d",&m);
for(i=0;i<m;i++){
    scanf("%d",&b[i]);
}

for (j = 0; j < m; j++) {
  left=0;
  right=n;
  key=b[j];
  while (left<right) {
    mid=(left+right)/2;
if(a[mid]==key){
  count++;
  break;}
else if(a[mid]<key) {left=mid+1;}
else right=mid;
}}
printf("%d\n",count);
return 0;
}
