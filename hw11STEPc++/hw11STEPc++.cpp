#include <iostream>
#include <algorithm>
using namespace std;

void random(int* ar, int size) {
    for (int i = 0; i < size; i++) {
        *(ar + i) = rand() % 10;
    }
}

void printF(int* ar, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(ar + i) << " ";
    }
}

int printMenu(int* A, int* B, int* C, int m, int n, int select) {
    int k = 0;
    if (select == 1) {
        for (int i = 0; i < m; i++) {
            bool found = false;
            bool isDuplicate = false;
            for (int j = 0; j < n; j++) {
                if (*(A + i) == *(B + j)) {
                    found = true;
                    break;
                }
            }
            for (int d = 0; d < k; d++) {
                if (*(A + i) == *(C + d)) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!found && !isDuplicate) {
                *(C + k) = *(A + i);
                k++;
            }
        }
    }
    if (select == 2) {
        for (int i = 0; i < m; i++) {
            bool foundInB = false;
            bool isDuplicate = false;
            for (int j = 0; j < n; j++) {
                if (*(A + i) == *(B + j)) {
                    foundInB = true;
                    break;
                }
            }
            for (int d = 0; d < k; d++) {
                if (*(A + i) == *(C + d)) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!foundInB && !isDuplicate) {
                *(C + k) = *(A + i);
                k++;
            }
        }
        for (int i = 0; i < n; i++) {
            bool foundInA = false;
            bool isDuplicate = false;
            for (int j = 0; j < m; j++) {
                if (*(B + i) == *(A + j)) {
                    foundInA = true;
                    break;
                }
            }
            for (int d = 0; d < k; d++) {
                if (*(B + i) == *(C + d)) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!foundInA && !isDuplicate) {
                *(C + k) = *(B + i);
                k++;
            }
        }
    }
    if (select == 3) {
        for (int i = 0; i < m; i++) {
            *(C + k) = *(A + i);
            k++;
        }
        for (int i = 0; i < n; i++) {
            *(C + k) = *(B + i);
            k++;
        }
    }
    return k;
}

int main()
{
    srand(time(0));
    system("chcp 1251>null");
    cout << "Введіть розміри першого(A) та другого(B) масиву: ";
    int m, n;
    cin >> m >> n;
    int* A = new int[m];
    int* B = new int[n];
    int* C = new int[m + n];
    cout << "Масив А: ";
    random(A, m);
    printF(A, m);
    cout << endl;
    cout << "Масив B: ";
    random(B, n);
    printF(B, n);
    int select;
    cout << endl;
    cout << "Вибираєте 1, 2 чи 3? ";
    cin >> select;
    int sizeC = printMenu(A, B, C, m, n, select);
    cout << "Результат: ";
    printF(C, sizeC);
    delete[] A;
    delete[] B;
    delete[] C;
}


