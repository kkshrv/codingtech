class Point
{
    public:
        double x; double y;
        Point(double _x, double _y);
        Point();
        ~Point();
        void move(double delta_x, double delta_y);
};

class Line
{
    public:
        Point points[2];
        Line(Point _p1, Point _p2);
        ~Line();
        void move(double delta_x, double delta_y);
        void rotate(double angle);
};

class Parallelogram
{
    private:
        Point points[4];
    public:
        Parallelogram(Point _p1, Point _p2, Point _p3, Point _p4);
        Parallelogram(Line _l1, Line _l2);
        ~Parallelogram();
        void move(double delta_x, double delta_y);
        void rotate(double angle);
};

class Rhombus : virtual public Parallelogram
{
    public:
        Point points[4];
        using Parallelogram::Parallelogram;
};

class Rectangle : virtual public Parallelogram
{
    public:
        Point points[4];
        using Parallelogram::Parallelogram;
};

class Square : virtual public Parallelogram
{
    public:
        Point points[4];
        using Parallelogram::Parallelogram;
};
