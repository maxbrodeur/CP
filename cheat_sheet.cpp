#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*-------------------C++CHEATSHEET---------------------//

Author: Max Brodeur

Description: Useful implementations for various
reccuring problems.

Includes:

GEOMETRY:
	- Polygon struct
	- Vector2D class

PATTERN MATCHING:
	- LPS + KMP for finding string/s in text

UTILITY:
	- print int arr
	- degrees to radians
	- setprecision
*/

//---------------------GEOMETRY------------------------//

//Pre-req
#include <utility>

// Polygon struct
struct Polygon {
	int n; //nb vertices
	pair<double,double>* vertices;

	Polygon (int n, pair<double,double>* vertices) {
		this->n = n;
		this->vertices = vertices;
	} 

	// get the area of the polygon (obviously just if the poly is a triangle lol)
	double triangle_area() {
		return abs(vertices[0].first*(vertices[1].second-vertices[2].second)+vertices[1].first*(vertices[2].second-vertices[0].second)+vertices[2].first*(vertices[0].second-vertices[1].second))/2.0;
	}

	// check if the point is inside the polygon
	bool is_inside(pair<double, double> point){
		double area = 0.0;
		for (int i = 0; i < n; ++i)
		{
			int j = (i+1)%n;
			pair<double, double> points[3];
			points[0] = vertices[i];
			points[1] = vertices[j];
			points[2] = point;
			Polygon triangle = Polygon(3, points);
			area += triangle.triangle_area();

		}
		return area == this->triangle_area();
	}


};

// 2D vector class for vector manip
//Pre-reqs
#include <cmath>
#include <iomanip>

//Vector class
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

//----------------------PATTERN MATCHING-----------------------//

// Knuth Morris Pratt Algorithm for finding strings in text

// LPS = Longest proper prefix which is also a suffix
void make_LPS(string pat, int* LPS){

	size_t M = pat.size();
	LPS[0]=0;
	size_t i = 1;
	size_t start = 0;
	while(i<M){
		if(pat[i]==pat[start]){ 
			start++;
			LPS[i]=start;
			i++;
		}else if(start!=0){ // iterate back to beggining (no i++ !!)
			start = LPS[start-1];
		}else{
			LPS[i]=0;
			i++;
		}
	}
}

// Return the index of the first occurence of the pattern in the text
int KMP_first(string pat, string text, int* LPS){
	int j = 0;
	for (int i = 0; i < text.size(); ++i)
	{

		while(j != 0 && pat[j]!=text[i]) {j=LPS[j-1];}
		if(pat[j]==text[i])j++;
		if(j==pat.size()){
			return i+1-pat.size();
			j=LPS[j-1];
		}
	}
	return -1;
}



// Return a vector containing the indices of all the occurences of pat in text
vector<int> KMP_all(string pat, string text, int* LPS){
	int j = 0;
	vector<int> ans;
	for (int i = 0; i < text.size(); ++i)
	{
		while(j != 0 && pat[j]!=text[i]) {j=LPS[j-1];}
		if(pat[j]==text[i])j++;
		if(j==pat.size()){
			ans.push_back(i+1-pat.size());
			j=LPS[j-1];
		}
	}
	return ans;
}



//-----------------------UTILITY------------------------//

//print an int array
void print_int_arr(int* arr, int size){
	cout<<"[";
	for (int i = 0; i < size; ++i)
	{
		cout<<" ";
		cout<<arr[i];
	}
	cout<<" ]"<<endl;
}


#include <iomanip>
#include <cmath>
void dummy(){

	// CALCULATE PI
	double pi = atan(1)*4;

	//CONVERT TO RADIANS
	double a = 324214331514;
	a = a*(pi/180.0); 

	//Specify the number of decimals to print / precision - include iomanip
	cout << fixed << setprecision(1) << pi << endl;



}


