#include <stdio.h>
#define N 10000

int main(){
int i,j,s,n1,t,n2,teto[N],teto2[N],count=0;
scanf("%d",&n1);
for(i=0;i<n1;i++){
scanf("%d",&teto[i]);
}
scanf("%d",&n2);
for(i=0;i<n2;i++){
scanf("%d",&teto2[i]);
}
for(i=0;i<n2;i++){
for(j=0;j<n1;j++){
if(teto2[i]==teto[j]){
count++;
break;
}
}
}
printf("%d\n",count);


return 0;
}
