#include<iostream>
#include "paddyBase.h"
#include "paddySaleInfo.h"
using namespace std;

class paddyApps : public paddyBase{   //inheritance: from paddyBase class (do all method to calculate all required data)
	private:
		paddySaleInfo saleInfo;       //composition: from paddySaleInfo class
		float pdPrice, subsidy, yield, incentive, totalCost, totalRevenue;
		string productivity;
		
	public:
		void setBaseData(float p, float q, float r){   //mutator: set paddy base data
			setPaddyBase(p,q,r);
		}
		void setInfoData(string n, string iD,float size, float weight, float deduct){  //mutator: set paddy info data
			saleInfo.setPDSale(n, iD, size, weight, deduct);  
		}
		
		void calNetWeight(){                                        //calculate net weight
			saleInfo.calNetWeight();
		}
		
		void caclPdPrice(){                                         //calculate paddy price
			pdPrice= saleInfo.getNetWeight() * getPdBasePrice();
		}
		
		void calSubsidy(){                                          //calculate subsidy
			subsidy= saleInfo.getNetWeight() * getPdSubcdPrice();
		}
		
		void calYield(){                                            //calculate yield
			yield= saleInfo.getNetWeight()/saleInfo.getsizePDField();
		}
		
		void calProductivity(){                                     //calculate productivity
			if(yield > 1.5){
				productivity= "High";
				incentive=200 * saleInfo.getsizePDField();
			}
			
			else if(yield>=1 && yield <=1.5){                       
				productivity= "Moderate";
				incentive=0;
			}
			
			else{
				productivity= "Low";
				incentive=0;
			}
		}
		
		
		
		void calTotalCost(){                                      //calculate total cost
			totalCost=saleInfo.getsizePDField() * getpdPlantCost();
		}
		
		void calTotalRevenue(){                                   //calculate total revenue
			totalRevenue = pdPrice + subsidy + incentive - totalCost;
		}
		
		string getProductivity(){                                 //accessor: get productivity
			return productivity;
		}
		
		string getID(){                                           //accessor: get ID
			return saleInfo.getID();
		}
		
		string getName(){                                         //accessor: get Name
			return saleInfo.getName();
		}
		
		float getIncentive(){                                     //accessor: get incentive
			return incentive;
		}
		
		float gettotalrevenue(){                                  // accessor: get total revenue
			return totalRevenue;
		}
		
		void display1(){                                          //display paddy base info
			cout << "\n\n\n\tPaddy price per ton: RM " << getPdBasePrice();
			cout << "\n\tSubsidy per ton: RM " << getPdSubcdPrice();
			cout << "\n\tCost planting paddy per relong: RM " << getpdPlantCost() << endl;
		}
		
		void display2(){                                         //display paddy sale info
			cout << "\n\tName:" <<saleInfo.getName();
			cout << "\n\tFarmer ID: " <<  saleInfo.getID();
			cout << "\n\tPaddy Field Size: " << saleInfo.getsizePDField() << " relong";
			cout << "\n\tPaddy Weight: " << saleInfo.getPD_weight() << " tons";
			cout << "\n\tDeduction in %: " << saleInfo.getweight_deduct();
			cout << "\n\tNet weight: " << saleInfo.getNetWeight() << " tons"<< endl;
		}
		
		void display3(){                                          //display paddy revenue info
			cout << "\n\tPaddy Price: RM " << pdPrice;
			cout << "\n\tSubsidy: RM " << subsidy;
			cout << "\n\tProductivity: " << productivity;
			cout << "\n\tIncentive: RM " << incentive;
			cout << "\n\tTotal cost " << saleInfo.getsizePDField() << " relong: RM " << totalCost;
			cout << "\n\tTotal Revenue: RM " << totalRevenue << endl;
		}
		
		paddyApps():paddyBase(0,0,0){                             //constructor
			paddySaleInfo("none", "none", 0, 0, 0);
			pdPrice=subsidy=yield=incentive=totalCost=totalRevenue=0;
		    productivity= " ";
			
		}
		
		~paddyApps(){                                             //destructor
		}
		
		friend void inputData(paddyApps& app);	                  //friend fuction: input sale info
};

void inputData(paddyApps& app){
	string name, ID;
    float  size, weight, deduct;
    
    cout << "\n\t..................... MyPaddy Input Sale Information ......................";
    cout << "\n\n\t1 Tons = 1000kg";
    cout << "\n\t1 Relong = 30,976 square feet";
    cout << "\n\n\tName: ";
    cin.ignore();       //Ignore any previous input
    getline(cin, name);
    cout << "\tFarmer ID: ";
    getline(cin, ID);
    cout << "\tPaddy Field Size in Relong: ";
    do{
    	cin >> size;
    	
    	if(cin.fail() || size <= 0){
            cout << "\tInput must be in non-numerical value and more than 0, Enter again: ";
        	cin.clear();
            cin.ignore(10000000000, '\n');
		}
	}while (cin.fail() || size <= 0);
     

    cout << "\tPaddy Weight (tons): ";
    do {
    	cin >> weight;
    	if (cin.fail() || weight <=0) {
        cout << "\tInput must be in non-numerical value, Enter again: ";
        cin.clear();
        cin.ignore(10000000000, '\n');
        }
    } while (cin.fail() || weight<=0);


    
    cout << "\tDeduction in % (Min:0|Max:10): ";
    
    
    do{
    	cin >> deduct;
    	if(deduct<0 || deduct>10 || cin.fail()){
    		cout << "\tPlease enter correct deduction value(Min:0|Max:10): ";
        	cin.clear();
            cin.ignore(10000000000, '\n');
		}
		
		else
		break;
		
	}while (true);
	
	
    app.setInfoData(name, ID, size, weight, deduct);
    app.calNetWeight();
    app.caclPdPrice();
    app.calYield();
    app.calProductivity();
    app.calSubsidy();
    app.calTotalCost();
    app.calTotalRevenue();
}
