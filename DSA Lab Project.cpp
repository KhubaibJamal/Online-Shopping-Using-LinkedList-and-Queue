// DSA Lab Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <sstream> // use for stringstream
using namespace std;

#pragma region Queue for customer
string queue[50];
int front = -1, rear = -1, n = 50;
void enqueue(string val)
{
	if (rear >= n)
	{
		cout << "Queue is overflow" << endl;
	}
	else
	{
		cout << "\t" << val << "\t" << endl;
		rear++;
		queue[rear] = val;
		cout << "\n|------------------------------------------------|\n";
	}
}

void dequeue()
{
	if (front == rear)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		front++;
		queue[front];
		cout << "\n|------------------------------------------------|\n";
	}
}

void displayQueue()
{
	if (rear == -1)
	{
		cout << "Queue is empty!" << endl;
	}
	else
	{
		for (int i = front + 1; i <= rear; i++)
		{
			cout << "\t " << queue[i] << "\t";
			cout << endl;
		}
		cout << "\n-----------------------------------------\n";
	}
}

#pragma endregion

struct Node
{
	int ID;
	string productName;
	double productPrice;
	int quantity;
	struct Node *next;
};

struct Node* head = NULL;
void addNewItem()
{
	system("cls"); //clear the screen
	int id, quantity;
	string name;
	double price;
	struct Node* temp = new Node;//temp variable
	struct Node* ptr = head;
	cout << "\t\t\tEnter Product ID:- ";
	cin >> id;
	temp->ID = id;
	cout << "\t\t\tEnter Product Name:- ";
	cin >> name;
	temp->productName = name;
	cout << "\t\t\tEnter Product Price:- ";
	cin >> price;
	temp->productPrice = price;
	cout << "\t\t\tEnter Product Quantity:- ";
	cin >> quantity;
	temp->quantity = quantity;
	if (head == NULL)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->next = NULL;
	}
	system("cls");
	cout << "\t\t\tThe Product is Inserter\n\n\n" << endl;
}

int searchProduct(int id)
{
	int count = 1;
	struct Node* ptr = head;
	while (ptr != NULL)
	{
		if (ptr->ID == id)
		{
			break;
		}
		else
		{
			count++;
		}
		ptr = ptr->next;
	}
	return count;
}

string check(int quant)
{
	int a = quant;
	stringstream ss;
	ss << a;
	string quantity = ss.str();
	if (quant <= 0)
	{
		return "out of stock!";
	}
	else
	{
		return quantity;
	}
}

int displayProduct()
{
	system("cls");
	int count = 0; // count the product
	struct Node* ptr = head;
	cout << "Existing Products are:\n";
	cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
	cout << "=============================================================\n";
	if (ptr == NULL)
	{
		cout << "\nNo Item Present in the Store\n" << endl;
	}
	else 
	{
		while (ptr != NULL)
		{
			cout << ptr->ID << "\t\t" << ptr->productName << "\t\t" << ptr->productPrice << "\t\t" << check(ptr->quantity) << endl;
			ptr = ptr->next;
			count++;
		}
		cout << "\nTotal Product in our Store is: " << count << "\n\n\n";
	}
	return count;
}

int deleteProduct()
{
	system("cls");
	displayProduct();
	int id;
	struct Node* current = head;
	struct Node* previous = head;
	cout << "\n\nEnter ID to Delete that Product: ";
	cin >> id;
	if (head == NULL)
	{
		system("CLS");
		cout << "List is empty! " << endl;
	}
	int pos = 0;
	int count = displayProduct();
	pos = searchProduct(id);
	if (pos <= count)
	{
		while (current->ID != id)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		system("cls");
		cout << "\nItem is Deleted!" << endl;
	}
	else
	{
		cout << "\n<<Item Not Found>>\n" << endl;
	}
	return count;
}

void modifyProduct()
{
	int id;
	double price;
	string pName;		//product name
	int newID, newQuantity;
	if (head == NULL)
	{
		system("CLS");
		cout << "List is Empty" << endl;
	}
	else
	{
		displayProduct();
		cout << "\t\tEnter ID to modify the product name and it's price:\n";
		cin >> id;
		struct Node* current = head;
		int pos = 0;//position
		int count;
		count = displayProduct();
		pos = searchProduct(id);
		//check node is present or not
		if (pos <= count)
		{
			while (current->ID != id)
			{
				current = current->next;
			}
			cout << "\nOld ID : " << current->ID << endl;
			cout << "\nOld name : " << current->productName << endl;
			cout << "\nOld Price : " << current->productPrice << endl;
			cout << "\nOld Quantity : " << current->quantity << endl;

			cout << endl << endl;
			cout << "Enter new ID: ";
			cin >> newID;
			current->ID = newID;
			cout << "Enter new Name: ";
			cin >> pName;
			current->productName = pName;
			cout << "Enter new Price: ";
			cin >> price;
			current->productPrice = price;
			cout << "Enter new Quantity: ";
			cin >> newQuantity;
			current->quantity = newQuantity;
		}
		else
		{
			cout << id << " is Not found!" << endl;
		}
	}
}

