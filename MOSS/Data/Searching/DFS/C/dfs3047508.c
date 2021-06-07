
#include <stdio.h>
#include <stdlib.h>

#define NIL -1

// translate 1-origin into 0-origin
int i0O(int index1Origin) {
    return index1Origin-1;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_STACK_VALUES 100
#define STR_MAX_LENGTH 100

typedef enum {
    WHITE,
    GRAY,
    BLACK
} Color;

// TRICKY Implementation
typedef struct {
    int * * adjacencyLists;
    Color * colors;
    int * discoverTimes;
    int * finishingTimes;
    int * p_time;
} GlobalVariablesPackage;

void visit(int vertexFrom, GlobalVariablesPackage gvp) {
//    printf("visiting index%d (1origin)\n", vertexFrom);
    gvp.colors[i0O(vertexFrom)] = GRAY;
    gvp.discoverTimes[i0O(vertexFrom)] = ++(*(gvp.p_time));
//    printf("discover index %d at time %d \n", vertexFrom, *(gvp.p_time));
    
    for (int j = 1, vertexTo; (vertexTo = gvp.adjacencyLists[i0O(vertexFrom)][i0O(j)]) != NIL; j++) {
        if (gvp.colors[i0O( vertexTo )] == WHITE)
            visit(vertexTo, gvp);
    }
    gvp.colors[i0O(vertexFrom)] = BLACK;
    gvp.finishingTimes[i0O(vertexFrom)] = ++(*(gvp.p_time));
//    printf("finish index %d at time %d \n", vertexFrom, *(gvp.p_time));
}

void dfs(int * (adjacencyLists[]), int nVertices) {
    Color colors[nVertices];
    int discoverTimes[nVertices], finishingTimes[nVertices];
    int time = 0;
    
    // GVP
    GlobalVariablesPackage gvp;
    gvp.adjacencyLists = adjacencyLists;
    gvp.colors = colors;
    gvp.discoverTimes = discoverTimes;
    gvp.finishingTimes = finishingTimes;
    gvp.p_time = &time;
    // GVP
    
    int i;
    
    for (i = 1; i <= nVertices; i++) 
        gvp.colors[i0O(i)] = WHITE;
    
    
    for (i = 1; i <= nVertices; i++)
        if (gvp.colors[i0O(i)] == WHITE)
            visit(i, gvp);
    
    
    
    // printing
    for (i = 1; i <= nVertices; i++)
        printf("%d %d %d\n", i, gvp.discoverTimes[i0O(i)], gvp.finishingTimes[i0O(i)]);
}

int main(int argc, char** argv) {
    int nVertices;
    
    // scan number of already existed events
    scanf("%d", &nVertices); 
    
    int *(adjacencyLists[nVertices]);
    int vertexFrom, vertexTo;
    int nEdges;
    int i,j;
    
    for (i = 1; i <= nVertices; i++) {
        scanf("%d", &vertexFrom); 
        scanf("%d", &nEdges); 
        
        // create adjacency list
        adjacencyLists[i0O(vertexFrom)] = (int *) malloc((nEdges+1) * sizeof(int));
        
        // write adjacency list
        for (j = 1; j <= nEdges; j++) {
            scanf("%d", &vertexTo); 
            adjacencyLists[i0O(vertexFrom)][i0O(j)] = vertexTo;
        }
        
        // terminal of adjacency list
        adjacencyLists[i0O(vertexFrom)][i0O(nEdges+1)] = NIL;
    }
    
//    // print result
//    printf("Scan result: \n");
//    for (i = 1; i <= nVertices; i++) {
//        for (j = 1; adjacencyLists[i0O(i)][i0O(j)] != NIL; j++) {
//            if (j > 1) printf(" ");
//            printf("%d", adjacencyLists[i0O(i)][i0O(j)]);
//        }
//        printf("\n");
//    }
    
    dfs(adjacencyLists, nVertices);
    

    return (EXIT_SUCCESS);
}


