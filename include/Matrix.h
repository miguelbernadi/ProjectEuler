// Template for representing a Matrix of any size and shape.
// Look at STL implementations (vector...)

#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>

/**
 * Template representing a Matrix of any size and shape.
 */

template < typename _T >
class Matrix
{
  private:
    /**
     * Vector for internal storage.
     */
    std::vector< _T > internals;

    /**
     * Total number of rows and columns of the matrix.
     */
    unsigned int rows_, cols_;

    /**
     * Calculates the position inside the vector for given coordinates.
     *
     * @param row coordinate
     * @param column coordinate
     * @throw out_of_range exception
     */
    unsigned int _calcPos(unsigned int& row, unsigned int& col) const;

    /**
     * Flag to check if the Matrix is squared.
     */
    bool square;

  public:
    /// Default constructor.
    Matrix() { }
    
    /**
     * 
     */
    Matrix(unsigned int rows, unsigned int cols);

    /**
     * Overwrites a cell's value.
     *
     * @param row coordinate
     * @param column coordinate
     * @param overwrite value
     */
    void insert(unsigned int row, unsigned int col, _T value);

    _T& at(unsigned int row, unsigned int col) { return this->internals.at( _calcPos(row, col) ); }
    _T at(unsigned int row, unsigned int col) const { return this->internals.at( _calcPos(row, col) ); }
    unsigned int rows() const { return this->rows_; }
    unsigned int cols() const { return this->cols_; }
    unsigned int size() const { return this->internals.size(); }
    bool isSquare() const { return this->square; }

    Matrix< _T > transpose();
    Matrix< _T > invert();

// Iterators
    /**
     * Returns the first element of the Matrix.
     */
    _T* begin() const { return this->at(0, 0); }
    
    /**
     * Returns the last element of the Matrix.
     */
    _T* end() const { return this->at(rows_ - 1, cols_ - 1 ); }

// Operator overloading
    /**
     * Accessor operators overloaded. Matrix(row, column) is the same as at(row, column).
     */
    _T& operator() (unsigned int row, unsigned int col);

    /**
     * Accessor operators overloaded. Matrix(row, column) is the same as at(row, column).
     */
    _T operator() (unsigned int row, unsigned int col) const;

    Matrix< _T > operator* (Matrix< _T > mat);
};

template < typename _T >
Matrix< _T >::Matrix(unsigned int rows, unsigned int cols) : rows_(rows), cols_(cols), square(false)
{
    if(rows == 0 || cols == 0)
    {
        throw std::out_of_range("Matrix size should be > 0");
    }
    if(rows == cols)
    {
        this->square = true;
    }
    internals.assign( this->size() , 0);
}

template < typename _T >
inline
unsigned int Matrix< _T >::_calcPos(unsigned int& row, unsigned int& col) const
{
    if(row > this->rows_ - 1 || col > this->cols_ - 1 )
    {
         std::ostringstream oss;
         oss << "Exceeded Matrix limits at (" << row << ", " << col << "). Real limits (" << rows_ - 1 << ", " << cols_ - 1 << ")"; 
         throw std::out_of_range( oss.str() );
    }
    return row * this->cols_ + col;
}

template < typename _T >
void Matrix< _T >::insert(unsigned int row, unsigned int col, _T value)
{
    this->internals.at( this->_calcPos(row, col) ) = value;
}

template < typename _T >
inline
_T& Matrix< _T >::operator() (unsigned row, unsigned col)
{
    return this->internals.at( this->_calcPos(row, col) );
}
 
template < typename _T >
inline
_T Matrix< _T >::operator() (unsigned row, unsigned col) const
{
    return this->internals.at( this->_calcPos(row, col) );
}


// Useful typedefs
//typedef Matrix<typename T, size, size> sqMatrix <typename T, int size>;
//typedef sqMatrix <typename T, 3> Matrix3 <typename T>;

