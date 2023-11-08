#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//CAMBIAR DESPUES A 512
#define N 2

float Mat[N][N];
float MatDD[N][N];
float V1[N];
float V2[N];
float V3[N];
float V4[N];

void InitData(){
	int i,j;
	srand(8824553);
	for( i = 0; i < N; i++ )
		 for( j = 0; j < N; j++ ){
			  Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
			   if ( (abs(i - j) <= 3) && (i != j))
				    MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
			    else if ( i == j )
				     MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
			     else MatDD[i][j] = 0.0;
			      }
	for( i = 0; i < N; i++ ){
		 V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		  V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		   V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
	}
}


//1
void PrintVect( float Vect[N], int from, int numel ){
	for (int i = from; i < from + numel; i++){
		printf("%f ", Vect[i]);
	}
	printf("\n");
}	

//2
void PrintRow( float mat[N][N], int row, int from, int numel ){
	for (int j=from;j < numel - from; j++){
		printf("%f ", mat[row][j]);
	}
	printf("\n");
}

//3
void MultEscalar( float vect[N], float vectres[N], float alfa ){
	for (int i=0;i <= sizeof(vect[N]); i++){
	       vectres[i] = alfa * vect[i];
	       printf("%f ", vectres[i]);	       
	}
	printf("\n");
}

//4
float Scalar( float vect1[N], float vect2[N] ){
	float total = 0.0;
	for (int i=0;i < N; i++){
		float res = 0.0;
		res = vect1[i] * vect2[i];
		total += res;
	}
	printf("%f \n", total);
	return total;
}
//5

float Magnitude( float vect[N] ){
        float res = 0.0;
        for (int i=0;i < N; i++){
	       	float suma = 0.0;
                suma =pow(vect[i], 2);
                res += suma;
        }
        float magnitut = sqrt(res);
        printf("%f ", magnitut);
        return magnitut;
}                                                                                              
//6

int Ortogonal (float vect1[N], float vect2[N]){
	float res = 0.0;
	res = Scalar(vect1,vect2);
	if (res == 0.0){
		return 1;
	} else {
		return 0;
	}
}

//7
void Projection( float vect1[N], float vect2[N], float vectres[N]){
	float escalar = Scalar(vect1, vect2);
	float magnitut = Magnitude(vect2);
	float res = escalar / magnitut;
	MultEscalar(vect2, vectres, res);
	
}

//8
float Infininorm( float M[N][N] ){
	float max = 0.0;
	for (int j=0; j < N; j++){
		float res = 0.0;
		for (int i=0; i < N; i++){
			res += M[j][i];
		}
		if (res > max) {
			printf("res: %f, max: %f ", res, max);	
			max = res; 
		}
	}
	printf("%f  ", max);
		
}

//9
float Onenorm( float M[N][N] ){
	float max = 0.0;
	for (int i=0; i < N; i++){
		float res = 0.0;
		for (int j=0; j < N; j++){
			res += M[j][i];
		}
		if (res > max) {
			max = res;
		}
	}
	printf("%f ", max);
}

//10
float NormFrobenius( float M[N][N] ){
	float sumatori = 0.0;
	float res = 0.0;
	for (int i=0; i < N; i++){
		for (int j=0; j < N; j++){ 
			sumatori += pow(M[i][j], 2);
		}
	}
	res = sqrt(sumatori);
	printf("%f ", res);
}	

//11

int DiagonalDom( float M[N][N] ){
	for ( int i=0; i < N; i++ ){			
		float max = M[0][0];
		float res = 0.0;
		for ( int j=0; j < N; j ++ ){
			if ( j != i ) {
				res += M[i][j];
			}
		}
		if (res > max) {
			return 0;
		}	
	}
	return 1;
}
		

int main() {
	InitData();
	//PrintVect(V1, 0, 5);
	//PrintVect(V3, 0, 5);
	PrintRow(Mat, 0, 0, 2);
	PrintRow(Mat, 1, 0, 2);
	printf("\n");
	//PrintRow(Mat, 2, 0, 5);
	//PrintRow(Mat, 3, 0, 5);
 	//PrintRow(Mat, 4, 0, 5);
	//PrintRow( Mat, 3, 0, 3);
	//MultEscalar(V1, V2, 2);
	//Scalar(V1,V3);
	//Magnitude(V1);
	//printf("%d \n", Ortogonal(V1,V2));
	//Projection(V1,V3,V2);
	//Infininorm(Mat);
	//Onenorm(Mat);
	NormFrobenius(Mat);
}
