#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
	   int i = low - 1;
	   
        for (int j = low; j < high; ++j){
        	if (arr[j] <= pivot) {
		   swap(arr[++i], arr[j]);
		}	  
	   }
		  
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    
    cout<<"Name : Ayush Chaware\n";
    cout<<"Roll No.  22\n";
    cout<<"Branch : AI\n";
    
     int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int n1 = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n1 - 1);
    
    for (int i = 0; i < n1; ++i) {
    cout << arr[i] << " ";
    }
    return 0;
}
