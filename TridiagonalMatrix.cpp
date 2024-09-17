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

int main()
{

    TriDiagonalMatrix myTriDiagonalMatrix(5);

    myTriDiagonalMatrix.display();

    cout << endl;

    myTriDiagonalMatrix.set(1, 1, 3);
    myTriDiagonalMatrix.set(1, 2, 7);
    myTriDiagonalMatrix.set(1, 3, 4);
    myTriDiagonalMatrix.set(1, 4, 9);
    myTriDiagonalMatrix.set(1, 5, 6);
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