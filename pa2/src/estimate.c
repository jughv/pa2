
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdio.h>




double** matmulti(double **mat1, double **mat2, int mat1col, int mat1row, int mat2col){

    double  **res = (double**) malloc (mat1row*sizeof(double));//allocate rows
    int temp = 0;


    for (int i = 0; i < mat1row; i++){
        res[i] = (double*)malloc(mat2col*sizeof(double));   //allocate columns
    }   


    for (int i = 0; i < mat1row; i++){ //multiply
        for(int k = 0; k < mat2col; k++){
            for (int j = 0; j < mat1col; j++){
                temp += mat1[i][j] * mat2[j][k];
            }
            res[i][k] = temp;
            temp = 0;
            
        }
    }
    return res;
}





double** inverse (double** matrix, int r, int c){
    
    double  **res = (double**) malloc (c*r*sizeof(double));//allocate rows
        for (int i = 0; i < r; i++){
        res[i] = (double*)malloc(c*sizeof(double));   //allocate columns
    }   

        for (int i = 0; i < r; i++){ //fill rows
            for (int j = 0; j < c; j++){
                res[i][j] = matrix[i][j];
            }        
    }

    

    return res;

}


int main (int argc, char **argv){

        if (argc < 3) {
		printf("error\n");
		return 1;
	} 


    double **xtest = NULL;


    FILE *train = fopen(argv[1], "r"); //training data
    FILE *data = fopen(argv[2], "r"); //data data
    int trainrows; //training data rows
    int traincolumns; //training data columns
    int datarows; //data data rows
    int datacolumns; //data data columns

    //training file arguments

   // fscanf(train,"%d\n", &rows);//need to figure out how to take in train
    fscanf(train," %lf\n", &traincolumns); // read num of columns
    fscanf(train," %lf\n", &trainrows); //read num of rows

    //data file arguments

    // fscanf(data,"%d\n", &rows);//need to figure out how to take in train
    fscanf(data," %lf\n", &datacolumns); // read num of columns
    fscanf(data," %lf\n", &datarows); //read num of rows


    double **xtrain = (double**)malloc(trainrows*sizeof(double*));//training file matrix
    double **y = (double**)malloc(trainrows*sizeof(double*));//y matrix
    double **xdata = (double**)malloc(datarows*sizeof(double*)); //data file matrix

    for (int i = 0; i<trainrows;i++){
        xtrain[i] = (double*)malloc(traincolumns+1*sizeof(double)); //allocate space for training columns
        xtrain[i][0] = 1; //first column is all 1
        y[i] = (double*)malloc(1*sizeof(double)); //allocate y columns
    }

    for (int i = 0; i<datarows;i++){
        xdata[i] = (double*)malloc(datacolumns+1*sizeof(double)); //allocate space for data columns
        xdata[i][0] = 1;//first column is all 1
    }

    for (int i = 0; i < trainrows; i++){
        for (int j = 1; j <= traincolumns; j++){
            fscanf(train," %lf", &xtrain[i][j]); //fill up values of training matrix

        }
        fscanf(train," %lf", &y[i][0]); //y values
        fscanf(train,"\n"); //next line
    }


    for(int i = 0; i <datarows; i++){
        xdata[i][0]= 1; //first column is all 1
        for(int j = 1;j<=datacolumns;j++){
            fscanf(data," %lf",&xdata[i][j]); //fill up test data matrix
        }
        fscanf(data, "\n");
    }

    //finished filling up matrixes from data files

    
    


    
    return 0;
}




