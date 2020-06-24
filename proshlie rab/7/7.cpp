#include <iostream>
#include <clocale>
#include <math.h>
#include <stdlib.h>
#define n 5
using namespace std;

// Функция ручного ввода
void Vruch(int A[n][n]) {
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
} 

//Чтение с файла

void ReadFile(int A[n][n]) {
	FILE* fl;
	fopen_s(&fl, "myFile.txt", "r");
	if (fl)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				fscanf_s(fl, "%d", &A[i][j]);
		fclose(fl);
	}
	else cout << "Ошибка открытия файла. \n";
}

// Функция заполнения одномерного массива Х
void xfactor(int A[n][n], int X[]) {

	int j = 4;

	for (int i = 0; i < 5; i++) {
		if (A[i][i] > A[i][j]) {
			X[i] = 1;
		}
		else {
			X[i] = -1;

		}
	}

}

int yfactor( int A[n][n], int i, int y ) {
	
	if (i == 5) {
		return y;
	}

	if ((A[i][0] % 2) == 0) {}
	else {
		y = y + 1;
	}

	i++;
	return yfactor(A, i, y);
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	int i, y, j, A[n][n], X[n];
	
	
	
	cout << "Ввести элементы массива:\n Вручную(1)\n С файла(2)" << endl;
	int c;
	cin >> c;
	// Выбор действия
	switch (c) {
	case 1: Vruch(A); break;
	
	case 2: ReadFile(A); break;

	default:
		cout << "Такого выбора не было!" << endl; break;
	}
	
	xfactor(A, X);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] <<" ";
		}
		cout << endl;
	}

	cout << endl << "X:";

	for (int i = 0; i < n; i++) {
		cout << X[i]<< " ";
	}
	y = yfactor(A, 0, 0);
	cout << endl << "Количество нечётных чисел в первом столбце Y= " << y << endl;

	FILE* fl;
	fopen_s(&fl, "output.txt", "w");
	if (fl)
	{
		cout << "\n";
		fprintf(fl, "Матрица A(5x5):\n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				fprintf(fl, "%3d", A[i][j]);
			fprintf(fl, "\n");
		}
		fprintf(fl, "Маccив X:\n");
		for (i = 0; i < n; i++)
			fprintf(fl, "%3d", X[i]);
		fprintf(fl, "\n");
		fprintf(fl, "Количество нечётных чисел в первом столбце Y= ");
		fprintf(fl, "%d", y);
		fclose(fl);
	}

	
	return 0;
}