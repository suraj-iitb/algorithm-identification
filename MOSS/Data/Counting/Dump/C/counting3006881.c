#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int *countingsort(int*,int,int);
int main(){
int i,n,max=INT_MIN;
int *list;
  scanf("%d",&n);
  list=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",list+i);
    if(max<*(list+i))max=*(list+i);
  }
  list=countingsort(list,n,max);
  for(i=0;i<n;i++)printf("%d%c",*(list+i),(i<n-1)?' ':'\n');
  return 0;
}
int *countingsort(int *origin,int n,int m){
int i;
int *countlist,*sortedlist;
  m++;
  countlist=(int*)malloc(m*sizeof(int));
  sortedlist=(int*)malloc(n*sizeof(int));
  for(i=0;i<m;i++)*(countlist+i)=0;
  for(i=0;i<n;i++)*(countlist+*(origin+i))+=1;
  for(i=0;i<m-1;i++)*(countlist+(i+1))+=*(countlist+i);
  for(i=n-1;i>-1;i--){
    *(sortedlist+*(countlist+*(origin+i))-1)=*(origin+i);
    *(countlist+*(origin+i))-=1;
}
  return sortedlist;
}

