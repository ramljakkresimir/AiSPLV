#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void gen_arr(float V[], int n, float dg, float gg);
int sekv_pret(float V[], int n, float x);
void sort(float V[], int n);
void swap(float* x, float* y);
int partition(float V[], int low, int high);
void quickSort(float V[], int low, int high);
int bin_pret(float V[], int n, float x);

int main()
{
    time_t t1, t2, t3, t4, t5, t6;
    int n;
    float* A;

    printf("Unesite n velicinu polja:\n");
    scanf("%d", &n);

    A = (float*)malloc(n * sizeof(float));

    gen_arr(A, n, 5, 300);
    /*for (int i = 0; i < n; i++) {
        printf("%f, ", A[i]);
    }*/
    

    float trazeni_br = 7;

    t1 = clock();

    sekv_pret(A, n, trazeni_br);

    t2 = clock();

    printf("\nVrijeme izmedu sekvecijalnog pr je: %ld ms", (t2 - t1));


    t3 = clock();

    sort(A, n);

    t4 = clock();

    printf("\nVrijeme izmedu sortiranja je: %ld ms", (t4 - t3));

    t5 = clock();

    bin_pret(A, n, trazeni_br);

    t6 = clock();

    printf("\nVrijeme izmedu binarnog pr je: %ld ms", (t6 - t5));

    return 0;

    free(A);
}

void gen_arr(float V[], int n, float dg, float gg) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        V[i] = dg + ((float)rand() / RAND_MAX) * (gg - dg);
    }
}


int sekv_pret(float V[], int n, float x) {
    for (int i = 0; i < n; i++) {
        if (V[i] == x) {
            return i;
        }
    }
    return -1;
}

void swap(float* a, float* b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}


int partition(float V[], int low, int high)
{
    float pivot = V[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (V[j] < pivot) {
            i++;
            swap(&V[i], &V[j]);
        }
    }
    swap(&V[i + 1], &V[high]);
    return i + 1;
}


void quickSort(float V[], int low, int high)
{
    if (low < high) {
        int pi = partition(V, low, high);
        quickSort(V, low, pi - 1);
        quickSort(V, pi + 1, high);
    }
}


void sort(float V[], int n)
{
    quickSort(V, 0, n - 1);
}


int bin_pret(float V[], int n, float x)
{
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (V[middle] == x) {
            return middle;
        }
        else if (V[middle] < x) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}