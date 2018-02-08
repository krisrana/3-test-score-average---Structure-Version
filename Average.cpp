/*
     Name:      Krishna rana
     Course:    CIS 160 ME1
     Date:      10/10/2016
     Program:   Average of three scores
     Description:  This program calculates the total average of three test score from the 
     				structure. Getting parameter from structure.
     
     
*/
#include <iostream>//Standard Input/output streams libary
#include <iomanip>// Header providing parametric manipulators
#include <string>// string type header

using namespace std;
// typedef to use create an alias name for another data type.
typedef int integer;
typedef short int sint;
typedef string str;
typedef float flt;
typedef char ch;

//Structure Defination
struct Student
{
	//Structure members, fields
	str name, result;
	integer id;
	sint t1,t2,t3;
	flt average;
	ch grade;
	
};

// Function prototype
void setdata (Student&);
void calcaverage(Student&);
char calcgrade(Student&);
void message(Student&);
void print (Student);

//Main() Function Defination
//This function runs the whole program with step by step intruction written below.
//main() has calls and parameters of other function in the program.
int main()
{
	//Local Definations/ Declarlations
	//Initialization of structure student value.
	Student S;
	//Function calls
	setdata(S);
	print(S);
	
	return 0;	
}
//setdata() Function Defination
//This function is used to get input from the user.
//The input consist of Name, id number and test scores.
//It's return type is null, but it passes the value of all the parameters via reference.
void setdata (Student& S)
{
	//Local Definations/ Declarlations
	//Input Section to get name, id number and test scores.
	//Get's the student name
	cout<<"Enter the Student name: ";
	getline(cin,S.name);
	//Get's the id number of student
	cout<<"Enter the ID number: ";
	cin>> S.id;
	//Get test score 1
	cout<<"Enter test score 1: ";
	cin>> S.t1;
	//Get test score 2
	cout<<"Enter test score 2: ";
	cin>> S.t2;
	//Get test score 3
	cout<<"Enter test score 3: ";
	cin>> S.t3;
	
	return ;
	
}
//calcaverage() Function Defination
//This function is used to calculate average from three test scores.
//The input consist value passed by reference from setdata() of test scores.
//It's return type is null, but it passes the value of average total via reference to main() for further use.
void calcaverage(Student& S)
{
	//Calculate the average from three test score
	S.average = (float(S.t1+S.t2+S.t3))/3;
	
}
//calcgrade() Function Defination
//This function is used to give you final grade based on the average.
//The input consist value passed by reference from calcaverage() of average.
//It's return type is char, it returns grade to main() for further use.
char calcgrade(Student& S)
{
	//if condition to find out grade based on the average
	if (S.average >= 90)
		S.grade = 'A';
		else if ((S.average >=80)&&(S.average <90))
			S.grade = 'B';
			else if ((S.average >=70)&&(S.average <80))
				S.grade = 'C';
				else if ((S.average >=60)&&(S.average <70))
					S.grade = 'D';
					else if (S.average < 60)
						S.grade = 'F';
						
	return S.grade;			
}
//message() Function Defination
//This function is used to give you message based on your grade.
//The input consist value passed by reference from calcgrade() of grade.
//It's return type is void, but it returns results based on condition of grades.
void message(Student& S)
{
	//if condition for message based on grade.
	//if grade = A,B,C message should be passed
	if ((S.grade == 'A')||(S.grade == 'B')||(S.grade == 'C'))
		S.result = "You passed";
		// if grade = D,F message should be failed
		else if ((S.grade == 'D')||(S.grade == 'F'))
			S.result = "You Failed";		
}
//Print() function Defination
//This function is the output section of the program
//It output's the Name, Id, Test scores, average, grade and result.                .
//Name, ID, test scores, average, grade and result are passed by reference.
//it's return type is null.
void print (Student S)
{
	//function calls within print()
	calcaverage (S);
	calcgrade (S);
	message(S);	
	//output heading for the program
	//setprecision(2) prints answers in 2 decimal spaces.
	cout << fixed << showpoint << setprecision(2);
	cout<<endl<<endl;
	cout<<"****************************************"<<endl;
	cout<<"Student Name: "<<setw(26)<<S.name<<endl;
	cout<<"ID number: "<<setw(29)<<S.id<<endl;
	cout<<"Test: \n";
	cout<<setw(10)<<"1- "<<S.t1<<endl;
	cout<<setw(10)<<"2- "<<S.t2<<endl;
	cout<<setw(10)<<"3- "<<S.t3<<endl;
	cout<<"Average: "<<setw(31)<<S.average<<endl;
	cout<<"Grade: "<< setw(20)<< S.grade<<" "<<setw(12) <<S.result<< endl;
	cout<<"****************************************"<<endl;
	
	return ; 
}

