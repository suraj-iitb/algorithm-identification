#include<stdio.h>

int temp[500000],cnt=0;

void MergeSort(int left,int right,int a[]);

void MergeSort(int left,int right,int a[]){
  int m,i,j,k;
  
  //printf("%d,%d,%d\n",left,right,a[0]);
  if(left>=right){
    return;
  }
  //ここまではok
  
  m=(left+right)/2;
  //左側を再起で呼び出し
  MergeSort(left,m,a);
  //右側を呼び出し
  MergeSort(m+1,right,a);
  
  //a[left]からa[m]を作業領域にコピー
  for(i=left;i<=m;i++){
    temp[i]=a[i];
    //printf("%d,",temp[i]);
  }

  //a[m+1]からa[right]を逆順にコピー　
  for(i=m+1,j=right;i<=right;i++,j--){
    temp[i]=a[j];
  }

  i=left;
  j=right;
  //小さい方から配列に戻す
  for(k=left;k<=right;k++){
    cnt++;
    if(temp[i]<temp[j]){
      a[k]=temp[i++];
    }else{
      a[k]=temp[j--];
    }
  }
	
}
int main(){
  int num,array[500000],i;

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&array[i]);
  }
  MergeSort(0,num-1,array);
  //printf("%d,%d\n",num,array[0]);

  for(i=0;i<num-1;i++){
    printf("%d ",array[i]);
  }
  
  printf("%d\n%d\n",array[num-1],cnt);
  return 0;
}

