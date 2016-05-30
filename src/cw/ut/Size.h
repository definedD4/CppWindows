//
// Created by Dima on 28.05.2016.
//

#ifndef CPPWINDOWS_SIZE_H
#define CPPWINDOWS_SIZE_H

#include <ostream>

namespace cw{
    namespace ut {

        class Size {
        private:
            int w_, h_;

        public:
            Size() : w_(0), h_(0) { }
            Size(const Size& src) : w_(src.w_), h_(src.h_) { }
            Size(int w_, int h_) : w_(w_), h_(h_) { }

            int w() const { return w_;}
            int h() const { return h_;}
        };

        inline std::ostream& operator <<(std::ostream& stream, const Size& size){
            stream << '(' << size.w() << ',' << size.h() << ')';
			return stream;
        }

    }
}

#endif //CPPWINDOWS_SIZE_H
