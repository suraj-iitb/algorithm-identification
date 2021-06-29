#include<stdio.h>

int binarySearch(int);

int n,ori[100000];

int main()
{
  int key[50000],i,j,count=0,m;
  
   scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ori[i]);
  }

  scanf("%d",&m);
   for(j=0;j<m;j++){
    scanf("%d",&key[j]);
    count+=binarySearch(key[j]);
   }

   printf("%d\n",count);

   return 0;
}

int binarySearch(int key)
{
  int mid,right,left;
  left=0;
  right=n;

  while(left<right){
    mid=(int){(left+right)/2};
      if(ori[mid]==key) return 1;
      else if(key<ori[mid]) right=mid;
      else left=mid+1;
  }
  return 0;
}

