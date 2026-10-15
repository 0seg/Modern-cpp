#include "boxcontainer.h"

BoxContainer::BoxContainer(size_t capacity){

    m_items = new value_type[capacity];
    m_capacity = capacity;
    m_size = 0;

}

BoxContainer::BoxContainer(const BoxContainer& source){

    //Set up the new box
    m_items = new value_type[source.m_capacity];
    m_capacity = source.m_capacity;
    m_size = source.m_size;

    //Copy the items over from source
    for(size_t i{}; i<m_size; ++i){
        m_items[i] = source.m_items[i];
    }

}

BoxContainer::~BoxContainer(){

    delete[] m_items;

}

void BoxContainer::stream_insert(std::ostream& out) const{

    out << "BoxContainer: size = " << m_size << ", capacity = " << m_capacity << std::endl;

    for(size_t i{}; i<m_size; ++i){
        out << m_items[i] << " ";
    }

    out << std::endl;

}

void BoxContainer::add(const value_type& item){

    if(m_size == m_capacity){
        expand(m_capacity + EXPAND_SIZE);
    }

    m_items[m_size] = item;
    ++m_size;

}

void BoxContainer::expand(size_t new_capacity){

    if(new_capacity <= m_capacity){
        return;
    }
    
    value_type* new_items = new value_type[new_capacity];


    for(size_t i{}; i<m_size; ++i){
        new_items[i] = m_items[i];
    }

    delete[] m_items;
    m_items = new_items;
    m_capacity = new_capacity;

}