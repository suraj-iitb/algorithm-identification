#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a[100]={0};
    int n=0;
    int counter=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){scanf("%d", &a[i]);}
    for(int m=0;m<=n-1;m++){
        for(int j=n-1;j>=m+1;j--){
            if(a[j]<a[j-1]){
                int temp=0;
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                counter++;
            }
        }
        if(m!=n-1){printf("%d ", a[m]);}
        else{printf("%d\n", a[m]);}
    }
    printf("%d\n", counter);
    return 0;
}



