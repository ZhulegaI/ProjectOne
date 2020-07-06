#include <iostream>
#include <locale.h>
#include <stdio.h>
# define N 5

using namespace std;

// Вариант с считыванием из файла
void sfile(int mas[][N]) {
	FILE* f;
	fopen_s(&f, "1.txt", "r");

	if (f) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fscanf_s(f, "%d", &mas[i][j]);
			}
		}
		fclose(f);
	}

}





void vruch(int mas[][N]) {

	cout << "Введите эл. матрицы A(5 x 5):" << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "A[" << i << "][" << j << "]:\t";
			cin >> mas[i][j];
		}
	}

}

int *vvod_X(int mas[][N], int X[N],void (*pfunc) (int masp[][N])) {

	pfunc(mas);

	int b=0, m=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (mas[i][j] < mas[i][j + 1]) b++; // по возростанию
			else if (mas[i][j] > mas[i][j + 1]) m++; //по убыванию
		}
	}
	if ((m == 20) or (b == 20))
		for (int i = 0; i < N; i++) X[i] = 1;
	else for (int i = 0; i < N; i++) X[i] = -1;
	
	return X;
}


void out(int X[], int mas[][N]) {

	int i, j, max = -100000, min = 1000000 ;


	cout << "Массив A(5 x 5): " << endl;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "Массив X[5]:" << endl;

	for (i = 0; i < N; i++) cout << X[i] << "\t";

	for (i = 0; i < N; i++) {
		if (mas[i][i] < min) min = mas[i][i];
		else if (mas[i][i] > max) max = mas[i][i];
	}

	cout << endl;

	cout << endl << "Y являющийся средним арифм. главной диагонали равен: " << (max + min) / 2 << endl;

}


void main() {
	setlocale(LC_CTYPE, "rus");

	int c;

	int mas[N][N];
	int X[N];

	void (*PointX)(int mas[][N]);
	cout << "Вы хотите ввести матрицу в ручную (1-да\\другая цифра - нет)" << endl;

	cin >> c;

	switch(c) {
	case 1: PointX = &vruch; break;

	default: PointX = &sfile;
	}


	out(vvod_X(mas, X, PointX), mas);


}

