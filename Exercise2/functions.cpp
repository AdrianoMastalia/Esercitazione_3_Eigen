#include"Eigen/Eigen"
#include"functions.hpp"

using namespace Eigen;

void PALU_solution (const Matrix2d &A, const Vector2d &b, const Vector2d &v_sol, double &err)
{
	/* I chose the partial PivLu because the matrix A is invertible, 
	to improve speed. There is less accuracy with respect to FullPiv,
	but as I'll calculate ther's still an efficient accuracy */
	
	Vector2d PALU_sol = A.partialPivLu().solve(b);
	
	/* Calculation of the relative error using the .norm() method from Eigen */
	
	err = ((v_sol-PALU_sol).norm())/(v_sol.norm());
}

void QR_solution (const Matrix2d &A, const Vector2d &b, const Vector2d &v_sol, double &err)
{
	/* Since the dimension of the matrix is small, I chose householderQR,
	because it's the fastest QR decomposition for small matrices,
	according to the official Eigen documentation*/
	
	Vector2d QR_sol = A.householderQr().solve(b);
	err = ((v_sol-QR_sol).norm())/(v_sol.norm());
}