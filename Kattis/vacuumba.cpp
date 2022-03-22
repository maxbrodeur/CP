#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Vector2D {
	double x, y;
	double a;

	Vector2D(double x, double y){
		this->x = x;
		this->y = y;

	}

	Vector2D operator += (Vector2D vec){
		this->x += vec.x;
		this->y += vec.y;

		return *this;
	}

	Vector2D operator + (Vector2D vec) {
		return Vector2D(x + vec.x, y + vec.y);
	}

	// GIVE RADIANS
	void rotate(double a){
		double b = this->get_angle(); //current angle
		double len = this->get_length(); //current length

		b += a; // new angle

		this->y = sin(b)*len;
		this->x = cos(b)*len;
	}

	void scale(double r){
		double b = this->get_angle(); //current angle
		double len = this->get_length(); //current length

		len *= r; // new len

		this->y = sin(b)*len;
		this->x = cos(b)*len;
	}

	double get_angle(){
		if(y==0.0 && x>0.0) return 0.0;
		if(y==0.0 && x<0.0) return atan(1)*4;
		if(x!=0)return atan(y/x);
		if(y==0)return 0;
		return atan(1)*4/2; //THIS IS PI/2
	}

	double get_length(){
		return sqrt(x*x + y*y); 
	}

	void print(){
		cout<<setprecision(4);
		cout<<"x: "<<x;
		cout<<"\ty: "<<y;
		cout<<"\tlength: "<<this->get_length();
		cout<<"\tangle: "<<this->get_angle();
		cout<<endl;

	}

};

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;

		Vector2D vec = Vector2D(0, 0);
		double angle = atan(1)*4/2;
		for (int i = 0; i < m; ++i)
		{
			double r, a;
			cin >> a >> r;

			Vector2D temp = Vector2D(r,0);

			double pi = atan(1)*4;
			a = a*(pi/180.0); //CONVERT TO RADIANS

			angle += a;

			temp.rotate(angle);

			vec += temp;
	

		}

		cout<<fixed<<setprecision(6)<<vec.x<<" "<<vec.y<<endl;
	}
}