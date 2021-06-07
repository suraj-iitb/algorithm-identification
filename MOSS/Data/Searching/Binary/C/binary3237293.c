#include<stdio.h>
int a[1000000];

int  binary_search(int target, int right){
    int mid, left;
    left = 0;
    while(left < right){
    mid = (right + left) / 2;
    if (target == a[mid]) {
        return 1;
    } else if (target < a[mid]) {
        right = mid;
    } else {
        left = mid + 1;
    }
    }
    return 0;
    }

int main(){
   int b, c, d, i, j, count;
   count = 0;
   
   scanf("%d", &c);
   for (i = 0; i < c; i++){
      scanf("%d", &a[i]);
   }
   scanf("%d", &d);
   for(i = 0; i < d; i++){
      scanf("%d", &b);
      if (binary_search(b, c) == 1){
        count++;
      }
   }
   printf("%d\n", count);
   
        
    
    return 0;
}

