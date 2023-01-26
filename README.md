# Competitive Programming [Cheat Sheet](./cheat_sheet.cpp)

Useful implementations for various
reccuring problems.

Includes:

1. NUMBER THEORY
	- [Fibonacci](#fibonacci)
	- [Factorization](#factorization)
	- [Is base 10 palindrome](#is-base-10-palindrome)
	- [GCD](#gcd)

2. GEOMETRY:
	- [Polygon struct](#polygon-struct)
	- [Vector2D struct](#polygon-struct)
	
3. PATTERN MATCHING:
	- [LPS + KMP](#kmp) for finding string/s in text (*Longest Prefix Suffix & Knuth Morris Pratt*)

4. DATA STRUCTURES
	- [Disjoint Sets](#disjoint-sets)
	
5. UTILITY:
	- [Print int array](#print-int-array)
	- [Calculate pi](#pi)
	- [Convert degrees to radians](#convert-to-radians)
	- [Set precision of output](#set-precision) (number of digits)

# NUMBER THEORY

## Fibonacci
Recursive with memoization
```cpp
#define size 4000001

unsigned mem[size] = {0};
bool checked[size] = {false};

// returns the unsigned fibonnaci number
unsigned fib(unsigned N) {
    if (!checked[N]){
        mem[N]=fib(N-1)+fib(N-2);
        checked[N]=true;
    }
    return mem[N];
}
```

## Factorization

```cpp
#include <vector>
vector<long> factorization(long N){
    vector<long> factors;
    for (size_t d = 2; d*d <= N; d++)
    {
        while(N%d==0){
            N /= d;
            factors.push_back(d);
        }
    }
    if (N>1)
    {
        factors.push_back(N);
    }
    return factors;
}
```

## is base 10 palindrome

```cpp
#include <vector>
bool is_base10_palindrome(long N){
    vector<int> digits;
    int count = 0;
    while (N>0)
    {
        int temp = N;
        N/=10;
        int digit = temp - N*10;
        digits.push_back(digit);
        count++;
    }
    vector<int>::iterator bot = digits.begin();
    vector<int>::iterator top = digits.end();
    int i = 0;
    while(i<count/2){
        top--;
        if(*bot!=*top){
            return false;
        }
        bot++;
        i++;
    }
    return true;   
}
```

## GCD
```cpp
long gcd(long a, long b){
    long r;
    // express a = b*n + r
    while(b>0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
```

# GEOMETRY

## Polygon Struct

```cpp
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
```

### Vector 2D struct

```cpp
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
```

# PATTERN MATCHING

## KMP

```cpp
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
```

# DATA STRUCTURES

## Disjoint Sets
```cpp
class DisjSet{
	int *L, n;

public:

	DisjSet(int n){

		L = new int[n];
		this->n = n;
		make_set();


	}

	void make_set(){

		for (int i = 0; i < n; ++i)
		{
			L[i] = i;
		}

	}

	int find(int x){
		int root = x;
		while(root!=L[root])root = L[root];
		while(x!=L[x]){
			int next = L[x];
			L[x] = root;
			x = next;
		}
		return x;
	}

	void Union(int x, int y){
		L[find(x)] = find(y);
	}

};
```

# Utility

## Print int array
```cpp
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
```

## pi
```cpp
double pi = atan(1)*4;
```

## Convert to radians 
```cpp
a = a*(pi/180.0);
```

## Set Precision
```cpp
cout << fixed << setprecision(1) << pi << endl;
```

## Specify c++ version
```
g++ -std=c++17 [FILENAME].cpp
```

### Link to [Kattis Profile](https://open.kattis.com/users/max-brodeur)
