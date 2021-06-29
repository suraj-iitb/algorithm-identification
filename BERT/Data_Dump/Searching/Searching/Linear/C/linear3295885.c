#include<stdio.h>
int main(){
int a[10001],b[501],c,d,i,j,e=0;
scanf("%d\n",&c);
for(i=0;i<c;i++){
scanf("%d ",&a[i]);
}
scanf("\n");
scanf("%d\n",&d);
for(i=0;i<d;i++){
scanf("%d ",&b[i]);
}
scanf("\n");
for(i=0;i<d;i++){
for(j=0;j<c;j++){
if(b[i]==a[j]){
e++;
break;
}
}
}
printf("%d\n",e);
return 0;
}
