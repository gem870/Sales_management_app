
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <map>
#include <sstream>

 using namespace std;

string  dortLine = "  ......................................  ",
shortDortline = " ...... ",
longDashLesft = "---------------->>> ",
longDashRight = " <<<----------------",
shortDashLesft = "------>> ",
shortDashRight = " <<------",
greaterThan = ">> ",
lessThan = " <<",
shortStars = " ******************* ",
longStars = "******************************************************************************",
longQualTo = "=================================================================",
space = "\t",
space2 = "\t\t";

   int itemCode;
	float price;
	float discount;
	string productName1;
class shpoing {
private:
	

public:
	//void menu();
	//void administrator();
	//void buyer();
	//void addProduct();
	//void edit();
	//void removeProduct();
	//void list();
	//void receipt();
};



void DiplayMenu() {
	cout << endl << endl;
	cout << space2 << longStars << endl << endl;
	cout << space2 << "              -->>           SUPERMARKET MAIN MENU           <<--   " << endl << endl;
	cout << space2 << longStars << endl << endl;
	cout << space2 << space2 << "     ...   Administrator     .1 " << lessThan << endl << endl;
	cout << space2 << space2 << "     ...   Buyer             .2 " << lessThan << endl << endl;
	cout << space2 << space2 << "     ...   Exit              .3 " << lessThan << endl << endl;
	cout << space2 << space2 << dortLine << endl << endl;
	cout << greaterThan << "Pls choose any of the option number: ";
}

void admiistrator() {
	string userID, password;
	cout << endl << endl;
	cout << longQualTo << endl << endl;
	cout << "           -->>         ADMINSTRATOR         <<--   " << endl << endl;
	cout << ">>                     Please Login..... " << endl;
	cout << "         " << dortLine << endl << endl;
	cout << "          Enter userID: ";
	cin >> userID;
	cout << "          Enter Password: ";
	cin >> password;

	

	cout << endl << endl;
	cout << longQualTo << endl << endl;
	cout << "           -->>         ADMINSTRATOR         <<--   " << endl << endl;
	cout << ">>                         MENU.. " << endl;
	cout << "         " << dortLine << endl << endl;
	cout << "         1.   Add Product " << endl;
	cout << "         2.   Mordify Product " << endl;
	cout << "         3.   Delete Product " << endl;
	int chioce;
	cout << " Please enter option: ";
	cin >> chioce;
	/*switch (chioce) {
		
	}*/

}


void buyer() {
	cout << endl << endl;
	cout << longQualTo << endl;
	cout << "                            ****" << endl;
	cout << "            -->>         SALES MENU         <<--   " << endl;
	cout << "                            ****" << endl;
	cout << longQualTo << endl;
	cout << endl << endl;

}

void addProduct() {
	cout << endl << endl;
	cout << space2 << longQualTo << endl << endl;
	cout << space2 << "           -->>         ADD NEW PRODUCTS         <<--   " << endl << endl;
	cout << space2 << "           " << dortLine << endl << endl;
	int productCode, product = 0, productPrice, productDiscount; string productName;
	cout << space2 << "          Enter product code:   ";
	cin >> itemCode;
	cout << space2 << "          Name of the product:  ";
	cin >> productName1;
	cout << space2 << "          Price of the product: $";
	cin >> price;
	cout << space2 << "          Discount on product:  $";
	cin >> discount;

	fstream myFile;
	myFile.open("businessRecord.txt", ios::in);
	if (!myFile)
      myFile.open("businessRecord.txt", ios::app|ios::out);
	if (myFile.is_open()) {
		myFile << itemCode << productName1 << price << discount << endl;
		myFile.close();
	}
	else
	{
		myFile >> productCode >> productPrice >> productName >> productDiscount;
		while (!myFile.eof()) {
			if (productCode = itemCode) {
				product++;
			}
			myFile >> productCode >> productPrice >> productName >> productDiscount;
		}
		myFile.close();

		if (product == 1)
			return;
		else {
			myFile.open("businessRecord.txt", ios::app | ios::out);
			myFile << itemCode << productName1 << price << discount << endl;
			myFile.close();
		}
	}
	cout << endl << endl;
	cout << space2 << ">>      product details have been noted..!" << endl;
	
}


