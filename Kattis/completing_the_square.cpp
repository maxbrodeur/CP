#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

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

	Vector2D operator -= (Vector2D vec){
		this->x -= vec.x;
		this->y -= vec.y;

		return *this;
	}

	Vector2D operator + (Vector2D vec) {
		return Vector2D(this->x + vec.x, this->y + vec.y);
	}

	Vector2D operator - (Vector2D vec) {
		return Vector2D(this->x - vec.x, this->y - vec.y);
	}

	// GIVE RADIANS
	void rotate(double a){
		double b = this->get_angle(); //current angle
		double len = this->get_length(); //current length

		b += a; // new angle

		this->y = sin(b)*len;
		this->x = cos(b)*len;
	}

	Vector2D scale(double r){
		double b = this->get_angle(); //current angle
		double len = this->get_length(); //current length

		len *= r; // new len

		this->y = sin(b)*len;
		this->x = cos(b)*len;

		return *this;
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

	double deg_to_rad(double deg){
		double pi = atan(1)*4;
		return deg*(pi/180.0);
	}

	double rad_to_deg(double rad){
		double pi = atan(1)*4;
		return rad*(180.0/pi);
	}

	void print(){
		cout<<setprecision(4);
		cout<<"x: "<<x;
		cout<<"\ty: "<<y;
		cout<<"\tlength: "<<this->get_length();
		cout<<"\tangle: "<<this->get_angle();
		cout<<endl;

	}

	double dot(Vector2D vec){
		return vec.x * this->x + vec.y * this->y;
	}

	double cross(Vector2D vec){
		return this->x * vec.y - this->y * vec.x;
	}

	// The triangle area formed by both vectors
	double triangle_area(Vector2D vec){
		return this->get_length() * vec.get_length() / 2.0;
	}

	// proj of this onto u
	Vector2D proj(Vector2D u){
		return u.scale(this->dot(u)/(u.get_length()*u.get_length()));
	}

	// angle between this and vec IN RADIANS
	double angle_between(Vector2D vec){
		return acos(this->dot(vec)/(this->get_length()*vec.get_length()));
	}

};

bool pred(Vector2D one, Vector2D two){
	return one.x <= two.x;
}


int main(){

	vector<Vector2D> vec;
	for (int i = 0; i < 3; ++i)
	{
		double x, y;
		cin >> x >> y;
		vec.push_back(Vector2D(x,y));
	}
	
	sort(vec.begin(),vec.end(), pred);

	Vector2D first = vec[1] - vec[0];
	Vector2D second = vec[2] - vec[0];

	Vector2D ans = Vector2D(0,0), side = Vector2D(0,0);

	if(first.get_length()>second.get_length()){
		ans = vec[0] + ( vec[1] - vec[2] );
	}else if(first.get_length()<second.get_length()){
		ans = vec[0] + ( vec[2] - vec[1] );
	}else{
		ans = vec[0] + first + second;
	}


	


	cout<< (int) ans.x << " " << (int) ans.y << endl;

	return 0;




}














