#include<iostream>
using namespace std;

class paddySaleInfo{ //class paddySaleInfo to store sale information(farmer name, ID, size field, paddy weight, weight deduction, net weight)
	private:
		string f_name;
		string f_ID;
		float sizePDField;
		float PD_weight;
		float weight_deduct;
		float netWeight;
		
	public:
		void setPDSale(string n, string iD, float size, float weight, float deduct){ //mutator
			f_name=n;
			f_ID=iD;
			sizePDField=size;
			PD_weight=weight;
			weight_deduct=deduct;	
		}
		
		string getName(){  //accessor farmer name
			return f_name;
		}
		
		string getID(){   // accessor farmer ID
			return f_ID;
		}
		
		void calNetWeight(){                                    //method to calculate net weight
			netWeight=PD_weight*((100-weight_deduct)/100.0); 
		}	
		
		 float getsizePDField(){    // accessor paddy field size
        	return sizePDField;
		}
		
		float getPD_weight(){       // accessor paddy weight
        	return PD_weight;
		}
		
		float getweight_deduct(){   // accessor weight deduction
        	return weight_deduct;
		}
		
        float getNetWeight(){       // accessor net weight
        	return netWeight;
		}
		
		paddySaleInfo(){}           // default constructor
		
		paddySaleInfo(string n, string iD, float size, float weight, float deduct){  // parameterized constructor
			f_name=n;
			f_ID=iD;
			sizePDField=size;
			PD_weight=weight;
			weight_deduct=deduct;
		}
		
		~paddySaleInfo(){}     //default destructor
		
};
