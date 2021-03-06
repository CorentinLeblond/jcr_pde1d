
#ifndef BOUND_CONDITIONS_HPP
#define BOUND_CONDITIONS_HPP
#include "mesh_spot.hpp"
#include<cmath>
#include<vector>
#include<algorithm>
#include <limits>
#include <iostream>

// we create a boundaries conditions class and 2 other classes neumann and derichtlet which inherit from it
// boundaries class
	
namespace project{
	
class bound_conditions 
	{
		public:
		
			bound_conditions(const mesh& _grid);
			
		protected:
		
			mesh m_grille;
	
	};
	
	
	class Neumann: public bound_conditions 
	{
		
		public:
		
			Neumann(const mesh& m_grid, const double& theta, const std::vector<double>& sigma, const std::vector<double>& rate);
			
			std::vector<double> get_cond() const;
			std::vector<double> get_coef_neumann() const;
			std::vector<double> matrix_neumann;
			std::vector<double> coef_neumann;
		
	};

	class Derichtlet: public bound_conditions 
	{
		
		public:
		
			Derichtlet(const mesh& m_grid, const std::vector<double>& rate);

			std::vector<double> get_cond() const;
			std::vector<double> matrix_derichtlet;
			
		
	};
}
	
#endif 