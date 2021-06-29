#include<stdio.h>
int main() {
   int i, j, num, temp, arr[256],k;
   scanf("%d", &num);
   for (i = 0; i < num; i++) {
      scanf("%d", &arr[i]);
   }
	for(i=0;i<num;i++){
	if(i==num-1)printf("%d",arr[i]);
	else
	printf("%d ",arr[i]);
	}
	putchar('\n');
   for (i = 1; i < num; i++) {
      temp = arr[i];
      j = i - 1;
      while ((temp < arr[j]) && (j >= 0)) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }
   
      arr[j + 1] = temp;
   
   	for (k = 0; k < num; k++) {
	if(k==num-1)printf("%d",arr[k]);
	else
        printf("%d ", arr[k]);
   }
	putchar('\n');
}
   return 0;
}
