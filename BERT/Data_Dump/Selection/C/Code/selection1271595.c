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

void selection_sort(long long elements[]){
    int i,j,mini;
    long long key;

    for(i=0;i<n;i++){
        mini=i;
        for(j=i;j<n;j++){
            if(elements[j]<elements[mini]){
                mini = j;
            }
        }
        if(mini!=i){
            key = elements[i];
            elements[i] = elements[mini];
            elements[mini] = key;
            cnt++;
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

    selection_sort(elements);
    print_array(elements);
    printf("%d\n",cnt);

    return 0;
}
