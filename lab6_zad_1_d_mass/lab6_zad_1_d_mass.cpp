
/* Даны целые положительные числа M, N и набор из N чисел.
 Сформировать матрицу размера M × N, у которой в каждой строке содержатся все
 числа из исходного набора (в том же порядке), кадая следующая строка умножена на d.
  динамический*/
#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int N, M;
    int d;

    cout << "Введите d: ";
    cin >> d;
    cout << "Введите размер матрицы M*N:\n";
    cin >> M;
    if (M <= 0 || M > 10) {
        cerr << "Ошибка: количество должно находиться в диапазоне [1;10]" << endl;
        return 1;
    }

    cin >> N;
    if (N <= 0 || N > 10) {
        cerr << "Ошибка: количество должно находиться в диапазоне [1;10]" << endl;
        return 1;
    }

    int** array;
    array = new int* [M];
    for (size_t i = 0; i < M; i++) {
        // Выделение памяти под строки матрицы
        // последний элемент массива - сумма оценок
        array[i] = new int[N];
    }

    cout << "Введите набор из " << N << " чисел: ";
    for (int i = 0; i < N; i++)
        cin >> array[0][i];
    for (int j = 1; j < M; j++)
        for (int i = 0; i < N; i++)
            array[j][i] = array[j - 1][i]*d;
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
            cout << array[j][i] << " ";
        cout << "\n";


    }
    for (size_t i = 0; i < M; i++) {
        delete[] array[i];
    }
    delete[] array;

}
