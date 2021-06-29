  #include<stdio.h>
  #define N 10000
  int search(int A[],int n,int key){
    int i=0;
    A[n]=key;
    while(A[i]!=key) i++;
    return i!=n;
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

