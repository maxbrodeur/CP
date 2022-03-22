#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>


using namespace std;



struct Polygon {
	int n; //nb vertices
	pair<double,double>* vertices;

	Polygon (int n, pair<double,double>* vertices) {
		this->n = n;
		this->vertices = vertices;
	} 

	double triangle_area() {
		return abs(vertices[0].first*(vertices[1].second-vertices[2].second)+vertices[1].first*(vertices[2].second-vertices[0].second)+vertices[2].first*(vertices[0].second-vertices[1].second))/2.0;
	}

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

int main() {

	pair<double,double>* vertices = new pair<double,double>[3];

	cin >> vertices[0].first >> vertices[0].second >> vertices[1].first  >> vertices[1].second >> vertices[2].first  >> vertices[2].second;
	Polygon triangle = Polygon(3,vertices);
	cout << fixed << setprecision(1) << triangle.triangle_area() << endl;
	int n;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		pair<double, double> tree;
		cin >> tree.first >> tree.second;	
		if(triangle.is_inside(tree)) count++;
	}

	cout<<count<<endl;

	return 0;
}