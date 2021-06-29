#include<stdio.h>
void binary(int *,int,int);

int k=0;
int num2;
int main(){
    int i,j,num1,first[100000],second[500000],same=0,left,right,mid;
    //一つ目の数列
    scanf("%d",&num1);
        for(int i=0;i<num1;i++){
            scanf("%d",&first[i]);
        }
    //二つ目の要素
    scanf("%d",&num2);
    for(i=0;i<num2;i++){
        scanf("%d",&second[i]);
    }
    for(i=0;i<num2;i++){
    k++;
    binary(first,num1,second[i]);
    }
    //printf("%d",k);
    return 0;
}

void binary(int *f,int num,int key){
  int left,right,mid;
  static int same=0;
     left=0;
     right=num;
        while(left<right){
            mid = (left + right)/2;
            if(f[mid]==key){
	      //printf("%d%d\n",f[mid],key);
                same++;
                break;
            }else if(key<f[mid]){
                right=mid;
            }else {
                left=mid+1;
            }
        }
	//printf("%d%d\n",k,num2);
	if(k==num2){
	  printf("%d\n",same);
	  }

}

