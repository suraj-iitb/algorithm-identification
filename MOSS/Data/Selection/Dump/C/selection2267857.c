#include <stdio.h>

int main(){
  int i, j, n, list[100], mini, temp, count = 0;

  scanf("%d", &n);

  for(i=0; i<n; i++) scanf("%d", &list[i]);

  for(i=0; i<n; i++){
    mini = i;
    for(j=i; j<n; j++){
      if(list[j] < list[mini]) mini = j;
    }
    if(i != mini){
      temp = list[i];
      list[i] = list[mini];
      list[mini] = temp;
      count++;
    }
  }

  for(i=0; i<n-1; i++) printf("%d ", list[i]);
  printf("%d\n%d\n", list[i], count);
  
  return 0;
}
