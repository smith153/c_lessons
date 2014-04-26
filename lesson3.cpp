#include <iostream> //needed for cout/cin
#include <time.h> //needed for time() and localtime()

using namespace std; // select std namespace

/*
This lesson will cover strutures and use functions with
pass by value and pass by address. 
We will create an array of Employee stucture types.
*/

//define the structure
struct Employee
{
  char name[40];
  char address[40];
  int  age;
  char time[80];
};

//function prototypes
char printMenu();
int getEmployee(Employee myList[], int count);
void viewAll(Employee myList[], int count);
void getTime(char * myTime);

int main()
{
  char a = '0';
  
  //create an array of 100 Employee stucts
  Employee S_myList[100];

  //this is a counter for how many stucts we are using
  int count = 0;

  while (a != 'q'){
	a = printMenu();

	if(a == '1')
		count = getEmployee(S_myList, count);

	else if (a == '2')
		viewAll(S_myList,count);

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
int getEmployee(Employee myList[], int count)
{
  

  //prompt and fill in data.
  cout << "Enter name:" << endl;
  cin >> myList[count].name;
  cout << "Enter address" << endl;
  cin >> myList[count].address;
  cout << "Enter age" << endl;
  cin >> myList[count].age;
  
  //pass time string to getTime function to be filled out.
  //remember time[] is a char array. the variable "time" is
  //just an address pointing to the first byte of the string.
  //So when we pass "myList[count].time", that is actually
  //passing the address to the function. Therefore inside the 
  //function we can directly modify the char array. This is 
  //true for all arrays. Using "[ ]" is what dereferences
  //and gets the data.
  getTime(myList[count].time);
  
  count++;
  return count;
}

void viewAll(Employee myList[], int count)
{
  cout << "\n\n";
  for (int i = 0; i < count; i++){
	cout << myList[i].name << endl;
	cout << myList[i].address << endl;
	cout << myList[i].age << endl;
	cout << myList[i].time << "\n" << endl;
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
