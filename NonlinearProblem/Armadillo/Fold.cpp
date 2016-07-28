#include <cmath>

#include <iostream>
#include <armadillo>
#include "Fold.hpp"

// Specialised constructor
Fold::Fold(const arma::vec* pParameters)
{
  // Read parameters
  mpParameters = new arma::vec(*pParameters);

}

Fold::~Fold()
{
  delete mpParameters;
}


void Fold::ComputeF(const arma::vec& u, arma::vec& f)
{

  double lambda = (*mpParameters)(0);
  f(0) = lambda - pow( u(0) ,2);
  f(1) = -u(1);

}

void Fold::ComputeDFDU(const arma::vec& u, arma::mat& dfdu)
{
  dfdu(0,0) = -2.0*u(0);
  dfdu(0,1) = 0.0;
  dfdu(1,0) = 0.0;
  dfdu(1,1) = -1.0;
}

void Fold::SetParameters(const arma::vec& val)
{
  (*mpParameters) << val(0);
}

bool ComputeStability(const arma::vec& val)
{
  bool stable = 1;
  for (int j=0;j<2;++j)
  {
    if ( val(j) > 0.0 )
    {
      stable = 0;
      break;
     }
  }
  return stable;
}    
     
     
     
     
