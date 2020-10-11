#include<stdio.h>

void insertion_sort(int*, int*);
void display(int*, int*);

int main(void) {
  int len, i, j;
  scanf("%d",&len);

  int data[len];

  for(i=0; i<len; i++) {
    scanf("%d", &data[i]);
  }
  display(data, &len);
  insertion_sort(data, &len);

  return 0;
}

void insertion_sort(int *data, int *len) {
  int i, j, v;

  for(i=1; i<*len; i++) {
    v = data[i];
    j = i-1;
    while(j>=0 && data[j]>v) {
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = v;
    display(data, len);
  }
}

void display(int *data, int *len) {
  int i;
  for(i=0; i<*len; i++) {
    if(i!=0) printf(" ");
    printf("%d", data[i]);
  }
  printf("\n");
}
