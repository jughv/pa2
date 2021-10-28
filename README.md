# pa2

Tryna pas comp arch project 2


double** inverseMatrix(double **matA, int dimension)
{

    double** matInverse=malloc(dimension*sizeof(double*)); 
    double **holder = matA;


//Allocate memory for the new matrix
    for(int i = 0; i < dimension; i++){

        matInverse[i] = malloc(dimension*sizeof(matInverse[0]));
    }
    

    //Takes matrix and makes it a indentity matrix

    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            matInverse[i][j] = 0.0;
        }
        matInverse[i][i] = 1.0;
    }


    for(int mainRow = 0; mainRow < dimension; mainRow++){
        
        double pivot = holder[mainRow][mainRow];
        for(int i = 0; i < dimension; i++){

            holder[mainRow][i] = holder[mainRow][i] / pivot;
            matInverse[mainRow][i] = matInverse[mainRow][i] / pivot;
        }

        for(int row = 0; row < dimension; row++){
            double yeet = holder[row][mainRow];
            if(row == mainRow){

            }else
            {
                for(int col = 0; col < dimension; col++){
                    holder[row][col] = holder[row][col] - (yeet * holder[mainRow][col]);
                    matInverse[row][col] = matInverse[row][col] - (yeet * matInverse[mainRow][col]);

                }

            }
            
        }
        


    }





/*for( int i = 0; i < dimension; i++){
    printf("\n");
    for(int j = 0; j < dimension; j++){
        printf("%f\t",matInverse[i][j]);
    }
}
*/
    
    return matInverse;
}
