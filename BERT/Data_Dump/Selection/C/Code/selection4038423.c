#include<stdio.h>


int c=0;
void s (int *x, int *y) {
  int temp; 
  temp = *x;
  *x = *y;
  *y = temp;

}


void sort (int array[], int size) {
  int i, j, in;

  for (i = 0; i < size-1; i++) {
    in = i;   
    for (j = i + 1; j < size; j++) {
      if (array[j] < array[in]){in = j; }   
    }
    if(in!=i)c++;
    s(&array[in], &array[i]);
  }
}

int main (void) {
  int g;
  scanf("%d",&g);
  int i;
  int a[100];
    for(i =0;i<g;i++){
      scanf("%d",&a[i]);
    }
  sort(a,g); 
  for (i = 0; i < g; i++) { printf("%d", a[i]);if(i!=g-1)printf(" ");}
  printf("\n");
  printf("%d\n",c);

  return 0;
}

