
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Utility function to print array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// 1. Selection Sort
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// 2. Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// 3. Insertion Sort
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while(j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// 4. Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 5. Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for(int j = low; j < high; j++)
        if(arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 6. Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for(int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 7. Counting Sort
void countingSort(int arr[], int n) {
    int max = *max_element(arr, arr+n);
    vector<int> count(max+1, 0), output(n);
    for(int i = 0; i < n; i++) count[arr[i]]++;
    for(int i = 1; i <= max; i++) count[i] += count[i-1];
    for(int i = n-1; i >= 0; i--) output[--count[arr[i]]] = arr[i];
    for(int i = 0; i < n; i++) arr[i] = output[i];
}

// 8. Radix Sort
int getMax(int arr[], int n) {
    return *max_element(arr, arr+n);
}

void countSortRadix(int arr[], int n, int exp) {
    int output[n], count[10] = {0};
    for(int i = 0; i < n; i++) count[(arr[i]/exp)%10]++;
    for(int i = 1; i < 10; i++) count[i] += count[i-1];
    for(int i = n-1; i >= 0; i--)
        output[--count[(arr[i]/exp)%10]] = arr[i];
    for(int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for(int exp = 1; m/exp > 0; exp *= 10)
        countSortRadix(arr, n, exp);
}

// 9. Using STL sort (IntroSort)
void stlSort(int arr[], int n) {
    sort(arr, arr + n);
}

// Main program
int main() {
    int arr[] = {5, 1, 4, 2, 8, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    // Uncomment desired sort
    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    // mergeSort(arr, 0, n-1);
    // quickSort(arr, 0, n-1);
    // heapSort(arr, n);
    // countingSort(arr, n);
    // radixSort(arr, n);
    stlSort(arr, n); // C++ STL sort (IntroSort)

    cout << "Sorted Array: ";
    printArray(arr, n);
    return 0;
}
