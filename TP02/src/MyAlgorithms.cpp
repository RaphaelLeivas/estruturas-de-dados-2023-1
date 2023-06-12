#include "../include/MyAlgorithms.hpp"

MyAlgorithms::MyAlgorithms() = default;
MyAlgorithms::~MyAlgorithms() = default;

// estavel
// pior caso: vetor entrada decrescente. é O(n^2)
// ele é simples, estável mas tem alto custo devido a n^2 de complexidade
// assintotica. codigo copiado dos slides do moodle
void MyAlgorithms::insertionSort(int* arr, int n) {
    int i, aux, j;

    for (i = 1; i < n; i++) {
        aux = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = aux;
    }
};

// estavel
// complexidade O(n log n), melhor que o insertion sort
// gasta mais espaco (usa recursividade)
// codigo copiado de https://www.geeksforgeeks.org/merge-sort/ e dos slides da
// disciplina
void MyAlgorithms::mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        this->mergeSort(arr, l, m);
        this->mergeSort(arr, m + 1, r);

        this->merge(arr, l, m, r);
    }
};

// algoritmo linear: radixsort
// pendente entender o que esta acontecendo aqui
void MyAlgorithms::radixSort(int* arr, int n) {
    int maxValue = this->getMaxInArray(arr, n);

    for (int exp = 1; maxValue / exp > 0; exp *= 10)
        this->countingSort(arr, n, exp);
}

void MyAlgorithms::printArray(int* arr, int n) {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

void MyAlgorithms::fillArrayWithRandom(int* arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000;
    }
}

LinkedList MyAlgorithms::getConvexHullByJarvis(LinkedList pointsList) {
    int size = pointsList.getSize();

    // Se tiver menos que 3 pontos, retorna erro
    if (size < 3) {
        throw std::invalid_argument(
            "Unable to getConvexHullByJarvis with less than 3 points!");
    };

    // lista com os pontos que achar do fecho convexo
    LinkedList result;

    // Busca o ponto com menor coordenada X
    int l = 0;
    for (int i = 0; i < size; i++) {
        if (pointsList.getByIndex(i).getX() < pointsList.getByIndex(l).getX()) {
            l = i;
        };
    }

    int p = l, q;
    do {
        result.insertEnd(pointsList.getByIndex(p));

        q = (p + 1) % size;
        for (int i = 0; i < size; i++) {
            if (orientation(pointsList.getByIndex(p), pointsList.getByIndex(i),
                            pointsList.getByIndex(q)) == 2) {
                q = i;
            };
        }
        p = q;
    } while (p != l);

    return result;
}

void MyAlgorithms::getConvexHullByGraham(LinkedList pointsList) {
    // pointsList.printList();
    // debug("HEERE");

    // return;

    // int size = pointsList.getSize();

    // lista com os pontos que achar do fecho convexo
    // LinkedList result;

    // // acha o ponto com menor coordenada Y
    // int ymin = pointsList.getByIndex(0).getY(), min = 0;
    // for (int i = 0; i < size; i++) {
    //     int y = pointsList.getByIndex(i).getY();
    //     if ((y < ymin) ||
    //         (ymin == y && pointsList.getByIndex(i).getX() <
    //                           pointsList.getByIndex(min).getX())) {
    //         ymin = pointsList.getByIndex(i).getY();
    //         min = i;
    //     }
    // }

    // Point lowestPoint = pointsList.getByIndex(min);

    // calcula os angulos polares em relacao ao lowestPoint, salvando no
    // attributo angle
    // for (int i = 0; i < size; i++) {
    //     Point currentPoint = pointsList.getByIndex(i);

    //     if (currentPoint.getX() == lowestPoint.getX() &&
    //         currentPoint.getY() == lowestPoint.getY()) {
    //         currentPoint.setAngle(0);
    //     } else {
    //         currentPoint.setAngle(
    //             acos((currentPoint.getX() - lowestPoint.getX()) /
    //                  this->getDistanceBetween(lowestPoint, currentPoint)));
    //     }
    // }

    // pointsList.printList();

    // return result;
}

// funcoes auxiliares
void MyAlgorithms::merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

int MyAlgorithms::getMaxInArray(int* arr, int n) {
    int maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) maxValue = arr[i];
    }
    return maxValue;
}

void MyAlgorithms::countingSort(int* arr, int n, int exp) {
    int* output = new int[n];
    int i, count[10] = {0};  // maximo: 10^10

    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++) count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) arr[i] = output[i];

    delete[] output;
}

int MyAlgorithms::orientation(Point p, Point q, Point r) {
    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
              (q.getX() - p.getX()) * (r.getY() - q.getY());

    if (val == 0) return 0;    // colieanres
    return (val > 0) ? 1 : 2;  // horario ou anti-horario
}

double MyAlgorithms::getPolarAngle(Point p1, Point p2) {
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    return std::atan2(dy, dx);
}

double MyAlgorithms::getDistanceBetween(Point p1, Point p2) {
    double nx = p1.getX() - p2.getX();
    double ny = p1.getY() - p2.getY();
    double h2 = pow(nx,2)+pow(ny,2);
    return pow(h2, 0.5);
}
