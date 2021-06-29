#include<stdio.h>
#define Infty 2000000000
int mothernum, mother[500000], left[300000], right[300000], counter=0;
int merge(int mother[], int Start, int Center, int End)
{
 int leftnum, rightnum, i, j, k;
 leftnum  = Center - Start;
 rightnum = End - Center;
 for(i = 0; i < leftnum; i++){
   left[i] = mother[Start+i];
 }
 for(i = 0; i < rightnum; i++){
   right[i] = mother[Center+i];
 }
 
 left[leftnum]   = Infty;
 right[rightnum] = Infty;
 i = 0;
 j = 0;  
 
 for(k = Start; k < End; k++){
   if (left[i] <= right[j]) {
     mother[k] = left[i];
     i = i + 1;
     counter++;
   } else {
     mother[k] = right[j];
     j = j + 1;
     counter++;
   }
 }
 return 0;
}

int mergeSort(int mother[], int Start, int End)
{
 int Center;
 if ( (Start+1) < End ) {
   Center = (End + Start) / 2;
   mergeSort(mother, Start, Center);
   mergeSort(mother, Center, End);
   merge(mother, Start, Center, End);
 }
 return 0;
}

int main()
{
 int i;
 scanf("%d", &mothernum);
 for (i = 0; i < mothernum; i++) {
   scanf("%d", &mother[i]);
 }
 
 mergeSort(mother, 0, mothernum);
 
 for (i = 0; i < mothernum-1; i++) {
   printf("%d ",mother[i]);
 }
 printf("%d\n",mother[mothernum-1]);
 
 printf("%d\n",counter);
 
 return 0;
}
