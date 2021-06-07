/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kundaikwangwari
 *
 * Created on July 23, 2019, 8:15 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define NIL -1
#define White 0
#define Grey 1
#define Black 2
#define size 105

/*
 * 
 */
int Timetrack,n;
int table[size][size];

void Visit(int V,int *StartTime,int *FinishTime, int *Color){
    
    
    //printf("am now visiting\n");

    Color[V] = Grey;
    //printf("going intp node %d, color %d\n",V,Color[V]);
    StartTime[V] = ++Timetrack;
    for(int u = 1; u < n + 1; u++){
        if(table[V][u] == NIL)continue;
        if(Color[u] == White)Visit(u,StartTime,FinishTime,Color);
    }
    Color[V] = Black;
    FinishTime[V] = ++Timetrack;


}

void DepthFirstSearch(int *Color,int *StartTime,int *FinishTime){
   
    for(int V = 1; V < n + 1; V++){
        Color[V] = White;
        Timetrack = 0;
    }
    
    for(int V = 1; V < n + 1; V++){
        //printf("about to visit...");
        if(Color[V] == White)Visit(V,StartTime,FinishTime,Color);
    }

}
int main(int argc, char** argv) {

    int V,k,edge;
    scanf("%d",&n);
    
    int Color[n+1],StartTime[n+1],FinishTime[n+1];
    for(int i = 1; i < n + 1; i++){
        for(int a = 1; a < n + 1; a++)table[i][a] = NIL;
}
    
    for(int i = 0; i < n ; i++){
        
        scanf("%d%d",&V,&k);
        //printf("V %d edges %d\n",V,edge);
        for(int a = 0; a < k; a++){
            scanf("%d",&edge);
            table[V][edge] = 1;
            //printf("table(%d)(%d) has value %d \n",V,edge,table[V][edge]);
        }
    }
    
    
        DepthFirstSearch(Color,StartTime,FinishTime);
        for(int i = 1; i < n + 1; i++){
            printf("%d %d %d\n",i,StartTime[i], FinishTime[i]);
        }
    
    return (0);
}


