//
// Created by Dima on 28.05.2016.
//

#ifndef CPPWINDOWS_SIZE_H
#define CPPWINDOWS_SIZE_H

#include <ostream>

namespace cw{
    namespace ut {

        class Size {
        public:
            int w, h;

            Size() : w(0), h(0) { }
            Size(const Size& src) : w(src.w), h(src.h) { }
            Size(int w_, int h_) : w(w_), h(h_) { }
        };

        std::ostream& operator <<(std::ostream& stream, const Size& size){
            stream << '(' << size.w << ',' << size.h << ')';
        }

    }
}

#endif //CPPWINDOWS_SIZE_H
