#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    int p;
    for (p = 0; p < n; p++)
    {
        scanf("%d", &a[p]);
    }

    int num = 0;
    int flag = 1;
    
    while (flag){
        flag = 0;
        int j;
        
        for (j = n - 1; j >= 1; j--){
            
            if (a[j] < a[j - 1]){
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                flag = 1;
                num++;
            }
        }
    }
    for (p = 0; p < n; p++){
        printf("%d", a[p]);
        if (p < n - 1){
            printf(" ");
        }
    }
    
    printf("\n%d\n", num);
    
    return 0;
}
