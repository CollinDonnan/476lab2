/*
  Author     : Gary M. Zoppetti
  Description: Do a BLAS multiply for testing correctness.
               Also include a routine for testing equality between matrices.
*/

#include <algorithm>
#include <concepts>
#include <limits>
#include <openblas64/cblas.h>
#include <type_traits>

#include "Matrix.hpp"

template<typename T>
void
multiplyBlas (Matrix<T>& C, Matrix<T> const& A, Matrix<T> const& B)
{
  static_assert (std::is_floating_point_v<T>,
                 "This logic only works for FP types");
  
  // TODO
  
  // Use CBLAS general matrix-matrix multiplication
  // C = alpha (A x B) + beta (C)
  if constexpr (// test for float)
  {
    cblas_sgemm (...); 
  }
  else if constexpr (// test for double)
  {
    cblas_dgemm (...);
  }
}

template<typename T>
bool
equalMatrices (Matrix<T> const& C1, Matrix<T> const& C2)
{
  auto equalityChecker { [N = C1.order ()] (auto a, auto b)
                         {
                           if constexpr (std::is_floating_point_v<T>)
                           {
                             T absA = std::abs (a);
                             T absB = std::abs (b);
                             T diff = std::abs (a - b);
                             T eps = std::numeric_limits<T>::epsilon ();
                             T tolerance =
                               100 * eps * N *
                               std::max ({ static_cast<T> (1), absA, absB });

                             return diff < tolerance;
                           }
                           else
                             return a == b;
                         } };

  return std::ranges::equal (C1, C2, equalityChecker);
}