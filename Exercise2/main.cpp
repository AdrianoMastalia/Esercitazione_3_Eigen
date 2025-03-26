#include<iostream>
#include<iomanip>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

int main()
{
	/* Defining the solution vector, to compute the relative errors */
	
	Vector2d v(-1.0e+0, -1.0e+0);
	Matrix2d A;
	
	/* I have to memorize the matrix A element by element, because 
	there is no apparent pattern in it. I didn't use a dinamic matrix because
	I know the fixed dimension of A*/
	
	A<<5.547001962252291e-01, -3.770900990025203e-02,
	   8.320502943378437e-01,-9.992887623566787e-01;
	   
	/*memorizing vector b */
	   
	Vector2d b_1(-5.169911863249772e-01, 1.672384680188350e-01);
	
	/* In the following line, I perform the calculation of the solution of
	Ax = b using PA = LU decomposition. I chose the partial PivLu because the matrix
	A is invertible, to improve speed. There is less accuracy with respect to FullPiv,
	but as I'll calculate ther's still an efficient accuracy */
	
	Vector2d sol_A_LU = A.partialPivLu().solve(b_1); 
	
	/*Here, I use the QR method to find the solution to the first system. Since the dimension
	of the matrix is small, I chose householderQR, because it's the fastest QR decomposition
	for small matrices, according to the official Eigen documentation*/
	
	Vector2d sol_A_QR = A.householderQr().solve(b_1);
	
	/*To calculate the relative error, I used the .norm() method */
	
	double error_A_LU = ((v-sol_A_LU).norm())/(v.norm());
	double error_A_QR = ((v-sol_A_QR).norm())/(v.norm());
	cout<<"Relative error of Lu method  1: "<<error_A_LU<<endl;
	cout<<"Relative error of QR method  1: "<<error_A_QR<<endl;
	
	/*In the following lines, I just apply the same procedure to the other
	matrices. */
	
	Matrix2d B;
	B<<5.547001962252291e-01, -5.540607316466765e-01, 
	   8.320502943378437e-01, -8.324762492991313e-01;
	Vector2d b_2(-6.394645785530173e-04, 4.259549612877223e-04);
	Vector2d sol_B_LU = B.partialPivLu().solve(b_2); 
	Vector2d sol_B_QR = B.householderQr().solve(b_2);
	double error_B_LU = ((v-sol_B_LU).norm())/(v.norm());
	double error_B_QR = ((v-sol_B_QR).norm())/(v.norm());
	cout<<"Relative error of Lu method  2: "<<error_B_LU<<endl;
	cout<<"Relative error of QR method  2: "<<error_B_QR<<endl;

	Matrix2d C;
	C<<5.547001962252291e-01, -5.547001955851905e-01, 
	8.320502943378437e-01, -8.320502947645361e-01;
	Vector2d b_3(-6.400391328043042e-10, 4.266924591433963e-10);
	Vector2d sol_C_LU = C.partialPivLu().solve(b_3); 
	Vector2d sol_C_QR = C.householderQr().solve(b_3);
	double error_C_LU = ((v-sol_C_LU).norm())/(v.norm());
	double error_C_QR = ((v-sol_C_QR).norm())/(v.norm());
	cout<<"Relative error of Lu method  3: "<<error_C_LU<<endl;
	cout<<"Relative error of QR method  3: "<<error_C_QR<<endl;


    return 0;
}