#include <iostream>
#include <random>
#include <chrono>

/*
Nombre: Randy Alexander Germosén Ureña
ID: 1013-4707
*/


using namespace std;

const int min_number = 1;
const int max_number = 100;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxElement = arr[0];
    for (int num : arr) {
        if (num > maxElement) {
            maxElement = num;
        }
    }

    vector<int> count(maxElement + 1, 0);

    for (int num : arr) {
        ++count[num];
    }

    int index = 0;
    for (int i = 0; i <= maxElement; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            --count[i];
        }
    }
}


void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printDatos(vector<int>& arr) {
    
    cout << "Datos del arreglo" << endl;

    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

}

int main() {
    int n;
    cout << "Ingrese el número de elementos a generar: ";
    cin >> n;

    vector<int> datos;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min_number, n);
    

    //Se genera una cantidad 'n' de números aleatorios

    for (int i = 0; i < n; ++i) {
        datos.push_back(dis(gen));
    }

    printDatos(datos);
    cout << endl << endl;



    /*

    //BubbleSort: Prueba con 'n' números aleatorios.
    cout << "Algoritmo de Ordenamiento Bubblesort" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(datos);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    printDatos(datos);
    cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << endl;

    //QuickSort: Prueba con 'n' números aleatorios.
    cout << "Algoritmo de Ordenamiento Quicksort" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(datos, 0, datos.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    printDatos(datos);
    cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << endl;

    //MergeSort: Prueba con 'n' números aleatorios.
    cout << "Algoritmo de Ordenamiento Mergesort" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(datos, 0, datos.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    printDatos(datos);
    cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << endl;

    //CountingSort: Prueba con 'n' números aleatorios.
    cout << "Algoritmo de Ordenamiento Countingsort" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    countingSort(datos);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    printDatos(datos);
    cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << endl;
    */

    //HeapSort: Prueba con 'n' números aleatorios.
    cout << "Algoritmo de Ordenamiento Heapsort" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(datos);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    printDatos(datos);
    cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << endl;

    return 0;
}