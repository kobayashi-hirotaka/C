// �v���O�����̐擪�ł��I
// C���ꉉ�K
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
//#define NDEBUG  //assert.h�̃C���N���[�h���O�ɒ�`���邱��
#include <assert.h>

void prog0() {
	printf("Welcome to JAPANIACE Techno College!!\n");
}

////////////////////////////////////////
//������艺�փv���O�����ǉ�
void prog1() {

}

/**
* ���K���v���O�������X�g
*/
void (*prog[])() = {
	prog0,
	// ������艺�֊֐���ǉ�
	prog1,
	
};

////////////// ������艺���C�����Ȃ����� ////////////
/**
* main�֐�.
* @brief ���K�������s
* @return 0
*/
int main(int argc, char* argv[]) {
	if (argc == 1) {				//�����Ȃ��ł͑S�v���O�������s
		for (int i =0; i< sizeof(prog)/sizeof(prog[0]); i++) {
			printf("--- ���K%d ---\n", i);
			prog[i]();
		}
	}
	else {
		int num = atoi(argv[1]);	//�s���Ȑ����w��̏ꍇ��prog0�����s
		if (num < sizeof(prog)/sizeof(prog[0])) {
			printf("--- ���K%d ---\n", num);
			prog[num]();
		}
		else {
			printf("�w�肳�ꂽ�v���O�������K�͂���܂���B\n");
		}
	}
	return 0;
}
