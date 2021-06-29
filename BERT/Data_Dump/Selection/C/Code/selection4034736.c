#include <stdio.h>
#define N 100

int main(){
    int num,i,j,minj,key,cnt=0;
    int data[N];

    scanf("%d",&num);

    for(i=0;i<num;i++){
        scanf("%d",&data[i]);
    }

    for(i=0;i<num;i++){
        minj = i;
        for(j=i;j<num;j++){
            if(data[j] < data[minj]){ 
                minj = j;
            }
        }
        if(minj != i){
            key = data[i];
            data[i] = data[minj];
            data[minj] = key;
            cnt++;
        }
    }

    for(i=0;i<num;i++){
        printf("%d",data[i]);
        if(i == num - 1) printf("\n");
        if(i != num - 1) printf(" ");
    }
    printf("%d\n",cnt);
    return 0;
}

