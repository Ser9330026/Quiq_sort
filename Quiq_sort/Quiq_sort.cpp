#include <iostream>

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right]; // Выбор опорного элемента (последний элемент)
        int i = left - 1;

        // Разбиение массива
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                i++;
                // Обмен элементов
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Размещаем опорный элемент на правильном месте
        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;

        int pi = i + 1; // Индекс опорного элемента

        // Рекурсивные вызовы
        quickSort(arr, left, pi - 1); // Сортировка левой части
        quickSort(arr, pi + 1, right); // Сортировка правой части
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}