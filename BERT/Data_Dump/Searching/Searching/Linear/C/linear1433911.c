#include <stdio.h>

int array[10000];

int n;
int search(int q){
int i = 0, flag = 0;
  while(i <= n){
     if(q == array[i]){
      flag = 1;
     }
     i++;

   }
  return flag;

}


int main(){
int i = 0, q = 0, p, sum = 0;
 scanf("%d", &n);
 for(i; i <= n - 1; i++)
   scanf("%d", &array[i]);

 scanf("%d", &q);

 for(i = 0; i <= q - 1; i++){
    scanf("%d", &p);
    sum += search(p);
 }

 printf("%d\n", sum);
 return 0;
}
