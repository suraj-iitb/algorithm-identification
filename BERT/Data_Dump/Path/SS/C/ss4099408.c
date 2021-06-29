#include <stdio.h>
#include <stdlib.h>

#define vmax (131072*8)
const long long INF=(1ll<<60); 

typedef struct Element {
    int id;
    long long cost;
} Element;

typedef struct Heap {
    Element tree[vmax];
    int cursize;
} Heap;

typedef struct Node {
    int id;
    int cost;
    struct Node *next;
} Node;

Element *new_element(int id,long long cost){
    Element *element=(Element*) malloc(sizeof(Element));
    element->id=id;
    element->cost=cost;
    return element;
}
void swap(Element *a,Element *b){
    Element tmp=*a;
    *a=*b;
    *b=tmp;
}

void push(Heap *heap,Element *elem){
    int i=heap->cursize;
    heap->tree[i]=*elem;
    heap->cursize++;
    while (i!=0){
        if (heap->tree[i].cost<heap->tree[(i-1)/2].cost){
            swap(&(heap->tree[i]),&(heap->tree[(i-1)/2]));
            i=(i-1)/2;
        }else{
            break;
        }
    }
}

void pop(Heap *heap){
    int i=0,j=1;
    heap->tree[0]=heap->tree[heap->cursize-1];
    heap->cursize--;
    while ((2*i+1)<heap->cursize){
        j=2*i+1;
        if ((2*i+2)<heap->cursize){
            if (heap->tree[(2*i+2)].cost<heap->tree[(2*i+1)].cost){
                j=2*i+2;
            }
        }
        if (heap->tree[i].cost>heap->tree[j].cost){
            swap(&(heap->tree[i]),&(heap->tree[j]));
            i=j;
        }else{
            break;
        }
    }
}



Node *new_node(int id,int cost){
    Node *node=(Node*) malloc(sizeof(Node));
    node->id=id;
    node->cost=cost;
    node->next=NULL;
    return node;
}

void link(Node** node,int id,int cost){
    if (*node==NULL){
        *node=new_node(id,cost);
    }else{
        Node *cur=*node;
        while (cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=new_node(id,cost);
    }
}

long long min(long long a,long long b){
    return (a<b?a:b);
}


void dijkstra(Node* linklist[vmax],int v,int r, long long cost[vmax]){
    int i;
    int visited[v];
    Heap heap;
    heap.cursize=0;
    for (i=0;i<v;i++){
        cost[i]=INF;
        visited[i]=0;
        push(&heap,new_element(i,cost[i]));
    }
    push(&heap,new_element(r,0ll));
    while (1){
        int minid;
        long long mincost;
        do{
            minid=heap.tree[0].id;
            mincost=heap.tree[0].cost;
            pop(&heap);
        }while(visited[minid] && heap.cursize!=0);
        if (heap.cursize==0){
            break;
        }
        visited[minid]=1;
        cost[minid]=mincost;

        Node *node=linklist[minid];
        while (node!=NULL){
            if (visited[node->id]==0 && (cost[node->id]>cost[minid]+node->cost)){
                push(&heap,new_element(node->id,cost[minid]+node->cost));
                
            }
            node=node->next;
        }
    }
}



int main(void){
    int v,e,r;
    int i;
    long long cost[vmax];
    scanf("%d%d%d",&v,&e,&r);
    Node *linklist[vmax];
    for(i=0;i<vmax;i++){
        linklist[i]=NULL;
    }

    for (i=0;i<e;i++){
        int s,t,d;
        scanf("%d%d%d",&s,&t,&d);
        link(&linklist[s],t,d);
    }
    
    dijkstra(linklist,v,r,cost);
    for(i=0;i<v;i++){
        if (cost[i]==INF){
            printf("INF\n");
        }else{
            printf("%lld\n",cost[i]);
        }
    }
    return 0;
}

