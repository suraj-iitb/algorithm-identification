//gcc -o program test.c
//./program
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4609152#2
#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

struct Card{
    char suit;//記号
    int value;//数
};
struct Card L[MAX/2+2],R[MAX/2+2];//カード情報を書くのする箱を作る

void merge(struct Card Do_merge[],int left,int mid,int right){
    int i,j,k;
    int left2mid=mid-left;
    int right2mid=right-mid;
    for(i=0;i<left2mid;i++){
        L[i]=Do_merge[left+i];
    }
    for(i=0;i<right2mid;i++){
        R[i]=Do_merge[mid+i];
    }
    L[left2mid].value=R[right2mid].value=SENTINEL;
    i=j=0;
    for(k=left;k<right;k++){
        if(L[i].value<=R[j].value){
            Do_merge[k]=L[i++];
        }else{
            Do_merge[k]=R[j++];
        }
    }
}

void mergeSort(struct Card Do_merge[],int left ,int right){
    int mid;
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(Do_merge,left,mid);
        mergeSort(Do_merge,mid,right);
        merge(Do_merge,left,mid,right);
    }
}

int partition(struct Card Do_quick[],int p,int r){//配列の分離
    int i,j;
    struct Card t,x;
    x=Do_quick[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(Do_quick[j].value<=x.value){
            i++;
            t=Do_quick[i];//値の交換
            Do_quick[i]=Do_quick[j];
            Do_quick[j]=t;
        }
    }
    t=Do_quick[i+1];//値の交換
    Do_quick[i+1]=Do_quick[r];
    Do_quick[r]=t;
    return i+1;
}

void quickSort(struct Card Do_quick[],int p,int r){
    int q;
    if(p<r){
        q=partition(Do_quick,p,r);
        quickSort(Do_quick,p,q-1);
        quickSort(Do_quick,q+1,r);
    }
}

int main(void){
    int card_num;//カードの枚数n
    int card_value;//カードの値v
    struct Card Do_merge[MAX],Do_quick[MAX];
    char Suit[10];//記号を入力させる。間違って複数の文字を書いても止めないために配列にしている？
    int stable=1;//安定か否かのbool型

    scanf("%d",&card_num);//カードの枚数入力
    for(int i=0;i<card_num;i++){//カード情報入力
        scanf("%s %d",Suit,&card_value);
        Do_merge[i].suit=Do_quick[i].suit=Suit[0];
        Do_merge[i].value=Do_quick[i].value=card_value;
    }

    mergeSort(Do_merge,0,card_num);
    quickSort(Do_quick,0,card_num-1);
    for(int i=0;i<card_num;i++){
        //マージソートとクイックソートの結果を比較して安定か否の判定
        if(Do_merge[i].suit!=Do_quick[i].suit){
            stable=0;
        }
    }
    if(stable==1){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
    for(int i=0;i<card_num;i++){
        printf("%c %d\n",Do_quick[i].suit,Do_quick[i].value);
    }
    return 0;
}
