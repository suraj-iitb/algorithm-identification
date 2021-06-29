#include <stdio.h>
#include <stdlib.h>
 typedef struct card {
     int num;
     char suit;
     int pos;
} card;



int main()
{
    int n;
    scanf("%d",&n);
    card array[n];
    for(int i =0; i<n; i++){
        scanf("%s %d", &array[i].suit, &array[i].num);
        array[i].pos=i;
    }

    void swap(card ar[], int l, int k){
        card temp;
        temp=ar[l];
        ar[l]=ar[k];
        ar[k]=temp;
    }

   int partition(card array[], int start, int end){
        int wall=start, key=array[end].num;
        for(int i =start; i<end; i++){
            if(array[i].num<=key) swap(array,i,wall), wall++;
        }
        swap(array,wall,end);
        return wall;
    }

    void quicksort(card arr[], int start, int end){
        if(start<end) {
            int mid = partition(arr,start,end);
            quicksort(arr, start, mid-1);
            quicksort(arr, mid+1, end);
        }
    }

    quicksort(array, 0,n-1);

    int check(card arr[], int len ){
        for(int i=0; i<len; i++){
            for (int j = i+1; j<len ; j++){
                if(arr[i].num==arr[j].num){
                    if(arr[i].pos>arr[j].pos) return 0;
                }
            }
        }
        return 1;
    }

    if(check(array, n)==1) printf("Stable\n"); else printf("Not stable\n");
    for (int i=0; i<n; i++) printf("%c %d\n", array[i].suit, array[i].num);


    return 0;
}

