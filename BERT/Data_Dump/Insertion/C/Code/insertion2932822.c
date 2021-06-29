#include<stdio.h>
int main(){
int i, j, size, a[100], key;
scanf("%d", &size);
for(i = 0; i < size; i++){
scanf("%d",&a[i]);
}
for(j = 0; j < size-1; j++){
printf("%d ",a[j]);
}
printf("%d\n", a[size-1]);
for(i = 1; i < size; i++){
key = a[i];
j = i-1;
while(j >= 0 && a[j] > key){
a[j+1] = a[j];
j--;
a[j+1] = key;
}
for(j = 0; j < size-1; j++){
  printf("%d ", a[j]);
}
printf("%d\n", a[size-1]);
}
return 0;
}
