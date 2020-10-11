














#include<stdio.h>


void ire(int*,int*);
void sort(int*,int);
int c;
int main(){
  int s,i,su[100];
  scanf("%d",&s);
  for(i=0;i<s;i++){
    scanf("%d",&su[i]);
  }

sort(su,s);
 for (i=0; i < s; i++) {


   printf("%d",su[i]);
   if(i!=s-1)printf(" ");
 } 
  printf("\n");
  printf("%d\n",c);
  return 0;
}
void sort (int su[], int size) {
  int i, j;

  for (i = 0; i < size - 1; i++){
    for (j = size - 1; j >= i + 1; j--){   
      if (su[j] < su[j-1]) { ire(&su[j], &su[j-1]);c++; }
    }
  }
}


void ire (int *x, int *y) {
  int temp;    
  temp = *x;
  *x = *y;
  *y = temp;
}

