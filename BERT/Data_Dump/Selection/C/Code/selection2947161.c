#include<stdio.h>
int main(){
  int i,num,min,j,alt,count=0;
  scanf("%d",&num);
  int buf[num];
  for(i=0;i<num;i++){

    scanf("%d",&buf[i]);
  }
  for(i=0;i<num;i++){
    min=i;
    for(j=i;j<num;j++){
      if(buf[j]<buf[min]){
	min=j;
      }
    }
    if( buf[i]>buf[min]){
	alt=buf[i];
	buf[i]=buf[min];
	buf[min]=alt;
	count ++;
    }
      
    
  }
  for(i=0;i<num;i++){
    if(i!=num-1){
      printf("%d ",buf[i]);
    }
    else printf("%d\n",buf[i]);
  }
  printf("%d\n",count);

}

