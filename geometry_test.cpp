#include "geometry.h"
#include <iostream>


int main() {
    Square* square = new Square(Point(0, 0), Point(40, 0), Point(40, 40), Point(0, 40));
    square->move(2,2);
    square->rotate(90);

    Rectangle* rectangle = new Rectangle(Point(0, 0), Point(40, 0), Point(40, 40), Point(0, 40));
    rectangle->move(2,2);
    rectangle->rotate(90);

    Parallelogram* parallelogram = new Parallelogram(Point(0, 0), Point(40, 0), Point(40, 40), Point(0, 40));
    parallelogram->move(2,2);
    parallelogram->rotate(90);

    Rhombus* rhombus = new Rhombus(Point(0, 0), Point(40, 0), Point(40, 40), Point(0, 40));
    rhombus->move(2,2);
    rhombus->rotate(90);

    Line* line1 = new Line(Point(0, 0), Point(40, 0));
    line1->move(2,2);
    line1->move(-2, -2);
    line1->rotate(90);

    Line* line2 = new Line(Point(0, 40), Point(40, 40));
    Rectangle* rectangle1 = new Rectangle(*line1, *line2);

    // delete (erase) all objects
    delete square;
    delete rectangle;
    delete parallelogram;
    delete rhombus;
    delete line1;
    delete line2;
    delete rectangle1;

    return 0;
}
