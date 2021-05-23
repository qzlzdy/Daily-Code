//============================================================================
// Name        : HDOJ_1097.cpp
// Author      : Qzlzdy
// Version     : C++
// Description : A hard puzzle
//============================================================================
#include <iostream>
#include <vector>
using namespace std;
class Matrix
{
public:
    Matrix(int size);
    int size();
    Matrix operator*(Matrix &matrix);
    vector<int> &operator[](int n);
    friend istream &operator>>(istream &in,Matrix &matrix);
    friend ostream &operator<<(ostream &out,Matrix &matrix);
private:
    int _size;
    vector<vector<int> > _matrix;
};
Matrix::Matrix(int size) : _matrix(size,vector<int>(size))
{
    _size = size;
}
int Matrix::size()
{
    return _size;
}
Matrix Matrix::operator *(Matrix &matrix)
{
    Matrix res(_size);
    for(int i = 0;i < _size; i++)
        for(int j = 0; j < _size; j++)
            for(int k = 0; k < _size; k++)
                res[i][j] = (res[i][j] + _matrix[i][k] * matrix[k][j]) % 9973;
    return res;
}
vector<int> &Matrix::operator [](int n)
{
    return _matrix[n];
}
istream &operator>>(istream &in,Matrix &matrix)
{
    for(auto &row : matrix._matrix)
        for(auto &it : row)
            in>>it;
    return in;
}
ostream &operator<<(ostream &out,Matrix &matrix)
{
    for(auto &row : matrix._matrix)
    {
        for(auto &it : row)
            out<<it<<" ";
        out<<endl;
    }
    return out;
}
int Tr(Matrix &matrix)
{
    int sum = 0;
    for(int i = 0; i < matrix.size(); i++)
        sum = (sum + matrix[i][i]) % 9973;
    return sum;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        Matrix matrix(n),res(n);
        for(int i = 0; i < n; i++)
            res[i][i] = 1;
        cin>>matrix;
        int p = 1;
        while(p != 0)
        {
            if(p & k)
                res = res * matrix;
            matrix = matrix * matrix;
            p <<= 1;
        }
        cout<<Tr(res)<<endl;
    }
}