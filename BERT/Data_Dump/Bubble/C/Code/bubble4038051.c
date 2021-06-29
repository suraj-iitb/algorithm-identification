#include<stdio.h>
#define LIM 100

void *bubs(int *,int *);

int main() {

  int N,num[LIM];
  int i,j;

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&num[i]);

  j=N;
  bubs(num,&N);
  
  for(i=0;i<j;i++) {
    if(i>0) printf(" ");
    printf("%d",num[i]);
  }

  printf("\n%d\n",N);

  return 0;

}

void *bubs(int *num,int *a) {

  int N=*a;
  int flag=1;
  int i,j;
  *a=0;

  while(flag==1) {

    flag=0;

    for(i=N-1;i>0;i--) {
      if(num[i] < num[i-1]) {
	j = num[i];
	num[i] = num[i-1];
	num[i-1] = j;
	flag=1;
	*a=*a+1;
      }
    }

  }
}
