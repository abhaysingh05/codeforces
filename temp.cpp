#include <stdio.h>

void separate(int arr[], int l, int r);
void merge(int arr[], int l, int r, int mid);
int main() {
    int arr[] = {100, 2, 5, 99, 10, 45, 32, 65, 51};
    int n = sizeof(arr) / sizeof(int);
    separate(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // sorted array print
    }

    return 0;
}
//     0  1 2 3  4   5  6  7 8
//    100 2 5 99 10 45 32 65 51
//            /    \
//    100 2 5 99   10 45 32 65 51 - 2 5 10 32 45 51 65 99 100
//        / \      
//   100 2   5 99 - 2 5 99 100
//    / \      
//  100  2 - 2 100

void separate(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        separate(arr, l, mid);// 0
        separate(arr, mid + 1, r);
        merge(arr, l, r, mid);
    }
}
void merge(int arr[], int l, int r, int mid) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2) {
        arr[k] = b[j];
        k++;
        j++;
    }
}