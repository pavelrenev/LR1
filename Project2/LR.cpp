#include <iostream>
#include <vector>
using namespace std;


template <class T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


template <typename T>
void swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}



template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


template <typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}



template <class T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printArray(const vector<T>& arr) {
    for (const T& val : arr)
        cout << val << " ";
    cout << endl;
    cout << endl;
}

int main() {
    int intArr1[] = { 122, 23, 43, 45, 12, 76, 1, 8, 2, 5 };
    int intSize = sizeof(intArr1) / sizeof(intArr1[0]);

    cout << "Original array: ";
    printArray(intArr1, intSize);

    bubbleSort(intArr1, intSize);

    cout << "Sorted array by bubbleSort: ";
    printArray(intArr1, intSize);

    
    int intArr2[] = { 122, 23, 43, 45, 12, 76, 1, 8, 2, 5 };

    quickSort(intArr2, 0, intSize - 1);

    cout << "Sorted array by quickSort: ";
    printArray(intArr2, intSize);


    vector <int> intArr3 = { 122, 23, 43, 45, 12, 76, 1, 8, 2, 5 };

    mergeSort(intArr3, 0, intSize - 1);

    cout << "Sorted array by mergeSort: ";
    printArray(intArr3);

    double doubleArr1[] = { 122.12, 23.3, 43.0, 45.3, 12.3, 76.1, 1.0, 8.2, 2.8, 5.9 };
    int doubleSize = sizeof(doubleArr1) / sizeof(doubleArr1[0]);
    
    cout << "Original array: ";
    printArray(doubleArr1, doubleSize);

    bubbleSort(doubleArr1, doubleSize);

    cout << "Sorted array by bubbleSort: ";
    printArray(doubleArr1, doubleSize);

    double doubleArr2[] = { 122.12, 23.3, 43.0, 45.3, 12.3, 76.1, 1.0, 8.2, 2.8, 5.9 };
    quickSort(doubleArr2, 0, intSize - 1);

    cout << "Sorted array by quickSort: ";
    printArray(doubleArr2, intSize);

    vector <double> doubleArr3 = { 122.12, 23.3, 43.0, 45.3, 12.3, 76.1, 1.0, 8.2, 2.8, 5.9 };

    mergeSort(doubleArr3, 0, doubleSize - 1);

    cout << "Sorted array by mergeSort: ";
    printArray(doubleArr3);

    return 0;
}