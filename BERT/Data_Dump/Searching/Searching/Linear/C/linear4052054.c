#include<stdio.h>

int LinearSearch(int);

int ori[10000],n; 

int main()
{
  int i,j,key[500],m,count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ori[i]);
  }

  scanf("%d",&m);
   for(j=0;j<m;j++){
    scanf("%d",&key[j]);
    count+=LinearSearch(key[j]);
   }

   printf("%d\n",count);

   return 0;

}

int LinearSearch(int key)
{
  int i;
  
  i=0;
  ori[n]=key;
  while(ori[i]!=key){
    i++;
    if(i==n) return 0;
  }
  return 1;
}
     

