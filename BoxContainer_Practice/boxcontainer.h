#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H
#include "stream_insertable.h"

class BoxContainer : public StreamInsertable{

    using value_type = int;

    static const size_t DEFAULT_CAPACITY = 30;

    public:
        BoxContainer(size_t capacity = DEFAULT_CAPACITY);
        BoxContainer(const BoxContainer& source);
        ~BoxContainer();

        //streamInsertable interface

        virtual void stream_insert(std::ostream& out) const override; 

        // helper getter methods

        size_t size( ) const {return m_size;}
        size_t capacity( ) const {return m_capacity;}

        void dummy_initialize(){

            for(size_t i{}; i<10; ++i){
                m_items[i] = i + 12;
            }

            m_size = 10;
        }

    private:  

        value_type* m_items;
        size_t m_size;
        size_t m_capacity;
};