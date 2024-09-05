#include <iostream>
using namespace std;
//#define pi 3.1
double area(double r);
void get_r();

double area(double r){
	  return  r*r;
}

class circle{
	private:
		 double r;
		 double pi;
    public:
    	double area();
    	double get_r(){
    	return r;	
		}
		double set_r(double rr){
			r=rr;	
		}
};
int main(){
	circle c;
	c.set_r(2.5);
	cout<<c.get_r()<<endl;
	return 0;
	  
}

