#include<stdio.h>
#define N 500000
int temp[N],c=0;
int main();
void MergeSort(int x[],int left,int right){
  int mid,i,j,k;
  if(left<right){
      mid=(left+right)/2;
      MergeSort(x,left,mid);
      MergeSort(x,mid+1,right);

      for(i=mid;i>=left;i--){
	temp[i]=x[i];
      }
      for(j=mid;j<=right;j++){
	temp[right-(j-(mid+1))]=x[j];}
      i=left;j=right;
      for(k=left;k<=right;k++){
	if(temp[i]<=temp[j])
	  x[k]=temp[i++];
	else x[k]=temp[j--];
c++;
}
}
}
int main(){
  int i,k,x[N];
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&x[i]);}
    MergeSort(x,0,k-1);
    for(i=0;i<k;i++){
if(i>0)printf(" ");      
 printf("%d",x[i]);

}
  printf("\n");
printf("%d\n",c);
return 0;
}

      

