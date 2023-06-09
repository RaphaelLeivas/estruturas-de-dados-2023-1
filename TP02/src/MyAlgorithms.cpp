#include "../include/MyAlgorithms.hpp"

MyAlgorithms::MyAlgorithms() = default;
MyAlgorithms::~MyAlgorithms() = default;

List<Point>* MyAlgorithms::getConvexPointsByJarvis(List<Point>* pointsList) {
    int size = pointsList->getSize();

    // Se tiver menos que 3 pontos, retorna erro
    if (size < 3) {
        throw std::invalid_argument(
            "Unable to getConvexPointsByJarvis with less than 3 points!");
    };

    // lista com os pontos que achar do fecho convexo
    List<Point>* result = new List<Point>(size);

    // Busca o ponto com menor coordenada X
    int l = 0;
    for (int i = 1; i < size; i++) {
        if (pointsList->getByIndex(i).getX() <
            pointsList->getByIndex(l).getX()) {
            l = i;
        };
    }

    int p = l, q;
    do {
        result->insertEnd(pointsList->getByIndex(p));

        q = (p + 1) % size;
        for (int i = 0; i < size; i++) {
            if (this->orientation(pointsList->getByIndex(p),
                                  pointsList->getByIndex(i),
                                  pointsList->getByIndex(q)) == 2) {
                q = i;
            };
        }
        p = q;
    } while (p != l);

    return result;
}

List<Point>* MyAlgorithms::getConvexPointsByGraham(List<Point>* points,
                                                   GrahamOption option) {
    int size = points->getSize();

    // Se tiver menos que 3 pontos, retorna erro
    if (size < 3) {
        throw std::invalid_argument(
            "Unable to getConvexPointsByGraham with less than 3 points!");
    };

    // acha o ponto com menor coordenada Y
    int ymin = points->getByIndex(0).getY(), min = 0;
    for (int i = 0; i < size; i++) {
        int y = points->getByIndex(i).getY();
        if ((y < ymin) || (ymin == y && points->getByIndex(i).getX() <
                                            points->getByIndex(min).getX())) {
            ymin = points->getByIndex(i).getY();
            min = i;
        }
    }

    Point lowestPoint = points->getByIndex(min);

    Point* newPoints = new Point[size];

    // calcula os angulos polares em relacao ao lowestPoint, salvando no
    // attributo angle e na nova lista
    for (int i = 0; i < size; i++) {
        Point currentPoint = points->getByIndex(i);

        if (currentPoint.getX() == lowestPoint.getX() &&
            currentPoint.getY() == lowestPoint.getY()) {
            currentPoint.setAngle(-1);
        } else {
            currentPoint.setAngle(
                acos((currentPoint.getX() - lowestPoint.getX()) /
                     this->getDistanceBetween(lowestPoint, currentPoint)));
        }

        newPoints[i] = currentPoint;
    }

    // aqui efetuamos a mudança do algoritmo de ordenação do Graham
    switch (option) {
        case GrahamOption::INSERTION_SORT: {
            this->sortByAngleInsertionSort(newPoints, size);
            break;
        }
        case GrahamOption::MERGE_SORT: {
            this->sortByAngleMergeSort(newPoints, 0, size - 1);
            break;
        }
        case GrahamOption::LINEAR_SORT: {
            this->sortByAngleCountingSort(newPoints, size);
            break;
        }

        default:
            this->sortByAngleMergeSort(newPoints, 0, size - 1);
    }

    List<Point>* newPointsList = this->checkSameAngles(newPoints, size);
    int newSize = newPointsList->getCurrentSize();

    // newPointsList->print();

    if (newSize < 3) {
        throw std::invalid_argument(
            "Unable to getConvexPointsByGraham with newSize less than 3 "
            "points!");
    }

    Stack<Point>* stack = new Stack<Point>(newSize);

    stack->push(newPointsList->getByIndex(0));
    stack->push(newPointsList->getByIndex(1));
    stack->push(newPointsList->getByIndex(2));

    for (int i = 3; i < newSize; i++) {
        while (!stack->isEmpty() &&
               this->orientation(this->getNextToTop(*stack), stack->getTop(),
                                 newPointsList->getByIndex(i)) != 2) {
            stack->pop();
        }

        stack->push(newPointsList->getByIndex(i));
    }

    List<Point>* finalResult = new List<Point>(size);

    while (!stack->isEmpty()) {
        Point p = stack->getTop();
        finalResult->insertEnd(p);
        stack->pop();
    }

    delete stack;
    delete[] newPoints;

    return finalResult;
}

// funcoes auxiliares
int MyAlgorithms::orientation(Point p, Point q, Point r) {
    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
              (q.getX() - p.getX()) * (r.getY() - q.getY());

    if (val == 0) return 0;    // colieanres
    return (val > 0) ? 1 : 2;  // horario ou anti-horario
}

