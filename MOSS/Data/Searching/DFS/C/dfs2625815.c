#include<stdio.h>

 int j, num, gyou, retu, kosuu, A[150][150]={0};
 int jump, time, Det[101]={0}, End[101]={0}, back[101]={0};

void Dsearch(int jump){
 int i;
 for(i=1; i<=num; i++){
   if ( (A[jump][i] == 1) && (Det[i] == 0) ) { 
     back[i] = jump;
     A[jump][i] = 0;
     jump = i;
     time++;
     Det[i] = time;
     i = 1;
   }
   if ( (i == num) && (End[jump] == 0) ) {
     time++;
     End[jump] = time;
     jump = back[jump];
     i = 0;
   }
   if (jump == -1) {
     break;
   }
 }

}

int main(){
 int i;
 scanf("%d", &num);

 for(i=1; i<=num; i++){
   scanf("%d %d", &gyou, &kosuu);
   for(j=0; j<kosuu; j++){
     scanf("%d", &retu);
     A[gyou][retu] = 1;
   }
 }

 for(i=1;i<=num;i++){
   if(Det[i]==0){
     time++;
     Det[i]=time; 
     back[i]=-1;
     Dsearch(i);
   }  
 }

 for(i=1; i<=num; i++){
   printf("%d %d %d\n", i, Det[i], End[i]);
 }

 return 0;
}
