#include <iostream>

using namespace std;

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

int main()
{

    LowerTriangular myLowerTriangular(5);

    myLowerTriangular.display();

    //myLowerTriangular.set(1, 5, 3);
    //myLowerTriangular.set(2, 1, 7);
    myLowerTriangular.set(2, 2, 4);
    myLowerTriangular.set(3, 1, 9);
    myLowerTriangular.set(3, 2, 6);
    myLowerTriangular.set(3, 3, 3);
    myLowerTriangular.set(4, 1, 7);
    myLowerTriangular.set(4, 2, 4);
    myLowerTriangular.set(4, 3, 9);
    myLowerTriangular.set(4, 4, 6);
    myLowerTriangular.set(5, 1, 3);
    myLowerTriangular.set(5, 2, 7);
    myLowerTriangular.set(5, 3, 4);
    myLowerTriangular.set(5, 4, 9);
    myLowerTriangular.set(5, 5, 6);

    myLowerTriangular.display();

    return 0;
}