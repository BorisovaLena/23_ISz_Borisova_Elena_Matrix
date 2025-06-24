#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix
{
private:
	int rows, cols; //���������� ����� � ��������
	vector<vector<int>> data; //��������� ������ � ������� �������

public:
	Matrix() : rows(0), cols(0) {}
	Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, vector<int>(cols, 0)) {} //�������� �������, ����������� ������

    int getRows() const //��������� ���������� �����
    {
        return rows;
    }

    int getCols() const //��������� ���������� ��������
    {
        return cols;
    }

    friend istream& operator>>(istream& is, Matrix& matrix);
    friend ostream& operator<<(ostream& os, const Matrix& matrix);

    //�������� ������
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

    //��������� ������
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

    //��������� ������
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

//���� �������
istream& operator>>(istream& is, Matrix& matrix)
{
    cout << "������� ���������� �����: ";
    is >> matrix.rows;
    cout << "������� ���������� ��������: ";
    is >> matrix.cols;

    matrix.data.resize(matrix.rows); //��������� ������� �������
    for (int i = 0; i < matrix.rows; i++)
    {
        matrix.data[i].resize(matrix.cols); //��������� ������� i-�� ������
        for (int j = 0; j < matrix.cols; j++)
        {
            cout << "������� [" << i + 1 << "][" << j + 1 << "]: ";
            is >> matrix.data[i][j];
        }
    }
    return is;
}

//����� �������
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
    cin >> matrix1;  //���� �������
    cout << matrix1; //����� �������

    Matrix matrix2;
    cin >> matrix2;  //���� �������
    cout << matrix2; //����� �������

    if (matrix1.getCols() == matrix2.getCols() && matrix1.getRows() == matrix2.getRows()) //���������� ����������� ���� ������
    {
        //��������
        Matrix matrixSum = matrix1 + matrix2;
        cout << "������� �����: \n";
        cout << matrixSum; //����� �������

        //cout << "������� ����� � �������������: \n";
        //matrix1 += matrix2;
        //cout << matrix1; //����� �������

        //���������
        Matrix matrixDif = matrix1 - matrix2;
        cout << "������� ��������: \n";
        cout << matrixDif; //����� �������

        //cout << "������� �������� � �������������: \n";
        //matrix1 -= matrix2;
        //cout << matrix1; //����� �������
    }
    else
    {
        cout << "��� �������� � ��������� ������� ������ ���� ����������� �������!\n";
    }

    if (matrix1.getCols() == matrix2.getRows()) //���������� �������� 1-�� ������� ����� ���������� ����� 2-�� �������
    {
        Matrix matrixMul = matrix1 * matrix2;
        cout << "������� ���������: \n";
        cout << matrixMul; //����� �������

        cout << "������� ��������� � �������������: \n";
        matrix1 *= matrix2;
        cout << matrix1; //����� �������
    }
    else
    {
        cout << "��� ��������� ���������� �������� 1-�� ������� ������ ���� ����� ���������� ����� 2-�� �������!\n";
    }

	return 0;
}