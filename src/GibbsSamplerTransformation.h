#ifndef _GIBBSSAMPLERTRANSFORMATION_H_
#define _GIBBSSAMPLERTRANSFORMATION_H_

#include "GibbsSamplerMap.h"
#include <vector>
#include <cmath>
#include <Rcpp.h>
#include <limits>
#include "Abc.h"

class GibbsSamplerTransformation : public GibbsSamplerMap {
  protected:
    // indicates which pattern is growth (will be removed most likely)
    int _whichPattern;

    // vector of case status (assume 0 is non-case) i.e. {0, 0, 0, 1, 1, 1}
    Rcpp::IntegerVector _treatStatus;

    // vector of time recordings
    Rcpp::NumericVector _timeRecorded;

    // current estimates
    Rcpp::NumericMatrix _theta;
    Rcpp::NumericMatrix _thresh;
    Rcpp::NumericVector _epsilon;

    // difference
    Rcpp::NumericVector _tolerance;

    // logistic growth normalization
    double _normalization;

    // ABC-MCMC updated parameters
    Abc _growth;

  public:
    GibbsSamplerTransformation(unsigned long nEquil, unsigned long nSample, unsigned int nFactor,
                               double alphaA, double alphaP, double nMaxA, double nMaxP,
                               unsigned long nIterA, unsigned long nIterP,
                               double max_gibbsmass_paraA, double max_gibbsmass_paraP,
                               unsigned long long atomicSize,
                               char label_A, char label_P, char label_D, char label_S,
                               vector<vector<double> > &DVector, vector<vector<double> > &SVector,
                               const string &simulation_id,
                               vector <vector <double> >  &parameters, char the_fixed_matrix, int whichPattern,
                               std::vector<int> treatStatus, std::vector<double> timeRecorded, 
                               Rcpp::NumericVector theta_init,
                               std::string prior="normal", std::string proposal="normal",
                               bool epsilon_mcmc=false, double delta=10.0, double epsilon=100.0,
                               double epsilon_prior=3.0, double prior_mean=0.0, double prior_sd=10.0,
                               bool fixedproposal=false, bool weightA=true);
    ~GibbsSamplerTransformation() {};

    Rcpp::NumericMatrix theta();
    Rcpp::NumericMatrix thresh();
    Rcpp::NumericVector epsilon();
    
    void abc_mcmc(int burn=0, int iter=0, int thin=1, double tolerance=5.0);

    map <unsigned long long, double> getADomain();
    map <unsigned long long, double> getPDomain();

    void weightAAtomicColumn(double weight=1.0);
    void setMass(unsigned long long location, double weight);
    void weightAColumn(double weight=1.0);
    void updatePRow();
    double calcWeight();

    Rcpp::NumericMatrix getA();
    Rcpp::NumericMatrix getP();

    // track acceptance and total proposals
    unsigned int accepted, proposed;

    // whether or not to weight A
    bool weightA;

    // get relevant column and rows
    Rcpp::NumericVector getAcol();
    Rcpp::NumericVector getProw();

    // current theta
    Rcpp::NumericVector currentTheta();
};

#endif
