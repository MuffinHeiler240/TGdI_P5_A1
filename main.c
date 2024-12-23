#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZEILEN 4
#define SPALTEN 4
#include "matrix.h"
#include "vector.h"

matrix random_matrix(matrix m) {
    int i,j;
    for ( i = 0; i < ZEILEN; i++) {
        for (j= 0; j < SPALTEN; j++) {
            setEntry(m,i,j,(rand() % 65)-32);
        }
    }
    return m;
}

vector random_vector(vector v) {
    int i;
    for (i = 0; i < ZEILEN; i++) {
        setValue(v,i, (rand() % 65)-32);
    }
    return  v;
}

void print_matrix(matrix m) {
    int i,j;
    for ( i = 0; i < ZEILEN; i++) {
        for (j= 0; j < SPALTEN; j++) {
            printf("%4.0f |", getEntry(m,i,j));
        }
        printf("\n");
    }
}

void print_vector(vector v) {
    int i;
    for (i = 0; i < ZEILEN; i++) {
        printf("%4.0f \n", getValue(v,i));
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));

    matrix m = createMatrix(ZEILEN, SPALTEN);
    random_matrix(m);
    printf("Matrix A:\n");
    print_matrix(m);

    printf("\n\n");

    vector v = createVector(ZEILEN);
    random_vector(v);
    printf("Vektor A:\n");
    print_vector(v);
    return 0;
}
