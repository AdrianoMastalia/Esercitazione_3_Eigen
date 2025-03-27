#include<iostream>
#include<iomanip>
#include "Eigen/Eigen"
#include "functions.cpp"

using namespace std;
using namespace Eigen;

int main()
{
	/* Inside v, I put the exact solution, needed in order to compute the relative error */
	
	Vector2d v;
	v << -1.0e+0, -1.0e+0;
	
	/*I create an array of matrices, so I don't have to update a single variable three times,
	obviously, this is correct as long as I know the number of linear systems to solve */
	
	Matrix2d matrices[3];
	matrices[0] <<  5.547001962252291e-01, -3.770900990025203e-02,
	8.320502943378437e-01,-9.992887623566787e-01;
	
	matrices[1] << 5.547001962252291e-01, -5.540607316466765e-01, 
	8.320502943378437e-01, -8.324762492991313e-01;
	
	matrices[2] << 5.547001962252291e-01, -5.547001955851905e-01, 
	8.320502943378437e-01, -8.320502947645361e-01;
	
	/* Now, I create also an array of vectors to solve the linear system */
	
	Vector2d vectors[3];
	vectors[0] << -5.169911863249772e-01, 1.672384680188350e-01;
	vectors[1] << -6.394645785530173e-04, 4.259549612877223e-04;
	vectors[2] << -6.400391328043042e-10, 4.266924591433963e-10;
	
	double error;
	
	for(int i = 0; i<3; i++)
	{
		/*I have to pass to the functions the matrix A, the coefficients vector b, 
		the exact solution v in order to compute the relative error, and the variable 
		error, modified every time by the function and printed inside this cycle to track 
		the different errors related to PALU and QR methods */
		
		PALU_solution(matrices[i],vectors[i],v,error);
		cout<<"Relative error of PALU method on matrix "<<i+1<<" : "<<error<<endl;
		QR_solution(matrices[i],vectors[i],v,error);
		cout<<"Relative error of QR method on matrix "<<i+1<<" : "<<error<<endl;
	}		
}