# Matrices
This repository describes matrix data structures and their different types.

Special matrices are, in fact, square matrices (n × n). 

Special matrices often contain a larger number of zero elements.

## Matrices types

There are differite form of these matrices an they are:

### 1. **Diagonal** Matrix

Definition: All elements except those on the diagonal are equal to 0.

Matrix[i, j] = 0  if(i != j)

Example of a diagonal matrix of dimension 5x5.

*3* 0 0 0 0 <br>
0 *7* 0 0 0 <br>
0 0 *4* 0 0 <br>
0 0 0 *9* 0 <br>
0 0 0 0 *6*

Because of this condition, the diagonal matrix can be represented in programming with the help of a 1D array.

The following class will describe the diagonal matrix and necessary operations performed on it:

```cpp
#include <iostream>

using namespace std;

template <class T>
class Diagonal
{
private:
    T dimension;
    T* arr;

public:
    Diagonal(T dimension)
    {
        this->dimension = dimension;
        arr = new T[dimension]{0};
    }

    ~Diagonal()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if(row == column)
            arr[row - 1] = value;
    }

    T get(int row, int column)
    {
        if(row == column)
            return arr[row - 1];
        else
            return 0;
    }

    void display()
    {
        for(int i = 0; i < dimension; i++)
        {
            for(int j = 0; j < dimension; j++)
            {
                if(i == j)
                    cout << arr[i] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

};

int main()
{

    Diagonal myDiagonal(5);

    myDiagonal.display();

    myDiagonal.set(1, 1, 3);
    myDiagonal.set(2, 2, 7);
    myDiagonal.set(3, 3, 4);
    myDiagonal.set(4, 4, 9);
    myDiagonal.set(5, 5, 6);

    myDiagonal.display();

    return 0;
}
```

### 2. **Lower Triangular** Matrix

Definition: A lower triangular matrix is a square matrix in which the lower triangular part of the matrix is filled with non-zero elements, and the upper triangular part of the matrix is filled with zero elements.

Matrix[i, j] = 0  if(i <= j)

Example of a lower triangular matrix of dimension 5x5.

*3* 0 0 0 0 <br>
*5* *7* 0 0 0 <br>
*2* *3* *4* 0 0 <br>
*8* *2* *6* *9* 0 <br>
*5* *6* *1* *6* *4*

The following class will describe the lower triangular matrix and necessary operations performed on it:

```cpp
template <class T>
class LowerTriangular
{
private:
    T dimension;
    T* arr;

public:
    LowerTriangular(T dimension)
    {
        this->dimension = dimension;
        arr = new T[dimension*(dimension + 1) / 2]{0};
    }

    ~LowerTriangular()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if(row >= column)
        {
            int index = (row * (row - 1) / 2) + (column - 1);
            arr[index] = value;
        }
    }

    T get(int row, int column)
    {
        if(row >= column)
        {
            int index = (row * (row - 1) / 2) + (column - 1);
            return arr[index];
        }
        else
            return 0;
    }

    void display()
    {
        for(int i = 1; i <= dimension; i++)
        {
            for(int j = 1; j <= dimension; j++)
            {
                if(i >= j)
                    cout << arr[i*(i - 1) / 2 + j - 1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
```

### 3. **Upper Triangular** Matrix

Definition: A upper triangular matrix is a square matrix in which the upper triangular part of the matrix is filled with non-zero elements, and the lower triangular part of the matrix is filled with zero elements.

Matrix[i, j] = 0  if(i >= j)

Example of a upper triangular matrix of dimension 5x5.

*5* *6* *1* *6* *4* <br>
0 *8* *2* *6* *9* <br>
0 0 *4* *5* *7* <br> 
0 0 0 *2* *3* <br>
0 0 0 0 *3*

The following class will describe the upper triangular matrix and necessary operations performed on it:

```cpp
#include <iostream>

using namespace std;

template <class T>
class UpperTriangular
{
private:
    T dimension;
    T* arr;

public:
    UpperTriangular(T dimension)
    {
        this->dimension = dimension;
        arr = new T[dimension*(dimension + 1) / 2]{0};
    }

    ~UpperTriangular()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if(row <= column)
        {
            int index = (column * (column - 1) / 2) + (row - 1);
            arr[index] = value;
        }
    }

    T get(int row, int column)
    {
        if(row <= column)
        {
            int index = (column * (column - 1) / 2) + (row - 1);
            return arr[index];
        }
        else
            return 0;
    }

    void display()
    {
        for(int i = 1; i <= dimension; i++)
        {
            for(int j = 1; j <= dimension; j++)
            {
                if(i <= j)
                    cout << arr[j*(j - 1) / 2 + i - 1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
```

### 4. **Symmetric** Matrix

