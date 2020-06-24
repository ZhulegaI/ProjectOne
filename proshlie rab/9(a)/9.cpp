
#include <iostream>
#include <stdio.h>
#include <clocale>

using namespace std;



void main()
{

    setlocale(LC_CTYPE, "rus");
    unsigned int n, i,  m, u, j, min=0, max=0;
    int k, el;
    cout << "Введите для (A[n][n]) n:,\n";
    cin >> n;

    int** mas = new int* [n];// Создал указатель на указатели

   

    for (i = 0; i < n; i++) {
        mas[i] = new int[n];
    }
    //////////////////////////////////////////////////////////////////////

    cout << "Введите элементы массива:,\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> mas[i][j];
        }
    }// заполнение двумерного массива

    system("cls");

    k = 0;
    u = 0;
    m = 100;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mas[j][i] >= 0) k++;
        }

        if ((k > u) && (k > 0)) {
            u = k;
            max = i;
        }

        if (k < m && (k > 0)) {
            m = k;
            min = i;
        }

        k = 0;
    } // Поиск минимума и максимума

    cout << endl << "Массив до изменения:\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << mas[i][j] << "\t";
        }

        cout << endl;
    }

    for (i = 0; i < n; i++) {
        el = mas[i][max];
        mas[i][max] = mas[i][min];
        mas[i][min] = el;
    }

    cout << endl << "Массив после изменения:\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << mas[i][j] << "\t";
        }

        cout << endl;
    }

    ///////////////////////////////////////////////////////////////////////
    for (i = 0; i < n; i++) {
        delete[] mas[i];
    }// Удалил одномерные массивы

    delete []mas;// Удалил динамический массив
}

