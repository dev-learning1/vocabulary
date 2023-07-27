
#include <stdio.h>
#include <string.h>
#include <stdlib.h>	// malloc, free �Լ��� ����� ��� ����
#include <time.h>


int rand_check(int random[], int idx, int num) {
	int i;
	srand(time(NULL));
	while (1) {
		random[idx] = rand() % num;
		//printf("rand %d: %d\n", idx, random[idx]);
		for (i = 0; i < idx; i++) {
			if (random[idx] == random[i]) {
				break;
			}
			else {
				if (i == idx - 1)	return random[idx];
			}
		}
		if (idx == 0)	return random[idx];
	}
}

int main() {
	char word[100][100], mean[100][100];
	int num = 0, i, sub_i;
	int option;
	int* random;
	char word_write[100], mean_write[100];
	int score = 0, fault = 0;

	printf("�ܾ��Է³����� ������ �����Է¿� f �Է�\n\n");
	while (1) {
		printf("��� �Է��Ͻÿ� : ");
		scanf("%s", word[num]);
		if (strcmp(word[num], "f") == 0) {	//�ܾ� �߰� ������
			break;
		}
		printf("�ѱ�� �Է��Ͻÿ� : ");
		scanf("%s", mean[num]);
		num += 1;
	}

	printf("\n-------------�ܾ���-----------------\n");
	for (i = 0; i < num; i++) {
		printf("%s : %s\n", word[i], mean[i]);
	}

	printf("\n-------------����-------------------\n");
	printf("1. �� ����\n2. ���� ����\n");
	scanf("%d", &option);
	printf("\n");

	//srand(time(NULL));
	random = (int*)malloc(sizeof(int) * num);    // (int ũ�� * �Է¹��� ũ��)��ŭ ���� �޸� �Ҵ�;
	for (i = 0; i < num; i++) {
		random[i] = rand_check(random, i, num);    //��ġ�������� ������ �ߺ� üũ
	}
	switch (option) {
	case 1:
		printf("----------���� �ۼ��Ͻÿ�-----------\n");
		for (i = 0; i < num; i++) {
			printf("%s : ", word[random[i]]);
			scanf("%s", mean_write);
			if (strcmp(mean[random[i]], mean_write) == 0) {    //��������
				score += 1;
				//printf("score : %d\n", score);
			}
			else {    //Ʋ������
				fault += 1;
				//printf("fault : %d\n", fault);
			}
		}
		printf("\n-------------����-------------------\n");
		printf("score : %d\nfault : %d", score, fault);
		break;
	case 2:
		printf("----------��� �ۼ��Ͻÿ�----------\n");
		for (i = 0; i < num; i++) {
			printf("%s : ", mean[random[i]]);
			scanf("%s", word_write);
			if (strcmp(word[random[i]], word_write) == 0) {    //��������
				score += 1;
				//printf("score : %d\n", score);
			}
			else {    //Ʋ������
				fault += 1;
				//printf("fault : %d\n", fault);
			}
		}
		printf("\n-------------����-------------------\n");
		printf("score : %d\nfault : %d", score, fault);
		break;
	}
	free(random);    // �������� �Ҵ��� �޸� ����
	random = NULL;	//�迭 �ʱ�ȭ
}
