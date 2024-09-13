#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int mas[] = { -41, 2, 32, 4, 5 };
	int min = mas[0], max = mas[0];
	for (int i = 0; i < sizeof(mas) / sizeof(int); ++i) {
		max = max > mas[i] ? max : mas[i];
		min = min > mas[i] ? mas[i] : min;
	}
	printf("Разница между максимальным и минимальным элементами массива: %d", max - min);
}