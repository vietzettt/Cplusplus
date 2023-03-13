#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <cstdio>
using namespace std;

#define N 4 // Номер журнал
#define MAX 20

int choose(string title, int max_choice)
{
    string input;
    int choice;
    do
    {
        cout << title;
        cin >> input;
        try
        {
            choice = stoi(input);
        }
        catch (std::out_of_range &e)
        {
            cerr << "Number is too big!!:)))" << endl;
        }
        catch (std::invalid_argument &e)
        {
            cerr << "Not a number!" << endl;
        }
        if ((choice > max_choice) || (choice == 0))
        {
            cerr << "There is no such option. Again!!!" << endl;
        }
    } while (choice > max_choice);
    return choice;
}

// hàm hiển thị mảng 1 chiều với tiêu đề và kích thước
void show_array(string title_show, int arr[], int n)
{
    cout << title_show << " = {";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << arr[i] << "}" << endl;
        }
        else
        {
            cout << arr[i] << ", ";
        }
    }
}

// hàm hoán đổi giá trị của 2 số
void swap_2num(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// hàm làm bài tập phần 1
void part1()
{
    // 1)	Создайте пустой массив
    int arr[MAX] = {}; // arr rong

    // 2)	Заполните массив числами от одного до N+10
    for (int i = 0; i < N + 10; i++)
    {
        arr[i] = i + 1;
    }
    show_array("New array: arr", arr, N + 10);

    // 3)	Вычислите сумму всех элементов в массиве
    int sum = 0;
    for (int i = 0; i < N + 10; i++)
    {
        sum += arr[i];
    }
    cout << "Sum of elements in array: Sum = " << sum << endl;

    // 4)	Удвоите значение каждого четного элемента массива
    for (int i = 0; i < N + 10; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr[i] = arr[i] * 2;
        }
    }

    // 5)	Для N<10: возведите каждый нечетный элемент массива в степень N
    //      Для N>10: умножьте каждый нечетный элемент массива на 1/N!
    for (int i = 0; i < N + 10; i++)
    {
        if (arr[i] % 2 == 1)
        {
            arr[i] = pow(arr[i], N);
        }
    }

    // 6)	Выведете массив на экран
    show_array("Array: arr", arr, N + 10);

    // 7)	Запишите в тот же массив его значения в обратном порядке
    for (int i = 0; i < int((N + 10) / 2); i++)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[N + 9 - i];
        arr[N + 9 - i] = temp;
    }
    show_array("Array reverse: arr", arr, N + 10);
    // 8)	 Очистите массив (например, заполнив числом N)
    for (int i = 0; i < N + 10; i++)
    {
        arr[i] = 0;
    }
    show_array("Delete Array: arr", arr, N + 10);
    // 9)	Заполните массив псевдослучаными значениями (используйте функцию rand())
    srand(time(NULL)); // random theo seed time thuc te
    for (int i = 0; i < N + 10; i++)
    {
        arr[i] = rand() & 0xff;
    }
    show_array("Array random: arr", arr, N + 10);

    // 10)	Отсортируйте массив любым способом
    int min;
    for (int i = 0; i < N + 10; i++)
    {
        for (int j = i + 1; j < N + 10; j++)
        {
            if (arr[i] > arr[j])
            {
                swap_2num(arr[i], arr[j]);
            }
        }
    }
    show_array("Sort array: arr", arr, N + 10);
    cout << endl;
}

// Освобождаем память (giải phóng bộ nhớ)
void clearMemory(auto **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double take_decimal_number(double num, int n)
{
    int base = 1;
    for (int i = 0; i < n; i++)
    {
        base *= 10;
    }
    double result = round(num * base) / base;
    return result;
}

void matrix_show(auto **matrix, int row, int col)
{
    cout << "MATRIX:" << endl;

    for (int i = 0; i < row; i++)
    {
        cout << "\t ";
        for (int j = 0; j < col; j++)
        {
            cout << setw(8) << right << take_decimal_number(matrix[i][j], 2) << " ";
        }
        cout << endl;
    }
}

// Tạo matrix ngẫu nhiên
void matrix_create(int **matrix, int row, int col)
{
    srand(time(NULL));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

// ma tran khuat hang i cot j
void getMatrixWithoutIJ(int **matrix, int n, int pos_i, int pos_j, int **newMatrix)
{
    int temp1 = 0;
    int temp2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (i == pos_i)
        {
            temp1 = 1;
        }
        temp2 = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (j == pos_j)
            {
                temp2 = 1;
            }
            newMatrix[i][j] = matrix[i + temp1][j + temp2];
        }
    }
}

