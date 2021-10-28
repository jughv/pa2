
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdio.h>

void print(double** matrix, int r){ //prints final answer
    for (int i =0;i<r;i++){
        printf("%.0f\n", matrix[i][0]);
    }
    return;
}

double **identity(int c){ //creates the identity matrix
    /*
    double **res = (double**)malloc(c*sizeof(double*));
    for (int i = 0; i < c; i++){
        res[i] = (double*)malloc(c*sizeof(double));   //allocate columns
    }
    */

    double **res = malloc(c*sizeof(double*));
    for (int i = 0; i < c; i++){
        res[i] = malloc(c*sizeof(res[0]));   //allocate columns
    }

        for (int i = 0; i < c; i++){
                for (int j = 0; j < c; j++){
            if(j == i){
                res[i][j]=1;
            }else{
                res[i][j]=0;
            }//end else

    }//end little for
    
}//end big for
    return res;
}


double **inverse(double **M, double **I, int r, int c){ //must invert the matrixes properly
//   double **res = (double**)malloc(r*sizeof(double*));
//   double **temp =M;
//    for (int i = 0; i < r; i++){
//       res[i] = (double*)malloc(c*sizeof(double));   //allocate columns
//    }
//    return res;

    double f; //pivoter

    for (int i =0; i<r; i++){
        f = M[i][i];

        for(int p = 0; p<c;p++){
                M[i][p] = M[i][p]/f;
                I[i][p] = I[i][p]/f;
        }//end small for

        for (int p = 0; p<c; p++){
            f = M[p][i];
            if(p == i){} //skip identities
            else{
                for (int x = 0; x<c; c++){
                    M[p][x]= M[p][x]- (f * M[i][x]);
                    I[p][x]= I[i][x] - (f * I[i][x]);
                }
            }//end else
        }

    }//end big for
    return I;
 //   return res;
}


double** matmulti(double **mat1, double **mat2, int mat1col, int mat1row, int mat2col){ //multiplies matrixes
        /*
    double  **res = (double**) malloc (mat1row*sizeof(double));//allocate rows
    int temp = 0;


    for (int i = 0; i < mat1row; i++){
        res[i] = (double*)malloc(mat2col*sizeof(double));   //allocate columns
    }   
    */
   int temp = 0;
   double **res = malloc(mat1row*sizeof(double*));
    for (int i = 0; i < mat1row; i++){
        res[i] = malloc(mat2col*sizeof(res[0]));   //allocate columns
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





double** transpose(double** matrix, int r, int c){ //basically flip the matrix
   /* 
    double  **res = (double**) malloc (r*sizeof(double));//allocate rows
        for (int i = 0; i < r; i++){
        res[i] = (double*)malloc(c*sizeof(double));   //allocate columns
    
    } 
    */  
    double **res = malloc(c*sizeof(double*));
    for (int i = 0; i < c; i++){
        res[i] = malloc(c*sizeof(res[0]));   //allocate columns
    }

        for (int i = 0; i < r; i++){ //fill rows
            for (int j = 0; j < c; j++){ //fill columns
                res[i][j] = matrix[j][i];
            }        
    }

    

    return res;

}


int main (int argc, char **argv){

        if (argc < 3) {
		printf("error\n");
		return 1;
	} 


 //   double **xtest = NULL;


    FILE *train = fopen(argv[1], "r"); //training data
    FILE *data = fopen(argv[2], "r"); //data data
    char str1[6], str2[6];
    int trainrows; //training data rows
    int traincolumns; //training data columns
    int datarows; //data data rows
    int datacolumns; //data data columns

    //training file arguments

    fscanf(train,"%5s\n",str1);////take in train string
    fscanf(train," %d\n", &traincolumns); // read num of columns
    traincolumns+=1; //add in ones column
    fscanf(train," %d\n", &trainrows); //read num of rows

    //data file arguments

    fscanf(data,"%5s\n", str2);//take in data string   
    fscanf(data," %d\n", &datacolumns); // read num of columns
    datacolumns +=1; //add in ones column
    fscanf(data," %d\n", &datarows); //read num of rows

    double ha;
    /*
    double **xtrain = (double**)malloc(trainrows*sizeof(double*));//training file matrix
    double **y = (double**)malloc(trainrows*sizeof(double*));//y matrix
    double **xdata = (double**)malloc(datarows*sizeof(double*)); //data file matrix
    */
    double **xtrain = malloc(trainrows*sizeof(double*));//training file matrix
    double **y = malloc(trainrows*sizeof(double*));//y matrix
    double **xdata = malloc(datarows*sizeof(double*)); //data file matrix

    for (int i = 0; i<trainrows;i++){
        /*
        xtrain[i] = (double*)malloc(traincolumns*sizeof(double)); //allocate space for training columns
        xtrain[i][0] = 1; //first column is all 1
        y[i] = (double*)malloc(1*sizeof(double)); //allocate y columns
        */
        xtrain[i] = malloc(traincolumns*sizeof(xtrain[0])); //allocate space for training columns
        xtrain[i][0] = 1; //first column is all 1
        y[i] = malloc(1*sizeof(double)); //allocate y columns
    }

    for (int i = 0; i<datarows;i++){
        /*
        xdata[i] = (double*)malloc(datacolumns*sizeof(double)); //allocate space for data columns
        xdata[i][0] = 1;//first column is all 1
        */
        xdata[i] = malloc(datacolumns*sizeof(xdata[0])); //allocate space for data columns
        xdata[i][0] = 1;//first column is all 1
        
    }

    for (int i = 0; i < trainrows; i++){
        for (int j = 1; j < traincolumns; j++){
            fscanf(train," %lf", &ha); //fill up values of training matrix
            xtrain[i][j] = ha;
        }
        fscanf(train," %lf", &y[i][0]); //y values
        fscanf(train,"\n"); //next line
    }


    for(int i = 0; i <datarows; i++){
        xdata[i][0]= 1; //first column is all 1
        for(int j = 1;j<datacolumns;j++){
            fscanf(data," %lf",&ha); //fill up test data matrix
            xdata[i][j] = ha;
        }
        fscanf(data, "\n");
    }

    //finished filling up matrixes from data files

    double **testtranspose = transpose(xtrain,traincolumns,trainrows); //create a transposed matrix X^T

    double **current = matmulti(testtranspose,xtrain, trainrows, traincolumns, traincolumns); //multiply transpose by original (X^TX)

    double **I = identity(traincolumns);

    double **testinverse= inverse(current, I, traincolumns, traincolumns); //inverse the multiple  (X^TX)^-1

    current = matmulti(testinverse,testtranspose, traincolumns,traincolumns,traincolumns); //multiply next pievce of the puzzle (X^TX)^-1X^T

    double **weights = matmulti(current,y,traincolumns,traincolumns,1); //current is now equal to weights (X^TX)^-1X^TY=W
    
    double **answer = matmulti(xdata,weights, datacolumns, datarows, 1); //answer is XW = Y

    print(answer, datarows); //prints answer

free(xtrain);
free(xdata);
free(y);
free(testtranspose);
free(current);
free(testinverse);
free(weights);
free(answer);
//free(xtest);


    return 0;
}