Definition: A symmetric matrix is a sqaure matrix in witch the elements of Matrix[i, j] = elements of Matrix[j, i].

if(Matrix[i, j] = Matrix[j, i])  then is a symmetric matrix

Example of a symmetric matrix of dimension 5x5.

*2* *2* *2* *2* *2* <br>
*2* *3* *3* *3* *3* <br>
*2* *3* *4* *4* *4* <br>
*2* *3* *4* *5* *5* <br>
*2* *3* *4* *5* *6*

The symmetric matrix class is similar to the upper triangular matrix class; the difference lies in the display function:

```cpp
void display()
{
    for(int i = 1; i <= dimension; i++)
    {
        for(int j = 1; j <= dimension; j++)
        {
            if(i <= j)
                cout << arr[j*(j - 1) / 2 + i - 1] << " ";
            else
                cout << arr[i*(i - 1) / 2 + j - 1] << " ";
        }
        cout << endl;
    }
}
```

### 5. **Tridiagonal** Matrix

Definition: The tridiagonal matrix must follow next conditions:

- i - j = 0 
- i - j = 1
- i - j = -1

Matrix[i, j] != 0  if( |i - j| <= 1)  
Matrix[i, j] = 0  if( |i - j| > 1)

Example of a diagonal matrix of dimension 5x5.

*3* *4* 0 0 0 <br>
*2* *7* *3* 0 0 <br>
0 *6* *4* *6* 0 <br>
0 0 *8* *9* *1* <br>
0 0 0 *7* *6* <br>

The following class will describe the tridiagonal matrix and necessary operations performed on it:

```cpp
#include <iostream>

using namespace std;

template <class T>
class TriDiagonalMatrix
{
private:
    T dimension;
    T* arr;

public:
    TriDiagonalMatrix(T dimension)
    {
        this->dimension = dimension;
        arr = new T[3 * dimension - 2]{0};
    }

    ~TriDiagonalMatrix()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if((row - column) == 0)
        {
            int index = row - 1;
            arr[index] = value;
        }
        else if((row - column) == 1)
        {
            int index = dimension + row - 2;
            arr[index] = value;
        }
        else if((row - column) == -1)
        {
            int index = 2 * dimension + row - 2;
            arr[index] = value;
        }
    }

    T get(int row, int column)
    {
        if((row - column) == 0)
        {
            int index = row - 1;
            return arr[index];
        }
        else if((row - column) == 1)
        {
            int index = dimension + row - 2;
            return arr[index];
        }
        else if((row - column) == -1)
        {
            int index = 2 * dimension + row - 2;
            return arr[index];
        }
        else
            return 0;
    }

    void display()
    {
        for(int i = 1; i <= dimension; i++)
        {
            for(int j = 1; j <= dimension; j++)
            {
                if((i - j) == 0)
                {
                    cout << arr[i - 1] << " ";
                }
                else if((i - j) == 1)
                {
                    cout << arr[dimension + i - 2] << " ";
                }
                else if((i - j) == -1)
                {
                    cout << arr[2 * dimension + i - 2] << " ";
                }
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
```

### 6. **Toeplitz** Matrix

Definition: A toeplitz matrix is a square matrix in which all the elements along each diagonal are identical.

Matrix[i, j] = Matrix[i - 1, j - 1]

Example of a toeplitz matrix of dimension 5x5:

*5* *6* *7* *8* *9* <br>
*4* *5* *6* *7* *8* <br>
*3* *4* *5* *6* *7* <br> 
*2* *3* *4* *5* *6* <br>
*1* *3* *3* *4* *5*

The following class will describe the toeplitz matrix and necessary operations performed on it:

```cpp
#include <iostream>

using namespace std;

template <class T>
class TriDiagonalMatrix
{
private:
    T dimension;
    T* arr;

public:
    TriDiagonalMatrix(T dimension)
    {
        this->dimension = dimension;
        arr = new T[2 * dimension - 1]{0};
    }

    ~TriDiagonalMatrix()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if(row <= column)
        {
            int index = column - row;
            arr[index] = value;
        }
        else
        {
            int index = dimension + row - column - 1;
            arr[index] = value;
        }
    }

    T get(int row, int column)
    {
        if(row <= column)
        {
            int index = column - row;
            return arr[index];
        }
        else
        {
            int index = dimension + row - column - 1;
            return arr[index];
        }
    }

    void display()
    {
        for(int i = 1; i <= dimension; i++)
        {
            for(int j = 1; j <= dimension; j++)
            {
                if(i <= j)
                    cout << arr[j - 1] << " ";
                else
                    cout << arr[dimension + i - j - 1] << " ";
            }
            cout << endl;
        }
    }
};
```
