% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/gapsMapTestRun.R
\name{gapsMapTestRun}
\alias{gapsMapTestRun}
\title{\code{gapsMapTestRun} calls the C++ MCMC code and performs Bayesian
matrix factorization returning the two matrices that reconstruct
the data matrix; as opposed to gapsRun, this method takes an
additional input specifying set patterns in the P matrix}
\usage{
gapsMapTestRun(D, S, FP, ABins = data.frame(), PBins = data.frame(),
  nFactor = 7, simulation_id = "simulation", nEquil = 1000,
  nSample = 1000, nOutR = 1000, output_atomic = FALSE,
  fixedMatrix = "P", fixedBinProbs = FALSE, fixedDomain = "N",
  alphaA = 0.01, nMaxA = 1e+05, max_gibbmass_paraA = 100, alphaP = 0.01,
  nMaxP = 1e+05, max_gibbmass_paraP = 100)
}
\arguments{
\item{D}{data matrix}

\item{S}{uncertainty matrix (std devs for chi-squared of Log Likelihood)}

\item{FP}{data.frame with rows giving fixed patterns for P}

\item{ABins}{a matrix of same size as A which gives relative
probability of that element being non-zero}

\item{PBins}{a matrix of same size as P which gives relative
probability of that element being non-zero}

\item{nFactor}{number of patterns (basis vectors, metagenes), which must be
greater than or equal to the number of rows of FP}

\item{simulation_id}{name to attach to atoms files if created}

\item{nEquil}{number of iterations for burn-in}

\item{nSample}{number of iterations for sampling}

\item{nOutR}{how often to print status into R by iterations}

\item{output_atomic}{whether to write atom files (large)}

\item{fixedMatrix}{character indicating whether A or P matrix
has fixed columns or rows respectively}

\item{fixedBinProbs}{Boolean for using relative probabilities
given in Abins and Pbins}

\item{fixedDomain}{character to indicate whether A or P is
domain for relative probabilities}

\item{alphaA}{sparsity parameter for A domain}

\item{nMaxA}{PRESENTLY UNUSED, future = limit number of atoms}

\item{max_gibbmass_paraA}{limit truncated normal to max size}

\item{alphaP}{sparsity parameter for P domain}

\item{nMaxP}{PRESENTLY UNUSED, future = limit number of atoms}

\item{max_gibbmass_paraP}{limit truncated normal to max size}
}
\description{
\code{gapsMapTestRun} calls the C++ MCMC code and performs Bayesian
matrix factorization returning the two matrices that reconstruct
the data matrix; as opposed to gapsRun, this method takes an
additional input specifying set patterns in the P matrix
}
