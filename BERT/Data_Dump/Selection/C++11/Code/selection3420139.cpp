#include <iostream>
#include <stdio.h>
using namespace std;

void swapp(int y[],int u, int k){

    int temp=y[u];
        y[u]=y[k];
        y[k]=temp;


}

int main(){
    int y,juml=0;
    scanf("%d",&y);
    int *p=new int[y];
    for(int i=0;i<y;i++){
        scanf("%d",&p[i]);
    }

    for(int u=0;u<y-1;u++){
        int minim=u;
        for(int k=u+1;k<y;k++){
            if(p[k]<p[minim])
            minim=k;
   }

        if(p[minim]<p[u])
        {
            swapp(p,u,minim);
        juml++;
        }

    }

    for(int r=0;r<y;r++){
        
           if( r ) printf(" ");
        printf("%d", p[r]);
       
    }
    cout<<"\n"<<juml<<"\n";
}

