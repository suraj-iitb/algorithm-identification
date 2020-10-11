#include <stdio.h>
#define INFTY 1000000001
int count=0;
void mergeSort(int*, int, int);
void merge(int *, int, int, int);

int main(){
  
  int n, S[500000], i;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }

  mergeSort(S, 0, n);

  for(i=0; i<n-1; i++){
    printf("%d ",S[i]);
  } printf("%d\n", S[n-1]);

  printf("%d\n", count);

  return 0;
}

void mergeSort(int S[], int left, int right){

  int mid, i;
  
  if( (left+1)<right ){ //left==rightじゃない時、２つ分けにしていく

    mid=(left+right)/2;

    mergeSort(S, left, mid);//left~midまで一旦sort
    mergeSort(S, mid, right);//mid~rightまでsort

    merge(S, left, mid, right);
  }
}
void merge(int S[], int left, int mid, int right){

  int nL=mid-left, nR=right-mid;
  int arrL[nL], arrR[nR];
  int i, j, k;

  for(i=0; i<nL; i++){

    arrL[i]=S[left+i];
  }
  for(i=0; i<nR; i++){

    arrR[i]=S[mid+i];
  }
  
  arrL[nL]=INFTY;//無限...絶対必要
  arrR[nR]=INFTY;//Sの要素より絶対に大きいであろう数を具体的にdefineする

  i=0;
  j=0;

  for(k=left; k<right; k++){ //これからS[]に2つの配列をの大小比較し、merge

    if(arrL[i]<=arrR[j]){
      S[k]=arrL[i];
      i++;
      count++;
    }else if(arrR[j]<arrL[i]){
      S[k]=arrR[j];
      j++;
      count++;
    }
  }//merge終了

}


  
  

  
    

