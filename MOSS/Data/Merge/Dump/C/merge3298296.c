#include<stdio.h>
#include<stdlib.h>

#define IMAX 2147483647

int n,A[500000],c=0;
void marge(int,int,int);

void msort(int left,int right){
  int mid;
  // printf("msort (%d,%d),%d\n",left,right,(int)(3/2));
  
  if(left+1 < right){
    mid=(left+right)/2;
    msort(left,mid);
    msort(mid,right);
    //    printf("|marge| (%d,%d,%d)\n",left,mid,right);    
    marge(left, mid, right);
  }
  // else printf("left=%d,right=%d\n",left,right);
}
void marge(int left,int mid, int right){
  int n1,n2,i,j,k,*L,*R ;
  n1=mid-left;
  n2=right-mid;
  L = (int *) malloc ( sizeof(int) * (n1+1) );
  R = (int *) malloc ( sizeof(int) * (n2+1) );
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];  
  L[n1]=R[n2]=IMAX;
  i=j=0;
  for(k=left;k<right;k++){
    c++;
    if(L[i]<=R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
    
  }
  //  for(i=0;i<n;i++)  printf("A[%d]=%d\n",i,A[i]);
  free(L);
  free(R);
}
    

int main(){
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  msort(0,n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",c);

  return 0;
}

  

