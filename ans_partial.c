#include <stdio.h>
#include <string.h>

int linear_search(int array[], int size, int number) {
    for(int i = 0; i < size; ++i)
        if (number == array[i]) return 1;
    return 0;
}

int binary_search(int array[], int size, int number) {
    int start = 0, end = size - 1;

    while(start <= end) {
        int mid = (start + end)/2;

        if (array[mid] == number) return 1;
        else if (array[mid] < number) start = mid + 1;
        else end = mid - 1;
    }

    return 0;
}

int binary_search_recursive(int array[], int start, int end, int number) {
    if (start > end) return 0;

    int mid = (start + end)/2;

    if (array[mid] == number) return 1;
    else if (array[mid] < number) return binary_search_recursive(array, mid + 1, end, number);
    else return binary_search_recursive(array, start, mid - 1, number);

    return 0;
}

void selection_sort(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        int min_i = i;

        for (int j = i + 1; j < size; ++j)
            if (array[j] < array[min_i]) min_i = j;

        if (i != min_i) {
            int swap_var = array[min_i];
            array[min_i] = array[i];
            array[i] = swap_var;
        }
    }
}

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int swap_var = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap_var;
            }
        }
    }
}

void merge_sort(int array[], int start, int end) {
    int size = end - start + 1;

    if (size <= 1) {
        return;
    }
    else if (size == 2) {
        if (array[start] > array[end]) {
            int swap_var = array[start];
            array[start] = array[end];
            array[end] = swap_var;
        }

        return;
    }

    int mid = start + size/2;

    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);

    static int sub_array[1000];
    memcpy(sub_array, array + start, (mid - start + 1) * sizeof(int));

    int i, j, k;
    for(i = 0, j = mid + 1, k = start; i <= (mid - start) && j <= end; k++) {
        if (array[j] < sub_array[i]) {
            array[k] = array[j];
            j++;
        }
        else {
            array[k] = sub_array[i];
            i++;
        }
    }

    for(; i <= (mid - start); k++, i++) array[k] = sub_array[i];
}

void quick_sort(int array[], int start, int end) {
    int size = end - start + 1;
    if (size <= 1) {
        return;
    }

    int pivot_index = start;

    int lower_index = pivot_index + 1;
    for (int i = pivot_index + 1; i <= end; ++i) {
        if (array[i] < array[pivot_index]) {
            int swap_var = array[i];
            array[i] = array[lower_index];
            array[lower_index] = swap_var;

            lower_index++;
        }
    }

    int swap_var = array[pivot_index];
    array[pivot_index] = array[lower_index - 1];
    array[lower_index - 1] = swap_var;

    quick_sort(array, start, lower_index - 2);
    quick_sort(array, lower_index, end);
}

void counting_sort(int array[], int size) {
    static unsigned int count[100000];

    for(int i = 0; i < size; ++i) {
        count[array[i]]++;
    }

    for(int i = 0, k = 0; i < 100000; ++i) {
        for(int j = 0; j < count[i]; ++j) {
            array[k++] = i;
        }
    }
}

void print_array(int array[], int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        if (i != 0) printf(", ");
        printf("%d", array[i]);
    }
    printf("]\n");
}

int is_sorted(int array[], int size) {
    for(int i = 1; i < size; ++i) {
        if (array[i - 1] > array[i]) return 0;
    }

    return 1;
}

int main() {
    int array[10000] = {8, 5, 2, 6, 9, 3, 1, 4, 0, 7};
    int size = 10;

    scanf("%d", &size);
    for(int i = 0; i < size; ++i) scanf("%d", &array[i]);

    int number = 0;
    scanf("%d", &number);

    int number2 = 0;
    scanf("%d", &number2);

    if (number2) printf("Should be\n");

    quick_sort(array, 0, size - 1);
    if (binary_search_recursive(array, 0, size - 1, number)) printf("Encontrado\n");
    else printf("Not\n");

    return 0;
}
