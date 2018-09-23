#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
void display(T *const A, int Size)
{

	for (int i = 0; i < Size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
//заполнение массива
template <typename T>
void fillArray(T *const A, int Size, int range, int T_MIN)
{
	for (int i = 0; i < Size; i++)
	{
		A[i] = rand() % range + T_MIN;
	}
}

void swap(int *a, int *b)
{
	int *temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int *const a, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
void selectSort(int *const a, int Size)
{
	int min = 0;
	for (int i = 0; i < Size-1; i++)
	{
		min = i;
		for (int j = i + 1; j < Size; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		swap(a[i], a[min]);
	}
}
void insertSort(int *const a, int Size)
{
	int j = 0;
	for (int i = 1; i < Size; i++)
	{
		int temp = a[i];
		j = i;

		while (j > 0 && a[j - 1] >= temp)
		{
			a[j] = a[j - 1];
			--j;
		}
		a[j] = temp;
	}
}

int main()
{
	const int T_MAX = 3000;
	const int T_MIN = 0;
	srand(time(NULL));
	int range = T_MAX - T_MIN + 1;

	const int ROW_SIZE = 10000;
	int a[ROW_SIZE];
	int b[ROW_SIZE];
	int c[ROW_SIZE];

	fillArray(a, ROW_SIZE, range, T_MIN);
	fillArray(b, ROW_SIZE, range, T_MIN);
	fillArray(c, ROW_SIZE, range, T_MIN);

	/*cout << "a array:\n" << endl;
	display(a, ROW_SIZE);
	cout << "b array:" << endl;
	display(b, ROW_SIZE);*/

	cout << "\nSorted by bubbleSort() array:" << endl;
	clock_t runtime = clock();
	bubbleSort(a, ROW_SIZE);
	runtime = clock() - runtime;
	cout << "Runtime of bubbleSort() is: " << runtime << endl;
	//display(a, ROW_SIZE);
	
	
	cout << "\nSorted by selectSort() array:" << endl;
	clock_t runtime2 = clock();
	selectSort(b, ROW_SIZE);
	runtime2 = clock() - runtime2;
	cout << "Runtime of selectSort() is: " << runtime2 << endl;
	//display(b, ROW_SIZE);

	cout << "\nSorted by selectSort() array:" << endl;
	clock_t runtime3 = clock();
	insertSort(c, ROW_SIZE);
	runtime3 = clock() - runtime3;
	cout << "Runtime of insertSort() is: " << runtime3 << endl;
	return 0;
}