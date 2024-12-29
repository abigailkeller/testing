functions {
  #include /functions/calc_loglik.stan
  #include /functions/calc_mu.stan
}

data{/////////////////////////////////////////////////////////////////////
    int<lower=1> n_C;    // number of trap samples
    array[n_C] int<lower=1> R_ind;   // index of locations for traditional samples
    int<lower=1> Nloc;   // total number of locations
    array[n_C] real<lower=0> n_E;   // number of animals in sample C
    int<lower=0> nparams;  // number of gear types
    array[n_C] int<lower=1> mat;  // vector of gear type integers
    int<lower=0,upper=1> ctch; // binary indicator of presence of catchability coefficient

}

parameters{/////////////////////////////////////////////////////////////////////
    vector<lower=0>[Nloc] alpha;  // alpha param for gamma distribution
    vector<lower=0.01>[Nloc] beta;  // beta param for gamma distribution
    vector<lower=-0.99999>[nparams] q_trans; // catchability coefficients
    }

transformed parameters{/////////////////////////////////////////////////////////////////////
    real<lower=0> coef[(ctch == 1) ? nparams+1 :  0];
    array[n_C] real<lower=0> E_trans;

    if(ctch == 1)
      coef = to_array_1d(append_row(1, 1+q_trans));

    for(j in 1:n_C){
      E_trans[j] = n_E[j] + 0.0000000000001;
    }
}

model{/////////////////////////////////////////////////////////////////////


    // get lambda
    real lambda[n_C];
    lambda = get_lambda_continuous(ctch, coef, mat, alpha, R_ind, n_C);

    for (j in 1:n_C) {
      E_trans[j] ~ gamma(lambda[j], beta[R_ind[j]]);  // Eq. 1.1
    }

    beta ~ gamma(0.25,0.25);
    alpha ~ gamma(0.01,0.01);

}

generated quantities{
  vector[nparams] q;
  vector[n_C] log_lik;
  matrix[Nloc,nparams+1] mu;  // matrix of catch rates

  ////////////////////////////////////
  // transform to interpretable params
  if(ctch == 1)
    q = q_trans + 1;

  mu = calc_mu_trad_continuous(Nloc, nparams, alpha, beta, q, ctch);

  ////////////////////////////////
  // get point-wise log likelihood

  // get lambda
  log_lik = calc_loglik_tradmod_continuous(beta, E_trans, R_ind, n_C,
                                           ctch, coef, mat, alpha);

}

