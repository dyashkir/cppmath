#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;



int main()
{
  //
  const int num_steps = 252;
  const int step_size = 1; 

  vec a = linspace<vec>(0, num_steps * step_size, num_steps + 1);
  cout << a << endl;


  //

  mat A_zeros = zeros<mat>(8,8);
  //
  mat A = randu<mat>(8,8);
  mat cube_of_A = A * A * A;
  cout << size(cube_of_A) << endl;
  cout << cube_of_A << endl;

  cout << A * A << endl;
  cout << cube_of_A * A.i() << endl;

  //
  cout << a.n_elem << endl;

  vec new_zero_a = zeros(size(a));
  cout << new_zero_a << endl;

  for(auto i:a) {
    cout << i;
  }

  cout << endl;
  mat loadCSV;

  loadCSV.load("../data/test.csv");
  cout <<  loadCSV << endl << size(loadCSV) << endl;

  mat other_data;
  other_data.load("../data/transition_matrix.csv");
  cout << size(other_data) << endl << other_data;

 /* 
  
  mat B = randu<mat>(4,5);

  mat C = zeros<mat>(size(A));
  mat CP = mat(A);

  cout << A << endl;
  cout << CP << endl;
  cout << size(A) << endl;
  cout << A*B.t() << endl;
*/
  return 0;
}
