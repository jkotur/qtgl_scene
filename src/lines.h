#ifndef LINES_H_0JYFXLCT
#define LINES_H_0JYFXLCT

#include <deque>

class Color {
public:
    float r;
    float g;
    float b;

    void rgb( float _r, float _g, float _b )
    {
        r = _r;
        g = _g;
        b = _b;
    }

};

class Lines {
public:
    class Point {
    public:
        Point( double x, double y ) : x(x), y(y)
        {
        }

        double x;
        double y;
        Color c;
    };

    typedef std::deque<Point> points_t;
    typedef points_t::iterator iterator;
    typedef points_t::const_iterator const_iterator;

    Point& add( double x, double y )
    {
        pts.emplace_back( x, y );
        return *pts.rbegin();
    }

    Point& at( unsigned i )
    {
        return pts[i];
    }

    size_t size() const { return pts.size(); }

    iterator begin() { return pts.begin(); }
    iterator end()   { return pts.end(); }
    const_iterator begin() const { return pts.begin(); }
    const_iterator end()   const { return pts.end(); }

protected:
    std::deque<Point> pts;
};

#endif /* end of include guard: LINES_H_0JYFXLCT */

