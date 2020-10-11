#include<stdio.h>
int main()
{
  int flag = 1;
  int n[100];
  int i,a,b,c=0;

  scanf("%d",&a);

  for(i = 0; i < a; i++){
    scanf("%d",&n[i]);
  }

  while(flag){
    flag = 0;
    for(i = a-1; i >=1; i--){
      if(n[i] < n[i-1]){
	b = n[i];
	n[i] = n[i-1];
	n[i-1] = b;
	flag = 1;
	c++;
      }
    }
  }
    for(i = 0; i < a; i++){
      printf("%d",n[i]);
      if(i < a-1) printf(" ");
    }
    printf("\n");
    printf("%d\n",c);
    return 0;
}
