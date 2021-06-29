#include<stdio.h>
#define N 10000
#define M 500
#define MAX 1000000000

int serch(int , int ,int *);
int linearSearch(int , int *, int );
int main(){
  int a,b[N],c,d[M],n,i,j,count = 0;
  scanf("%d",&a);
  for(i = 0; i < a; i++)
    scanf("%d",&b[i]);

  scanf("%d",&c);
  for(i = 0; i < c; i++)
    scanf("%d",&d[i]);

  for(i = 0; i < a; i++){
    if(serch(i,a,b) == 1) continue;
    n = linearSearch(c,d,b[i]);
    if(n != -1) count++;
  }

  printf("%d\n",count);
  return 0;
}

int serch(int x, int a, int *b){
  int i,j;
   for ( i = x + 1; i < a ; i++) {
            if (b[x] == b[i]) {
              return 1;
        }
    }

    return 0;
}

int linearSearch(int c, int *d, int key){
  int i = 0;
  d[c] = key;
  while (d[i] != key){
    i++;
  }
    if (i == c) return -1;
    return i;

}
