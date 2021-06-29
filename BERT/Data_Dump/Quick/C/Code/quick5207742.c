#include <stdio.h>
#include <math.h>
 
#define N_LIMIT 100000
#define MAX 1000000

void sort(void);

typedef struct C{
    char pic;
    int num;
    int id;
}card;
 
int part(card arrarr[], int p, int r){
    int x, i, j;
    card rep;
    x = arrarr[r].num;
    i = p-1;
     
    for(j = p; j < r; j++) {
        if(arrarr[j].num <= x) {
            i++;
            rep = arrarr[i];
	    arrarr[i] = arrarr[j];
	    arrarr[j] = rep;
        } 
    }
    rep = arrarr[i+1];
    arrarr[i+1] = arrarr[r];
    arrarr[r] = rep;
    return i + 1;
}
 
void quick(card arrarr[], int P, int R){
    int Q,i;
    if(P < R) {
        Q = part(arrarr, P, R);
        quick(arrarr, P, Q - 1);
        quick(arrarr, Q + 1, R);
    }

        for(i=0;i<20000;i++)printf("");
}
 
int isSta(card arrarr[], int n){
    int i;
    for(i=1; i<n; i++) {
        if(arrarr[i-1].num == arrarr[i].num) {
            if(arrarr[i - 1].id > arrarr[i].id) return 0;
        }
    }
    return 1;
}
 
int main(int argc,char *argv[]){
    int i, n;
    card arrarr[N_LIMIT];
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf(" %c %d", &arrarr[i].pic, &arrarr[i].num);
        arrarr[i].id=i;
    }
    quick(arrarr, 0, n-1);
 
    if(isSta(arrarr, n)) printf("Stable\n");
    else printf("Not stable\n");
    for(i=0; i<n; i++) {
        printf("%c %d\n", arrarr[i].pic, arrarr[i].num);
    }
    return 0;
}



void sort(void){
    int *a,*b,*rep,i;

    *rep = *a;
    *a = *b;
    *b = *rep;

    for(i=0;i<20000;i++)printf("");
}

	 
