#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//============================================================================
#define pred(x) ((x)-1)
#define succ(x) ((x)+1)
#define True    1
#define False   0
//#define max(x,y) (((x)<(y))?y:x)
//============================================================================
#define MAX_BUFFER  102
struct graph{
    unsigned char node;
    unsigned char hands;
    unsigned char first;
    unsigned char last;
    short    d;
    struct graph **gary;
};
typedef struct graph TGraph;
//============================================================================
unsigned char Ybuffer[MAX_BUFFER];
char Zbuffer[MAX_BUFFER][MAX_BUFFER];
short Stamp;
//============================================================================
void prnnode(TGraph *gptr)
{
    short j;

    printf("node=%d, hands=%d, ", gptr->node, gptr->hands);
    for (j=0; j<gptr->hands; j++)
        printf("%d ", gptr->gary[j]->node);
    printf("\n");
}
//----------------------------------------------------------------------------
void search(TGraph *gptr, short n)
{
    short i;

#ifdef DESKTOP
    prnnode(gptr);
#endif
    if (gptr->d<0 || n<gptr->d){
        gptr->d=n;
    }
    for (i=0; i<gptr->hands; i++){
        if (gptr->gary[i]->d<0 || n<gptr->gary[i]->d)
            search(gptr->gary[i], succ(n));
    }
}
//----------------------------------------------------------------------------
void input(FILE *file)
{
    short i,j,n,k,u,c,d; char buffer[20]; TGraph *graphary,*gptr;

    fgets(buffer, sizeof(buffer)-1, file);
    sscanf(buffer, "%d", &n);
    graphary=malloc(n*sizeof(TGraph));
    memset(graphary, 0, sizeof(TGraph));
    for (i=Stamp=0; i<n; i++){
        fscanf(file, "%hd", &u);
        fscanf(file, "%hd", &k);
        gptr=&graphary[pred(u)];
        gptr->node=u;
        gptr->hands=k;
        gptr->d=-1;
        gptr->gary=malloc(k*sizeof(TGraph*));
        for (j=0; j<k; j++){
            fscanf(file,"%hd", &c);
            gptr->gary[j]=&graphary[pred(c)];
        }
    }
#ifdef DESKTOP
    for (i=0; i<n; i++){
        prnnode(&graphary[i]);
    }
#endif
    search(graphary, 0);
    for (i=0; i<n; i++){
        gptr=&graphary[i];
        if (gptr->node)
            printf("%d %d\n", gptr->node, gptr->d);
    }

}
//============================================================================
#ifndef DESKTOP
int main()
{
    input(stdin);
    return 0;
}
#endif
