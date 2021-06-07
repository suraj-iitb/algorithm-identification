#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//============================================================================
struct List{
    struct List *prev;
    struct List *next;

    long   key;
};
typedef struct List TList;
//============================================================================
#define MAXCMD 4
const char Command[MAXCMD][20]={
    "insert",
    "delete",
    "deleteFirst",
    "deleteLast"
};
TList *top,*btm;

//============================================================================
void dump(int *A, int N)
{
    int i;

    for (i=0; i<N; i++){
        if (i)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}
//============================================================================
void cdump(char *str)
{
    int i;

    printf("%d:", strlen(str));;
    for (i=0; i<strlen(str); i++){
        if (i)
            printf(" ");
        printf("%02X", (unsigned char)str[i]);
    }
    printf("\n");
}
//============================================================================
TList *searchlist(TList *lst, long key)
{
    while(lst!=NULL){
        if (lst->key==key)
            return lst;
        lst=lst->next;
    }
    return NULL;
}
//============================================================================
void insertlist(long key)
{
    TList *lst;

    lst=malloc(sizeof(TList));
    if (top==NULL){
        top=lst;
        btm=lst;
        top->prev=NULL;
        top->next=NULL;
    }else{
       lst->next=top;
       lst->prev=top->prev;
       top->prev=lst;
       top=lst;
    }
    lst->key=key;
}
//============================================================================
void addlist(long key)
{
    TList *lst;

    lst=malloc(sizeof(TList));
    if (top==NULL){
        top=lst;
        btm=lst;
        top->prev=NULL;
        top->next=NULL;
    }else{
       lst->next=btm->next;
       lst->prev=btm;
       btm->next=lst;
       btm=lst;
    }
    lst->key=key;
}
//============================================================================
void deletelist(TList *lst)
{
    if (lst==NULL)
        return;
    if (lst==top)
        top=top->next;
    if (lst==btm)
        btm=btm->prev;
    if (lst->prev!=NULL)
        lst->prev->next=lst->next;
    if (lst->next!=NULL)
        lst->next->prev=lst->prev;
    free(lst);
}
//============================================================================
void cleanlist(void)
{
    if (top==NULL)
        return;
    while (top->next!=NULL){
        deletelist(top->next);
    }
    deletelist(top);
}
//============================================================================
//============================================================================
//============================================================================
//============================================================================

void input(void)
{
    long *S,*T; long n,q,i,j,k,upper,lower,sum;

    top=btm=NULL;
    //printf("%ld\n%ld", n, i);
    scanf("%ld", &n);
    S=malloc(n*sizeof(long));
    for (i=0; i<n; i++){
        scanf("%ld", &S[i]);
        //addlist(S);
    }
    scanf("%ld", &q);
    T=malloc(q*sizeof(long));
    for (i=0; i<q; i++)
        scanf("%ld", &T[i]);
    for (i=sum=0; i<q; i++){
        for (j=n/2, upper=n-1, lower=0, k=n; k; k>>=1){
            if (T[i]==S[j]){
                sum++;
                break;
            }
            if (T[i]>S[j]){
                lower=j;
                j=(j+upper+1)/2;
            }else
            if (T[i]<S[j]){
                upper=j;
                j=(lower+j)/2;
            }
       }
        //if (searchlist(top, T[i])!=NULL)
        //    sum++;
    }
    printf("%d\n", sum);
    free(T);
    free(S);
    //cleanlist();
}
//============================================================================
int main()
{
    input();
    return 0;
}
//---------------------------------------------------------------------------
