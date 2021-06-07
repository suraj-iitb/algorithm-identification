  #include<stdio.h>
  #define N 100000
  int search(int A[],int n,int key){
    int left=0,right=n,mid;
    while (left<right){
      mid=(left+right)/2;
      if(A[mid]==key){
        return mid;
      }else if(key<A[mid]){
        right=mid;
      }else{
        left=mid+1;
      }
    }
    return 0;
  }
  int main(){
    int i,num,A[N+1],q,key,sum=0;
    scanf("%d",&num);
    for(i=0;i<num;i++){
      scanf("%d",&A[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d",&key);
      if(search(A,num,key))sum++;
    }
    printf("%d\n",sum);
    return 0;
  }

