#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int linearSearch(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int> &arr, int target, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int choice;
    vector<int> arr;

    do
    {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Input Array" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Merge Sort" << endl;
        cout << "4. Linear Search" << endl;
        cout << "5. Binary Search" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int target;

        switch (choice)
        {
        case 1:
        {
            int n, element;
            cout << "Enter number of elements: ";
            cin >> n;
            arr.clear();
            cout << "Enter elements: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> element;
                arr.push_back(element);
            }
            break;
        }
        case 2:
        {
            if (arr.empty())
            {
                cout << "Array is empty. Please input elements first." << endl;
            }
            else
            {
                selectionSort(arr);
                cout << "Array sorted using Selection Sort: " << endl;
                for (int i = 0; i < arr.size(); i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        }
        case 3:
        {
            if (arr.empty())
            {
                cout << "Array is empty. Please input elements first." << endl;
            }
            else
            {
                mergeSort(arr, 0, arr.size() - 1);
                cout << "Array sorted using Merge Sort: " << endl;
                for (int i = 0; i < arr.size(); i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter element to search: ";
            cin >> target;

            if (arr.empty())
            {
                cout << "Array is empty. Please input elements first." << endl;
            }
            else
            {
                int result = linearSearch(arr, target);
                if (result != -1)
                {
                    cout << "Element found at index: " << result << endl;
                }
                else
                {
                    cout << "Element not found." << endl;
                }
            }
            break;
        }
        case 5:
        {
            cout << "Enter element to search: ";
            cin >> target;

            if (arr.empty())
            {
                cout << "Array is empty. Please input elements first." << endl;
            }
            else
            {
                selectionSort(arr);

                // Print the sorted array
                cout << "Sorted array: ";
                for (int i = 0; i < arr.size(); i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;

                int result = binarySearch(arr, target, 0, arr.size() - 1);
                if (result != -1)
                {
                    cout << "Element found at index: " << result << endl;
                }
                else
                {
                    cout << "Element not found." << endl;
                }
            }
            break;
        }

        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}