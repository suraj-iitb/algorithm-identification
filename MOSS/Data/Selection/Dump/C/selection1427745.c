#include <stdio.h>
#define N 100

int array[N];
int cnt = 0;

void change(int *n, int *i){
int d;
d = *i;
*i = *n;
*n = d;

cnt++;
}

void sort(int p){
int i, c = 0, min;

 while(c <= p - 1){
   min = c;
 for(i = c; i <= p - 1; i++){
  if(array[i] < array[min])
   min = i;

 }
 if(c != min){
 change(&array[c], &array[min]);
 }
  c++;
 }

}

int main(){
int p, i;
scanf("%d", &p);
for(i = 0; i <= p - 1; i++) scanf("%d", &array[i]);
sort(p);
for(i = 0; i <= p - 1; i++){
 if(i > 0) printf(" ");

printf("%d", array[i]);
}
printf("\n%d\n", cnt);
return 0;

}
