#ifndef EOS_HPP
#define EOS_HPP
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
// equation of state class taking a path to a (specifically formatted) tabulated EoS file as input
class EOS{
    public:
        EOS(std::string);
        ~EOS();
        double p_at_e(double) const; // evaluate pressure at given energy density
        double e_at_p(double) const; // evaluate energy density at given pressure
        double p_at_h(double) const; // evaluate pressure at given enthalpy
        double h_at_p(double) const; // evaluate enthalpy at given pressure
        double rho_at_p(double) const; // evaluate density at given pressure
    public:
        double e_surface,p_surface;
    private:
        int i,n_tab; // number of tabulated points in tabulated EoS
        double p,rho,h,n0; // tabulated EoS file parameters
        FILE* f_eos; //t abulated EoS file
        std::vector<double> log_e_tab,log_p_tab,log_h_tab,log_n0_tab,log_rho_tab; //log tabulated EoS parameters
};
#endif