void buy()
{
	system("cls");
	displayProduct();
	string product[20]; //array for display sold item
	int noOfItem, c = 0, i = 1;
	double pay = 0, price;
	if (head == NULL)
	{
		cout << "\n<<<<There is no items to buy>>>>\n\n";
	}
	else
	{
		cout << "How many items you wanna to buy!\n";
		cin >> noOfItem;
		int count = displayProduct();		//for store no of nodes  in count
		while (i <= noOfItem)
		{
			struct Node* current = head;
			int quantity; a:

			cout << "Enter ID of item that you want to buy: ";
			int id, pos = 0;				// pos for position
			cin >> id;
			if (id == -1)
			{
				system("cls");
				return;
			}
			pos = searchProduct(id);
			if (pos <= count)
			{
				//item availabel in the list
				while (current->ID != id)
				{
					current = current->next;
				}
				cout << "How many quantities you want:";
				cin >> quantity;
				if (current->quantity < quantity)
				{
					cout << "\n\n\t\t\t----The Quantity You Entered is not available---" << endl;
					cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
					goto a;						// jump to a
				}
				product[c] = current->productName;// this will conatin the items buy names in array; 
				c++;
				pay = pay + (current->productPrice*quantity); // calculate bill
				current->quantity = current->quantity - quantity; //chang in quantity
				i++;
			}
			else
			{
				cout << "\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
			}
		}

		string customer;
		cout << "\n\t\t Enter Your Name :";
		cin >> customer;
		enqueue(customer);
		system("cls");
		cout << "\n\n\n\n\t\t\tYou have bought : ";
		for (int i = 0; i < noOfItem; i++)
		{//    show that item you have bought
			cout << product[i] << ",";
		}
		price = pay*(0.90);					//with 10% discount
		cout << "\n\nOriginal price : " << pay;
		cout << "\n with 10% discount: " << price << "\nThank you! for the shopping\n\n";
	}
}

void administator()
{
	system("cls");
	int choice;
	do {
		//choice for below message
		cout << "\t\t============================================" << endl;
		cout << "\t\t|          Administator Portal              |" << endl;
		cout << "\t\t============================================" << endl;
		cout << "\t\t     Enter 1 for ADD a new product    " << endl;
		cout << "\t\t     Enter 2 to display all products   " << endl;
		cout << "\t\t     Enter 3 for MODIFY Existing product" << endl;
		cout << "\t\t     Enter 4 for Delete a particular product item" << endl;
		cout << "\t\t     Enter 5 for Customers List " << endl;
		cout << "\t\t     Enter 6 for Dequeue customer" << endl;
		cout << "\t\t     Enter 0 for Main Menu" << endl;
		cout << "\nEnter Your choice >>>";
		cin >> choice;
		switch (choice) {
		case 1:
			addNewItem();
			break;
		case 2:
			system("cls");
			displayProduct();
			break;
		case 3:
			modifyProduct();
			system("cls");
			break;
		case 4:
			deleteProduct();
			cout << "\n-------Product is Deleted-------\n";
			break;
		case 5:
			system("cls");
			cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
			displayQueue();
			break;
		case 6:
			system("cls");
			cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
			dequeue();
			displayQueue();
			break;
		default:
			system("cls");

		}
	} while (choice != 0);
}

COORD coord = { 0, 0 };
void gotoxy(int x, int y) //set cursoer position
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main()
{
	system("color FF");     //  for console color
	gotoxy(17, 5);
	cout << "--------------------------------------------------" << endl;
	gotoxy(17, 7);
	cout << "||            Shopping Club System                ||" << endl;
	gotoxy(17, 9);
	cout << "--------------------------------------------------" << endl;
	gotoxy(17, 11);
	cout << "|Subject Teacher ->> Sir Abdul Khaliq <<-- |\n" << endl;
	gotoxy(17, 13);
	cout << ">>>----Project Implemented By-----<<<" << endl;
	gotoxy(22, 15);
	cout << "Khubaib Jamal\t  (2020F-BCS-265)" << endl << endl;
	system("pause");
	system("cls");
	system("color F1");
AGAIN:
	int i = 0; // for trolly number
	int choice;
	do
	{
		cout << "\n\t\t|--------<Main Menu>-----------|";
		cout << "\n\n";
		cout << "\t\t 1)Administator of Market\n";
		cout << "\t\t 2)Customer               \n";
		cout << "\t\t 3)Exit                    \n";

		cout << "\nEnter Your choice >>>";
		cin >> choice;
		switch (choice)
		{
		case 1:
			administator();
			break;
		case 2:
			cout << endl << endl;
			//function that' call customers!!!
			i = i + 1;
			cout << "Your Trolli No is : " << i << endl;
			cout << endl << endl;
			cout << "		    	__" << endl;
			cout << "		      /   |" << endl;
			cout << "		     /		" << endl;
			cout << "	 ___________/		" << endl;
			cout << "	|__/____/___|		" << endl;
			cout << "	|__/____/___|		" << endl;
			cout << "	|__/_____/__|		" << endl;
			cout << "	________/		" << endl;
			cout << "	o     o		" << endl;
			system("pause");
			buy();
			break;
		case 3:
			system("cls");
			cout << "\n\n\t\t\tFORGET ALL THE REASONS WHY IT WON'T WORK AND BELIEVE THE ONE REASON WHY IT WILL!\n\n" << endl;
			cout << "\n\n\t\t\t\t\tTHANK YOU\t\t\t\t";
			break;
		default:
			system("cls");
			cout << "\n\n\t\t\tEnter right choice.\nTry again!" << endl;
			goto AGAIN;
			break;
		}
	} while (choice != 3);
	_getch();
	return 0;
}
