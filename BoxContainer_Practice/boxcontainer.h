#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H
#include "stream_insertable.h"

class BoxContainer : public StreamInsertable{

    using value_type = int;

    static const size_t DEFAULT_CAPACITY = 30;
    static const size_t EXPAND_SIZE = 10;

    public:
        BoxContainer(size_t capacity = DEFAULT_CAPACITY);
        BoxContainer(const BoxContainer& source);
        ~BoxContainer();

        //streamInsertable interface

        virtual void stream_insert(std::ostream& out) const override; 

        // helper getter methods

        size_t size( ) const {return m_size;}
        size_t capacity( ) const {return m_capacity;}

        void add(const value_type& item);

        //remove items

        bool remove_item(const value_type& item);
        size_t remove_all(const value_type& item);
        
    private:
        
        void expand(size_t new_capacity);


    private:  

        value_type* m_items;
        size_t m_size;
        size_t m_capacity;
};