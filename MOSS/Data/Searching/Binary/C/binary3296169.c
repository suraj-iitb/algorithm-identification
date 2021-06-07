#include<stdio.h>
#define N 100000
#define NOT_FOUND 0

int binarySearch(int);
int S[N],n;

int main(){
  int count=0;
  int T[N],i,j,q;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

  for(j=0;j<q;j++){

    if(binarySearch(T[j]) != 0){
        count++;

    }
  }

  printf("%d\n",count);

  return 0;
}

int binarySearch(int key){
 int l=0;
 int r,mid;

 r=n;

 while(l < r){
   mid = (l+r)/2;

   if(key == S[mid]) return 1;

  else if(key < S[mid]) {
     r = mid;

   }
     else {
       l = mid + 1;

     }

}
 return NOT_FOUND;


}


