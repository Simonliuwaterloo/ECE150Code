#include <iostream>
#include <cmath>
#include <string>
int main();


struct point_t;
struct point_t{
	int x;
	int y;
};
double distance( point_t u, point_t v);
double distance( point_t u, point_t v){
	return sqrt(pow(v.x - u.x, 2) + pow(v.y - u.y, 2));
}
int main(){
  point_t a;
  a.x = 1;
  a.y = 2;
  point_t b;
  b.x = 2;
  b.y =4;
  std::cout << distance(a, b);

}
