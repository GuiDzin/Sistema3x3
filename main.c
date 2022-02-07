#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int i, j;    
	int x, y, z;   
	int det, det2a, det2b, det2c;                              
	double sis[3][4], solucao[3], temp[3][4], coef_10, coef_20, coef_21; 	
	
	printf("Entre com os coeficientes do sistema de 3 incognitas: \n");
	printf("Ex.: Ax + By + Cz = D \n");
	printf("[0,0]= A; [0,1]= B, [0,2]= C, [0,3]=D \n\n");
	
	for (i = 0; i < 3; i++) {
  		for (j = 0; j < 4; j++) {
    		printf("[%d:%d] = ", i, j);
    		scanf("%lf", &sis[i][j]);
  		}
	}
	
    det = ((sis[0][0]*sis[1][1]*sis[2][2])+(sis[0][1]*sis[1][2]*sis[2][0])+(sis[0][2]*sis[1][0]*sis[2][1]))-((sis[0][2]*sis[1][1]*sis[2][0])+(sis[0][0]*sis[1][2]*sis[2][1])+(sis[0][1]*sis[1][0]*sis[2][2]));
    det2a = ((sis[0][3]*sis[1][1]*sis[2][2])+(sis[0][1]*sis[1][2]*sis[2][3])+(sis[0][2]*sis[1][3]*sis[2][1]))-((sis[0][2]*sis[1][1]*sis[2][3])+(sis[0][3]*sis[1][2]*sis[2][1])+(sis[0][1]*sis[1][3]*sis[2][2]));
    det2b = ((sis[0][0]*sis[1][3]*sis[2][2])+(sis[0][3]*sis[1][2]*sis[2][0])+(sis[0][2]*sis[1][0]*sis[2][3]))-((sis[0][2]*sis[1][3]*sis[2][0])+(sis[0][0]*sis[1][2]*sis[2][3])+(sis[0][3]*sis[1][0]*sis[2][2]));
    det2c = ((sis[0][0]*sis[1][1]*sis[2][3])+(sis[0][1]*sis[1][2]*sis[2][0])+(sis[0][3]*sis[1][0]*sis[2][1]))-((sis[0][3]*sis[1][1]*sis[2][0])+(sis[0][0]*sis[1][3]*sis[2][1])+(sis[0][1]*sis[1][0]*sis[2][3]));
    
    if(sis[0][0] == 0){
		temp[0][0] = sis[1][0];	sis[1][0] = sis[0][0]; sis[0][0] = temp[0][0];
		temp[0][1] = sis[1][1];	sis[1][1] = sis[0][1]; sis[0][1] = temp[0][1];
		temp[0][2] = sis[1][2];	sis[1][2] = sis[0][2]; sis[0][2] = temp[0][2];
		temp[0][3] = sis[1][2];	sis[1][3] = sis[0][3]; sis[0][3] = temp[0][3];
	}
	
	printf("\n");
		printf(" Matriz Aumentada:\n");
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
    			printf(" %5.2lf ", sis[i][j]);
  			}
  		printf("\n");
		}
		
    printf("Aqui");
	printf(" %5.2li ", det);
	printf(" %5.2li ", det2a);
	printf(" %5.2li ", det2b);
	printf(" %5.2li ", det2c);
    
    if(det != 0){
    	printf("\n O Sistema eh Possivel e Determinado (SPD) \n");
    	
    	coef_10 = -1.0 * sis[1][0] / sis[0][0];
		coef_20 = -1.0 * sis[2][0] / sis[0][0];
		
		for (j = 0; j < 4; j++) {
  			sis[1][j] += coef_10 * sis[0][j];
  			sis[2][j] += coef_20 * sis[0][j];
		}
	
		coef_21 = -1.0 * sis[2][1] / sis[1][1];
		for (j = 1; j < 4; j++) {    
  			sis[2][j] += coef_21 * sis[1][j];
		}
	
		printf("\n");
		printf(" Matriz resultante:\n");
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
    			printf(" %5.2lf ", sis[i][j]);
  			}
  			printf("\n");
		}
	
		solucao[2] = (sis[2][3]) / sis[2][2];
		solucao[1] = (sis[1][3] - (solucao[2] * sis[1][2])) / sis[1][1];
		solucao[0] = (sis[0][3] - (solucao[2] * sis[0][2]) - (solucao[1] * sis[0][1])) / sis[0][0];
	
		printf("\n Resultados do sistema (x,y,z): \n");
		printf(" {(%5.2lf %5.2lf %5.2lf)}", solucao[0], solucao[1], solucao[2]);
		
	} else if ((det == 0) && ((det2a != 0) || (det2b != 0) || (det2c != 0))){
		printf("\n O Sistema eh Impossivel (SI)");
	} else if (det == 0){
		printf("\n O Sistema eh Possivel, porem Indeterminado (SPI) \n");		
	}
		
	return 0;
}
