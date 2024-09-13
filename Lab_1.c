#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#define N 4
#define M 5

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n;
	printf("Введите размер массива: ");
	scanf("%d", &n);
	int* mas = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		mas[i] = rand() % 200 - 100;
		printf("%d ", mas[i]);
	}
	printf("\n");
	int min = mas[0], max = mas[0];
	for (int i = 0; i < n; ++i) {
		max = max > mas[i] ? max : mas[i];
		min = min > mas[i] ? mas[i] : min;
	}
	printf("Разница между максимальным (%d) и минимальным (%d) элементами массива: %d\n\n", max, min, max - min);

	int** mas2 = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; ++i) {
		mas2[i] = (int*)malloc(sizeof(int) * M);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			mas2[i][j] = rand() % 200 - 100;
			printf("%4d ", mas2[i][j]);
		}
		printf("\n");
	}

	printf("Суммы значений в каждой строке:\n");
	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = 0; j < M; ++j) {
			sum += mas2[i][j];
		}
		printf("Строка %d: %d\n", i + 1, sum);
	}

	printf("Суммы значений в каждом столбце:\n");
	for (int j = 0; j < M; ++j) {
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += mas2[i][j];
		}
		printf("Столбец %d: %d\n", j + 1, sum);
	}
	free(mas2);

	for (int i = 0; i < N; ++i) {
		free(mas2[i]);
	}
	return 0;
}
