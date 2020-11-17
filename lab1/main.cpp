#include <iostream>
#include <random>

using namespace std;

int* realloc_(int* &arr, int &size_of_container) {
    int *extended = new int[size_of_container + 10];
    for (int i = 0; i < size_of_container + 10; i++) {
        extended[i] = 0;
    }
    for (int i = 0; i < size_of_container; i++) {
        extended[i] = arr[i];
    }
    size_of_container += 10;
    return extended;
}

void insert_(int* &arr, int pos, int val, int &size, int &size_of_container) {
    // 'pos' = after which element 'val' will be inserted; [pos + 1] = index of val
    if (size + 1 >= size_of_container)
        arr = realloc_(arr, size_of_container);
    for (int i = size; i > pos + 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos + 1] = val;
    size++;
}

int find_max(int* arr, int size) {
    int max = -100;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

double find_median(int* arr, int size) {
    double median = 0;
    for (int i = 0; i < size; i++) {
        median += arr[i];
    }
    median /= size;
    return median;
}

int main(){

    cout << "Введите размер массива" << endl;

    int size;
    cin >> size;

    int size_of_container = size;
    int *A = new int[size];

    for (int i = 0; i < size; i++) {
        A[i] = rand() % 100 - 50;
    }

    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << find_median(A, size) << endl;

    for (int i = 0; i < size; i++) {
        if (A[i] > 0) {
            insert_(A, i, 0, size, size_of_container);
        }
    }

    //cout << size << " " << size_of_container << endl;
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << find_median(A, size) << endl;
}

