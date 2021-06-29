#include<stdio.h>
#define MAX_LEN 10000
#define MAX_QUE 500

int main(){
    int num, que_num, i, j, numList[MAX_LEN], queList[MAX_QUE], ans=0;
    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%d", &numList[i]);
    }
    scanf("%d", &que_num);
    for(i=0; i<que_num; i++){
        scanf("%d", &queList[i]);
    }
    for(i=0; i<que_num; i++){
        for(j=0; j<num; j++){
            if(queList[i] == numList[j]){
                ans++;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
