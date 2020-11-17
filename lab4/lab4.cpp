#include <iostream>

using namespace std;

class Matrix
{
private:
    int m;                                                            // размерность матрицы
    void reduce_matrix(int **elements, int **p, int i, int j, int m); // получение матрицы без строки и столбца
    int count_det(int **elements, int m);                             // вычисление определителя

public:
    int **elements; // элементы матрицы

    void set_matrix(); // задание матрицы
    Matrix();          // конструктор без параметров
    Matrix(int m_);    // конструктор с параметром размерности матрицы
    ~Matrix();         // деструктор

    void print_matrix();               // вывод матрицы
    int determinant();                 // получение определителя
    Matrix operator+(const Matrix &b); // перегруженная функция сложения
    Matrix operator-(const Matrix &b); // перегруженная функция вычитания
    Matrix operator*(const Matrix &b); // перегруженная функция умножения на матрицу
    Matrix operator*(int b);           // перегруженная функция умножения на число
};

void Matrix::set_matrix()
{
    while (m <= 0)
    {
        cout << "Введите размерность матрицы\n";
        cin >> m;
    }
    cout << "Размерность = " << m << endl;
    cout << "Введите элементы матрицы\n";
    elements = new int *[m];
    for (int i = 0; i < m; i++)
    {
        elements[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> elements[i][j];
        }
    }
}

Matrix::Matrix()
{
    m = 1;
    elements = new int *[1];
}

Matrix::Matrix(int m_)
{
    m = m_;
    cout << "Задание матрицы\n";
    set_matrix();
}

Matrix::~Matrix()
{
    cout << "Удаление матрицы\n";
}

void Matrix::print_matrix()
{
    cout << "Вывод матрицы\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << elements[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::reduce_matrix(int **elements, int **p, int i, int j, int m)
{
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < m - 1; ki++)
    {
        if (ki == i)
            di = 1;
        dj = 0;
        for (kj = 0; kj < m - 1; kj++)
        {
            if (kj == j)
                dj = 1;
            p[ki][kj] = elements[ki + di][kj + dj];
        }
    }
}

int Matrix::count_det(int **elements, int m)
{
    int i, j, d, k, n;
    int **p;
    p = new int *[m];
    for (i = 0; i < m; i++)
        p[i] = new int[m];
    j = 0;
    d = 0;
    k = 1;
    n = m - 1;
    if (m == 1)
    {
        d = elements[0][0];
        return (d);
    }
    if (m == 2)
    {
        d = elements[0][0] * elements[1][1] - (elements[1][0] * elements[0][1]);
        return (d);
    }
    if (m > 2)
    {
        for (i = 0; i < m; i++)
        {
            reduce_matrix(elements, p, i, 0, m);
            d = d + k * elements[i][0] * count_det(p, n);
            k = -k;
        }
    }
    return (d);
}

int Matrix::determinant()
{
    return count_det(elements, m);
}

Matrix Matrix::operator+(const Matrix &sec)
{
    Matrix tmp = Matrix();
    tmp.m = m;
    tmp.elements = elements;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp.elements[i][j] += sec.elements[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator-(const Matrix &sec)
{
    Matrix tmp = Matrix();
    tmp.m = m;
    tmp.elements = elements;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp.elements[i][j] -= sec.elements[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator*(const Matrix &sec)
{
    Matrix tmp = Matrix();
    tmp.m = m;
    tmp.elements = elements;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp.elements[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                tmp.elements[i][j] += elements[i][k] * elements[k][j];
            }
        }
    }
    return tmp;
}

Matrix Matrix::operator*(int b)
{
    Matrix tmp = Matrix();
    tmp.m = m;
    tmp.elements = elements;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp.elements[i][j] *= b;
        }
    }
    return tmp;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Matrix a = Matrix(3);
    a.print_matrix();
    cout << a.determinant()<<endl;
    Matrix b = Matrix(3);
    b.print_matrix();
    cout << b.determinant()<<endl;

    Matrix tmp = a + b;
    tmp.print_matrix();
    cout << tmp.determinant()<<endl;

    tmp = a - b;
    tmp.print_matrix();
    cout << tmp.determinant()<<endl;

    tmp = a * b;
    tmp.print_matrix();
    cout << tmp.determinant()<<endl;

    tmp = a * 2;
    tmp.print_matrix();
    cout << tmp.determinant()<<endl;

    return 0;
}