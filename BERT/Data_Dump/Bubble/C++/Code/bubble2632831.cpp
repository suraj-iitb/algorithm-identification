#include <cstdio>

int a[100],n,count = 0;


void print(){
    for(int i=0;i<n;i++){
        if(i>0) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    printf("%d\n", count);
}


void bubbleSort(){
    int i = 0,j,flag = 1,tmp;
    while(flag == 1){
        flag = 0;
        for(j=n-1;j>i;j--){
            if(a[j-1]>a[j]){
                count++;
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
            }
        }
        i++;
    }
}


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubbleSort();
    print();
    return 0;
}
