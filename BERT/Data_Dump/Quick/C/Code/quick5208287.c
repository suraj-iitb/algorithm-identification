#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 100000
#define N 100


typedef struct{
  char e[2]; //絵柄                                                              
  int num; //数                                                                  
  int t;
} C;

void swap(C *, C *);
int par(C *, int, int);
void quick(C *, int, int);


int main(){
  C a[MAX];
  int i,n;
  int co=0;


  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%s %d", a[i].e, &a[i].num);
    a[i].t = i+1;
  }

  quick(a,0,n-1);

  for(i=0; i<n; i++){
    if(a[i].num == a[i+1].num && a[i].t > a[i+1].t){
      co++;
      break;
      }
  }


  if(co==0) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0; i<n; i++){
    printf("%s %d\n", a[i].e, a[i].num);
  }



  return 0;
}




void swap(C *a, C *b){
  C tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int par(C *a, int p, int r){ //partition                                         
  int j;
  int x = a[r].num;
  int i = p-1;

  for(j=p; j<r; j++){
    if(a[j].num <= x){
      i++;
      swap(&a[j],&a[i]);
    }
  }

  swap(&a[i+1],&a[r]);
  return i+1;


}

void quick(C *a, int p, int r){ //quickSort                                      
  int q;

  if(p<r){
    q = par(a,p,r);
    quick(a,p,q-1);
    quick(a,q+1,r);
  }
}

