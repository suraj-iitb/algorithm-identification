#include <stdio.h>
#define N 100000

int num1,num2,math1[N],math2[N],i;

void input(void){
    scanf("%d",&num1);
    for(i=0;i<num1;i++)scanf("%d",&math1[i]);
    scanf("%d",&num2);
    for(i=0;i<num2;i++)scanf("%d",&math2[i]);
}

int main(void){
    int left,right,mid,count=0,key;
    input();
    for(i=0;i<num2;i++){
        key = math2[i];
        left = 0;
        right = num1;
      while(left < right){
        mid = (left + right) / 2;
        if(key == math1[mid]){
	         count++;
        	break;
        }
        else if(key < math1[mid])right = mid;
        else left = mid + 1;
        }
    }
    printf("%d\n",count);
    return 0;
}
