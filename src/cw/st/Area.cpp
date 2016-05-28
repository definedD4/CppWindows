//
// Created by Dima on 28.05.2016.
//

#include "Area.h"

namespace cw {
    namespace st {

        Area::Area(Area *parrent) {
            m_Parrent = parrent;

            if(!isRoot()){ // element is not root
                m_Parrent->m_Children.push_back(this);
            }
        }

        Area::~Area() {
            for(Area* child : m_Children){
                delete child;
            }

            if(!isRoot()){ // element is not root
                m_Parrent->m_Children.erase(std::find(m_Parrent->m_Children.begin(),
                                                      m_Parrent->m_Children.end(),
                this));
            }
        }

        //TODO: Add global position caching and lazy computation.
        ut::Point Area::getGlobalPos() const {
            if(isRoot()) {
                return m_Pos;
            }
            return m_Pos + m_Parrent->getGlobalPos();
        }
    }
}

