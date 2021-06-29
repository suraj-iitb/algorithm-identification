//============================================================================
// 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//============================================================================
typedef struct{
    char suit;
    int  value;
    int  order;
}TCard;
//============================================================================
int BubbleSort(TCard *ary, int n)
{
    int i,j,k,l, cnt; TCard chg;

    for (k=cnt=0, l=n; k<n-1; k++, l--)
    for (i=0,j=1; j<l; i++, j++){
        if (ary[j].value<ary[i].value)
            chg=ary[i], ary[i]=ary[j], ary[j]=chg, cnt++;
	}
    return cnt;
}
//============================================================================
int SelectionSort(TCard *ary, int n)
{
    int i,j,minj,cnt; TCard chg;

    for (i=cnt=0; i<n; i++){
        for (j=minj=i; j<n; j++){
            if (ary[j].value<ary[minj].value)
                minj=j;
        }
        if (i!=minj)
            chg=ary[i], ary[i]=ary[minj], ary[minj]=chg, cnt++;
    }
    return cnt;
}
//============================================================================
void selectionsort()
{
    int i,cnt, n; TCard *ary;

    scanf("%d", &n);
    ary=malloc(n*sizeof(TCard));
    for (i=0; i<n; i++)
        scanf("%d", &ary[i].value);
    cnt=SelectionSort(ary, n);
    for (i=0; i<n; i++){
        if (i) printf(" ");
        printf("%d", ary[i].value);
    }
    printf("\n%d\n", cnt);
    free(ary);
}
//============================================================================
void cardsort()
{
    int i,cnt,nstb,n; TCard *ary; char sub[10];

    scanf("%d", &n);
    ary=malloc(n*sizeof(TCard));
    for (i=0; i<n; i++){
        scanf("%s", sub);
        //scanf("%c%d", &ary[i].suit, &ary[i].value);
        ary[i].suit=*sub;
        ary[i].value=sub[1]-'0';
        ary[i].order=i;
    }
    cnt=BubbleSort(ary, n);
    for (i=nstb=0; i<n; i++){
        if (i) printf(" ");
        printf("%c%d", ary[i].suit, ary[i].value);
        if (i<n-1)
        if (ary[i].value==ary[i+1].value && ary[i+1].order<ary[i].order)
                nstb++;
    }
    printf("\n%s\n", (nstb)?"Not stable":"Stable");
    cnt=SelectionSort(ary, n);
    for (i=0; i<n; i++){
        if (i) printf(" ");
        printf("%c%d", ary[i].suit, ary[i].value);
        if (i<n-1)
        if (ary[i].value==ary[i+1].value && ary[i+1].order<ary[i].order)
                nstb++;
    }
    printf("\n%s\n", (nstb)?"Not stable":"Stable");
    free(ary);
}
//============================================================================
int main(void)
{
    selectionsort();
    //cardsort();
    return 0;
}
//============================================================================
