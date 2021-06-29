#include<stdio.h>

int main(int argc, char* argv[])
{
  int a[200], n;
  int i, j, w, mini, swc;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &a[i]);
  }

  swc = 0;
  for(i = 1; i < n; i++){
    mini = i;
    for(j = i; j <= n; j++){
      if(a[j] < a[mini]){
        mini = j;
      }
    }
	if(mini != i){
      w = a[i];
      a[i] = a[mini];
      a[mini] = w;
      swc++;
	}
  }

  for(i = 1; i < n; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n", a[i]);
  printf("%d\n", swc);

  return(0);
}
