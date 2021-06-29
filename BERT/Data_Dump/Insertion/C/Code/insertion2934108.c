#include<stdio.h>
#include<stdlib.h>

int main(){
int i = 0;
int data = 0;
int V = 0;
int j = 0;
int *insert;
int k;

scanf("%d",&data);
insert = (int *)malloc(sizeof(int)*data);

for(i = 0 ; i < data ; i++){
scanf("%d",&insert[i]);
}
for(i = 0; i < data ; i++){
V = insert[i];
j = i - 1;

while(j >= 0 && insert[j] > V){
  insert[j + 1] = insert[j];
  j--;
  insert[j + 1] = V;

}
for(k=0; k<data; k++){
 if(k!=data-1)printf("%d ",insert[k]);
 else printf("%d",insert[k]);
}
printf("\n");
}
return 0;
}
