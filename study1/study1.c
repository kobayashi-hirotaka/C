//
// C言語演習
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* 作業用 */
char line[100];

/**
* @brief 2進数文字列変換
* @param ix 変換する数字
* @param 有効ビット数（最大３２）
* @return char* 文字列先頭ポインタ
*/
char *bin2str(int ix, int nbit) {
	unsigned int bit = 0x01<<(nbit-1);
	int i=0;
	for (; bit!=0; i++) {
		if ((ix & bit) != 0) {
			line[i] = '1';
		}
		else {
			line[i] = '0';
		}
		bit >>= 1;
	}
	line[i] = 0;
	return line;
}

/**
* @brief １６進数当てゲーム
*/
#define TRYS	30	//回数
#define HASTIME	2	//1回の持ち時間（秒）
void game1() {
	int quest0 = 0;
	int quest = 0;
	int ans = 0;
	clock_t start, end;
	printf("★１６進数当てゲーム開始！！\n");
	//printf("表示された２進数の１６進表記%d個を%d秒以内に入力し\n"
		//"クリアを目指してください。\n",TRYS, HASTIME*TRYS);
	start = clock();
	srand((unsigned)time(NULL));
	for(int i=0; i<TRYS; i++) {
		while(quest0 == quest) {
			//頻繁に同じ値が出るので、違う値が出るまで繰り返す。
			quest0 = rand()%16;
		}
		quest = quest0;
		printf("%2d回目:%s>", i+1, bin2str(quest, 4));
		scanf("%x", &ans);
		if (quest != ans) {
			printf("不正解です！やり直し。\n");
			exit(1);
		}
		end = clock();
		if ((end - start)/CLOCKS_PER_SEC > TRYS*HASTIME) {
			printf("時間切れです！やり直し。\n");
			exit(1);
		}
	}
	printf("おめでとう！合格です。\n");
}

void prog0() {
	printf("Welcome to JAPANIACE Techno College!!\n");
}

////////////////////////////////////////
//ここより下へプログラム追加
void prog1() {
	int ix = 10;
	int iy = 20;
	printf("ix=%d iy=%d\n", ix, iy);
	
	double dx = 10.5;
	double dy = 20.25;
	printf("dx=%f dy=%f\n", dx, dy);
	
	short sx = 0x10;
	short sy = 0x20;
	printf("sx=%d sy=%d\n", sx, sy);
	
	char a = 'A'; // 半角文字
	char aiu[ ] = "あ"; // 全角文字
	printf("a=%c aiu=%s\n", a, aiu);
}

/**
* 演習問題プログラムリスト
*/
void (*prog[])() = {
	prog0,
	// ここより下へ関数を追加
	prog1,
};

////////////// ここより下を修正しないこと ////////////
/**
* main関数.
* @brief 演習問題を実行
* @return 0
*/
int main(int argc, char* argv[]) {
	if (argc == 1) {				//引数なしでは全プログラム実行
		for (int i =0; i< sizeof(prog)/sizeof(prog[0]); i++) {
			printf("--- 演習%d ---\n", i);
			prog[i]();
		}
	}
	else {
		int num = atoi(argv[1]);	//不当な数字指定の場合はprog0を実行
		if (num < sizeof(prog)/sizeof(prog[0])) {
			printf("--- 演習%d ---\n", num);
			prog[num]();
		}
		else {
			printf("指定されたプログラム演習はありません。\n");
		}
	}
	return 0;
}
