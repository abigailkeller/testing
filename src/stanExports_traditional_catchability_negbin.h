// Generated by rstantools.  Do not edit by hand.

/*
    eDNAjoint is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    eDNAjoint is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with eDNAjoint.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_traditional_catchability_negbin_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_traditional_catchability_negbin");
    reader.add_event(49, 47, "end", "model_traditional_catchability_negbin");
    return reader;
}
#include <stan_meta_header.hpp>
class model_traditional_catchability_negbin
  : public stan::model::model_base_crtp<model_traditional_catchability_negbin> {
private:
        int C;
        std::vector<int> R;
        int Nloc;
        std::vector<int> E;
        int nparams;
        matrix_d mat;
public:
    model_traditional_catchability_negbin(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_traditional_catchability_negbin(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_traditional_catchability_negbin_namespace::model_traditional_catchability_negbin";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "C", "int", context__.to_vec());
            C = int(0);
            vals_i__ = context__.vals_i("C");
            pos__ = 0;
            C = vals_i__[pos__++];
            check_greater_or_equal(function__, "C", C, 1);
            current_statement_begin__ = 3;
            validate_non_negative_index("R", "C", C);
            context__.validate_dims("data initialization", "R", "int", context__.to_vec(C));
            R = std::vector<int>(C, int(0));
            vals_i__ = context__.vals_i("R");
            pos__ = 0;
            size_t R_k_0_max__ = C;
            for (size_t k_0__ = 0; k_0__ < R_k_0_max__; ++k_0__) {
                R[k_0__] = vals_i__[pos__++];
            }
            size_t R_i_0_max__ = C;
            for (size_t i_0__ = 0; i_0__ < R_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "R[i_0__]", R[i_0__], 1);
            }
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "Nloc", "int", context__.to_vec());
            Nloc = int(0);
            vals_i__ = context__.vals_i("Nloc");
            pos__ = 0;
            Nloc = vals_i__[pos__++];
            check_greater_or_equal(function__, "Nloc", Nloc, 1);
            current_statement_begin__ = 5;
            validate_non_negative_index("E", "C", C);
            context__.validate_dims("data initialization", "E", "int", context__.to_vec(C));
            E = std::vector<int>(C, int(0));
            vals_i__ = context__.vals_i("E");
            pos__ = 0;
            size_t E_k_0_max__ = C;
            for (size_t k_0__ = 0; k_0__ < E_k_0_max__; ++k_0__) {
                E[k_0__] = vals_i__[pos__++];
            }
            size_t E_i_0_max__ = C;
            for (size_t i_0__ = 0; i_0__ < E_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "E[i_0__]", E[i_0__], 0);
            }
            current_statement_begin__ = 6;
            context__.validate_dims("data initialization", "nparams", "int", context__.to_vec());
            nparams = int(0);
            vals_i__ = context__.vals_i("nparams");
            pos__ = 0;
            nparams = vals_i__[pos__++];
            check_greater_or_equal(function__, "nparams", nparams, 0);
            current_statement_begin__ = 7;
            validate_non_negative_index("mat", "C", C);
            validate_non_negative_index("mat", "nparams", nparams);
            context__.validate_dims("data initialization", "mat", "matrix_d", context__.to_vec(C,nparams));
            mat = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(C, nparams);
            vals_r__ = context__.vals_r("mat");
            pos__ = 0;
            size_t mat_j_2_max__ = nparams;
            size_t mat_j_1_max__ = C;
            for (size_t j_2__ = 0; j_2__ < mat_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < mat_j_1_max__; ++j_1__) {
                    mat(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 12;
            validate_non_negative_index("mu", "Nloc", Nloc);
            num_params_r__ += (1 * Nloc);
            current_statement_begin__ = 13;
            num_params_r__ += 1;
            current_statement_begin__ = 14;
            validate_non_negative_index("q_trans", "nparams", nparams);
            num_params_r__ += nparams;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_traditional_catchability_negbin() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 12;
        if (!(context__.contains_r("mu")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        validate_non_negative_index("mu", "Nloc", Nloc);
        context__.validate_dims("parameter initialization", "mu", "double", context__.to_vec(Nloc));
        std::vector<double> mu(Nloc, double(0));
        size_t mu_k_0_max__ = Nloc;
        for (size_t k_0__ = 0; k_0__ < mu_k_0_max__; ++k_0__) {
            mu[k_0__] = vals_r__[pos__++];
        }
        size_t mu_i_0_max__ = Nloc;
        for (size_t i_0__ = 0; i_0__ < mu_i_0_max__; ++i_0__) {
            try {
                writer__.scalar_lb_unconstrain(0, mu[i_0__]);
            } catch (const std::exception& e) {
                stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu: ") + e.what()), current_statement_begin__, prog_reader__());
            }
        }
        current_statement_begin__ = 13;
        if (!(context__.contains_r("phi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable phi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("phi");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "phi", "double", context__.to_vec());
        double phi(0);
        phi = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, phi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable phi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 14;
        if (!(context__.contains_r("q_trans")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable q_trans missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("q_trans");
        pos__ = 0U;
        validate_non_negative_index("q_trans", "nparams", nparams);
        context__.validate_dims("parameter initialization", "q_trans", "vector_d", context__.to_vec(nparams));
        Eigen::Matrix<double, Eigen::Dynamic, 1> q_trans(nparams);
        size_t q_trans_j_1_max__ = nparams;
        for (size_t j_1__ = 0; j_1__ < q_trans_j_1_max__; ++j_1__) {
            q_trans(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_lb_unconstrain(-(0.99999), q_trans);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable q_trans: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 12;
            std::vector<local_scalar_t__> mu;
            size_t mu_d_0_max__ = Nloc;
            mu.reserve(mu_d_0_max__);
            for (size_t d_0__ = 0; d_0__ < mu_d_0_max__; ++d_0__) {
                if (jacobian__)
                    mu.push_back(in__.scalar_lb_constrain(0, lp__));
                else
                    mu.push_back(in__.scalar_lb_constrain(0));
            }
            current_statement_begin__ = 13;
            local_scalar_t__ phi;
            (void) phi;  // dummy to suppress unused var warning
            if (jacobian__)
                phi = in__.scalar_lb_constrain(0, lp__);
            else
                phi = in__.scalar_lb_constrain(0);
            current_statement_begin__ = 14;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> q_trans;
            (void) q_trans;  // dummy to suppress unused var warning
            if (jacobian__)
                q_trans = in__.vector_lb_constrain(-(0.99999), nparams, lp__);
            else
                q_trans = in__.vector_lb_constrain(-(0.99999), nparams);
            // transformed parameters
            current_statement_begin__ = 18;
            validate_non_negative_index("coef", "C", C);
            std::vector<local_scalar_t__> coef(C, local_scalar_t__(0));
            stan::math::initialize(coef, DUMMY_VAR__);
            stan::math::fill(coef, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 20;
            for (int i = 1; i <= C; ++i) {
                current_statement_begin__ = 21;
                stan::model::assign(coef, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            (1 + dot_product(get_base1(mat, i, "mat", 1), q_trans)), 
                            "assigning variable coef");
            }
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 18;
            size_t coef_k_0_max__ = C;
            for (size_t k_0__ = 0; k_0__ < coef_k_0_max__; ++k_0__) {
                if (stan::math::is_uninitialized(coef[k_0__])) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: coef" << "[" << k_0__ << "]";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable coef: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            // model body
            current_statement_begin__ = 29;
            for (int j = 1; j <= C; ++j) {
                current_statement_begin__ = 31;
                lp_accum__.add(neg_binomial_2_log<propto__>(get_base1(E, j, "E", 1), (get_base1(coef, j, "coef", 1) * get_base1(mu, get_base1(R, j, "R", 1), "mu", 1)), phi));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("mu");
        names__.push_back("phi");
        names__.push_back("q_trans");
        names__.push_back("coef");
        names__.push_back("q");
        names__.push_back("log_lik");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(Nloc);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(nparams);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(C);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(nparams);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(C);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_traditional_catchability_negbin_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        std::vector<double> mu;
        size_t mu_d_0_max__ = Nloc;
        mu.reserve(mu_d_0_max__);
        for (size_t d_0__ = 0; d_0__ < mu_d_0_max__; ++d_0__) {
            mu.push_back(in__.scalar_lb_constrain(0));
        }
        size_t mu_k_0_max__ = Nloc;
        for (size_t k_0__ = 0; k_0__ < mu_k_0_max__; ++k_0__) {
            vars__.push_back(mu[k_0__]);
        }
        double phi = in__.scalar_lb_constrain(0);
        vars__.push_back(phi);
        Eigen::Matrix<double, Eigen::Dynamic, 1> q_trans = in__.vector_lb_constrain(-(0.99999), nparams);
        size_t q_trans_j_1_max__ = nparams;
        for (size_t j_1__ = 0; j_1__ < q_trans_j_1_max__; ++j_1__) {
            vars__.push_back(q_trans(j_1__));
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 18;
            validate_non_negative_index("coef", "C", C);
            std::vector<double> coef(C, double(0));
            stan::math::initialize(coef, DUMMY_VAR__);
            stan::math::fill(coef, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 20;
            for (int i = 1; i <= C; ++i) {
                current_statement_begin__ = 21;
                stan::model::assign(coef, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            (1 + dot_product(get_base1(mat, i, "mat", 1), q_trans)), 
                            "assigning variable coef");
            }
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            // write transformed parameters
            if (include_tparams__) {
                size_t coef_k_0_max__ = C;
                for (size_t k_0__ = 0; k_0__ < coef_k_0_max__; ++k_0__) {
                    vars__.push_back(coef[k_0__]);
                }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 38;
            validate_non_negative_index("q", "nparams", nparams);
            Eigen::Matrix<double, Eigen::Dynamic, 1> q(nparams);
            stan::math::initialize(q, DUMMY_VAR__);
            stan::math::fill(q, DUMMY_VAR__);
            current_statement_begin__ = 39;
            validate_non_negative_index("log_lik", "C", C);
            Eigen::Matrix<double, Eigen::Dynamic, 1> log_lik(C);
            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik, DUMMY_VAR__);
            // generated quantities statements
            current_statement_begin__ = 41;
            stan::math::assign(q, add(q_trans, 1));
            current_statement_begin__ = 43;
            for (int j = 1; j <= C; ++j) {
                current_statement_begin__ = 44;
                stan::model::assign(log_lik, 
                            stan::model::cons_list(stan::model::index_uni(j), stan::model::nil_index_list()), 
                            neg_binomial_2_log(get_base1(E, j, "E", 1), (get_base1(coef, j, "coef", 1) * get_base1(mu, get_base1(R, j, "R", 1), "mu", 1)), phi), 
                            "assigning variable log_lik");
            }
            // validate, write generated quantities
            current_statement_begin__ = 38;
            size_t q_j_1_max__ = nparams;
            for (size_t j_1__ = 0; j_1__ < q_j_1_max__; ++j_1__) {
                vars__.push_back(q(j_1__));
            }
            current_statement_begin__ = 39;
            size_t log_lik_j_1_max__ = C;
            for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
                vars__.push_back(log_lik(j_1__));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_traditional_catchability_negbin";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t mu_k_0_max__ = Nloc;
        for (size_t k_0__ = 0; k_0__ < mu_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        size_t q_trans_j_1_max__ = nparams;
        for (size_t j_1__ = 0; j_1__ < q_trans_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "q_trans" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t coef_k_0_max__ = C;
            for (size_t k_0__ = 0; k_0__ < coef_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "coef" << '.' << k_0__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
        size_t q_j_1_max__ = nparams;
        for (size_t j_1__ = 0; j_1__ < q_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "q" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t log_lik_j_1_max__ = C;
        for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t mu_k_0_max__ = Nloc;
        for (size_t k_0__ = 0; k_0__ < mu_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        size_t q_trans_j_1_max__ = nparams;
        for (size_t j_1__ = 0; j_1__ < q_trans_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "q_trans" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t coef_k_0_max__ = C;
            for (size_t k_0__ = 0; k_0__ < coef_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "coef" << '.' << k_0__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
        size_t q_j_1_max__ = nparams;
        for (size_t j_1__ = 0; j_1__ < q_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "q" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t log_lik_j_1_max__ = C;
        for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
    }
}; // model
}  // namespace
typedef model_traditional_catchability_negbin_namespace::model_traditional_catchability_negbin stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
