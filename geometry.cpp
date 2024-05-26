#include "geometry.h"
#include "math.h"

Point::Point(double _x, double _y)
{
    this->x = _x;
    this->y = _y;
}

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::~Point() {}

void Point::move(double delta_x, double delta_y)
{
    this->x += delta_x;
    this->y += delta_y;
}

Line::Line(Point _p1, Point _p2)
{
    this->points[0] = _p1;
    this->points[1] = _p2;
}

Line::~Line() {}

void Line::move(double delta_x, double delta_y)
{
    for (int i = 0; i < 2; i++)
    {
        this->points[i].x += delta_x;
        this->points[i].y += delta_y;
    }
}

void Line::rotate(double angle)
{
    for (int i = 0; i < 2; i++)
    {
        this->points[i].x = this->points[i].x * cos(angle) - this->points[i].y * sin(angle);
        this->points[i].y = this->points[i].x * sin(angle) + this->points[i].y * cos(angle);
    }
}

Parallelogram::Parallelogram(Point _p1, Point _p2, Point _p3, Point _p4)
{
    this->points[0] = _p1;
    this->points[1] = _p2;
    this->points[2] = _p3;
    this->points[3] = _p4;
}

Parallelogram::Parallelogram(Line _l1, Line _l2)
{
    this->points[0] = _l1.points[0];
    this->points[1] = _l1.points[1];
    this->points[2] = _l2.points[0];
    this->points[3] = _l2.points[1];
}

Parallelogram::~Parallelogram() {}

void Parallelogram:: move(double delta_x, double delta_y)
{
    for (int i = 0; i < 4; i++)
    {
        this->points[i].x += delta_x;
        this->points[i].y += delta_y;
    }
}

void Parallelogram::rotate(double angle)
{
    for (int i = 0; i < 4; i++)
    {
        this->points[i].x = this->points[i].x * cos(angle) - this->points[i].y * sin(angle);
        this->points[i].y = this->points[i].x * sin(angle) + this->points[i].y * cos(angle);
    }
}
