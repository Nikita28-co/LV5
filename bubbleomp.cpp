#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

// Sequential Bubble Sort
void sequentialBubbleSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Parallel Bubble Sort (Odd-Even Sort)
void parallelBubbleSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i < n; i++) {

        if(i % 2 == 0) {

            #pragma omp parallel for
            for(int j = 0; j < n - 1; j += 2) {
                if(arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }

        } else {

            #pragma omp parallel for
            for(int j = 1; j < n - 1; j += 2) {
                if(arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

void printArray(vector<int> arr) {
    for(int x : arr){
    	cout << x << " ";
	}
        
    cout << endl;
}

int main() {

    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
//    int n;
//
//    cout<<"Enter number of elements :";
//    cin>>n;
//    vector<int> arr(n);
//    for (int i=0;i<n;i++){
//    	cin>>arr[i];
//    	
//	}

    vector<int> seqArr = arr;
    vector<int> parArr = arr;

    double start, end;

    // Sequential Bubble Sort
    start = omp_get_wtime();
    sequentialBubbleSort(seqArr);
    end = omp_get_wtime();

    cout << "Sequential Bubble Sort: ";
    printArray(seqArr);
    cout << "Time: " << end - start << " seconds\n";

    // Parallel Bubble Sort
    start = omp_get_wtime();
    parallelBubbleSort(parArr);
    end = omp_get_wtime();

    cout << "\nParallel Bubble Sort: ";
    printArray(parArr);
    cout << "Time: " << end - start << " seconds\n";

    return 0;
}
