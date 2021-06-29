#include <stdio.h>

#define MAX 500000
#define INF 1000000000

void merge(int,int,int);

void mergesort(int,int);

int R[MAX],L[MAX];

int s[MAX];

int count=0;

int main()
{
  int i,left=0,g=0,right=0,n=0;

  scanf("%d",&n);

  g = n;

  for(i = 0;i < n;i++){

    scanf("%d",&s[i]);

  }

  /*  mid left right  wo tu ku ru */

  left = 0;

  right = n;

  /*   mid = (left + right) / 2;   */

/* hennkou  */

  mergesort(left,right);




for(i = 0;i < g - 1;i++){

  printf("%d ",s[i]);

}

printf("%d\n",s[i]);

printf("%d\n",count);

return 0;
}

void merge(int left,int mid,int right){

  int i,j,k,n1,n2;

  n1 = mid - left;

  n2 = right - mid;


  for(i = 0;i <= n1 - 1;i++){

    L[i] = s[left + i];

  }

  for(i = 0;i <= n2 - 1;i++){

    R[i] = s[mid + i];

  }

  L[n1] = INF;

  R[n2] = INF;


  i = 0;

  j = 0;


  for(k = left;k < right;k++){

    count = count + 1;

    if(L[i] <= R[j]){

      s[k] = L[i];
      i = i + 1;

    }

    else{

      s[k] = R[j];
      j = j + 1;

    }
    }


  }

void mergesort(int left,int right){

  int mid;


  if(left + 1 < right){

    mid = (left + right) / 2;

    mergesort(left,mid);    /*  !!!!!!!!  */

    mergesort(mid,right);

    merge(left,mid,right);


  }


}

