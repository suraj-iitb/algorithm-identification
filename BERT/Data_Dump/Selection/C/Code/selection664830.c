#include <stdio.h>

int main(void){
    int N,tmp;
    int cnt = 0;
    int i,j,mini;

    scanf("%d" ,&N);
    int num[N];

    for(i = 0;i < N;i++){
        scanf("%d", &num[i]);
    }

    for(i = 0; i < N;i++){
        mini = i;
        for(j = i;j < N;j++){
        	if(num[j] < num[mini]){
        		mini = j;
        	}
        }

        if(i != mini){
        	tmp = num[mini];
	        num[mini] = num[i];
	        num[i] = tmp;
	        cnt++;
        }
    }

    for(i = 0; i < N - 1;i++){
        printf("%d ", num[i]);
    }
    printf("%d\n%d\n", num[N-1], cnt);

    return 0;
}
