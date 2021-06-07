#include<stdio.h>
#include<stdlib.h>
#define N 100000

int line1[N],line2[N];

int main(){
  int i,left=0,right,mid,point1,point2,n=0;
  scanf("%d",&point1);
  for(i=0 ; i<point1 ; i++){
    scanf("%d",&line1[i]);
  }
  scanf("%d",&point2);
  for(i=0 ; i<point2 ; i++){
    scanf("%d",&line2[i]);
  }
  for(i=0 ; i<point2 ; i++){
    left=0;
    right = point1;
    while(left<right){
      mid = (left+right)/2;
      if(line2[i] == line1[mid]){
	n++;
	break;
      }
      if(line2[i] > line1[mid]) left = mid+1;
      else if(line2[i] < line1[mid]) right = mid;
    }
  }
  printf("%d\n",n);
  return 0;
}

