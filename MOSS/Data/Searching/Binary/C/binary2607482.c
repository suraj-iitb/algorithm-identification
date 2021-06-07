#include<stdio.h>

int binarySearch(int key, int a[], int num){
   int left = 0;
   int right = num;
   int mid = 0;

   while(1){
      mid = (left + right) / 2;

      if(a[mid] == key){
         return 1;
      }else if(key < a[mid]){
         right = mid;
      }else{
         left = mid + 1;
      }

      if(left >= right){
         return 0;
         break;
      }
   }


}



int main () {

   int s[100000] = {0};
   int t = 0;
   int n, q, i;
   int count = 0;

   scanf("%d", &n);

   for(i = 0; i < n; i++){
      scanf("%d", &s[i]);
   }

   scanf("%d", &q);

   for(i = 0; i < q; i++){
      scanf("%d", &t);

      if(binarySearch(t,s,n)){
         count++;
      }
   }

   printf("%d\n", count);

   return 0;

}


   
