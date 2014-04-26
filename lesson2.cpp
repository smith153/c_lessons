#include <iostream> //needed for cout/cin

using namespace std; // select std namespace

/*
For this program we will create a few functions all with the same name
and that do essentially the same thing
we will use the dereference operator '*' as well as the get 
address/reference operator '&'
http://www.cplusplus.com/doc/tutorial/functions/
http://www.cplusplus.com/doc/tutorial/functions2/
*/

// function prototypes
//this function returns a char
char printMenu();
//this function takes an address of a char
void printMenu(char *myChar);
//this function takes a char and creates a reference to the address
void printMenu(char &myChar);

int main()
{
  char a;
  //myInt is a pointer to a dynamically allocated int datatype
  //http://www.cplusplus.com/doc/tutorial/dynamic/
  int *myInt = new int;


  //since 'a' will be used as an expression to a loop, lets make sure we know what the value is first
  a = '\0';
  while(a != 'q'){

	//this loop will always be true. we will use the "break" command to get out (there is also a "continue" command)
	while(1){
		cout << "choose print function:\n1. a = printMenu();\n2. printMenu(&a);\n3. printMenu(a);\n\n" << endl;
		cin >> a;

		if ( a == '1')
			a = printMenu(); //function returns char selected by user
		else if ( a == '2')
			printMenu(&a); //pass address of char. '&' is "get address" function in this context
		else if ( a == '3')
			printMenu(a); //create reference to char address
		else 
			continue;

		break;
	}
	
	if (a == '1')
		cout << "address is: " << myInt << endl;

	if (a == '2')
		cout << "myInt is: " << *myInt << endl; //notice the dereference operator

	if (a == '3'){
		cout << "Enter a new integer:" << endl;
		cin >> *myInt;
	}
}

  return 0;
}

//functions are defined here. They can also be in another file
char printMenu()
{
  char a;
  cout << "1. print address of myInt\n2. print myInt\n3. change myInt\nq. quit\n\n" << endl;
  cin >> a;
  return a;
}

void printMenu(char &myChar)
{
  cout << "1. print address of myInt\n2. print myInt\n3. change myInt\nq. quit\n\n" << endl;
  cin >> myChar; //myChar is a reference to the same memory block of 'char a' from int main
}

void printMenu(char *myChar)
{
  cout << "1. print address of myInt\n2. print myInt\n3. change myInt\nq. quit\n\n" << endl;
  cin >> *myChar; //notice the dereference operator

}


