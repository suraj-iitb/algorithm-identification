#include<stdio.h>

int haku(int KOTA[],int H){
    int a,b,c,sr=0,pet;
    for(a=0;a<H-1;a++){
        pet=a;
        for(b=a;b<H;b++){
            if(KOTA[b]<KOTA[pet]) pet=b;
        }
        c=KOTA[a];
        KOTA[a]=KOTA[pet];
        KOTA[pet]=c;
        if(a!=pet) sr++;
    }
    return sr;
} 
int main(){
    int KOTA[100],H,a,sr;
    scanf("%d",&H);
    for(a=0;a<H;a++){
        scanf("%d",&KOTA[a]);
    }
    sr=haku(KOTA,H);
    for(a=0;a<H;a++){
        if(a>0) printf(" ");
        printf("%d",KOTA[a]);
    }
    printf("\n");
    printf("%d\n",sr);
    return 0;
}

