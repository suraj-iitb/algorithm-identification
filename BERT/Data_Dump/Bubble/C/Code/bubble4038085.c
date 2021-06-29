#include <stdio.h>
#define N 100
int main() {
    int n, a[N],i,j,flag = 0,tmp,count=0;
    
    scanf("%d",&n);

    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {

        flag = 1; // 逆の隣接要素が存在する
        while (flag == 1) {
            flag = 0;
            for (j = n - 1; j > 0; j--) {
                if (a[j] < a[j - 1]) {
                    tmp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = tmp;
                    flag = 1;
                    count++;
                }
            }
            
        }

    }

    for (i = 0; i < n; i++){
      printf("%d", a[i]);
      if(i != n-1) printf(" ");
    }

    printf("\n%d\n",count);
}

