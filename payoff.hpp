#ifndef PAY_OFF_HPP
#define PAY_OFF_HPP
#include <algorithm> 
#include<vector>
#include <limits>
// Act on containers through iterators to apply modyfing/non_modifying operations

class PayOff 
	{
		 public:
			//Constructor
			PayOff(){};
			// Virtual destructor to avoid memory leaks when destroying the base and inherited classes
			virtual ~PayOff() {}; 
			// We turn the payoff into a functor, goal is to compute initial condition
			virtual double operator() (const double& S,const double& df = 1) const = 0;
			//virtual double init_cond(const double& S)) const;
	};
	
	
	
	//First payoff class created for european call options
	//It inherits from Payoff
	class PayOffCall : public PayOff 
	{
		public:
		
			PayOffCall(const double& K);
			virtual ~PayOffCall() {};

			// Virtual function is now over-ridden (not pure-virtual anymore)
			virtual double operator() (const double& S,const double& df = 0) const;
			//virtual double init_cond(const double& S)) const;
		  
		 private:
		 
			double m_K; // Variable for the Strike price

		 
	};
#endif