// 1)	Вычислить определитель матрицы (TÍNH ĐỊNH THỨC MA TRẬN)
long long matrix_det(int **matrix, int n)
{
    long long det = 0;
    int degree = 1; // (-1)^(1+j)
    if (n == 1)
    {
        return matrix[0][0];
    }
    else if (n == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        int **newMatrix = new int *[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            newMatrix[i] = new int[n - 1];
        }

        for (int j = 0; j < n; j++)
        {
            getMatrixWithoutIJ(matrix, n, 0, j, newMatrix);
            det = det + (degree * matrix[0][j] * matrix_det(newMatrix, n - 1));
            degree = -degree;
        }
        clearMemory(newMatrix, n - 1);
    }
    return det;
}

// matrix T
void matrix_T(double **maxtrix, int n, double **new_matirx)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            new_matirx[i][j] = maxtrix[j][i];
        }
    }
}

// 4)	Найти обратную матрицу
void adj_matrix(int **matrix, int n, double **adj_matrix)
{
    double **temp_Matrix = new double *[n];
    for (int i = 0; i < n; i++)
    {
        temp_Matrix[i] = new double[n];
    }
    int degree;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 2 != 0)
            {
                degree = -1;
            }
            else
            {
                degree = 1;
            }
            int **M_Matrix = new int *[n - 1];
            for (int i = 0; i < n - 1; i++)
            {
                M_Matrix[i] = new int[n - 1];
            }
            getMatrixWithoutIJ(matrix, n, i, j, M_Matrix);
            temp_Matrix[i][j] = (degree * matrix_det(M_Matrix, n - 1)) * (1 / (matrix_det(matrix, n) * 1.0));
            clearMemory(M_Matrix, n - 1);
        }
    }
    matrix_T(temp_Matrix, n, adj_matrix);
    clearMemory(temp_Matrix, n);
}

void sub_menu()
{
    cout << "-----------------You want-----------------" << endl;
    cout << "1. Show matrix" << endl;
    cout << "2. Matrix determinant" << endl;
    cout << "3. Inverse matrix (number 4)" << endl;
    cout << "4. Back to menu" << endl;
    cout << "5. Exit" << endl;
    cout << "----------------------------------------" << endl;
}

void part2()
{
    int n;
    do
    {
        n = choose("Enter a matrix n = ", 100);
    } while (n == 0);

    int **matrix = new int *[n]; // Объявляем двумерный динамический массив
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }
    bool done = true;
    matrix_create(matrix, n, n);
    while (done)
    {
        sub_menu();
        int choice = choose("Please choose the request you want (number): ", 5);
        switch (choice)
        {
        case 1:
            system("cls");
            matrix_show(matrix, n, n);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Det Matrix = " << matrix_det(matrix, n) << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            if (matrix_det(matrix, n) == 0)
            {
                cout << "There is no inverse matrix because the determinant is 0!!!" << endl;
            }
            else
            {
                double **new_matrix = new double *[n]; // Объявляем двумерный динамический массив
                for (int i = 0; i < n; i++)
                {
                    new_matrix[i] = new double[n];
                }
                adj_matrix(matrix, n, new_matrix);
                matrix_show(new_matrix, n, n);
                clearMemory(new_matrix, n);
                system("pause");
            }
            break;
        case 4:
            done = false;
            break;
        case 5:
            cout << "Exit!!!";
            exit(0);
        }
    }
    clearMemory(matrix, n);
}

void menu()
{
    cout << "-------------------MENU-----------------" << endl;
    cout << "1. Show result part 1" << endl;
    cout << "2. Matrix calculation" << endl;
    cout << "3. Exit" << endl;
    cout << "----------------------------------------" << endl;
}

int main()
{
    while (true)
    {
        system("cls");
        menu();
        int choice = choose("Please choose the request you want (number): ", 3);
        switch (choice)
        {
        case 1:
            system("cls");
            part1();
            system("pause");
            break;
        case 2:
            system("cls");
            part2();
            break;
        case 3:
            cout << "Exit!!!";
            exit(0);
        }
    }
}
