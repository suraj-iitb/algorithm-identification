#include<iostream>
#include<cstdio>

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>s= ;i--)

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define MAXN 10000+10
int a[MAXN],n;

void print() {
    REP(i,0,n-1) {
        if(i>0) printf(" ");
        printf("%d",a[i]);
    }
    puts("");
}

int main() {
    n=read();
    REP(i,0,n-1) a[i]=read();
    
    print();
    REP(i,1,n-1) {
        int v=a[i];
        int j=i-1;
        while(j>=0&&a[j]>v) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        print();
    }
    return 0;
}