void edith() {
	cout << endl << endl;
	cout << space2 << longQualTo << endl << endl;
	cout << space2 << "           -->>         MODIFY PRODUCT RECORD         <<--   " << endl << endl;
	cout << space2 << "           " << dortLine << endl << endl;
	fstream myFile1, myFile2;
	int productCode, product = 0, productPrice, code, productDiscount; string productName;
	cout << space2 << "           product code:  " << endl;
	cin >> productCode;
	myFile1.open("businessRecord.txt", ios::in);
	if (!myFile1) {
		cout << "   .....  >>      File does not exist..!! " << endl;
	}
	else {
		myFile2.open("businessRecord1.txt", ios::app | ios::out);
		myFile1 >> itemCode >> productName1 >> price >> discount;
		while (!myFile1.eof()) {
			if (productCode == itemCode) {
				cout << ">> Pls enter new code:  ";
				cin >> productCode;
				cout << "Name of the product:    ";
				cin >> productName;
				cout << "Product price:          $";
				cin >> productPrice;
				cout << "Enter discount amount:  $";
				cin >> productDiscount;
				myFile2 << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount;
				cout << "           -------{ Record Edited }------- " << endl;
				product++;

			}
			else {
				myFile2 << " " << itemCode << " " << productName1 << " " << price << " " << discount;
			}
			myFile1 >> itemCode >> productName1 >> price >> discount;
		}
		myFile1.close();
		myFile2.close();
		remove("businessRecord.txt");
		rename("businessRecord.txt", "businessRecord.txt");
		if (product == 0) {
			cout << " ....... ?? Record not found. " << endl;
		}
	}
}

void deleteFunction() {
	fstream myFile1, myFile2;
	int productCode, product = 0;
	cout << endl << endl;
	cout << longQualTo << endl << endl;
	cout << longDashLesft << "DELETE PRODUCT " << endl;
	cout << "       " << dortLine << endl;
	cout << "Enter product code: ";
	cin >> productCode;
	myFile1.open("businessRecord.txt",ios::in);
	if (!myFile1) {
		cout << "   >>    ......   File does not Exit. " << endl;
	}
	else {
		myFile2.open("businessRecord1.txt",ios::app|ios::out);
		myFile1 >> itemCode >> productName1 >> price >> discount;
		while (!myFile1.eof()) {
			if (productCode == itemCode) {
				cout << ">>  ......      Product Deleted succesfully. ! " << endl;
				product++;
			}
			else {
				myFile2 << " " << itemCode << productName1 << price << discount;
			}
		}
		myFile1.close();
		myFile2.close();
		remove("businessRecord.txt");
		rename("businessRecord1.txt", "businessRecord.txt");
		if (product == 0) {
			cout << ">>   ......  Record not found. " << endl;
		}
	}
}

void listOfItems() {
	fstream myFile;
	myFile.open("businessRecord.txt", ios::in);
	cout << longStars << endl;
	cout << "    >>                 List of i tems " << endl << endl;
	cout << "         P.NUMBER     P.NAME     P.PRICE    " << endl;
	cout << "  " << longQualTo << endl << endl;
	myFile >> itemCode >> productName1 >> price >> discount;
	while (!myFile.eof()) {
		cout << "         " << itemCode << "     " << productName1 << "     " << price;
		myFile >> itemCode >> productName1 >> price >> discount;
	}
	myFile.close();
}

void receipt() {
	fstream myFile;
	int array_code[100];
	int array_quantity[100];
	char choice;
	int code = 0;
	float amount = 0;
	float discount = 0;
	float total = 0;
	cout << endl << endl;
	cout << "             ........   RECEIPT   ........  " << endl;
	cout << "|_______________________________________________________|" << endl;
	myFile.open("businessRecord.txt", ios::in);
	if (myFile) {
		cout << endl << endl;
		cout << "           .... Empty database !! " << endl;
	}
	else {
		myFile.close();
		listOfItems();
		cout << endl << endl;
		cout << "        ------>>      Please place an order." << endl << endl;
		do {
			cout << "Enter the product code: ";
			cin >> array_code[code];
			cout << "Enter product quantity: ";
			cin >> array_quantity[code];
			for (int i = 0; i < code; i++) {
				if (array_code[code] == array_code[i]) {
					cout << endl;
					cout << "       -->>   Duplicatte product code. Please try agian !" << endl;
					return;
				}
			}
			code++;
			cout << ">>  ......   Do you want to purchace another product ! " << endl;
			cin >> choice;
		} while (choice == 'y');

		cout << "                    ------- RECEIPT ------- " << endl;
		cout << "         P.NUMBER     P.NAME     P.PRICE    P.DISCOUNT" << endl;
		for (int i = 0; i < code; i++) {
			myFile.open("businessRecord.txt", ios::in);
			myFile >> itemCode >> productName1 >> price >> discount;
			while (!myFile.eof()) {
				if (itemCode == array_code[i]) {
					amount == price * array_quantity[i];
					discount = amount - (amount * discount / 100);
					total = total + discount;
					cout << itemCode << productName1 << array_quantity[i] << price << discount;
				}
				myFile >> itemCode >> productName1 >> price >> discount;
			}
		}
		myFile.close();
	}
	cout << endl << endl;
	cout << longStars << endl << endl;
	cout << "       TOTAL AMOUNT:  $" << total << endl;
}



int main()
{
	listOfItems();



	system("pause > 0");
}

