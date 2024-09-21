/* Q.No. 3
Create a class 'Student' with three data members which are name, age and address. 
The constructor of the class assigns default values to name as "unknown", age as '0' and address as "not available".
 It has two functions with the same name 'setInfo'. 
 First function has two parameters for name and age and assigns the same 
 whereas the second function takes has three parameters which are assigned to name, age and address respectively. 
 Print the name, age and address of 10 students.
 Use array of objects.
*/

#include<iostream>
using namespace std;
class Student
{
	private : string name, address;
			  int age;
			  
	public : Student(string n="unknown",int a=0,string add="not available")
				{
					name=n;
					age=a;
					address=add;
				}
				
				void setInfo(string sname, int s_age)
				{
					name=sname;
					age=s_age;

				}
				void setInfo(string st_name,int s_a,string s_add)
				{
					name=st_name;
					s_a=age;
					s_add=address;

				}
				void showdata()
				{
					cout<<"\n Name of student is :"<<name;
					cout<<"\n Age is :"<<age;
					cout<<"\n Address :"<<address;
				}
};

int main()
{	int n=10;
	Student s[10] = {(Student("Purva",26,"nashik")),
					(Student("ankita",25,"pune")),
					(Student("Pratima",21,"pune")),
					(Student("John")),
					(Student("Sam",26,"karnataka")),
					(Student("Aditi",22,"nagpur")),
					(Student("Samantha",29,"nashik")),
					(Student("Shiv",26,"nashik")),
					(Student("Kajal",30,"chennai")),
					(Student("Seema",25))
					
					};
					for(int i=0;i<n;i++)
					{
						s[i].showdata();
					}
}