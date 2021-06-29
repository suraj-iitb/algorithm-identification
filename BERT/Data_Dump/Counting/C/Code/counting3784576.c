#include<stdio.h>
int main(){
int a[10010],n,i,j,c,d=0;
scanf("%d\n",&n);
for(i=0;i<10001;i++){
a[i]=0;
}
for(i=0;i<n;i++){
scanf("%d",&c);
a[c]++;
}
for(i=0;i<10001;i++){
for(j=0;j<a[i];j++){
if(d==0){
printf("%d",i);
d++;
}
else{
printf(" %d",i);
}
}
}
printf("\n");
return 0;
}
