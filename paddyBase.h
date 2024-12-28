#include<iostream>
using namespace std;

class paddyBase{    //class paddyBase to store all three base price(base price, subsidy price, plant cost)
	private:
    	float pdBasePrice;
		float pdSubcdPrice;
		float pdPlantCost;
		
	public:
		void setPaddyBase(float p, float q, float r){ //mutator
			pdBasePrice=p;
			pdSubcdPrice=q;
			pdPlantCost=r;
		}
		
		float getPdBasePrice(){                       //accessor to get PdBasePrice
		return pdBasePrice;
		}
		
		float getPdSubcdPrice(){                     //accessor to get PdSubcdPrice
		return pdSubcdPrice;
		}
		
		
    	float getpdPlantCost(){                      //accessor to get pdPlantCost
		return pdPlantCost;
		}
		
		paddyBase(){                                 //default constructor
			pdBasePrice=0;
			pdSubcdPrice=0;
			pdPlantCost=0;
		}
		
		paddyBase(float p, float q, float r){        //parameterized constructor
			pdBasePrice=p;
			pdSubcdPrice=q;
			pdPlantCost=r;
		}
        
		
		~paddyBase(){                                 //default destructor
		}
		
};
