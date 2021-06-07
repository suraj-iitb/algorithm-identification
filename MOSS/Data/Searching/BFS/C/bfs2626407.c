#include<stdio.h>
#define zyougen 150
int i, j, num, gyou, retu, kosuu, A[zyougen][zyougen]={0};
int point, min[zyougen], kyori,used[zyougen],box[zyougen]={0};

int nearest(int used[]){
 for(i=1; i<=num; i++){
   if (used[box[i]] == 1) {
     return box[i];
   }
 }
 return -1;
}

int main(){

 scanf("%d", &num);
 for(i=1; i<=num; i++){
   scanf("%d %d", &gyou, &kosuu);
   for(j=0; j<kosuu; j++){
     scanf("%d", &retu);
     A[gyou][retu] = 1;
   }
   min[i] = zyougen;
 }

 point = 1;
 used[point] = 1;
 min[point] = 0;
 j=0;

 while(point != -1){
   for(i=1; i<=num; i++){
     if (A[point][i] == 1) {
       kyori = min[point] + 1;
       if (min[i] > kyori) {
         min[i] = kyori;
       }
       if (used[i] == 0) {
         used[i] = 1;
         j++;
         box[j] = i;
       }
     }
   }
   used[point] = -1;
   point = nearest(used);
 }

 for(i=1; i<=num; i++){
   if(min[i] == zyougen){
     min[i] = -1;
   }
 }

 for(i=1; i<=num; i++){
   printf("%d %d\n", i, min[i]);
 }

 return 0;
}
