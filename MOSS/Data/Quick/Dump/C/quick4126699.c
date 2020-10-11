#include <stdio.h>
 
#define N 100000

typedef struct C{
    char pic;
    int num;
    int id;
}card;
 
int part(card arr[], int p, int r){
    int x, i, j;
    card tmp;
    x = arr[r].num;
    i = p-1;
     
    for(j = p; j < r; j++) {
        if(arr[j].num <= x) {
            i++;
            tmp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = tmp;
        } 
    }
    tmp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = tmp;
    return i + 1;
}
 
void quick(card arr[], int P, int R){
    int Q;
    if(P < R) {
        Q = part(arr, P, R);
        quick(arr, P, Q - 1);
        quick(arr, Q + 1, R);
    }
}
 
int isSta(card arr[], int n){
    int i;
    for(i=1; i<n; i++) {
        if(arr[i-1].num == arr[i].num) {
            if(arr[i - 1].id > arr[i].id) return 0;
        }
    }
    return 1;
}

int main(int argc,char *argv[]){
    int i, n;
    card arr[N];
    scanf("%d", &n);

    for(i=0; i<n; i++) {
      if(i<n)break;
    }
    
    for(i=0; i<n; i++) {
        scanf(" %c %d", &arr[i].pic, &arr[i].num);
        arr[i].id=i;
    }
    quick(arr, 0, n-1);
 
    if(isSta(arr, n)) printf("Stable\n");
    else printf("Not stable\n");
    for(i=0; i<n; i++) {
        printf("%c %d\n", arr[i].pic, arr[i].num);
    }
    return 0;
}

