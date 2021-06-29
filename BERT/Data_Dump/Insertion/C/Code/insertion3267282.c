#include <stdio.h>
#include <stdlib.h>

int *get_list(int);
void sort(int);
void display(int *,int);

int main(){
  int n=0,i=0,j=0,key=0;
  int *list;
  scanf("%d",&n);

  sort(n);
  
  free(list);
  
  return 0;
}
  
int *get_list(int n){
  int *list;
  int i=0;
  
  list = (int *)malloc(sizeof(int)*n);

  if(0 <= n && n <= 100){
    
    for(i=0;i<n;i++){
      
      scanf("%d",list + i);
      
      if(0>list[i] || list[i]>1000){
	printf("error\n");
	exit(8);
      }
      //printf("%d ",*(list+i));
    }
    //printf("\n");
  }
  else{
    printf("error\n");
    exit(8);
  }
  return list;
  }

void sort(int n){
  int i=0,j=0,key=0;
  int *list; 
  list = get_list(n);
  
  display(list,n);
  
  for(i=1; i<n; i++){
    key = list[i];
    j = i-1;
    while(j>=0 && list[j]>key){
      list[j+1] = list[j];
      j--;
    }
    list[j+1]=key;
    display(list,n);
  }
}

void display(int *list,int n){
  int i=0;
  
  for(i=0; i<n; i++){
    if(i)printf(" ");
    printf("%d",list[i]);
  }
  printf("\n");
}

