#include<stdio.h>
#define H 100000
#define SAO 2000000000

struct Key{
    char s;
    int v;
};

struct Key L[H / 2 + 2],R[H / 2 + 2];

void haku(struct Key B[],int h,int l, int m,int r){
    int i,j,k;
    int h1=m-l;
    int h2=r-m;
    for(i=0;i<h1;i++) L[i]=B[l+i];
    for(i=0;i<h2;i++) R[i]=B[m+i];
    L[h1].v=R[h2].v=SAO;
    i=j=0;
    for(k=l;k<r;k++){
        if(L[i].v<=R[j].v){
            B[k]=L[i++];
        }else{
            B[k]=R[j++];
        }
        }
    }
    void hakusort(struct Key B[],int h,int l, int r){
        int m;
        if(l+1<r){
            m=(l+r)/2;
            hakusort(B,h,l,m);
            hakusort(B,h,m,r);
            haku(B,h,l,m,r);
        }
    }
    int par(struct Key B[],int h,int q, int r){
        int i,j;
        struct Key k,x;
        x=B[r];
        i=q-1;
        for(j=q;j<r;j++){
            if(B[j].v<=x.v){
                i++;
                k=B[i];
                B[i]=B[j];
                B[j]=k;
            }
        }
        k=B[i+1];
        B[i+1]=B[r];
        B[r]=k;
        return i+1;
    }
    void quick(struct Key B[],int h,int q,int r){
        int p;
        if(q<r){
            p=par(B,h,q,r);
            quick(B,h,q,p-1);
            quick(B,h,p+1,r);
        }
    }
    int main(){
        int h,i,x;
        struct Key P[H],B[H];
        char W[10];
        int sta=1;
        scanf("%d",&h);
        for(i=0;i<h;i++){
            scanf("%s %d",W,&x);
            P[i].s=B[i].s=W[0];
            P[i].v=B[i].v=x;
        }
        hakusort(P,h,0,h);
        quick(B,h,0,h-1);
        for(i=0;i<h;i++){
            if(P[i].s!=B[i].s) sta=0;
        }
        if(sta==1) printf("Stable\n");
        else printf("Not stable\n");
        for(i=0;i<h;i++){
            printf("%c %d\n",B[i].s,B[i].v);
        }
    return 0;
}
