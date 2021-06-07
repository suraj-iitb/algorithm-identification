#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define listcount 100000


typedef struct num{
	int value;
	struct num* under;
	struct num* over;
} number;



int main() {
	int n;
	scanf("%d",&n);
	if(n > 0){ //念のため
		int v;
		scanf("%d",&v);
		number first;
		first.value = v;
		first.under = NULL;
		first.over = NULL;
		
		for(int i = 1; i < n; i++){
			scanf("%d",&v);
			number *p = &first;
			
			for(int quit = 0;quit < 5 ;){
				if(p->value < v){
					if(p->over == NULL){
						//導入
						number *ins;
						if ((ins = (number *) malloc(sizeof(number))) == NULL) {
							break;
						}
						ins->value = v;
						ins->under = NULL;
						ins->over = NULL;
						p->over = ins;
						quit = 10;
					}else{
						p = p->over;
					}
				}else if(p->value > v){
					if(p->under == NULL){
						//導入
						number *ins;
						if ((ins = (number *) malloc(sizeof(number))) == NULL) {
							break;
						}
						ins->value = v;
						ins->under = NULL;
						ins->over = NULL;
						p->under = ins;
						quit = 10;
					}else{
						p = p->under;
					}
				}else{
					quit = 10;
				}
			}
		}
		//qの値
		scanf("%d",&n);
		int counter = 0; /// 一致数
		for(int i = 0; i < n; i++){
			scanf("%d",&v);
			number *p = &first;
			
			for(int quit = 0;quit < 5 ;){
				if(p->value < v){
					if(p->over == NULL){
						quit = 10;
					}else{
						p = p->over;
					}
				}else if(p->value > v){
					if(p->under == NULL){
						quit = 10;
					}else{
						p = p->under;
					}
				}else{
					counter++;
					quit = 10;
				}
			}
			
			
		}
		printf("%d\n",counter);
	}
	return 0;
}