double MyAlgorithms::getDistanceBetween(Point p1, Point p2) {
    double nx = p1.getX() - p2.getX();
    double ny = p1.getY() - p2.getY();
    double h2 = pow(nx, 2) + pow(ny, 2);
    return pow(h2, 0.5);
}

void MyAlgorithms::sortByAngleMergeSort(Point* points, int left, int right) {
    if (left < right) {
        int center = left + ((right - left) / 2);
        this->sortByAngleMergeSort(points, left, center);
        this->sortByAngleMergeSort(points, center + 1, right);

        this->mergeHalves(points, left, center, right);
    }
}

void MyAlgorithms::sortByAngleInsertionSort(Point* points, int n) {
    int i, j;
    Point aux;

    for (i = 1; i < n; i++) {
        aux = points[i];
        j = i - 1;

        while (j >= 0 && points[j].getAngle() > aux.getAngle()) {
            points[j + 1] = points[j];
            j = j - 1;
        }
        points[j + 1] = aux;
    }
};

void MyAlgorithms::sortByAngleCountingSort(Point* points, int n) {
    // multiplica por 1000 e arredonda, para trabalhar com inteiros
    int factor = 1000;

    for (int i = 0; i < n; ++i) {
        double roundedAngle = round(points[i].getAngle() * factor);
        points[i].setRoundedAngle((int)roundedAngle);
    }

    Point maxPoint = this->getLargestPointAngle(points, n);
    int maxValue = maxPoint.getRoundedAngle();
    int i, j;

    int* count = new int[maxValue + 1];
    for (i = 0; i <= maxValue; i++) {
        count[i] = 0;  // inicializa com zero
    }

    for (i = 0; i < n; i++) {
        if (points[i].getRoundedAngle() < 0) {
            count[0]++;
            continue;
        }

        count[points[i].getRoundedAngle()]++;
    }

    i = 0;

    for (j = 0; j <= maxValue; j++) {
        while (count[j] > 0) {
            // points[i++] = j;
            count[j]--;
        }
    }

    delete[] count;
};

Point MyAlgorithms::getLargestPointAngle(Point* points, int n) {
    double maxAngle = -1;
    Point maxPoint;

    for (int i = 0; i < n; i++) {
        if (points[i].getAngle() > maxAngle) {
            maxPoint = points[i];
            maxAngle = maxPoint.getAngle();
        }
    }
    return maxPoint;  // the max element from the array
};

// se dois pontos tem o mesmo angulo polar, mantem apenas o que é mais longe do
// inicial
List<Point>* MyAlgorithms::checkSameAngles(Point* points, int size) {
    Point initial = points[0];

    // usa lista encadeada, pois nao sei o tamanho final dela
    List<Point>* newPoints = new List<Point>(size);
    newPoints->insertEnd(initial);

    List<Point>* aux = new List<Point>(size);

    for (int i = 1; i < size - 1; ++i) {
        while (points[i].getAngle() == points[i + 1].getAngle() ||
               points[i].getAngle() == points[i - 1].getAngle()) {
            // vai jogando para a lista auxiliar
            aux->insertEnd(points[i]);
            ++i;  // pula o proximo
        }

        // na lista auxiliar, busca o que tem maior distancia ao inicial
        double maxDistance = 0;
        Point farthestPoint;
        farthestPoint.setAngle(-1);  // indica que nao foi setado aindo
        for (int j = 0; j < aux->getCurrentSize(); ++j) {
            // calcula a distancia
            double distance =
                this->getDistanceBetween(aux->getByIndex(j), initial);
            if (distance > maxDistance) {
                maxDistance = distance;
                farthestPoint = aux->getByIndex(j);
            }
        }

        if (farthestPoint.getAngle() == -1) {
            newPoints->insertEnd(points[i]);
        } else {
            newPoints->insertEnd(farthestPoint);
        }
    }

    return newPoints;
}

void MyAlgorithms::mergeHalves(Point* points, int left, int center, int right) {
    int i, j, k;
    int n1 = center - left + 1;
    int n2 = right - center;

    Point* tempP1 = new Point[n1];
    Point* tempP2 = new Point[n2];

    for (i = 0; i < n1; i++) {
        tempP1[i] = points[left + i];
    }
    for (j = 0; j < n2; j++) {
        tempP2[j] = points[center + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (tempP1[i].getAngle() <= tempP2[j].getAngle()) {
            points[k] = tempP1[i];
            i++;
        } else {
            points[k] = tempP2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        points[k] = tempP1[i];
        i++;
        k++;
    }

    while (j < n2) {
        points[k] = tempP2[j];
        j++;
        k++;
    }

    delete[] tempP1;
    delete[] tempP2;
}

Point MyAlgorithms::getNextToTop(Stack<Point>& stack) {
    Point p = stack.pop();
    Point res = stack.getTop();
    stack.push(p);
    return res;
}
