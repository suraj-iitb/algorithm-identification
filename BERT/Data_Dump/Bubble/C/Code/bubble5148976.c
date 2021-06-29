#include<stdio.h>

int main(void)
{
	int sequence[100];//数列
	int sequence_length;//数列の長さ
	int caunt = 0;
	int tmp;//値交換に使用する変数
	int i;
	int j;
	int k = 0;
	//入力
	scanf("%d", &sequence_length);
	for(i = 0;i < sequence_length;i++){
		scanf("%d", &sequence[i]);
	}
	//バブルソート
	for(i = 0;i < sequence_length - 1;i++){
		for(j = sequence_length - 1;j > i;j--){
			if(sequence[j - 1] > sequence[j]){
				tmp = sequence[j];
				sequence[j] = sequence[j - 1];
				sequence[j - 1] = tmp;
				caunt++;
			}
		}
	}
	//出力
	while(1){
	    printf("%d", sequence[k]);
	    k++;
		if(k == sequence_length){
	        break;
	    }
	    printf(" ");
	}
	printf("\n");
	printf("%d\n", caunt);
	
	return 0;
}


