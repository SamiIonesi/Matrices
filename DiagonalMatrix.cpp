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