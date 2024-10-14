#include <stdio.h>

#define SIZE 5
void addMatrices(int ma1[SIZE][SIZE],int ma2[SIZE][SIZE], int addedMatrix[SIZE][SIZE]){ //adds the two matrices

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            addedMatrix[i][j] = ma1[i][j] + ma2[i][j];
        }
    }

}

void multiplyMatrices(int ma1[SIZE][SIZE],int ma2[SIZE][SIZE], int multMatrix[SIZE][SIZE]){ //multiplies the two matrices

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            multMatrix[i][j] = 0;
            for (int k = 0; k < SIZE;k++) {
                multMatrix[i][j] += ma1[i][k] * ma2[k][j];
            }
        }
    }


}

void transposeMatrix(int matrix[SIZE][SIZE], int transposed[SIZE][SIZE]){ //transposes the desired matrix

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            transposed[i][j] = matrix[j][i];
        }
    }

}

void printMatrix(int matrix[SIZE][SIZE]){ //prints the desired matrix

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    //matrices given as sample input matrices in the lab assignment specifications
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE]; //sacrificial matrix to use to print and store modified matrices


    //sample order of functions to output a sample output for submission purposes
    printMatrix(m1);
    addMatrices(m1,m2,result);
    printMatrix(result);
    multiplyMatrices(m1,m2,result);
    printMatrix(result);
    transposeMatrix(m1,result);
    printMatrix(result);

    system("Pause");
    return 0;
}