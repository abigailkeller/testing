
<!-- README.md is generated from README.Rmd. Please edit that file -->

# eDNAjoint

<img src="man/figures/logo.png" align="right" height="300" />
<!-- badges: start --> <!-- badges: end -->

The goal of *eDNAjoint* is to interpret observations from paired eDNA
and traditional surveys. The package runs a Bayesian model integrates
these two data streams to jointly estimate parameters like the false
positive probability of eDNA detection and expected catch rate at a
site. Optional model variations allow inclusion of site-level covariates
that scale the sensitivity of eDNA sampling relative to traditional
sampling, as well as estimation of catchability coefficients when
multiple traditional gear types are used. Additional functions in the
package facilitate interpretation of model fits.

## Installation

You can install the development version of eDNAjoint:

``` r
#install.packages('xxx', repo='http://repo_adress', type='source')
```

## Example

The main functionality in *eDNAjoint* is the use of `jointModel()` that
will fit the model to data. Further functions like `summarize()` and
`detection.calculate()` can be used to help with model fit
interpretation.

This example fits the joint model to data from paired, replicated eDNA
and seine sampling observations of endangered tidewater gobies
(*Eucyclogobius newberryi*) from a study by Schmelzle and Kinziger
(2016). The following variation of the joint model includes site-level
covariates that scale the sensitivity of eDNA sampling relative to
traditional sampling.

``` r
library(eDNAjoint)
data(gobyData)
# run the joint model with two covariates
goby.fit <- jointModel(data = gobyData, cov=c('Filter_time','Salinity'), 
                       family = 'poisson', p10priors = c(1,20), q=FALSE)
```

And then this model fit can be accessed to do things like summarize the
posterior distribution for the probability of a false positive
detection, $p_{10}$:

``` r
# summarize p10 posterior
summarize(goby.fit, par = 'p10')
#>      mean se_mean    sd 2.5% 97.5%    n_eff Rhat
#> p10 0.001       0 0.001    0 0.003 13971.53    1
```

Or to find the number of eDNA samples and traditional survey samples
necessary to detect presence of the species at a given expected catch
rate:

``` r
# find the number of samples necessary to detect presence at the mean covariate values, 
# if the expected catch rate (mu) is 0.1, 0.5, or 1.
detection.calculate(goby.fit, mu = c(0.1,0.5,1), cov.val=c(0,0))
#>       mu n_traditional n_eDNA
#> [1,] 0.1            24     14
#> [2,] 0.5             5      3
#> [3,] 1.0             3      2
```

You can find much more detailed examples of the functions in *eDNAjoint*
and the model underlying the package in the package vignette.

## References

Keller, A.G., Grason, E.W., McDonald, P.S., Ramon-Laca, A., Kelly, R.P.
(2022). Tracking an invasion front with environmental DNA. *Ecological
Applications*. 32(4): e2561. <https://doi.org/10.1002/eap.2561>

Schmelzle, M.C. and Kinziger, A.P. (2016). Using occupancy modelling to
compare environmental DNA to traditional field methods for
regional-scale monitoring of an endangered aquatic species. *Molecular
Ecology Resources*. 16(4): 895-908.
[https://doi.org/10.1111/1755-0998.12501](https://doi.org/10.1002/eap.2561)
