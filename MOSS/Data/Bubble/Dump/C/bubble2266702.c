#include <stdio.h>

#define N 100

int main(){

int i;
int j;
int n;
int tmp;
int count=0;
int data[N];

scanf("%d",&n);

for(i=0;i<n;i++){
scanf("%d",&data[i]);
 }
for(i=0;i<n-1;i++){
 for(j=1;j<n;j++){
   if(data[j]<data[j-1]){
   tmp = data[j];
   data[j] = data[j-1];
   data[j-1] = tmp;
   count++;
  }
 }
}

for(i=0;i<n-1;i++){
  printf("%d ",data[i]);
 }
 printf("%d\n",data[i]);
 printf("%d\n",count);
 return 0;
}
