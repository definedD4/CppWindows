//
// Created by Dima on 28.05.2016.
//

#ifndef CPPWINDOWS_POINT_H
#define CPPWINDOWS_POINT_H

#include <ostream>

namespace cw{
    namespace ut {

        class Point {
        private:
            int x_, y_;

        public:
            Point() : x_(0), y_(0) { }
            Point(const class Point& src) : x_(src.x_), y_(src.y_) { }
            Point(int x_, int y_) : x_(x_), y_(y_) { }

            int x() const { return x_; }
            int y() const { return y_; }
        };

        inline std::ostream& operator <<(std::ostream& stream, const Point& point){
            stream << '(' << point.x() << ',' << point.y() << ')';
        }

        inline Point operator +(const Point& left, int right){
            return Point(left.x() + right, left.y() + right);
        }

        inline Point operator +(const Point& left, const Point& right){
            return Point(left.x() + right.x(), left.y() + right.y());
        }
    }
}

#endif //CPPWINDOWS_POINT_H
