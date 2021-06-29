#include <stdio.h>
void Search(int);
int S[10000],count=0;
int main(){
	int Slength,Tlength,key;
	int i;


//input S
scanf("%d",&Slength);
for(i=0;i<Slength;i++){
	scanf("%d",&S[i]);
}

//input T
scanf("%d",&Tlength);
for(i=0;i<Tlength;i++){
	scanf("%d",&key);
	Search(key);
}



//output C
printf("%d\n",count);

	return 0;
}


void Search(int key){
int i;
	for(i=0;i<10000;i++){
		if(S[i]==key){
			count++;
			break;
		}
	}

}

