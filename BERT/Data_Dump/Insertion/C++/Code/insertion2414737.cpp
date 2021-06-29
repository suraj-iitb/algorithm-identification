#include <stdio.h>

// insertion sort


void output(int a[], int n){
    for(int i=0; i<n-1; i++) {
        printf("%d ", a[i]);
    }
        printf("%d\n", a[n-1]);
}


int main() {
    int n;
    int now_position = 1;
    int sorted_position = 0;
    int v;
    int slide = 0;
    int a[100];
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }


    


    while (now_position < n ) {
        output(a, n);
        //printf("now_position: %d, sorted_position: %d\n", now_position, sorted_position);
        //for(int i=0; i<n; i++) {
        //    printf("%d ", a[i]);
        //}
        //printf("\n");
        v = a[now_position];
        
        for (int i=now_position-1; i>=0; i--){
            if (v <= a[i]) {
                slide++;
            }
        }
        int tmp = 0 ;
        for (int i=0; i<slide; i++){
            a[now_position + tmp] = a[now_position + tmp - 1];
            tmp--;

        }
        
        //printf("slide %d\n", slide);
        //printf("v = %d\n", v);
        a[now_position + tmp] = v;
        slide=0; 
        now_position++;  
        
        
        
    }
        output(a, n);
        //for(int i=0; i<n; i++) {
        //    printf("%d ", a[i]);
        //}
        //printf("\n");

    
    return 0;
}
