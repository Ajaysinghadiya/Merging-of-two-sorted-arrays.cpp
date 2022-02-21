#include <iostream>
using namespace std;

class ArraysOperations//Declaring the class for the array operations
{
public:
    int *array1, *array2, *final_array;//Declaring the three arrays

    void merging_of_arrays(int size1, int size2);//Declaring the member function

    void display(int size_of_final_array);
};

void ArraysOperations::merging_of_arrays(int size1, int size2)//Merging of the two sorted arratys
{
    int i = 0, j = 0, k = 0;//Initializing all three variables with the initial indices of the three arrays
    while (i < size1 && j < size2)//The loop will run untill the indices of the arrays
    {
        if (array1[i] < array2[j])//Checking whether the element is smaller or not
        {
            final_array[k] = array1[i];//And then coping the values
            k++, i++;
        }
        else
        {
            final_array[k] = array2[j];
            k++, j++;
        }
    }
    for (; i < size1; i++)//Remaining elements will be copied from these loops
    {
        final_array[k] = array1[i];
        k++;
    }
    for (; j < size2; j++)
    {
        final_array[k] = array2[j];
        k++;
    }
}

void ArraysOperations::display(int size_of_final_array)//Defining the display function
{
    for (int i = 0; i < size_of_final_array; i++)
    {
        cout << final_array[i] << " ";
    }
    cout << endl;
}

int main()
{
    ArraysOperations ao;
    int size_of_array1, size_of_array2;
    cout << "Enter the size of array 1 :" << endl;
    cin >> size_of_array1;

    ao.array1 = new int[size_of_array1];//creating the space for the array in the heap memory

    cout << "Enter the size of array 2 :" << endl;
    cin >> size_of_array2;

    ao.array2 = new int[size_of_array2];//creating the space for the array in the heap memory

    cout << "Enter the elements of array 1 :" << endl;
    for (int i = 0; i < size_of_array1; i++)
        cin >> ao.array1[i];

    cout << "Enter the elements of array 2 :" << endl;

    for (int j = 0; j < size_of_array2; j++)
        cin >> ao.array2[j];

    ao.final_array = new int[size_of_array1 + size_of_array2];//creating the space for the array in the heap memory

    ao.merging_of_arrays(size_of_array1, size_of_array2);

    cout << "Your array after merging the both arrays :" << endl;

    ao.display(size_of_array1 + size_of_array2);

    return 0;
}
