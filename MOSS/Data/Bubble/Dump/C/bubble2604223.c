#include <stdio.h>

int main(void){

int i,j;
int a[101];
int len, tmp;
int count=0;

scanf("%d",&len);

for(i=1; i<=len; i++){
scanf("%d",&a[i]);
}

for(i=1; i<=len-1; i++){

for(j=len; j >=i+1; j--){

if(a[j] < a[j-1]){

tmp = a[j];
a[j] = a[j-1];
a[j-1] = tmp;
count++;

}

}

}

for(i=1; i<=len; i++){

printf("%d",a[i]);
if(i!=len){
printf(" ");

}

}

printf("\n%d\n",count);

return 0;

}
