#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix
{
private:
	int rows, cols; //Количество строк и столбцов
	vector<vector<int>> data; //Двумерный вектор с данными матрицы

public:
	Matrix() : rows(0), cols(0) {}
	Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, vector<int>(cols, 0)) {} //Создание матрицы, заполненной нулями

    int getRows() const //Получение количества строк
    {
        return rows;
    }

    int getCols() const //Получение количества столбцов
    {
        return cols;
    }

    friend istream& operator>>(istream& is, Matrix& matrix);
    friend ostream& operator<<(ostream& os, const Matrix& matrix);

    //Сложение матриц
    Matrix operator+(const Matrix& matr) const
    {
        Matrix matrResult(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrResult.data[i][j] = data[i][j] + matr.data[i][j];
            }
        }
        return matrResult;
    }

    Matrix& operator+=(const Matrix& matr)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] += matr.data[i][j];
            }
        }
        return *this;  
    }

    //Вычитание матриц
    Matrix operator-(const Matrix& matr) const
    {
        Matrix matrResult(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrResult.data[i][j] = data[i][j] - matr.data[i][j];
            }
        }
        return matrResult;
    }

    Matrix& operator-=(const Matrix& matr)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] -= matr.data[i][j];
            }
        }
        return *this;
    }

    //Умножение матриц
    Matrix operator*(const Matrix& matr) const
    {
        Matrix matrResult(rows, matr.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < matr.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    matrResult.data[i][j] += data[i][k] * matr.data[k][j];
                }
            }
        }
        return matrResult;
    }

    Matrix& operator*=(const Matrix& matr)
    {
        *this = *this * matr;
        return *this;
    }   
};

//Ввод матрицы
istream& operator>>(istream& is, Matrix& matrix)
{
    cout << "Введите количество строк: ";
    is >> matrix.rows;
    cout << "Введите количество столбцов: ";
    is >> matrix.cols;

    matrix.data.resize(matrix.rows); //Изменение размера матрицы
    for (int i = 0; i < matrix.rows; i++)
    {
        matrix.data[i].resize(matrix.cols); //Изменение размера i-ой строки
        for (int j = 0; j < matrix.cols; j++)
        {
            cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            is >> matrix.data[i][j];
        }
    }
    return is;
}

//Вывод матрицы
ostream& operator<<(ostream& os, const Matrix& matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            os << setw(4) << matrix.data[i][j];
        }
        os << '\n';
    }
    return os;
}

int main()
{
	system("chcp 1251>null");

    Matrix matrix1;
    cin >> matrix1;  //Ввод матрицы
    cout << matrix1; //Вывод матрицы

    Matrix matrix2;
    cin >> matrix2;  //Ввод матрицы
    cout << matrix2; //Вывод матрицы

    if (matrix1.getCols() == matrix2.getCols() && matrix1.getRows() == matrix2.getRows()) //Одинаковая размерность двух матриц
    {
        //Сложение
        Matrix matrixSum = matrix1 + matrix2;
        cout << "Матрица суммы: \n";
        cout << matrixSum; //Вывод матрицы

        //cout << "Матрица суммы с присваиванием: \n";
        //matrix1 += matrix2;
        //cout << matrix1; //Вывод матрицы

        //Вычитание
        Matrix matrixDif = matrix1 - matrix2;
        cout << "Матрица разности: \n";
        cout << matrixDif; //Вывод матрицы

        //cout << "Матрица разности с присваиванием: \n";
        //matrix1 -= matrix2;
        //cout << matrix1; //Вывод матрицы
    }
    else
    {
        cout << "Для сложения и вычитания матрицы должны быть одинакового размера!\n";
    }

    if (matrix1.getCols() == matrix2.getRows()) //Количество стоблцов 1-ой матрицы равно количеству строк 2-ой матрицы
    {
        Matrix matrixMul = matrix1 * matrix2;
        cout << "Матрица умножения: \n";
        cout << matrixMul; //Вывод матрицы

        cout << "Матрица умножения с присваиванием: \n";
        matrix1 *= matrix2;
        cout << matrix1; //Вывод матрицы
    }
    else
    {
        cout << "Для умножения количество стоблцов 1-ой матрицы должно быть равно количеству строк 2-ой матрицы!\n";
    }

	return 0;
}