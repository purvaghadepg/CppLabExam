/*Q2
Write a program to print the area of two rectangles having sides (4,5) and (5,8) respectively 
by creating a class named 'Rectangle' with a function named 'Area' which returns the area. Length
*/

#include<iostream>
using namespace std;
class Rectangle
{
	private : float length,breadth,area;
			
	public : float Area(float x,float y)
				{
					length=x;
					breadth = y;
					float area=0;
					area=length*breadth;
					return(area);
				}
};
				
int main()
{
	float area;
	Rectangle r1,r2;


	cout<<"\n Area of rectangle 1 having sides length = 4 and breadth = 5 is : \n"<<r1.Area(4,5);

	cout<<"\n Area of rectangle 2 having sides length = 5 and breadth = 8 is : \n"<<r2.Area(5,8);
	
}
		
  