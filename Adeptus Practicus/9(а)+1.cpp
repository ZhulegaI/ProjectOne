#include <iostream>
#include <stdio.h>
#include <clocale>

using namespace std;

void polozhit(const int n, int* mas[]) {
	
	int t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mas[i][j] > 0) t++;
		}
	}

	if (t == 0) cout << "Нет положительных эл." << endl;
}

void p1(int k, const int n, int m[], int* mas[]) {
	int l, t = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (m[i] != (-1)) {
			k++;
			
			t = 0;
			if (k > 1) {
				if (c == 0) {
					cout << "Меняем столбец " << (i + 1) << " обнуляя" << endl;
					c++;
				}
				for (int j = 0; j < n; j++) {
					mas[j][i] = 0;
				}
			}
		}//Обнуление повторяющихся (см. на условие варианта)
		c = 0;
	}
}

void kol_vo(int &i, const int n,  int m[], int* mas[]) {
	int  l = n - 1, kol = 0;
	
	for (int j = 0; j < n; j++) {
		while ((l >= 0) && (j!=l)) {
			if (mas[j][i] == mas[l][i]) {
				m[i] = i;//запомнил столбец с повт. эл.
				
				kol++;
			}
			l--;
		}
	}
		cout << "Одинаковое кол-во эл. в столбце " << (i + 1) << " равняется: " << kol << endl;
		kol = 0;
}

void raz(const int n, int* mas[]) {
	int l, u;
	int* m = new int[n];

	
	for (int i = 0; i < n; i++) {

		polozhit(n, mas);
		m[i] = -1;
		int c = 0;

		kol_vo(i, n, m, mas);

		for (int j = n - 1; j >= 0; j--) {
			l = j - 1;
			while (l >= 0) {
				
				if (mas[j][i] < mas[l][i]) {
					if (c == 0) {
						cout << "Меняем столбец " << (i+1) << " по возростанию" << endl;
						c++;
					}
					u = mas[j][i];
					mas[j][i] = mas[l][i];
					mas[l][i] = u;
				}
				l--;
			}
			
			
		}
		
	 c = 0;
	}// Расспределение по возростанию эл. и запоминание столбцов с повт.

	p1(0, n, m, mas);

	delete[]m;

}

void p2(const int n, int* mas[]) {

	cout << "После выполнения:" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << "\t";
		}

		cout << endl;
	}//Вывод массива
}

void main() {

	setlocale(LC_CTYPE, "rus");
	cout << "Введите кол-во элементов n для A(n x n): " << endl;

	int n, i, j, err = 0;

	cin >> n;
	int** mas = new int* [n];

	for (i = 0; i < n; i++) {
		mas[i] = new int[n];
	}
	//////////////////////////////////////////////////////////////////////

	cout << "Введите элементы не равные 0:,\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> mas[i][j];
			if (mas[i][j] == 0)  break;
		}
		if (mas[i][j] == 0) {
			cout << "Ошибка, найден элемент не удовлетворяющий условию!" << endl;
			err = 1;
			break; }
	}// заполнение двумерного массива

	


	if (err != 1) {

		raz(n, mas);

		p2(n, mas);

	}
	


	///////////////////////////////////////////////////////////////////////
	for (i = 0; i < n; i++) {
		delete[] mas[i];
	}// Удалил одномерные массивы

	delete[]mas;// Удалил динамический массив

}
