//
// Created by Dima on 28.05.2016.
//

#ifndef CPPWINDOWS_AREA_H
#define CPPWINDOWS_AREA_H

#include <vector>
#include <algorithm>

#include "../ut/Size.h"
#include "../ut/Point.h"

namespace cw {
    namespace st {

        class Area {
        private:
            ut::Point m_Pos;
            ut::Size m_Size;

            Area* m_Parrent;
            std::vector<Area*> m_Children;

        public:
            Area() = delete;
            Area(const Area& src) = delete;
            Area(const Area&& src) = delete;
            Area(Area* parrent);
            ~Area();

            bool isRoot() const { return m_Parrent == nullptr; }
            bool isLeaf() const { return m_Children.size() == 0; }
            bool isNode() const { return !(isRoot() || isLeaf()); }

            Area* getParrent() const { return m_Parrent; }
            const std::vector<Area*> getChildren() const { return m_Children; }

            ut::Point getPos() const { return m_Pos; }
            void setPos(const ut::Point &Pos) { m_Pos = Pos; }
            ut::Size getSize() const { return m_Size; }
            void setSize(const ut::Size &Size) { m_Size = Size; }

            ut::Point getGlobalPos() const;
        };

    }
}

#endif //CPPWINDOWS_AREA_H
