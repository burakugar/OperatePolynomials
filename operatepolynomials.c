/* BURAK UGAR 200104004100 HW5
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/
#include <stdio.h>
#include "hw5_lib.h"
#include <math.h>
#include <stdlib.h> //for exit function

/**************************************FOR OPERATE POLYNOMIALS *************************************************************************/
void check_input(int *temp1,double *a3,int *temp2,double *a2,int *temp3,double *a1,int *temp4,double *a0){
	double a00=*a0,a11=*a1,a22=*a2,a33=*a3;
	/* considering all possibilities to check if the user entered the polynomials coeefs in right order if s(he) didnt change the order */
	if(*temp1==3 && *temp2==2 && *temp3==1 && *temp4==0){
		*a3=a33;
		*a2=a22;
		*a1=a11;
		*a0=a00;
	}
	else if(*temp1==3 && *temp2==2 && *temp3==0 && *temp4==1){
		*a3=a33;
		*a2=a22;
		*a1=a00;
		*a0=a11;
	}
	else if(*temp1==3 && *temp2==1 && *temp3==0 && *temp4==2){
		*a3=a33;
		*a2=a00;
		*a1=a22;
		*a0=a11;
	}
	else if(*temp1==3 && *temp2==1 && *temp3==2 && *temp4==0){
		*a3=a33;
		*a2=a11;
		*a1=a22;
		*a0=a00;
	
	}
	else if(*temp1==3 && *temp2==0 && *temp3==1 && *temp4==2){
		*a3=a33;
		*a2=a00;
		*a1=a11;
		*a0=a22;
		
	}
	else if(*temp1==3 && *temp2==0 && *temp3==2 && *temp4==1){
		*a3=a33;
		*a2=a11;
		*a1=a00;
		*a0=a22;
		
	}
	/* */
	else if(*temp1==2 && *temp2==1 && *temp3==0 && *temp4==3){
		*a3=a00;
		*a2=a33;
		*a1=a22;
		*a0=a11;
		
	}
	else if(*temp1==2 && *temp2==1 && *temp3==3 && *temp4==0){
		*a3=a11;
		*a2=a33;
		*a1=a22;
		*a0=a00;
		
	}
	else if(*temp1==2 && *temp2==3 && *temp3==0 && *temp4==1){
		*a3=a22;
		*a2=a33;
		*a1=a00;
		*a0=a11;
		
	}
	else if(*temp1==2 && *temp2==3 && *temp3==1 && *temp4==0){
		*a3=a22;
		*a2=a33;
		*a1=a11;
		*a0=a00;
		
	}
	else if(*temp1==2 && *temp2==0 && *temp3==1 && *temp4==3){
		*a3=a00;
		*a2=a33;
		*a1=a11;
		*a0=a22;
		
	}
	else if(*temp1==2 && *temp2==0 && *temp3==3 && *temp4==1){
		*a3=a11;
		*a2=a33;
		*a1=a00;
		*a0=a22;
		
	}
	/* */
	else if(*temp1==1 && *temp2==2 && *temp3==3 && *temp4==0){
		*a3=a11;
		*a2=a22;
		*a1=a33;
		*a0=a00;
	
	}
	else if(*temp1==1 && *temp2==2 && *temp3==0 && *temp4==3){
		*a3=a00;
		*a2=a22;
		*a1=a33;
		*a0=a11;
		
	}
	else if(*temp1==1 && *temp2==3 && *temp3==0 && *temp4==2){
		*a3=a22;
		*a2=a00;
		*a1=a33;
		*a0=a11;
		
	}
	else if(*temp1==1 && *temp2==3 && *temp3==2 && *temp4==0){
		*a3=a22;
		*a2=a11;
		*a1=a33;
		*a0=a00;
		
	}
	else if(*temp1==1 && *temp2==0 && *temp3==3 && *temp4==2){
		*a3=a11;
		*a2=a00;
		*a1=a33;
		*a0=a22;
		
	}
	else if(*temp1==1 && *temp2==0 && *temp3==2 && *temp4==3){
		*a3=a00;
		*a2=a11;
		*a1=a33;
		*a0=a22;
		
	}
	/* */
	else if(*temp1==0 && *temp2==2 && *temp3==1 && *temp4==3){
		*a3=a00;
		*a2=a22;
		*a1=a11;
		*a0=a33;
		
	}
	else if(*temp1==0 && *temp2==2 && *temp3==3 && *temp4==1){
		*a3=a11;
		*a2=a22;
		*a1=a00;
		*a0=a33;
	
	}
	else if(*temp1==0 && *temp2==1 && *temp3==2 && *temp4==3){
		*a3=a00;
		*a2=a11;
		*a1=a22;
		*a0=a33;
	
	}
	else if(*temp1==0 && *temp2==1 && *temp3==3 && *temp4==2){
		*a3=a11;
		*a2=a00;
		*a1=a22;
		*a0=a33;

	}
	else if(*temp1==0 && *temp2==3 && *temp3==1 && *temp4==2){
		*a3=a22;
		*a2=a33;
		*a1=a11;
		*a0=a22;

	}
	else if(*temp1==0 && *temp2==3 && *temp3==2 && *temp4==1){
		*a3=a22;
		*a2=a11;
		*a1=a00;
		*a0=a33;
	
	}
	
}

void operate_polynomials  (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double* b0, char op)
{
	double r1; double *point_1;
	double r2; double *point_2;
	double r3; double *point_3;
	double r4; double *point_4;
	double r5; double *point_5;
	double r6; double *point_6;
	double r7; double *point_7;
	if(op=='+'){
		
		r4= *a3+*b3; point_1=&r1; /*operating sum */
		r3= *a2+*b2; point_2=&r2;
		r2= *a1+*b1; point_3=&r3;
		r1= *a0+*b0; point_4=&r4;
		printf("\nResulting polynomials coeffs are:%lf %lf %lf %lf",*point_4,*point_3,*point_2,*point_1);
	}
	else if(op=='-'){
		 /*operating substituion */
		r4= *a3-*b3; point_1=&r1;
		r3= *a2-*b2; point_2=&r2;
		r2= *a1-*b1; point_3=&r3;
		r1= *a0-*b0; point_4=&r4;
		printf("\nResulting polynomials coeffs are:%lf %lf %lf %lf",*point_4,*point_3,*point_2,*point_1);
	}
	else if(op=='*'){ /*operating multiplication and assigning the values to corresponding pointers*/
		
		r7=(*a3)*(*b3);							point_7=&r7;
		r6=(*a3)*(*b2)+(*a2)*(*b3);						point_6=&r6;
		r5=(*a2)*(*b2)+(*a3)*(*b1)+(*a1)*(*b3),				 point_5=&r5;
		r4=(*a3)*(*b0)+(*a0)*(*b3)+(*a2)*(*b1)+(*a1)*(*b2);  point_4=&r4;
		r3=(*a2)*(*b0)+(*a0)*(*b2)+(*a1)*(*b1);              point_3=&r3;
		r2=(*a1)*(*b0)+(*a0)*(*b1);			point_2=&r2;
		r1=(*a0)*(*b0); 				point_1=&r1;
		printf("\nResulting polynomials coeffs are:%lf %lf %lf %lf %lf %lf %lf",*point_7,*point_6,*point_5,*point_4,*point_3,*point_2,*point_1);
	}
}