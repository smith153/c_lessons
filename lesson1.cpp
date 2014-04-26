#include <iostream> //needed for cout/cin
#include <fstream> // needed for ifstream/ofstream
#include <stdio.h> //needed for printf() and remove()

using namespace std; // select std namespace


/*
Just about ever line needs to end with a ";",
usually not a line ending with a "{" or "}" though
compile using "g++ -oherman herman.cpp"
run using ./herman
default file will be "a.out" unless a name is given to it with the "-o" option above
for if, while,ect statements an expression is considered 
true if it is any value other than 0

main function, required
*/
int main()
{
//operators and order: http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
//datatypes: http://www.cplusplus.com/doc/tutorial/variables/

//single character
char a;
//string, (character array)
char myString[100] = "Hello from myString";
char myString1[5];
//signed integer
int myInt = 5; //for hex use 0x05

//floating point
float myFloat;
//double length floating point
double myDouble;

//writing to terminal:
cout << "myString: " << myString << "\n" << endl;
//or use printf() 
//http://www.cplusplus.com/reference/clibrary/cstdio/printf/
printf("here is myString: %s and here is myInt %d \n",myString,myInt);

//lets get console input
printf("Type one character,\n");

cin >> a;

//lets look at a switch statement
//bottom of page here: http://www.cplusplus.com/doc/tutorial/control/

switch(a){
	case '1': 
		printf("you entered 1\n");
		break;
	case '2':
		printf("you entered 2\n");
		break;
	case '3':
		printf("you entered 3\n");
		break;
	case '4':
		printf("you entered 4\n");
		break;
	default:
		printf("printf says you entered %c\n",a);
		cout << "cout says you entered " << a << endl;
}

//we can also print out a character array with a loop (instead of using the easier cout or printf functions

//lets make an index variable
int i = 0;

//there is null terminal "\0" at the end of every string
//print one character at a time and then prints a new line
printf("myString printed from a while loop:\n");
while (myString[i] != '\0'){
	cout << myString[i];
	i++; //i = i + 1;
}
//print new line
cout << endl;


//lets print the whole 100 byte array and see what is in it
//this int i is in a different scope than the one above and thus in a different memory location
printf("myString printed from a for loop:\n");
for(int i = 0; i < 100; i++){
	cout << myString[i];
}
cout << endl;

//what would happen if went past 100?
//we would over run the 100 byte array boundry and the 
//OS would segfault/terminate our program

//we can use our character array to take in more than one character from the terminal
cout << "enter up to 99 characters:" << endl;
cin >> myString1;
cout << "you entered: " << myString1 << "\n" << endl;


//lets use the c++ streaming library to read and write files
//http://www.cplusplus.com/doc/tutorial/files/
//declare an input stream:
ifstream INFILE;

//declare an output stream:
ofstream OUTFILE;

//lets create and open a file by calling the open function of our ofstream variable
//ofstream defaults to output mode
OUTFILE.open("myFile");

//lets dump myString to it

OUTFILE << myString << endl;

//we can even write byte by byte
//http://www.cplusplus.com/reference/iostream/ostream/
OUTFILE.put(myString[1]); //put 2nd character of myString to file twice
OUTFILE.put(myString[1]); 
OUTFILE.close();

//now lets read the file in and see what we have
//binary mode would look like: INFILE.open ("filename", ios::binary);
//http://www.cplusplus.com/reference/iostream/iostream/
INFILE.open("myFile");
INFILE >> myString;

cout << "We just read in the file, the data is:\n" << myString << endl;
cout << "where is the rest of myString?" << endl;
//note that with cin or ifstream, by default it will stop reading once it reaches a space (if not in binary mode)

//set file pointer to beginning again.
INFILE.seekg(0);


i = 0;
//while not at end of file, get one byte and put it in the array
while( !INFILE.eof() ){
	myString[i] = INFILE.get();
	i++;
}
//the above will read the whole file but the null terminator '\0' will be missing
//therefore when we print using the below, it will print out the whole 100 byte array
//it may also over run the array boundry and cause a segfault in some cases
cout << "here is the rest of myString: " << myString << endl;

//remove our file
remove("myFile");

//main() is declared as returning an int so lets return one now to exit
return 0;

}


