#include <stdio.h>
#define N 100
int main()
{
    int data[N];
    int i,num,flag,key,cnt=0;
    

    scanf("%d",&num);

    for(i=0;i<num;i++){
        scanf("%d",&data[i]);
    }
    flag = 1;
    while(flag == 1){
        flag = 0;
        for(i=num-1;i>=1;i--){
            if(data[i] < data[i-1]){
                key = data[i];
                data[i] = data[i-1];
                data[i-1] = key;
                flag = 1;
                cnt++;
            }
        }
    }
    for(i=0;i<num;i++){
        printf("%d",data[i]);
        if(i != num-1) printf(" ");
        if(i == num -1) printf("\n");
    }
    printf("%d\n",cnt);
    return 0;
}

