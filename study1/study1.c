//
// C���ꉉ�K
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* ��Ɨp */
char line[100];

/**
* @brief 2�i��������ϊ�
* @param ix �ϊ����鐔��
* @param �L���r�b�g���i�ő�R�Q�j
* @return char* ������擪�|�C���^
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
* @brief �P�U�i�����ăQ�[��
*/
#define TRYS	30	//��
#define HASTIME	2	//1��̎������ԁi�b�j
void game1() {
	int quest0 = 0;
	int quest = 0;
	int ans = 0;
	clock_t start, end;
	printf("���P�U�i�����ăQ�[���J�n�I�I\n");
	//printf("�\�����ꂽ�Q�i���̂P�U�i�\�L%d��%d�b�ȓ��ɓ��͂�\n"
		//"�N���A��ڎw���Ă��������B\n",TRYS, HASTIME*TRYS);
	start = clock();
	srand((unsigned)time(NULL));
	for(int i=0; i<TRYS; i++) {
		while(quest0 == quest) {
			//�p�ɂɓ����l���o��̂ŁA�Ⴄ�l���o��܂ŌJ��Ԃ��B
			quest0 = rand()%16;
		}
		quest = quest0;
		printf("%2d���:%s>", i+1, bin2str(quest, 4));
		scanf("%x", &ans);
		if (quest != ans) {
			printf("�s�����ł��I��蒼���B\n");
			exit(1);
		}
		end = clock();
		if ((end - start)/CLOCKS_PER_SEC > TRYS*HASTIME) {
			printf("���Ԑ؂�ł��I��蒼���B\n");
			exit(1);
		}
	}
	printf("���߂łƂ��I���i�ł��B\n");
}

void prog0() {
	printf("Welcome to JAPANIACE Techno College!!\n");
}

////////////////////////////////////////
//������艺�փv���O�����ǉ�
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
	
	char a = 'A'; // ���p����
	char aiu[ ] = "��"; // �S�p����
	printf("a=%c aiu=%s\n", a, aiu);
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
