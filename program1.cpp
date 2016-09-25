//Dakota Erickson
// J762Q949
//Program 1
// Inventory management program


#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Part
{
public:

    int part_number;
    string description;
    int quantity;
    float price_per_item;
    double total;

};

void printAllParts(Part [], int);
void addPart(Part [], int&);
void modifyPart(Part [], int&);
void printTotal(Part [], int);

int main()
{
//big data structure
Part arr[100];  //this is the array to hold objects
int count=0;  	// this is the count to tell how many different parts are in the array


//try to read file from here

//read from file and update arr[i]

std:: fstream file("inventory.txt", std::ios::in);
	
	if(file)
	{
		int i =0; 			//this is the index
		int partNum = 0;
		std::string description = " ";
		int quantity = 0;
		float unitPrice = 0;
		
		//use a loop to keep reading file
		//if reading file fails, the loop will end
		while(file >> partNum && i<100)
		{
			// because we have a newline character, we have to ignore it
			file.ignore();
			std::getline(file, description);
			file >> quantity;
			file >> unitPrice;
			
			//copy info from local variables to array element variables
			
			arr[i].part_number=partNum;
			arr[i].description=description;
			arr[i].quantity=quantity;
			arr[i].price_per_item=unitPrice;
			i++;
			count++;
		}


	
}

	int choice=0;
	cout << "Please make a choice: "<< endl;
	cout <<"************************" << endl;
	cout << "1. Print the parts."<<endl;
	cout << "2. Create new part."<<endl;
	cout << "3. Modify a part."<<endl;
	cout << "4. Print total."<<endl;
	cout << "5. Exit the program."<<endl;
	cin >> choice;
    while (cin.good() && choice<=5)
    {
        switch (choice)
        {
        case 1:
        printAllParts(arr, count);
        cout << endl;
        break;
        case 2:
        cin.ignore();
        addPart(arr, count);
        cout << endl;
        break;
        case 3:
        modifyPart(arr, count);
        cout << endl;
        break;
        case 4:
        printTotal(arr, count);
        break;
        case 5:
	{std::fstream file("inventory.txt", std::ios::out);
	
	//if file is good, then write to the file
	if(file)
	{
	
		for(int i=0;i<count;i++)
		{
		file << arr[i].part_number << endl;
		file << arr[i].description << endl;
		file << arr[i].quantity << endl;
		file << arr[i].price_per_item << endl;
		}
		std::cout<<"Writing file \"inventory.txt\""<<std::endl;
	}
	else
	{
		std::cout<<"Error when writing to file."<<std::endl;
	}
	
	//close the file when finished
	file.close();
    return 0;    
		}
        default:
        cout<< endl << "Invalid choice" << endl<< endl;
        break;
	}
	
	cout << "Please make a choice: "<< endl;
	cout <<"************************" << endl;
	cout << "1. Print the parts."<<endl;
	cout << "2. Create new part."<<endl;
	cout << "3. Modify a part."<<endl;
	cout << "4. Print total."<<endl;
	cout << "5. Exit the program."<<endl;
	cout<<"Please make another choice: ";
	cin >> choice;
	cout << endl;
}


}



//Prints inventory onto screen
void printAllParts(Part arr[], int count)
{
	if(count == 0)
	{
		cout << "Empty Inventory!" << endl<<endl;
		return;
	}

	for(int i=0;i<count;i++)
	{
		cout<<"Part number: " << arr[i].part_number << endl;
		cout<<"Part description: " << arr[i].description << endl;
		cout<<"Part quantity: " << arr[i].quantity << endl;
		cout<<"Part value: " << arr[i].price_per_item << endl<< endl;
	}
	
}


//allows the user to add a new part to the inventory
void addPart(Part arr[], int & count)
{
	cout << "New part description: ";
	string description; //description of part being added to inventory
	getline(cin, description);

	cout<< "New part quantity: ";
	int quantity=0; //quantity of part being added to inventory
	cin>> quantity;

	cout<<"Unit price: ";
	float price =0; //price of part being added to inventory
	cin >> price;
	
	arr[count].part_number = count+1;
	arr[count].description = description;
	arr[count].quantity = quantity;
	arr[count].price_per_item = price;
	arr[count].total = arr[count].quantity*arr[count].price_per_item;

	count++;
}


//allows the user to modify an existing part within the inventory
void modifyPart(Part  arr[], int & count)
{
	int newpart =-1; // the variable used to store the part number chosen to modify
	string newdescription;	// the new description for the part being modified
	
	cout<< "Please enter the part number you would like to modify: ";
    cin>> newpart;
    
    cout << "Modifying part number: " << newpart << endl;

    cout << "New part description: ";
	cin.ignore();  //ignores the return character given during cin
	getline(cin, newdescription);

	cout<< "New part quantity: ";
	int quantity=0; //new quantity of part
	cin>> quantity;

	cout<<"Unit price: ";
	float price =0; //new price of part
	cin >> price;
	
	arr[newpart-1].description = newdescription;
	arr[newpart-1].quantity = quantity;
	arr[newpart-1].price_per_item = price;
	arr[newpart-1].total = arr[newpart-1].quantity*arr[newpart-1].price_per_item;

}



//Prints the total value of inventory
void printTotal(Part arr[], int count)
{
    float total = 0; // used to hold total value
    
    //loops through every item in inventory and adds values together
    for(int i=0;i<= count ;i++)
	{
		total = total+(arr[i].quantity*arr[i].price_per_item);
	}
    cout <<"Total price of inventory: " << total << endl<< endl;
}
