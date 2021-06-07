#include<stdio.h>

void scan(int[],int);
int search(int,int);

int s[100000];
int t[50000];

int main(){

  int n=0,q=0,c=0;

  scanf("%d",&n);
  scan(s,n);
 
  scanf("%d",&q);
  scan(t,q);

  c=search(n,q);
 
  printf("%d\n",c);

  return 0;
}

void scan(int a[],int m){

  int i;
  for(i=0;i<m;i++){
    scanf("%d",&a[i]);
  }
}

int search(int n,int q){

  int i=0,c=0;
  int left=0;
  int right=n;
  int mid=0;

  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<=right){
      mid = (left + right) / 2;
      if(s[mid]==t[i]){
	c++;
	break;
      } 
      if(s[mid] < t[i]){
	left = mid + 1;
      } else {
	right = mid - 1;
      }
    }
  }
  return c;
  
}
