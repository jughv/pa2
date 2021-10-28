# pa2

Tryna pas comp arch project 2


double cellMultiplication(double **matA, double **matB, int row, int col, int size){

double result = 0;
for(int i = 0; i < size; i++){
    result = (matA[row][i] * matB[i][col]) + result;
    }

return result;
}

double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2)
{
    
    //printf("\nLine 113");
    double** result= malloc(r1 * sizeof(double*)); 
    //printf("\nLine 115");
      if( c1 != r2){
          printf("Cannot Multiply Matrices: Line 38");
          free(result);
        return NULL;
    }

    //printf("Line 122");
    for(int i = 0; i < r1; i++){
        result[i] = malloc(c2 * sizeof(result[0]));
    }

    int size = c1;

    int resultR = r1;
    int resultC = c2;

    for( int i = 0; i < resultR; i++){
        for(int j = 0; j < resultC; j++){
            result[i][j] = cellMultiplication(matA, matB, i ,j , size);  
        }
    }

   // printf("yeet");
    return result;
}
