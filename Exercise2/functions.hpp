#pragma once
#include"Eigen/Eigen"

using namespace Eigen;

/* Declarations of the functions used in the program, I passed matrices and vectors by reference
to save memory (they are quite expensive), err is not const since it has to be updated by the functions
and printed in the main */

void PALU_solution (const Matrix2d &A, const Vector2d &b, const Vector2d &v_sol, double &err);
void QR_solution (const Matrix2d &A, const Vector2d &b, const Vector2d &v_sol, double &err);