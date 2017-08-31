/* Home Inventory System, Noel Dumas, August 2017
	This program lets the user create and inventory list with pars, add on-hands to output their shopping list with the number of each item to be purchased.  Always have what you need!  
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void getNewItem();
void getList();
void getOnHand();
void getShopList();

string newItem = "";
int parNum = 0;
int onHand = 0;
int amtNeed = 0;

int main(){
	int menuChoice = 0;
	
	do{
		cout << "1  Enter item to inventory and par (amount of each item) needed on-hand." << endl;
		cout << "2  Get list of items and there pars." << endl;
		cout << "3  Enter what is on-hand to create shopping list." << endl;
		cout << "4  Get your shopping list!" << endl;
		cout << "5  End program." << endl << endl;
		cout << "Enter menu choice: ";
		cin >> menuChoice;
		cout << endl << endl;
		
		if(menuChoice == 1)
			getNewItem();
		else 
			if(menuChoice == 2)
				getList();
		else 
			if(menuChoice == 3)
				getOnHand();
		else 
			if(menuChoice == 4)
				getShopList();
	}	while(menuChoice != 5);
	
	return 0;
}

void getNewItem(){
	
	ofstream outInv;
	outInv.open("homeInventory.txt", ios::app);
	
	if(outInv.is_open()){
		
		cout << "Enter new item to your inventory (-1 to stop): ";
		cin.ignore(100, '\n');
		getline(cin, newItem);
		while(newItem != "-1"){
			
			cout << "Enter how many of this item needed: ";
			cin >> parNum;
			
			outInv << newItem << '#' << parNum << endl;
			
			cout << endl;
			cout << "Enter new item to your inventory (-1 to stop): ";
			cin.ignore(100, '\n');
			getline(cin, newItem);
		}
		outInv.close();
	}else 
		cout << "File could not be opened." << endl;
}

void getList(){
	
	ifstream inInv;
	inInv.open("homeInventory.txt");
	
	if(inInv.is_open()){
		
		getline(inInv, newItem, '#');
		inInv >> parNum;
			
		while(!inInv.eof()){
			
			cout << newItem << endl;
			cout << parNum << endl;
			getline(inInv, newItem, '#');
			inInv >> parNum;
		}
		inInv.close();
		cout << endl << endl;
	}else 
		cout << "File could not be opened." << endl;
}

void getOnHand(){
	
	ifstream inInv;
	inInv.open("homeInventory.txt");
	
	ofstream outList;
	outList.open("shoppingList.txt");
		
	if(inInv.is_open()){
		
		getline(inInv, newItem, '#');
		inInv >> parNum;
		
		while(inInv.good()){
			
			if(outList.is_open()){
				
				cout << newItem << endl;
				cout << "Enter how many you have of this item: ";
				cin >> onHand;
				
				amtNeed = parNum - onHand;
				
				outList << newItem << '#' << amtNeed << endl;
							
				getline(inInv, newItem, '#');
				inInv >> parNum;
				
				while(!inInv.eof()){
					
					cout << newItem << endl;			
					cout << "Enter how many you have of this item: ";
					cin >> onHand;	
					
					amtNeed = parNum - onHand;
										
					outList << newItem << '#' << amtNeed << endl;	
					
					getline(inInv, newItem, '#');
					inInv >> parNum;									
				}
				outList.close();
				cout << endl;
			}else 
				cout << "outList file could not be opened." << endl;
				
		}
	
		inInv.close();
		cout << endl;
	}else 
		cout << "inInv file could not be opened." << endl;
}

void getShopList(){
	
	ifstream inList;
	inList.open("shoppingList.txt");
	
	if(inList.is_open()){
		
		getline(inList, newItem, '#');
		inList >> amtNeed;
				
		while(!inList.eof()){
				
			cout << newItem;
			cout << ": ";
			cout << amtNeed;
			getline(inList, newItem, '#');
			inList >> amtNeed;
		}
		inList.close();
		cout << endl << endl;
	}else 
			cout << "File could not be opened." << endl;
}
	