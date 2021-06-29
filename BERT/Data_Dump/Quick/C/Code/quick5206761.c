#include<stdio.h>
#include<time.h>
#include<math.h>
#define VMAX 100000
#define SENTINELD 2000000000

struct Card {
    char su;
    int val;
    int idz;
};

int part(struct Card Aum[], int num, int pum, int rum){
    int ium,jum;
    struct Card tum,xum;
    xum = Aum[rum];
    ium = pum-1;
    for (jum = pum;jum<rum;jum++){
        if (Aum[jum].val <= xum.val){
            ium++;
            tum = Aum[ium]; Aum[ium] = Aum[jum]; Aum[jum] = tum;
        }
    }
    tum = Aum[ium+1]; Aum[ium+1] = Aum[rum]; Aum[rum] = tum;
    return ium+1;
}

void quick(struct Card Aum[], int num, int pum, int rum){
    int qum;
    if (pum<rum){
        qum = part(Aum, num, pum, rum);
        quick(Aum, num, pum, qum-1);
        quick(Aum, num, qum+1, rum);
    }
}

int main(){
    int num, ium, vum;
    struct Card Aum[VMAX];
    char Sum[10];
    int stableum = 1;

    scanf("%d", &num);

    for (ium=0;ium<num;ium++){
        scanf("%s %d", Sum, &vum);
        Aum[ium].su = Sum[0];
        Aum[ium].val = vum;
        Aum[ium].idz = ium;
    }

    quick(Aum, num, 0, num-1);

    for (ium=0;ium<num;ium++){
        if (Aum[ium-1].val == Aum[ium].val && Aum[ium-1].idz > Aum[ium].idz){
            stableum = 0;
            break;
        }
    }

    if (stableum == 1) printf("Stable\n");
    else printf("Not stable\n");
    for (ium=0;ium<num;ium++){
        printf("%c %d\n", Aum[ium].su, Aum[ium].val);
    }

    return 0;
}

