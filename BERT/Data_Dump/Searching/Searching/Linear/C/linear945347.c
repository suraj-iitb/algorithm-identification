#include<stdio.h>

void scan(int*[],int);
int search(int*[],int*[],int,int);

int main(){

  int i,j,n=0,q=0,c=0;
  int* s[10000];
  int* t[500];

  scanf("%d",&n);
  scan(s,n);
 
  scanf("%d",&q);
  scan(t,q);

  c=search(s,t,n,q);
 
  printf("%d\n",c);

  return 0;
}

void scan(int* a[], int m){

  int i;
  for(i=0;i<m;i++){
    scanf("%d",&a[i]);
  }
}

int search(int* s[],int* t[],int n,int q){

  int i,j,c = 0;

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(t[i]==s[j]){
	c++;
	break;
      }
    }
  }

  return c;

}
