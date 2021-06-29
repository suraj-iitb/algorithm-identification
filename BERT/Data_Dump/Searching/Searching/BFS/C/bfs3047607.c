
#include <stdio.h>
#include <stdlib.h>

#define NIL_VERTEX -1
#define INT_TIME -1

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

typedef struct {
    int * adjacencyList;
    Color color;
    int discoverTime;
    int key;
} Vertex;

void copyVertex(Vertex * p_out, Vertex in) {
    p_out->adjacencyList = in.adjacencyList;
    // dangourous!! what if the malloc is free-ed?!!
    p_out->color = in.color;
    p_out->discoverTime = in.discoverTime;
    p_out->key = in.key;
};

/*
 * VertexQueue
 */
typedef struct {
    Vertex * vertices;
    int head;
    int tail;
    int length;
} VertexQueue;

void initalizeVertexQueue(VertexQueue * p_queue, int length) {
    p_queue->vertices = (Vertex *)malloc(length * sizeof(Vertex));
    // TODO: ^ dangerous!! (?)
    p_queue->head = 0;
    p_queue->tail = 0;
    p_queue->length = length;
}

int isEmpty(VertexQueue queue) {
    return (queue.tail == queue.head);
}
void dequeue(Vertex * p_vertex, VertexQueue * p_queue) {
//    Process x;// = p_queue->processes[p_queue->head];
    copyVertex(p_vertex, p_queue->vertices[p_queue->head]);
    
    if (p_queue->head + 1 == p_queue->length) 
        p_queue->head = 0;
    else 
        p_queue->head = p_queue->head + 1;
    
//    return x;
//    // is it safe to return struct with string inside?
//    printf("dequeue: %d\n", p_vertex->key);
}
void enqueue(VertexQueue * p_queue, Vertex vertex) {
//    printf("enqueue: %d\n", vertex.key);
//    p_queue->processes[p_queue->tail] = process;
    copyVertex(&p_queue->vertices[p_queue->tail], vertex);
    
    if (p_queue->tail + 1 == p_queue->length) 
        p_queue->tail = 0;
    else 
        p_queue->tail = p_queue->tail + 1;
}






void bfs(Vertex vertices[], int nVertices, int sourceIndex) {
    for (int i = 1; i <= nVertices; i++) {
        if (i != sourceIndex) {
            vertices[i0O(i)].color = WHITE;
            vertices[i0O(i)].discoverTime = INT_TIME;
        }
        else {
            vertices[i0O(i)].color = GRAY;
            vertices[i0O(i)].discoverTime = 0;
        }
    }
//    printf("sourceIndex: %d\n", sourceIndex);
    
    VertexQueue queue;
    initalizeVertexQueue(&queue, nVertices);
    
    Vertex vertexFrom;
    Vertex *p_vertexTo;
    enqueue(&queue, vertices[i0O(sourceIndex)]);
    
    while (!isEmpty(queue)) {
        dequeue(&vertexFrom, &queue);
//        printf("vertices[i0O(%d)].discoverTime: %d\n", vertexFrom.key, vertexFrom.discoverTime);
        
        for (int i = 1; vertexFrom.adjacencyList[i0O(i)] != NIL_VERTEX; i++) {
            p_vertexTo = &vertices[i0O(  vertexFrom.adjacencyList[i0O(i)]  )];
            
            if (p_vertexTo->color == WHITE) {
                p_vertexTo->color = GRAY;
                p_vertexTo->discoverTime = vertexFrom.discoverTime +1;
//                printf("p_vertexTo->key: %d, vertexFrom.key :%d, p_vertexTo->discoverTime: %d\n", p_vertexTo->key, vertexFrom.key, p_vertexTo->discoverTime);
                enqueue(&queue, *p_vertexTo);
            }
        }
        
        vertexFrom.color = BLACK;
    }
}

int main(int argc, char** argv) {
    int nVertices;
    
    // scan number of already existed events
    scanf("%d", &nVertices); 
    
    Vertex vertices[nVertices];
    int indexFrom, indexTo;
    int nEdges;
    int i,j;
    
    for (i = 1; i <= nVertices; i++) {
        scanf("%d", &indexFrom); 
        vertices[i0O(indexFrom)].key = indexFrom;
        scanf("%d", &nEdges); 
        
        // create adjacency list
        vertices[i0O(indexFrom)].adjacencyList = (int *) malloc((nEdges+1) * sizeof(int));
        
        // write adjacency list
        for (j = 1; j <= nEdges; j++) {
            scanf("%d", &indexTo); 
            vertices[i0O(indexFrom)].adjacencyList[i0O(j)] = indexTo;
        }
        
        // terminal of adjacency list
        vertices[i0O(indexFrom)].adjacencyList[i0O(nEdges+1)] = NIL_VERTEX;
    }
    
//    // print result
//    printf("Scan result: \n");
//    for (i = 1; i <= nVertices; i++) {
//        for (j = 1; adjacencyLists[i0O(i)][i0O(j)] != NIL_VERTEX; j++) {
//            if (j > 1) printf(" ");
//            printf("%d", adjacencyLists[i0O(i)][i0O(j)]);
//        }
//        printf("\n");
//    }
    
    bfs(vertices, nVertices, 1);
    
    for (i = 1; i <= nVertices; i++) {
        printf("%d %d\n", i, vertices[i0O(i)].discoverTime);
    }

    return (EXIT_SUCCESS);
}


