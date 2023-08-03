// QuickSort algorithm
// Pick an array item as the pivot : (1) Is in the correct position, so that (2) items to its left are smaller, and (3) items to its right are larger


int partition(int arr[], int low, int high) {
  int pivot = arr[high];

  int count = 0;
}

void quickSort(int arr[], int low, int high) {
  if (low >= high) { return; }
  int pivot = partition(arr, low, high);
  quickSort(arr, low, pivot - 1);
  quickSort(arr, pivot + 1, high);
}

// int[] randomizedQuickSort(int[] arr) {
  
// }

int main() {

}