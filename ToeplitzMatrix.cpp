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
        if((row <= column) == 0)
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

int main()
{

    TriDiagonalMatrix myTriDiagonalMatrix(5);

    myTriDiagonalMatrix.display();

    cout << endl;

    myTriDiagonalMatrix.set(1, 1, 5);
    myTriDiagonalMatrix.set(2, 2, 5);
    myTriDiagonalMatrix.set(3, 3, 5);
    myTriDiagonalMatrix.set(4, 4, 5);
    myTriDiagonalMatrix.set(5, 5, 5);
    myTriDiagonalMatrix.set(2, 2, 3);
    myTriDiagonalMatrix.set(2, 3, 7);
    myTriDiagonalMatrix.set(2, 4, 4);
    myTriDiagonalMatrix.set(2, 5, 9);
    myTriDiagonalMatrix.set(3, 3, 6);
    myTriDiagonalMatrix.set(3, 4, 3);
    myTriDiagonalMatrix.set(3, 5, 7);
    myTriDiagonalMatrix.set(4, 4, 4);
    myTriDiagonalMatrix.set(4, 5, 9);
    myTriDiagonalMatrix.set(5, 5, 6);
    myTriDiagonalMatrix.set(2, 1, 4);
    myTriDiagonalMatrix.set(3, 2, 9);
    myTriDiagonalMatrix.set(4, 3, 6);

    myTriDiagonalMatrix.display();

    cout << myTriDiagonalMatrix.get(1, 3);

    return 0;
}