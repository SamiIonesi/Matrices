#include <iostream>

using namespace std;

template <class T>
class SymmetricMatrix
{
private:
    T dimension;
    T* arr;

public:
    SymmetricMatrix(T dimension)
    {
        this->dimension = dimension;
        arr = new T[dimension*(dimension + 1) / 2]{0};
    }

    ~SymmetricMatrix()
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
                    cout << arr[i*(i - 1) / 2 +  - 1] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    SymmetricMatrix mySymmetricMatrix(5);

    mySymmetricMatrix.display();

    cout << endl;

    mySymmetricMatrix.set(1, 1, 3);
    mySymmetricMatrix.set(1, 2, 7);
    mySymmetricMatrix.set(1, 3, 4);
    mySymmetricMatrix.set(1, 4, 9);
    mySymmetricMatrix.set(1, 5, 6);
    mySymmetricMatrix.set(2, 2, 3);
    mySymmetricMatrix.set(2, 3, 7);
    mySymmetricMatrix.set(2, 4, 4);
    mySymmetricMatrix.set(2, 5, 9);
    mySymmetricMatrix.set(3, 3, 6);
    mySymmetricMatrix.set(3, 4, 3);
    mySymmetricMatrix.set(3, 5, 7);
    mySymmetricMatrix.set(4, 4, 4);
    mySymmetricMatrix.set(4, 5, 9);
    mySymmetricMatrix.set(5, 5, 6);

    mySymmetricMatrix.display();

    cout << mySymmetricMatrix.get(1, 3);

    return 0;
}