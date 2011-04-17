#include <vector>
#include <algorithm>
#include <sstream>
#include <stdexcept>

template< typename _T >
class Node
{
  private:
    _T Content;

  public:
    Node( _T& content ) : Content(content) { }
    _T content() const { return Content; }
};

template <typename _T>
class TriangleTree
{
  private:
    std::vector< Node<_T>* > tree;
    unsigned int floors_max;
    unsigned int _calcPos(unsigned int floor, unsigned int room);

  public:
    TriangleTree() { }
    void add( _T value );
    Node<_T>* at(unsigned int floor, unsigned int room) { return this->tree.at( this->_calcPos(floor, room) ); }
    unsigned int lastFloor() const { return floors_max; }

// Iterators

// Operator overloads
    Node<_T>* operator() (unsigned int row, unsigned int col);
    Node<_T>* operator() (unsigned int row, unsigned int col) const;
};

template < typename _T >
unsigned int TriangleTree< _T >::_calcPos(unsigned int floor, unsigned int room)
{
    if(room > floor || floor > floors_max)
    {
        std::ostringstream oss;
        oss << "Exceeded Triangle Tree bounds at (" << floor << ", " << room << ").";
        throw std::out_of_range( oss.str() );    
    }
    unsigned int sum = 0;
    for(unsigned int i = 0; i <= floor; ++i)
    {
        sum += i;
    }
    return sum += room + 1;
}

template < typename _T >
void TriangleTree< _T >::add( _T value )
{
    tree.push_back( new Node< _T >( value ) );
    if( this->_calcPos(this->floors_max, 0) < tree.size() - 1 )
    {
        ++this->floors_max;
    }
}
