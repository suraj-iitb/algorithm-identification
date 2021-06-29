#include<stdio.h>
int search(int a);

int a1[100000],n;

int search(int a){
  int left=0;
  int right=n;
  int mid;


  while(left<right){
    mid=(left+right)/2;
    if(a==a1[mid]){return 1;}

    
    if(a>=a1[mid]){left=mid+1;}
    else {right=mid;}

  }
  return 0;
}



int main(){
  scanf("%d",&n);



  int i;
  
  for(i=0;i<n;i++){
    scanf("%d",&a1[i]);
  }


  
  int a2_num;
  scanf("%d",&a2_num);



  int a2;
  int count=0;
  
  for(i=0;i<a2_num;i++){
    scanf("%d",&a2);
    if(search(a2)==1){count=count+1;}
  }




  
  printf("%d\n",count);


  
  return 0;

}

