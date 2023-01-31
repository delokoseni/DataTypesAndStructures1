#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm> 
using namespace std;

void InputArray(double* arr, int size); // функция ввода динамического массива
void OutputArray(double* arr, int size); // функция вывода динамического массива
void SimpleSorting(double* arr, int size); // функция сортировки выбором для динамического массива
void ImprovedSorting(double* arr, int left, int right); // функция сортировки Хоара для динамического массива
int BinarySearch(double* arr, int size, double key); // функция бинарного поиска для динамического массива
void InputVector(vector<double> *myvector); // функция ввода динамического вектора
void OutputVector(vector<double> *myvector); // функция вывода динамического вектора
void VectorSimpleSorting(vector<double> *myvector); // функция сортировки выбором для вектора
void VectorImprovedSorting(vector<double> *myvector, int left, int right); // функция сортировки Хоара для вектора
int VectorBinarySearch(vector<double> *myvector, double key); // функция бинарного поиска для вектора

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    double* arr, search = 1.72896;
    cout << "Введите размер массива: ";
    cin >> n;
    arr = new double[n];
    vector<double> myvector(n);
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
    InputVector(&myvector);
    OutputVector(&myvector);
    VectorSimpleSorting(&myvector);
    cout << "Результат сортировки выбором: ";
    OutputVector(&myvector);
    InputVector(&myvector);
    VectorImprovedSorting(&myvector, 0, n-1);
    cout << "Результат сортировки Хоара: ";
    OutputVector(&myvector);
    cout << "Результат поиска индекса элемента равного " << search << " в векторе: " << VectorBinarySearch(&myvector, search);
    return 0;
}

void SimpleSorting(double* arr, int size)
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
    int i, j;
    double m, buffer;
    i = left;
    j = right;
    m = *(arr + (i + j + 1) / 2); // срединный элемент
    do {
        while (*(arr + i) < m)
            i++;
        while (*(arr + j) > m)
            j--;
        if (i <= j) { //обмен i, j элементов местами
            buffer = *(arr + i);
            *(arr + i) = *(arr + j);
            *(arr + j) = buffer;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        ImprovedSorting(arr, left, j);
    if (i < right)
        ImprovedSorting(arr, i, right);
}

void InputArray(double* arr, int size)
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
    while (left < right) {
        mid = (left + right) / 2;
        if (*(arr + mid) > key)
            right = mid; // проверяем, какую часть нужно отбросить с поиска
        else
            left = mid + 1;
    }
    right--;
    if (*(arr + right) == key)
        return right; // индекс ключа
    else
        return -1; // ключ не найден
}

void InputVector(vector<double> *myvector)
{
    vector<double>::iterator it; // итератор вектора типа double
    for (it = (*myvector).begin(); it < (*myvector).end(); it++) // присвоение итератору значения итератора вектора myvector
    {
        cout << "Введите элемент вектора: ";
        cin >> *it;
    }
}

void OutputVector(vector<double> *myvector)
{
    vector<double>::iterator it; 
    for (it = (*myvector).begin(); it < (*myvector).end(); it++)
    {
        cout << *it << " ";
    }
}

void VectorSimpleSorting(vector<double> *myvector)
{
    vector<double>::iterator it, jt, kt;
    double x;
    for (it = (*myvector).begin(); it < (*myvector).end(); it++) { // i - номер текущего шага
        kt = it;
        x = *it;
        for (jt = it + 1; jt < (*myvector).end(); jt++) // цикл выбора наименьшего элемента
            if (*jt < x) {
                kt = jt;
                x = *jt;
            }
        *kt = *it;
        *it = x; // меняем местами наименьший с *(arr + i)
    }
}

void VectorImprovedSorting(vector<double> *myvector, int left, int right)
{
    int i, j;
    double m, buffer;
    i = left;
    j = right;
    m = myvector->at((i + j + 1) / 2); // срединный элемент
    do {
        while (myvector->at(i) < m)
            i++;
        while (myvector->at(j) > m)
            j--;
        if (i <= j) { //обмен i, j элементов местами
            buffer = myvector->at(i);
            myvector->at(i) = myvector->at(j);
            myvector->at(j) = buffer;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        VectorImprovedSorting(myvector, left, j);
    if (i < right)
        VectorImprovedSorting(myvector, i, right);
}

int VectorBinarySearch(vector<double> *myvector, double key)
{
    int left = 0; // левая граница массива
    int right = myvector->size(); // правая граница массива
    int mid; // срединный индекс отрезка [left, right]
    while (left < right) {
        mid = (left + right) / 2;
        if (myvector->at(mid) > key)
            right = mid; // проверяем, какую часть нужно отбросить с поиска
        else
            left = mid + 1;
    }
    right--;
    if (myvector->at(right) == key)
        return right; // индекс ключа
    else
        return -1; // ключ не найден
}