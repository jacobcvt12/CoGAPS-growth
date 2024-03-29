#include <iostream>
#include "sub_func.h"
#include <stdexcept>

using std::logic_error;

namespace gaps {

double sub_func::pexp(double p, double rate, bool boolpara1, bool boolpara2) {
    boost::math::exponential_distribution<> exp(rate);
    double pexp_val = cdf(exp, p);
    return pexp_val;
}

double sub_func::qexp(double q, double rate, bool boolpara1, bool boolpara2) {
    boost::math::exponential_distribution<> exp(rate);
    double qexp_val = quantile(exp, q);
    return qexp_val;
}

double sub_func::dgamma(double newMass, double shape, double scale, bool boolpara) {
    boost::math::gamma_distribution<> gam(shape, scale);
    double dgamma_val = pdf(gam, newMass);
    return dgamma_val;
}

double sub_func::pgamma(double p, double shape, double scale, bool boolpara1, bool boolpara2) {
    boost::math::gamma_distribution<> gam(shape, scale);
    double pgamma_val = cdf(gam, p);
    return pgamma_val;
}

double sub_func::qgamma(double q, double shape, double scale, bool boolpara1, bool boolpara2) {
    boost::math::gamma_distribution<> gam(shape, scale);
    double qgamma_val = quantile(gam, q);
    return qgamma_val;
}

double sub_func::dnorm(double u, double mean, double sd, bool unknown) {
    boost::math::normal_distribution<> norm(mean, sd);
    double dnorm_val = pdf(norm, u);
    return dnorm_val;
}

double sub_func::qnorm(double q, double mean, double sd, double INF_Ref, double unknown) {
    boost::math::normal_distribution<> norm(mean, sd);
    double qnorm_val = quantile(norm, q);
    return qnorm_val;
}

double sub_func::pnorm(double p, double mean, double sd, double INF_Ref, double unknown) {
    boost::math::normal_distribution<> norm(mean, sd);
    double pnorm_val = cdf(norm, p);
    return pnorm_val;
}

double sub_func::runif(double a, double b) {
    if (b < a) {
        throw logic_error("error");

    } else if (a == b) {
        return a;

    } else {
        double rng = randgen('U', 0, 0);
        return a + (b - a) * rng; // ----- temp! used at the moment
    }
}

arma::vec dmvnorm(arma::mat x, arma::rowvec mean, arma::mat sigma) {
    double log2pi = std::log(2.0 * M_PI);

    int n = x.n_rows;
    int xdim = x.n_cols;
    arma::vec out(n);
    arma::mat rooti = arma::trans(arma::inv(trimatu(arma::chol(sigma))));
    double rootisum = arma::sum(log(rooti.diag()));
    double constants = -(static_cast<double>(xdim)/2.0) * log2pi;

    for (int i=0; i < n; i++) {
        arma::vec z = rooti * arma::trans( x.row(i) - mean) ;    
        out(i)      = constants - 0.5 * arma::sum(z%z) + rootisum;     
    }  

    out = exp(out);

    return(out);
}

}
