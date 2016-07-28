#ifndef FOLDHEADERDEF
#define FOLDHEADERDEF

#include <iostream>
#include <armadillo>
#include "AbstractNonlinearProblem.hpp"
#include "AbstractNonlinearProblemJacobian.hpp"

class Fold:
  public AbstractNonlinearProblem,
  public AbstractNonlinearProblemJacobian
{

  public:

    //Specialised constructor
    Fold(const arma::vec* pParameters);

    // Destructor
    ~Fold();

    // Right-hand side
    void ComputeF(const arma::vec& u, arma::vec& f);

    // Jacobian
    void ComputeDFDU(const arma::vec& u, arma::mat& dfdu);

    // Set parameters
    void SetParameters(const arma::vec& val);

    // For assessing stability
    friend bool ComputeStability(const arma::vec& val);

  private:

    // Hiding default constructor
    Fold();

    // Parameters
    arma::vec* mpParameters;

};

bool ComputeStability(const arma::vec& val);

#endif
