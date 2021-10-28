#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define DEBUG 0

void freedom(double **matrix, int r){ //free columns of matrices
    for (int i =0;i<r;i++){
        free(matrix[i]);
    }
    free(matrix);
}
/*
void print(double** matrix, int r){ //prints final answer
    for (int i =0;i<r;i++){
        
        printf("%.0f\n", matrix[i][0]);
    }
    return;
}
*/

void printmat(double **mat, int matrow, int matcol){
    for (int a = 0; a < matrow; a++){
        for (int b = 0; b < matcol; b++){
            printf("%.5f", mat[a][b]);
            if (b+1 == matcol){
                continue;
            }
            printf(" ");
        }
        if (a+1 == matrow){
            continue;
        }
        printf("\n");
    }
    printf("\n"); 
}



double **identity(int c){ //creates the identity matrix
    /*
    double **res = (double**)malloc(c*sizeof(double*));
    for (int i = 0; i < c; i++){
        res[i] = -0(double*)malloc(c*sizeof(double));   //allocate columns
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


double **inverse(double **M, double **I, int n){ //must invert the matrixes properly
//   double **res = (double**)malloc(r*sizeof(double*));
//   double **temp =M;
//    for (int i = 0; i < r; i++){
//       res[i] = (double*)malloc(c*sizeof(double));   //allocate columns
//    }
//    return res;
    double **temp = M;
    double f,g; //pivoter

    /*
    for (int i =0; i<n; i++){
        f = temp[i][i];

        for(int p = 0; p<n;p++){
                temp[i][p] = temp[i][p] / f;
                I[i][p] = I[i][p] / f;
        }//end small for

        for (int p = 0; p<n; p++){
            g = temp[p][i];
            if(p == i){} //skip identities
            else{
                for (int x = 0; x<n; x++){
                    temp[p][x]= M[p][x]- (g * temp[i][x]);
                    I[p][x]= I[p][x] - (g * I[i][x]);
                    if(DEBUG){
                        printf("current matrix:\n");
                        printmat(I, n, n);
                        printf("\n");
                    }
                }
            }//end else
        }



    }//end big for
    */

    
   for (int i =0; i<n; i++){
        f = temp[i][i];

        for(int p = 0; p<n;p++){
                temp[i][p] = temp[i][p] / f;
                I[i][p] = I[i][p] / f;
        }//end small for
        if(DEBUG){
                        printf("it1:\n");
                        printf("current matrix:\n");
                        printmat(I, n, n);
                        printf("\n");

                        printf("old matrix:\n");
                        printmat(temp, n, n);
                        printf("\n");
                    }

        for (int p =i+1; p<n; p++){
            g = temp[p][i];
            
            
                for (int x = 0; x<n; x++){
                    //if(p == i  ){continue;}
                    temp[p][x]= temp[p][x]- (g * temp[i][x]);
                    I[p][x]= I[p][x] - (g * I[i][x]);
                    //temp[x][p]= temp[x][p]- (g * temp[i][p]);
                    //I[x][p]= I[x][p] - (g * I[i][p]);
                
            }//end else
        }
        if(DEBUG){
                        printf("it2:\n");
                        printf("current matrix:\n");
                        printmat(I, n, n);
                        printf("\n");

                        printf("old matrix:\n");
                        printmat(temp, n, n);
                        printf("\n");
                    }

    }


    for(int i = n-1;i>=0;i--){
        for (int p = i-1; p>=0; p--){
            g = temp[p][i];
            
            
                for (int x = n-1; x>=0; x--){
                    if(p == i ){continue;}
                    temp[p][x]= temp[p][x]- (g * temp[i][x]);
                    I[p][x]= I[p][x] - (g * I[i][x]);
                   //temp[x][p]= temp[x][p]- (g * temp[i][p]);
                    //I[x][p]= I[x][p] - (g * I[i][p]);
                
            }//end else
        }
        if(DEBUG){
                        printf("current matrix:\n");
                        printmat(I, n, n);
                        printf("\n");

                        printf("old matrix:\n");
                        printmat(temp, n, n);
                        printf("\n");
                    }

    }
    
        if(DEBUG){
                        printf("current matrix:\n");
                        printmat(I, n, n);
                        printf("\n");

                        printf("old matrix:\n");
                        printmat(temp, n, n);
                        printf("\n");
                    }


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
   //double temp = 0.0;

   double **res = malloc(mat1row*sizeof(double*));
    for (int i = 0; i < mat1row; i++){
        res[i] = malloc(mat2col*sizeof(res[0]));   //allocate columns
    }
    


    for (int i = 0; i < mat1row; i++){ //multiply
        for(int j = 0; j < mat2col; j++){
            res[i][j] =0;
            for (int k = 0; k < mat1col; k++){
                //temp = (mat1[i][j] * mat2[j][k]) + temp;
                res[i][j] += mat1[i][k] *mat2[k][j];
                /*if(DEBUG){
                    printf("%lf\n", res[i][j]);
                }*/
            }
            //res[i][j] = temp;
           // temp = 0.0;
            
            
            
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
   // printf("train :%s\n",str1);
    fscanf(train," %d\n", &traincolumns); // read num of columns
    traincolumns+=1; //add in ones column
    //printf("train columns:%d\n",traincolumns);
    fscanf(train," %d\n", &trainrows); //read num of rows
    //printf("train rows:%d\n",trainrows);

    //data file arguments

    fscanf(data,"%5s\n", str2);//take in data string  
    //printf("data :%s\n",str2); 
    fscanf(data," %d\n", &datacolumns); // read num of columns
    datacolumns +=1; //add in ones column
    //printf("data columns:%d\n",datacolumns);
    fscanf(data," %d\n", &datarows); //read num of rows
    //printf("data rows:%d\n",datarows);

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

    if(DEBUG){
    printf("xtrain: \n");
    printmat(xtrain, trainrows, traincolumns);
    printf("\n");
    }
    

    for(int i = 0; i <datarows; i++){
        xdata[i][0]= 1; //first column is all 1
        for(int j = 1;j<datacolumns;j++){
            fscanf(data," %lf",&ha); //fill up test data matrix
            xdata[i][j] = ha;
        }
        fscanf(data, "\n");
    }
     if(DEBUG){
    printf("xdata: \n");
    printmat(xdata, datarows, datacolumns);
    printf("\n");
    }

    //finished filling up matrixes from data files

    double **testtranspose = transpose(xtrain,traincolumns,trainrows); //create a transposed matrix X^T

    if(DEBUG){
    printf("transposed:\n");
    printmat(testtranspose, traincolumns, trainrows);
    printf("\n");
    }

    double **current = matmulti(testtranspose,xtrain ,trainrows, traincolumns,    traincolumns); //multiply transpose by original (X^TX)

    if(DEBUG){
    printf("current:\n");
    printmat(current, traincolumns, traincolumns);
    printf("\n");
    }

    double **I = identity(traincolumns);

    if(DEBUG){
    printf("I:\n");
    printmat(I, traincolumns, traincolumns);
    printf("\n");
    }

    //double **testinverse= inverse(current, I, traincolumns, traincolumns); //inverse the multiple  (X^TX)^-1
    double **testinverse= inverse(current,I, traincolumns); //inverse the multiple  (X^TX)^-1


    if(DEBUG){
    printf("testinverse:\n");
    printmat(testinverse, traincolumns, traincolumns);
    printf("\n");
    }

    double **xtxi = matmulti(testinverse,testtranspose, traincolumns,traincolumns,traincolumns); //multiply next pievce of the puzzle (X^TX)^-1X^T

    if(DEBUG){
    printf("xtxi:\n");
    printmat(xtxi, traincolumns, traincolumns);
    printf("\n");
    }

    double **weights = matmulti(xtxi,y,traincolumns,traincolumns,1); //current is now equal to weights (X^TX)^-1 X^T Y=W

    if(DEBUG){
    printf("weights:\n");
    printmat(weights, traincolumns, 1);
    printf("\n");
    }
    
    double **answer = matmulti(xdata,weights, datacolumns, datarows, 1); //answer is XW = Y

     if(DEBUG){
         printf("answer:\n");
     }
    //printmat(answer, datarows, 1);
    //print(answer, datarows); //prints answer
    //printf(":\n");

   for (int i = 0; i< datarows;i++){
        printf("%.0f\n", answer[i][0]);
   }

freedom(xtrain, trainrows);
freedom(xdata, datarows);
freedom(testtranspose, trainrows);
freedom(current, traincolumns);
freedom(testinverse, traincolumns);
freedom(xtxi,traincolumns);
freedom(y,trainrows);
freedom(weights,traincolumns);
freedom(answer,datarows);
//free(xtest);


    return 0;
}

