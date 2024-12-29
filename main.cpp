

#include<iostream>  
#include<conio.h>   
#include "paddyApps.h"
#include<iomanip>  //preprocessor directive: provide access to "setw()" and "setprecision()".
#include<unistd.h> // preprocessor directive: provide access to "sleep()".
using namespace std;

int main(){
	
	float p, q, r, size, weight, deduct;  
	int input=0, location=0, numFarmer=0, highNum=0, lowNum=0, modNum=0, chances=0, userChoice=0, loc=-1;
	string name, ID, searchID;
	bool proceed=true;
	bool stat=true;
    char choice;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO MYPADDY APPS";
    sleep(1.5);
    system("cls"); 
    cout << "\t\t\t\t\t\tMyPaddy Apps";
    cout << "\n\n\n\tYou need to specify number of farmer first:)";  
	cout << "\n\tInput number of farmer: "; // input no of farmer
	do{
    	cin >> numFarmer;
    	
		if(cin.fail()){                  // user input other than int
			cout << "\tNumber of farmer cannot be alphabet or character, Enter again: ";
        	cin.clear();                // clear error flag
            cin.ignore(10000000000, '\n');  //discard up to 10000000000 character or until newline character is encountered in input buffer
		}
		
		else if(cin.peek() != '\n'){    //user input other float(decimal point value)
			cout << "\tNumber of farmer must be in integer, Enter again: ";
        	cin.clear();
            cin.ignore(10000000000, '\n');
		}
		
		else if(numFarmer<=0 ){   
    		cout << "\tNumber of farmer must be more than 0, Enter again: ";
        	cin.clear();
            cin.ignore(10000000000, '\n');
		}
		
		else
		break;
		
	}while (true);
	
   	system("cls"); 
        		
	paddyApps ob[numFarmer];
	
	do{ 
		cout <<"\n\t--------------------------------\n"; // menu
        cout <<"\t MyPaddy Apps\n"; 
        cout <<"\t--------------------------------\n";
        cout <<"\t 1. Input Paddy Base Information\n"; 
        cout <<"\t 2. Input Paddy Sale Information\n"; 
        cout <<"\t 3. Display Paddy Base Price\n"; 
        cout <<"\t 4. Display Paddy Sale Information \n"; 
        cout <<"\t 5. Display Paddy Revenue Information\n"; 
        cout <<"\t 6. Paddy Apps Summary\n"; 
        cout <<"\t 7. Exit\n"; 
        cout <<"\t Your Choice: "; 
        do {
        	cin >> choice;
        	if (cin.fail() || (choice<'1' || choice>'7') || cin.peek() != '\n' ){
        		if(chances<2){
        			chances++;
            		cout << "\t Please enter right choice: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Clear the entire input buffer
				}
				else {
					cout <<"\n\tYou already try 3 times, please restart again this app in 5 seconds..." << endl;  //tell user to restart app
			    	sleep(5);                                                                                     //delay for 5 second
			    	return 0;
				}
			}
        	
			else {
				chances=0;
				break;
			}
         } while (true);
        cout << fixed << showpoint << setprecision(2);         //get fix 2 decimal point 
        
        switch(choice){
        	case '1':  //input base info
        		system("cls");
        		cout << "\n\t................... MyPaddy Input Paddy Base Information ....................\n";
        		cout << "\n\n\t1 Tons = 1000kg";
        		cout << "\n\t1 Relong = 30,976 square feet";
            	cout << "\n\n\tPaddy price per ton: RM " ;
            	do{
                	cin >> p;
                	if(p<=0 || cin.fail()){
                		cout << "\tPrice must be more than 0, Enter again: ";
                    	cin.clear();
                        cin.ignore(10000000000, '\n');
            		}
		
            		else
            		break;
            	}while (true);
	
            	cout << "\tSubsidy per ton: RM " ;
            	do{
            	cin >> q;
            	if(q<0 || cin.fail()){
            		cout << "\tSubsidy must more or equal to 0, Enter again: ";
                	cin.clear();
                    cin.ignore(10000000000, '\n');
	        	}
		
        		else
        		break;
            	}while (true);
	
         	cout << "\tCost planting paddy per relong: RM " ;
        	do{
        	cin >> r;
        	if(r<=0 || cin.fail()){
       	    cout << "\tCost must be more than 0, Enter again: ";
        	cin.clear();
            cin.ignore(10000000000, '\n');
    		}
		
    		else
    		break;
        	}while (true);
        	
        	
        	for(int i=0; i<numFarmer; i++){
        		ob[i].setPaddyBase(p,q,r);
        		ob[i].calNetWeight();
        		ob[i].caclPdPrice();
                ob[i].calYield();
                ob[i].calProductivity();
                ob[i].calSubsidy();
                ob[i].calTotalCost();
                ob[i].calTotalRevenue();
			}
        	chances=0;
        	cout <<"\n\t";
        	system("pause");
        	system("cls");
			break;
        	
        	case '2': // input sale info
        		system("cls"); 
        		do{
        		stat=true;	
        		for(int i=0; i<numFarmer; i++){
        			cout << "\n\tFarmer: " << i+1 << endl;
        			inputData(ob[i]);
					chances=0;	
					cout << "\n\t";
        		    system("pause");
        			system("cls");
				} 
				
				for(int i=0; i<numFarmer; i++){
					for(int c=i+1; c<numFarmer; c++){
						if(ob[i].getID()==ob[c].getID()){
						cout << "\n\tFarmer " << i+1 << ": " << ob[i].getName() << " and Farmer " 
						<< c+1 << ": " << ob[c].getName() << " cannot have same ID:" << ob[i].getID();
						stat=false;
						break;
				    	}
					}	
				}
				
				if(!stat){
					cout << "\n\tPlease enter again.\n";
				    cout << "\n\t";
				    system("pause");
				    system("cls");
				}
				
				}while(!stat);
				break;
				
		    case '3':  //display base info
		    	system("cls"); 
		    	cout << "\n\t...................Paddy Base Information....................";
		    	ob[0].display1();
		    	chances=0;
		    	cout <<"\n\t";
		    	system("pause");
				system("cls"); 
		    	break;
		    
		    case '4': //display sale info
				system("cls"); 
		    	cout << "\n\t................... MyPaddy Sales Information ....................\n";
		    	cout << "\n\t 1. Display all farmer information";
		    	cout << "\n\t 2. Dislpay information based on farmer ID";
				cout << "\n\t Your choice:";
		    	do{
		    		cin >> userChoice;
		    		if(userChoice!=1 && userChoice!=2 || cin.fail() || cin.peek() != '\n'){
		    			cout << "\t Please Enter Correct Choice: ";
		    			cin.clear();
                        cin.ignore(10000000000, '\n');
					}
					
					else
					break;
				}while(true);
				
				if(userChoice==1){ //for display all condition
					system("cls");
					cout << "\n\t................... MyPaddy Sales Information ....................";
					for(int i=0; i<numFarmer; i++){
		    		cout << "\n\n\tFarmer: " << i+1 ;
		    		ob[i].display2();
		    		cout << "\n\t\t~ * ~ ";
				    }
				    chances=0;
				    cout <<"\n\t";
				    system("pause");
		    		system("cls");
				}
		    	 
		    	else if(userChoice==2){ //for display based on ID condition
		    		system("cls");
					cout << "\n\t................... MyPaddy Sales Information ....................\n";
		    		cout << "\n\tEnter Farmer ID:";
		    		cin.ignore();
		    		getline(cin , searchID);
		    		
		    		for(int i=0; i<numFarmer; i++){
		    			if(searchID==ob[i].getID()){
		    				loc=i;
		    				stat=false;
						}
						
					}
					
					if(stat==false){
						system("cls");
						cout << "\n\t................... MyPaddy Sales Information ....................\n\n";
						ob[loc].display2();
						cout <<"\n\t";
						system("pause");
		    		    system("cls");	
					}
					
					
					else{
		    	    	system("cls");
						cout << "\n\t................... MyPaddy Sales Information ....................\n\n";
						cout << "\tFarmer ID " << searchID << " not found\n\n\t";
						system("pause");
		    	    	system("cls");
					}
					
					userChoice=chances=0;
					loc=-1;
					stat=true;
				}
				break;
				
			case '5':     //display revenue info
				system("cls"); 
				cout << "\n\t................... MyPaddy Revenue Information ....................\n";
				cout << "\n\t 1. Display all farmer revenue information";
		    	cout << "\n\t 2. Dislpay revenue based on farmer ID";
				cout << "\n\t Your choice:";
		    	do{
		    		cin >> userChoice;
		    		if(userChoice!=1 && userChoice!=2 || cin.fail() || cin.peek() != '\n'){
		    			cout << "\t Please Enter Correct Choice: ";
		    			cin.clear();
                        cin.ignore(10000000000, '\n');
					}
					
					else
					break;
				}while(true);
				
				if(userChoice==1){    //for display all condition
					system("cls");
					cout << "\n\t................... MyPaddy Revenue Information ....................";
					for(int i=0; i<numFarmer; i++){
					cout << "\n\n\tFarmer: " << i+1 ;
					ob[i].display2();
					ob[i].display3();
					cout << "\n\t\t~ * ~ ";
			     	}
			     	cout <<"\n\t";
				    system("pause");
		    		system("cls");
				}
		    	 
		    	else if(userChoice==2){   //for based on ID condition
		    		system("cls");
					cout << "\n\t................... MyPaddy Revenue Information ....................\n";
		    		cout << "\n\tEnter Farmer ID:";
		    		cin.ignore();
		    		getline(cin , searchID);
		    		
		    		for(int i=0; i<numFarmer; i++){
		    			if(searchID==ob[i].getID()){
		    				loc=i;
		    				stat=false;
						}
				
					}
					
					if(stat==false){
						system("cls");
						cout << "\n\t................... MyPaddy Revenue Information ....................\n\n";
						ob[loc].display2();
						ob[loc].display3();
						cout <<"\n\t";
						system("pause");
		    		    system("cls");	
					}
					
					
					else{
		    	    	system("cls");
						cout << "\n\t................... MyPaddy Revenue Information ....................\n\n";
						cout << "\tFarmer ID " << searchID << " not found\n\n\t";
						system("pause");
		    	    	system("cls");
					}
					
					userChoice=chances=0;
					loc=-1;    // set back location to -1
					stat=true;
				    }	
				    break;
				
			case '6':    //summary
				system("cls"); 
				cout << "\n\t.................................. MYPaddy Apps Summary ...................................";
				cout << "\n\n\n\tID\t|Name\t\t\t|Productivity\t|Total Incentive\t|Total Revenue";
				cout << "\n\t--------------------------------------------------------------------------------------------\n";
				for(int i=0; i<numFarmer; i++){                  //calculate total for high, moderate and low
					if(ob[i].getProductivity()=="High")
                        highNum++;
						
					else if(ob[i].getProductivity()=="Moderate")
                        modNum++;
					
					else if(ob[i].getProductivity()=="Low")
                        lowNum++;
				}
				
				for(int i=0; i<numFarmer; i++){                // display summary table
					cout << "\t" << ob[i].getID() << "\t|";
                    cout << setw(15) << ob[i].getName() << "\t|";
                    cout << setw(9) << ob[i].getProductivity() << "\t|";
                    cout << "RM " << ob[i].getIncentive() << "\t\t|";
                    cout << "RM " << ob[i].gettotalrevenue() << endl;
				}
				cout << "\n\n\n\n\t** ** ** ** ** ** ** ** ** ** ** \n";
				cout << "\tTotal high productivity     :" << highNum;
				cout << "\n\tTotal moderate productivity :" << modNum;
				cout << "\n\tTotal low productivity      :" << lowNum;
				cout << "\n\tTotal farmer                :" << numFarmer << endl;
				
				highNum=lowNum=modNum=chances=0;                 
				
				cout <<"\n\t";
				system("pause");
				system("cls"); 
				break;
				
			case '7':  //exit
			    proceed=false; 
			    system("cls");
			    cout << "\n\n\n\n\n\n\t\t\t\t\t\tThank You for Using MyPaddy Apps:)\n\n\n\n\n\n\n\n\n\n";
			    sleep(3);
                break;
                
	}	
}while(proceed==true);
cout <<"\n\n\t";
return 0;
}
