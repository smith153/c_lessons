#include <iostream> //needed for cout/cin
#include <time.h> //needed for time() and localtime()

using namespace std; // select std namespace

/*
This lesson will cover strutures and use functions with
pass by value and pass by address. 
Employee structures will be stored in a linked list
instead of an array. http://en.wikipedia.org/wiki/Linked_list
*/

struct Employee
{
  char name[40];
  char address[40];
  char age[5];
  char time[80];
  Employee *Next;
};

char printMenu();
void getEmployee(Employee **newEm);
void viewAll(Employee *myList);
void getTime(char * myTime);

int main()
{
  char a = '0';

  //create a pointer to an Employee struct and set the address to 0
  //this will always be the head of the list
  Employee *S_myList = 0;

  while (a != 'q'){
	a = printMenu();

	if(a == '1')
		getEmployee(&S_myList);

	else if (a == '2')
		viewAll(S_myList);

  }

  return 0;
}

//function definitions 
char printMenu()
{
  char selection;
  cout << "\nWelcome\n1. Enter new employee\n2. View all\nq. Quit" << endl;
  cin >> selection;
  return selection;
}

//getEmployee() will dynamically create an Employee struct, 
//fill in the data varables, and link the address pointer
//to the first node in the list.
//myList is a pointer to an Employee struct pointer
void getEmployee(Employee **myList)
{
  Employee *newEm;  //create struct pointer for new employee
  bool flag = false; //flag used for testing whether the list is empty

  //if myList address is still set to 0, then this is the first node in the list
  if(*myList == 0){
	//create dynamically allocated structure and
	//myList and newEm both get same address
	*myList = newEm = new Employee;
	//since this is the first node, set the next
	//address to 0
	newEm->Next = 0;
	flag = true;
  }
  else
	//else is entered if this is not the first time
	//the function is called.
	//get address of dynamically allocated struct
	newEm = new Employee;

  //prompt and fill in data.
  cout << "Enter name:" << endl;

  //because newEm is just an address, we must dereference it. 
  //the "->" is short hand for "(* )."
  cin >> (*newEm).name;
  cout << "Enter address" << endl;
  cin >> newEm->address;
  cout << "Enter age" << endl;
  cin >> newEm->age;
  
  //pass time variable to getTime() to be filled in
  getTime(newEm->time);

  //if this is not the first time the function is called then set the Next node pointer
  //to the head node in the list. Then set the head node pointer to our freshly
  //create Employee structure. Remember, myList is a pointer to a pointer
  if(!flag){
	newEm->Next = *myList;
	*myList = newEm;
  }

}

//viewAll() prints all nodes in the list
//remember, myList is just an address
//the last step in the loop sets myList to
//the address of the next node in the list
//the last node has a Next value of "0"
void viewAll(Employee *myList)
{
  cout << "\n\n";
  while (myList != 0){
	cout << myList->name << endl;
	cout << myList->address << endl;
	cout << myList->age << endl;
	cout << myList->time << "\n" << endl;

 	myList = myList->Next;
  }

}

void getTime(char * myTime)
{
  time_t seconds;
  tm *tmPtr; //tm is a structure for time data

  //get time in seconds, man -s3 time
  time(&seconds);
  //convert seconds to localtime, value returned is a tm structure, man -s3 localtime
  tmPtr = localtime(&seconds);

  //format tmPtr structure into a string, man -s3 strftime
  strftime(myTime, 80, "%m-%d-%Y_%H:%M:%S" ,tmPtr);

}
