#include<stdio.h>
int main(){
  int a,i,j,n,q,S[100000],T[50000],c1=0,c2=0;
  int left=0,mid,right,value;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  for(a=0;a<q;a++){
    left=0;
    right=n;
    while(left<=right){
      // value=(left+right) % 2;                                                
      //if(value==0){                                                           
      //mid = (left+right) / 2;}                                                
      //else if(value!=0){                                                      
      mid = (left+right)/2;
      if(S[mid] == T[a]){
        c1++;
        c2++;
        break;
        if(c2>=2){
          c1--;
        }
      }
      else if (S[mid] < T[a]){
        left = mid + 1;
      }
      else{
        right = mid - 1;
      }
    }
  }
  printf("%d\n",c1);
  return 0;
}

