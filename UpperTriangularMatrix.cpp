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

int main()
{

    UpperTriangular myUpperTriangular(5);

    myUpperTriangular.display();

    cout << endl;

    myUpperTriangular.set(1, 1, 3);
    myUpperTriangular.set(1, 2, 7);
    myUpperTriangular.set(1, 3, 4);
    myUpperTriangular.set(1, 4, 9);
    myUpperTriangular.set(1, 5, 6);
    myUpperTriangular.set(2, 2, 3);
    myUpperTriangular.set(2, 3, 7);
    myUpperTriangular.set(2, 4, 4);
    myUpperTriangular.set(2, 5, 9);
    myUpperTriangular.set(3, 3, 6);
    myUpperTriangular.set(3, 4, 3);
    myUpperTriangular.set(3, 5, 7);
    myUpperTriangular.set(4, 4, 4);
    myUpperTriangular.set(4, 5, 9);
    myUpperTriangular.set(5, 5, 6);

    myUpperTriangular.display();

    cout << myUpperTriangular.get(1, 3);

    return 0;
}