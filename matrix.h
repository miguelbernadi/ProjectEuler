// MatrixIterator...
class Matrix
{
  private:
    int rows, cols;
    int matrixarray;
    int pos;
    const int begin;
    const int end;
    int setpos(int rownumber, int colnumber);
  protected:

  public:
    Matrix(int rows, int cols);
    int access(int rownumber, int colnumber);
    int next();
    int add(int number);
    int add(int rownumber, int colnumber, int number);
    int dump();
};

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), pos(0), begin(0), end(rows*cols) {};

int Matrix::setpos(int rownumber, int colnumber)
{
    if(rownumber > rows || colnumber > cols || rownumber < 1 || colnumber < 0)
    {
        return 1;
    }
    pos = (rownumber - 1) * cols + colnumber;
    return 0;
}

// Devuelve el contenido de la celda
int Matrix::access(int rownumber, int colnumber)
{
    if( setpos(rownumber, colnumber) )
    {
        return this->matrixarray[pos];
    }
    return 1;
}

int Matrix::next()
{
    pos++;
    if(pos <= end)
    {
        return 0;
    }
    return 1;
}

int Matrix::add(int number)
{
    this->matrixarray[pos] = number;
    return 0;
}

int Matrix::add(int rownumber, int colnumber, int number)
{
    if( setpos(rownumber, colnumber) )
    {
        matrixarray[pos] = number;
        return 0;
    }
    return 1;
}

int Matrix::dump()
{

    return 0;
}