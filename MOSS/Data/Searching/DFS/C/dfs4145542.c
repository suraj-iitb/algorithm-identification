#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
    int num;
    int *array;
    int d;
    int f;
}List;

int max;
List list[200];
int jud[200];
int time;

void visit(int);


int main(){
    int gb;

    scanf("%d",&max);

    for(int i=1;i<=max;i++){
        scanf("%d%d",&gb,&list[i].num);
        list[i].array=malloc(sizeof(int)*list[i].num);
        for(int j=0;j<list[i].num;j++){
            scanf("%d",&list[i].array[j]);
        }
    }

    for(int i=1;i<=max;i++){
        jud[i]=WHITE;
    }
    time=0;
    for(int i=1;i<=max;i++){
            if(jud[i]==WHITE)
                visit(i);
    }

    for(int i=1;i<=max;i++){
        printf("%d %d %d\n",i,list[i].d,list[i].f);
    }



    return 0;
}

void visit(int n){
    jud[n]=GRAY;
    list[n].d=++time;
    for(int i=0;i<list[n].num;i++){
        if(jud[list[n].array[i]]==WHITE)
            visit(list[n].array[i]);
    }
    jud[n]=BLACK;
    (list+n)->f=++time;
}

