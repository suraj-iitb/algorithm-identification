#include<stdio.h>

int n,cnt=0;

void print_array(long long elements[]){
    int j;
    for(j=0;j<n;j++){
        printf("%lld",elements[j]);
        if(j<(n-1)) printf(" ");
    }
    printf("\n");
}

void bubble_sort(long long elements[]){
    int i,j;
    long long key;

    for(i=0;i<n;i++){
        for(j=n-1;j>=i+1;j--){
            if(elements[j]<elements[j-1]){
                key = elements[j];
                elements[j] = elements[j-1];
                elements[j-1] = key;
                cnt++;
            }
        }
    }
}

int main(){
    long long elements[100];
    int i;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&elements[i]);
    }

    bubble_sort(elements);
    print_array(elements);
    printf("%d\n",cnt);

    return 0;
}
