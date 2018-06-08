#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

double quantile(arma::vec d, double confidence_level) {
  vec sorted = sort(d);

  int confidence_level_index = (d.n_elem - 1) * confidence_level;
  int x_floor = floor(confidence_level_index);

  vec interpolation_result;

  vec x; 
  x << x_floor << x_floor + 1;

  vec xx;
  xx << confidence_level_index;

  vec y = sorted(span(x_floor, x_floor+1));

  interp1(x, y, xx, interpolation_result);

  //cout << x << " y: " << y << " xx: " << xx << "  YY " << YY << endl; 

  return interpolation_result[0];
}

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


  mat QQ = randn<vec>(10123);
  
  cout << "Quantile(" << size(QQ) << ") max: " << max(QQ) << "  = " <<  quantile(QQ, 0.9599) << endl;
 /* 
  
  mat B = randu<mat>(4,5);

  mat C = zeros<mat>(size(A));
  mat CP = mat(A);

  cout << A << endl;
  cout << CP << endl;
  cout << size(A) << endl;
  cout << A*B.t() << endl;
*/
  cout << A(1,2) << endl;

  A(1,2) = 0.666666;

  cout << A(1,2)*A(1,2)<< endl;


  cube cy = randu<cube>(4,8,8);

  mat ze = zeros<mat>(8,8);

  cy(span(0), span::all, span::all) = ze;

  cout << A << endl;

  cout << sum(A, 1) << endl;

  //normalizing rows
  vec su = sum(A, 1);
  A.each_col( [su](vec& val) { val = val/su; } );

  cout << A << endl;

  cout << sum(A, 1) << endl;

  mat N = ones<mat>(3,3);
  N(0,0) = 5.0;
  cout << N << endl;

  //better normalize
  cout << normalise(N, 1, 1) << endl;

  mat transition_matrix = other_data(span(1, 8), span(span::all));

  transition_matrix(7,7) = 1.1;
  transition_matrix(6,7) = 0.1;

  cout << transition_matrix << endl;
  cout << normalise(transition_matrix, 1, 1) << endl;

  return 0;
}
