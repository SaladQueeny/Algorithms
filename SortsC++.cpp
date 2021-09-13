
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

void Raspechatka(int strok, int stolb, int** a)
{
	for (int i = 0; i < strok; ++i)
	{
		for (int j = 0; j < stolb; ++j)
			cout << setw(3) << a[i][j];
		cout << endl;

	}
}

//complexity - O(n^2) Сравниваем соседние элементы. Здесь ещё реализован флаг, который выходит из столбца если там уже ничего не переставляется
void bubbleSort(int strok, int stolb, int** array)
{
	for (int j = 0; j < stolb; j++)
	{
		for (int k = 0; k < strok; k++)
		{
			int chik = 0;
			for (int i = 0; i < strok - k - 1; i++)
			{
				if ((array[i][j] > array[i + 1][j]))
				{
					int b = array[i][j];
					array[i][j] = array[i + 1][j];
					array[i + 1][j] = b;


					++chik;
				}

			}
			if (chik == 0) {
				break;
			}
		}
	}
}

//complexity - O(n^2) Мы стоим на конкретном элементе, далее ищем наименьший элемент и меняем местами с конкретным элементом
void SelectionSort(int strok, int stolb, int** array)
{
	int i, ja;
	int count, key;
	for (int j = 0; j < stolb; ++j) {
		for (i = 0; i < strok - 1; i++)
		{
			count = array[i][j]; key = i;
			for (ja = i + 1; ja < strok; ja++) {

				if (array[ja][j] < array[key][j]) {
					key = ja;
				}
			}
			if (key != i)
			{


				array[i][j] = array[key][j];
				array[key][j] = count;

			}

		}
	}
}
//complexity - O(n^2) Берётся элемент и ставится на своё место(следующий элемент больше чем этот для данного случая)
void insert_sort(int strok, int stolb, int** array)
{
	int hold, uf = 0, sh;
	for (int j = 0; j < stolb; j++)
	{
		for (int i = 1; i < strok; i++)
		{
			int temp, item;
			temp = array[i][j];
			item = i - 1;
			while (item >= 0 && array[item][j] > temp)
			{
				array[item + 1][j] = array[item][j];
				array[item][j] = temp;
				item--;
			}

		}
	}
}
//complexity - the worst O(n^2), the best - O(n log2 n). Сначала берем 2 элемента, расстояние между которыми=размер массива/2.
//Если элементы не на своём месте, меняем местами пока не встанет на нужное место(условие правильного сравнения выполнится).
//И так далее, уменьшаем шаг в 2 раза пока не дойдём до 0
void shell_sort(int** array, double strok, double stolb)
{
	int temp, k, j, i;
	for (int h = 0; h < stolb; h++)
	{
		for (k = strok / 2; k > 0; k /= 2)
		{
			for (i = k; i < strok; i++)
			{
				temp = array[i][h];
				for (j = i; j >= k; j -= k)
				{

					if (temp < array[j - k][h])
					{
						array[j][h] = array[j - k][h];

					}
					else
					{
						break;
					}
				}
				array[j][h] = temp;
			}
		}
	}

}
//complexity - the worst O(n^2), the best - O(n log2 n). Алгоритм состоит из трёх шагов:
//Выбрать элемент из массива. Назовём его опорным.
//Разбиение: перераспределение элементов в массиве таким образом, что элементы, меньшие опорного, помещаются перед ним, а большие или равные - после.
//Рекурсивно применить первые два шага к двум подмассивам слева и справа от опорного элемента. Рекурсия не применяется к массиву, в котором только один элемент или отсутствуют элементы.
void QuickSort(int strok, int stolb, int** array, int first, int last, int j) {

	int f = first, l = last;
	int mid, count;
	mid = array[(f + l) / 2][j];
	
	while (f <= l)
	{
		
		while (array[f][j] < mid) {
			if (array[f][j] < mid) {
				do {
					if (array[f][j] < mid) {
						f++;
					}
				} while ( array[f][j] < mid);
			}
		}


		while (array[l][j] > mid) {
			if (array[l][j] > mid) {
				do {
					if (array[l][j] > mid) {
						l--;
					}

				} while (array[l][j] > mid);
			}
		}


		if (f <= l)
		{
			if (f != l) {

				if (array[f][j] > array[l][j]) {
					count = array[f][j];
					array[f][j] = array[l][j];
					array[l][j] = count;

				}
			}
			f++;
			l--;
		}

	}
	if (first < l) QuickSort(strok, stolb, array, first, l, j);
	if (f < last) QuickSort(strok, stolb, array, f, last, j);

}

void obnovlenie(int strok, int stolb, int** array, int** array1) {
	for (int i = 0; i < strok; ++i) {
		for (int j = 0; j < stolb; ++j) {
			array1[i][j] = array[i][j];
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	double strok;
	cout << "Введите кол-во строк:\n";
	while (!(cin >> strok) || (cin.peek() != '\n') || (strok <= 0) || (strok - int(strok) != 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неправильное значение! Введите снова." << endl;
	}
	double stolb;
	cout << "Введите кол-во столбцов:\n";
	while (!(cin >> stolb) || (cin.peek() != '\n') || (stolb <= 0) || (stolb - int(stolb) != 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неправильное значение! Введите снова." << endl;
	}
	cout << endl;
	int** array = new int* [strok];
	for (int i = 0; i < strok; ++i) {
		array[i] = new int[stolb];
	}
	for (int i = 0; i < strok; ++i) {
		for (int j = 0; j < stolb; ++j) {
			array[i][j] = rand() % 100;//i*2;
		}
	}
	cout << "Первоначальная матрица: " << endl;
	Raspechatka(strok, stolb, array);
	cout << "\n";
	int** array1 = new int* [strok];
	for (int i = 0; i < strok; ++i)
		array1[i] = new int[stolb];
	//--------------------------------------------------------------------------------------------------------------------
	obnovlenie(strok, stolb, array, array1);
	bubbleSort(strok, stolb, array1);
	cout << "Матрица, отсортированная с помощью метода пузырька:" << endl;
	cout << endl;
	Raspechatka(strok, stolb, array1);

	//--------------------------------------------------------------------------------------------------------------------
	obnovlenie(strok, stolb, array, array1);
	cout << "Матрица, отсортированная с помощью метода отбора:" << endl;
	cout << endl;
	SelectionSort(strok, stolb, array1);
	Raspechatka(strok, stolb, array1);

	//--------------------------------------------------------------------------------------------------------------------
	obnovlenie(strok, stolb, array, array1);
	cout << "Матрица, отсортированная с помощью метода вставок:" << endl;
	cout << endl;
	insert_sort(strok, stolb, array1);
	Raspechatka(strok, stolb, array1);

	//--------------------------------------------------------------------------------------------------------------------
	obnovlenie(strok, stolb, array, array1);
	cout << "Матрица, отсортированная с помощью метода Шелла:" << endl;
	cout << endl;
	shell_sort(array1, strok, stolb);
	Raspechatka(strok, stolb, array1);

	//--------------------------------------------------------------------------------------------------------------------
	obnovlenie(strok, stolb, array, array1);
	cout << "Матрица, отсортированная с помощью метода быстрой сортировки:" << endl;
	cout << endl;
	int first = 0, last = strok - 1;
	if (strok == 1) {
		cout << ' ' << endl;
	}
	else {
		for (int j = 0; j < stolb; j++) {
			QuickSort(strok, stolb, array1, first, last, j);
		}
	}
	Raspechatka(strok, stolb, array1);


	cout << endl;
	system("pause");
}
