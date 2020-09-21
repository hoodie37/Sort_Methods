#include "pch.h"
#include <iostream>
#include "pch.h"
#include <stdlib.h> 
#include <iostream> 
#include <stdio.h>
#include <conio.h> 
#include <time.h> 
#include <conio.h> 
#include "windows.h"

using namespace std;

void show(int a[], int n, int pos, int elem) {
	Sleep(400);
	system("cls");
	for (int i = 0; i < n; ++i) {
		if (i == pos) {
			printf("%20i\n", elem);
		}
		else {
			printf("%10i\n", a[i]);
		}
	}
}

void show2(int a[], int n, int pos, int elem, int elem2) {
	Sleep(200);
	system("cls");
	for (int i = 0; i < n; ++i) {
		if (i == pos) {
			printf("%20i\n", elem);

		}
		else {
			if (i - 1 == pos) {
				printf("%20i\n", elem2);
			}
			else printf("%10i\n", a[i]);
		}
	}

}

void show3(int a[], int n, int pos, int elem, int elem2) {
	Sleep(300);
	system("cls");
	for (int i = 0; i < n; ++i) {
		if (i == pos) {
			printf("%20i\n", elem);

		}
		else {
			if (i - 1 == pos) {
				printf("%20i\n", elem2);
			}
			else printf("%10i\n", a[i]);
		}
	}

}




int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Выберите метод сортировки:\n 1. Вставками\n 2. Пузырьковая\n 3. Челночная\n");
	int o = 0;
	cin >> o;
	if (o == 1)
	{
		int a[10];
		srand(time(0));
		for (int i = 0; i < 10; i++) {
			a[i] = rand() % 101;
		}
		int n = sizeof(a) / sizeof(int);
		show(a, n, -1, 0);
		for (int i = 1; i < n; ++i) {
			int t = a[i];
			show(a, n, i, t);
			int j = i - 1;
			while ((j >= 0) && (t < a[j])) {
				a[j + 1] = a[j];
				show(a, n, j, t);
				--j;
			}
			a[j + 1] = t;
			show(a, n, -1, 0);
		}
	}
	else if (o == 2)
	{
		int j;
		const int n = 10;
		int a[n];
		srand(time(0));
		for (int i = 0; i < n; ++i) {
			a[i] = rand() % 101;
			//printf("%i", a[i]);
		}
		//show2(a, n, -2, 0, 1);
		for (int i = 1; i < n; ++i) {
			show2(a, n, -2, 0, 1);
			for (int j = 0; j < n - i; j++) {
				show2(a, n, j, a[j], a[j + 1]);
				if (a[j] > a[j + 1]) {
					int t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
					show2(a, n, -2, a[j], t);
				}
				else {
					show2(a, n, -2, a[j], a[j + 1]);
				}
			}
		}
		show2(a, n, -2, 0, 1);
	}
	else {
		int j;
		const int n = 10;
		int a[n];
		srand(time(0));
		for (int i = 0; i < n; ++i) {
			a[i] = rand() % 101;
			//printf("%i", a[i]);
		}
		//show3(a, n, -2, 0, 1);
		for (int i = 1; i < n; ++i) {
			show3(a, n, -2, 0, 1);
			for (int j = 0; j < n - i; j++) {
				show3(a, n, j, a[j], a[j + 1]);
				if (a[j] > a[j + 1]) {
					swap(a[j], a[j + 1]);
					show3(a, n, -2, a[j], a[j + 1]);
				}
				else {
					show3(a, n, -2, a[j], a[j + 1]);
				}
			}
			for (int j = n - i; j > 0; j--) {
				show3(a, n, j, a[j], a[j + 1]);
				if (a[j] < a[j - 1]) {
					swap(a[j], a[j - 1]);
					show3(a, n, -2, a[j], a[j - 1]);
				}
				else {
					show3(a, n, -2, a[j], a[j - 1]);
				}
			}
		}
		show3(a, n, -2, 0, 1);

	}
	system("pause");
	return 0;
}
