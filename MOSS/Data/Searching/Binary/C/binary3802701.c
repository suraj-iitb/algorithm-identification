#include<stdio.h>

  int a[100100];
  int n1;
int binarySearch(int key){
  int left =0;
  int right=n1;
  int mid;
  while(left<right){
    mid=(left+right)/2;
    if(a[mid]==key){
      return 1;
    }else if(key<a[mid]){
      right=mid;
    }else{
      left=mid+1;
    }
  }
  return 0;
}

int main(){
  int n2,b,cnt=0;
  int i=0,j=0;

  scanf("%d",&n1);
  while(i!=n1){
    scanf("%d",&a[i]);
    i++;
  }
  scanf("%d",&n2);

  while(j!=n2){
    scanf("%d",&b);
    if(binarySearch(b))cnt++;
    j++;
  }


  printf("%d\n",cnt);

}

