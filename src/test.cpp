#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
  mat A = randu<mat>(4,5);
  mat B = randu<mat>(4,5);

  mat C = zeros<mat>(size(A));
  mat CP = mat(A);

  cout << A << endl;
  cout << CP << endl;
  cout << size(A) << endl;
  cout << A*B.t() << endl;

  return 0;
}
