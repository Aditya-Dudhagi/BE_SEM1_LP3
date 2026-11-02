#include <bits/stdc++.h>
using namespace std;

int comparisonDeter = 0, comparisonRand = 0;

int partitionDet(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisonDeter++;

        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortDet(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partitionDet(arr, low, high);
        quickSortDet(arr, low, p - 1);
        quickSortDet(arr, p + 1, high);
    }
}

int partitionRand(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisonRand++;

        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortRand(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partitionRand(arr, low, high);
        quickSortRand(arr, low, p - 1);
        quickSortRand(arr, p + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input!";
        return 0;
    }

    vector<int> arr1(n);

    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    vector<int> arr2 = arr1;

    srand(time(0));

    quickSortDet(arr1, 0, n - 1);
    quickSortRand(arr2, 0, n - 1);

    cout << "\nDeterministic Quick Sort: ";
    for (int x : arr1)
        cout << x << " ";

    cout << "\nDeterministic comparisons: " << comparisonDeter;

    cout << "\n\nRandomized Quick Sort: ";
    for (int x : arr2)
        cout << x << " ";

    cout << "\nRandomized comparisons: " << comparisonRand << endl;

    return 0;
}