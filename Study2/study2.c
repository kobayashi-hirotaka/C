// プログラムの先頭です！
// C言語演習
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
//#define NDEBUG  //assert.hのインクルードより前に定義すること
#include <assert.h>

void prog0() {
	printf("Welcome to JAPANIACE Techno College!!\n");
}

////////////////////////////////////////
//ここより下へプログラム追加
void prog1() {

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
