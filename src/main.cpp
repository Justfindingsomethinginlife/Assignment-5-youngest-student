#include <iostream>
#include <cstring>
#include <climits>

class student
{
private:
	int age;
	double gpa;
	char* name;

public:
	student();
	~student();

	void set_all(char* name, int age, double gpa);
	void print();
};

student::student()
{
	name = new char[1000]; 
}

student::~student()
{
	delete []name; 
}

void student::set_all(char* name, int age, double gpa)
{
	strncpy(this->name, name, 1000);
	this->age = age;
	this->gpa = gpa;
}

void student::print()
{
	std::cout << "Name: " << name << "\n";
	std::cout << "Age: " << age << "\n";
	std::cout << "GPA: " << gpa << std::endl;
}

int main(int argc, char ** argv)
{
	student *p;
	int i,c,n=(argc-1)/3;
	int mark=0, lo = INT_MIN;

	p = new student[n];
	
	for(c=0, i=1;c<n;c++, i+=3)
	{
		p[c].set_all(argv[i], atoi(argv[i+1]), atof(argv[i+2]));
		if(lo > atoi(argv[i+1]))
		{
			lo = atoi(argv[i+1]);
			mark=c;
		}
	}
	
	if(n != 0)
	{	
		printf("Youngest Student\n");
		p[mark].print();
	}
	
	delete []p;

	return 0;
}
