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

bool BoxContainer::remove_item(const value_type& item){

    size_t index{m_capacity + 999};

    for(size_t i{}; i<m_size; ++i){
        if(m_items[i] == item){
            index = i;
            break;
        }
    }

    if(index > m_size){
        return false;
    }

    m_items[index] = m_items[m_size - 1];
    --m_size;
    return true;

}   

size_t BoxContainer::remove_all(const value_type& item) {
    size_t count{};

    while (remove_item(item)) {
        ++count;
    }

    return count;
}


void BoxContainer::operator+=(const BoxContainer& operand){
    //Check if we need to expand the current box
    if((m_size + operand.m_size) > m_capacity){
        expand(m_size + operand.m_size);
    }
    
    //Copy the items from the operand box into this box
    for(size_t i{}; i<operand.m_size; ++i){
        m_items[m_size + i] = operand.m_items[i];
    }

    m_size += operand.m_size;
    
}

void BoxContainer::operator=(const BoxContainer& source){

    value_type* new_items;

    if(this == &source){
        return;
    }

    if(m_capacity < source.m_capacity){

        new_items = new value_type[source.m_capacity];
        delete[] m_items;
        m_items = new_items;
        m_capacity = source.m_capacity;
    }

    for(size_t i{}; i<source.m_size; ++i){
        m_items[i] = source.m_items[i];
    }

    m_size = source.m_size;

}
    
BoxContainer operator+(const BoxContainer& left, const BoxContainer& right){
    BoxContainer result(left.size() + right.size());
    result += left;
    result += right;
    return result;
}

BoxContainer operator+(const BoxContainer& left, const BoxContainer& right) {
    BoxContainer result(left);
    result += right;
    return result;
}