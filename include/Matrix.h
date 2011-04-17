// Template for representing a Matrix of any size and shape.
// Look at STL implementations (vector...)

#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>

template < typename _T >
class Matrix
{
  private:
    std::vector< _T > internals;
    unsigned int rows_, cols_;
    unsigned int _calcPos(unsigned int& row, unsigned int& col) const;

  protected:

  public:
    Matrix(unsigned int rows, unsigned int cols);
    void insert(unsigned int row, unsigned int col, _T value);
    _T at(unsigned int row, unsigned int col) const { return internals.at( _calcPos(row, col) ); }
    unsigned int rows() const { return rows_; }
    unsigned int cols() const { return cols_; }
    unsigned int size() const { return rows_ * cols_; }

// iterators
    _T* begin() const { return at(0, 0); }
    _T* end() const { return at(rows_ - 1, cols_ - 1 ); }

// Operator overloading
    _T& operator() (unsigned int row, unsigned int col);
    _T operator() (unsigned int row, unsigned int col) const;
};

template < typename _T >
Matrix< _T >::Matrix(unsigned int rows, unsigned int cols) : rows_(rows), cols_(cols)
{
    if(rows == 0 || cols == 0)
    {
        throw std::out_of_range("Matrix size should be > 0");
    }
    internals.assign( this->size() , 0);
}

template < typename _T >
inline
unsigned int Matrix< _T >::_calcPos(unsigned int& row, unsigned int& col) const
{
    if(row > rows_ - 1 || col > cols_ - 1 )
    {
         std::ostringstream oss;
         oss << "Exceeded Matrix limits at (" << row << ", " << col << "). Real limits (" << rows_ - 1 << ", " << cols_ - 1 << ")"; 
         throw std::out_of_range( oss.str() );
    }
    return row * cols_ + col;
}

template < typename _T >
void Matrix< _T >::insert(unsigned int row, unsigned int col, _T value)
{
    internals[ _calcPos(row, col) ] = value;
}

template < typename _T >
inline
_T& Matrix< _T >::operator() (unsigned row, unsigned col)
{
    return internals.at( _calcPos(row, col) );
}
 
template < typename _T >
inline
_T Matrix< _T >::operator() (unsigned row, unsigned col) const
{
    return internals.at( _calcPos(row, col) );
}


// Useful typedefs
//typedef Matrix<typename T, size, size> sqMatrix <typename T, int size>;
//typedef sqMatrix <typename T, 3> Matrix3 <typename T>;

