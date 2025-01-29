//Given a sorted array of integers, find if there exists a pair of elements whose sum is equal to a given number target
#include <stdio.h>

int findPairWithSum(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            return 1;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return 0;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (findPairWithSum(arr, n, target)) {
        printf("Pair found!\n");
    } else {
        printf("Pair not found.\n");
    }

    return 0;
}
