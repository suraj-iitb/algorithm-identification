#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name;
    int Val;
    int index;
}Dat;


void swap(Dat *Card, int i, int j){
    
    Dat temp = Card[i];
    Card[i] = Card[j];
    Card[j] = temp;
}

int Partition(Dat *Card, int p, int r){
    
    int x = Card[r].Val;
    int i = p-1;
    for(int j = p; j < r; j++){
        if (Card[j].Val <= x){
        i+=1;
        swap(Card, i , j);
        }
    }
 swap(Card, i+1, r);
 return i + 1;
 }

void QuickSort(Dat *Card, int p, int r){
    
    if (p < r){
        int q = Partition(Card, p, r);
        QuickSort(Card, p, q-1);
        QuickSort(Card, q+1, r);
    }
}
/*
 * 
 */
int main(int argc, char** argv) {
    
    int Num;
    scanf("%d",&Num);
    Dat *Card = (Dat*)malloc(Num * sizeof(Dat));
    
    for(int a = 0; a < Num; a++){
        
        scanf(" %c %d",&Card[a].name,&Card[a].Val);
        Card[a].index = a;
    }

    QuickSort(Card,0,Num-1);
    

    int stable = 1;
    for(int a = 0; a < Num - 1; a++){
        if(Card[a].Val == Card[a + 1].Val){
           if(Card[a].index > Card[a + 1].index){
               stable = 0;
               break;
           }
        }
    }
    
    if(stable == 1)printf("Stable\n");
    if(stable == 0)printf("Not stable\n");

    
    for(int a = 0; a < Num; a++){
        
            printf("%c %d\n",Card[a].name,Card[a].Val);
    }

    return (0);
}

