#include<iostream>
class Shape;//base class
class Shape{
public:
  Shape(int x, int y, int  dx, int dy);
protected:
  int center_x;
  int center_y;
  unsigned int width;
  unsigned int height;
  bool solid;
  int angle;
};
Shape::Shape(int x, int y, int dx, int dy) {
  center_x = x;
  center_y = y;
  width = dx;
  height = dy;
  solid = false;
  angle = 0;
}
class Rectangle: public Shape{
public:
  Rectangle(int x,int y,int dx,int dy);
  void call();
private:
  int name;
};
void Rectangle::call() {
  std::cout << width <<std::endl;
}

Rectangle::Rectangle(int x,int y,int dx,int dy):
Shape{x,y,dx,dy}{
}

class Eclipse: public Shape {
public:
  Eclipse(int x,int y,int dx,int dy);
private:
};
Eclipse::Eclipse(int x,int y,int dx,int dy):
Shape{x,y,dx,dy}{

}
class Polygon: public Shape {
public:
  Polygon(int x,int y, int dx, int dy, unsigned int n);
private:
  unsigned int num_sides;
};
Polygon::Polygon(int x,int y, int dx, int dy, unsigned int n):
Shape{x,y,dx,dy},
num_sides{n}{
}
class Star: public Polygon {
private:
  unsigned int sharpness;
};
int main() {
  Rectangle kay{1,1,1,1};
  kay.show();
}
