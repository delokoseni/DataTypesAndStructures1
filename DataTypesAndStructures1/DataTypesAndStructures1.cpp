#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm> 
using namespace std;

void SimpleSorting(double* arr, int size);
void ImprovedSorting(double* arr, int left, int right);
void Exchange(double* arr, int i, int j);
void InputArray(double* arr, int size);
void OutputArray(double* arr, int size);
int BinarySearch(double* arr, int size, double key);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    double *arr, search = 1.72896;
    cout << "Введите размер массива: ";
    cin >> n;
    arr = new double[n];
    InputArray(arr, n);
    SimpleSorting(arr, n);
    cout << "Результат сортировки выбором: ";
    OutputArray(arr, n);
    cout << endl;
    InputArray(arr, n);
    ImprovedSorting(arr, 0, n-1);
    cout << "Результат сортировки Хоара: ";
    OutputArray(arr, n);
    cout << endl;
    cout << "Результат поиска индекса элемента равного " << search << " в массиве: " << BinarySearch(arr, n, search);
    return 0;
}

void SimpleSorting(double *arr, int size) 
{
    int i, j, k;
    double x;
    for (i = 0; i < size; i++) { // i - номер текущего шага
        k = i; 
        x = *(arr + i);
        for (j = i + 1; j < size; j++) // цикл выбора наименьшего элемента
            if (*(arr + j) < x) {
                k = j; 
                x = *(arr + j); // k - индекс наименьшего элемента
            }
        *(arr + k) = *(arr + i); 
        *(arr + i) = x; // меняем местами наименьший с *(arr + i)
    }
}

void ImprovedSorting(double* arr, int left, int right)
{
    int i, j, h;
    double m;
    i = left;
    j = right;
    m = *(arr + (i + j + 1) / 2);
    do {
        while (*(arr+i) < m) 
            i++; 
        while (*(arr + j) > m)
            j--; 
        if (i <= j) {
            Exchange(arr, i, j);//обмен i, j элементов местами
            i++; 
            j--;
        }
    } while (i <= j);
    if (left < j)
        ImprovedSorting(arr, left, j);
    if (i < right)
        ImprovedSorting(arr, i, right);
}

void Exchange(double* arr, int i, int j) 
{
    double buffer;
    buffer = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = buffer;
}

void InputArray(double *arr, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        cout << "Введитe " << i + 1 << " элемент массива: ";
        cin >> *(arr + i);
    }
}

void OutputArray(double* arr, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
}

int BinarySearch(double* arr, int size, double key) {
    int left = 0; // левая граница массива
    int right = size; // правая граница массива
    int mid; // срединный индекс отрезка [left, right]
    bool flag = false;
    while ((left <= right) && (flag != true)) {
        mid = (left + right) / 2; 
        if (*(arr +mid) == key) 
            flag = true; 
        if (arr[mid] > key) // проверяем, какую часть нужно отбросить
            right = mid - 1; 
        else 
            left = mid + 1;
    }
    if (flag)
        return mid; // индекс ключа
    else
        return -1; // ключ не найден
}