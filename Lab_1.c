#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

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
	printf("Разница между максимальным (%d) и минимальным (%d) элементами массива: %d", max, min, max - min);
	return 0;
}