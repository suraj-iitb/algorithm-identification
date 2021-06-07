#include <stdio.h>
#include <stdlib.h>
#define MAX 10001
int main() {
int i,j;
int n,m,a[MAX],b[MAX],key,count=0;
scanf("%d",&n);
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
scanf("%d",&m);
for(i=0;i<m;i++){
    scanf("%d",&b[i]);
}
i=0;
for (j = 0; j < m; j++) {
  key=b[j];
  while (a[i]!=key) {
    i++;
    if(i==n) {break;}
  }
  if(i!=n) {count++;}
  i=0;
}
printf("%d\n",count);

return 0;
}
