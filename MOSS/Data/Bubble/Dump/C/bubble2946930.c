#include<stdio.h>
int main(){
  int i,num,j,alt,count=0;
  scanf("%d",&num);
  int buf[num];
  for(i=0;i<num;i++){

    scanf("%d",&buf[i]);
  }
  for(i=0;i<num;i++){
    for(j=num-1;j>=i+1;j--){
      if(buf[j]<buf[j-1]){
	alt=buf[j];
	buf[j]=buf[j-1];
	buf[j-1]=alt;
	count++;
      }

    }


  }
  for(i=0;i<num;i++){
    if(i!=num-1)printf("%d ",buf[i]);
    else printf("%d\n",buf[i]);
  }
  printf("%d\n",count);
}

