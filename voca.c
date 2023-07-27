
#include <stdio.h>
#include <string.h>
#include <stdlib.h>	// malloc, free 함수가 선언된 헤더 파일
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

	printf("단어입력끝내고 싶으면 영어입력에 f 입력\n\n");
	while (1) {
		printf("영어를 입력하시요 : ");
		scanf("%s", word[num]);
		if (strcmp(word[num], "f") == 0) {	//단어 추가 끝내기
			break;
		}
		printf("한국어를 입력하시요 : ");
		scanf("%s", mean[num]);
		num += 1;
	}

	printf("\n-------------단어장-----------------\n");
	for (i = 0; i < num; i++) {
		printf("%s : %s\n", word[i], mean[i]);
	}

	printf("\n-------------퀴즈-------------------\n");
	printf("1. 뜻 쓰기\n2. 영어 쓰기\n");
	scanf("%d", &option);
	printf("\n");

	//srand(time(NULL));
	random = (int*)malloc(sizeof(int) * num);    // (int 크기 * 입력받은 크기)만큼 동적 메모리 할당;
	for (i = 0; i < num; i++) {
		random[i] = rand_check(random, i, num);    //위치랜덤값과 랜덤값 중복 체크
	}
	switch (option) {
	case 1:
		printf("----------뜻을 작성하시요-----------\n");
		for (i = 0; i < num; i++) {
			printf("%s : ", word[random[i]]);
			scanf("%s", mean_write);
			if (strcmp(mean[random[i]], mean_write) == 0) {    //맞은개수
				score += 1;
				//printf("score : %d\n", score);
			}
			else {    //틀린개수
				fault += 1;
				//printf("fault : %d\n", fault);
			}
		}
		printf("\n-------------점수-------------------\n");
		printf("score : %d\nfault : %d", score, fault);
		break;
	case 2:
		printf("----------영어를 작성하시요----------\n");
		for (i = 0; i < num; i++) {
			printf("%s : ", mean[random[i]]);
			scanf("%s", word_write);
			if (strcmp(word[random[i]], word_write) == 0) {    //맞은개수
				score += 1;
				//printf("score : %d\n", score);
			}
			else {    //틀린개수
				fault += 1;
				//printf("fault : %d\n", fault);
			}
		}
		printf("\n-------------점수-------------------\n");
		printf("score : %d\nfault : %d", score, fault);
		break;
	}
	free(random);    // 동적으로 할당한 메모리 해제
	random = NULL;	//배열 초기화
}
