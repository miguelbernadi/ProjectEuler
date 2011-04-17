#include <fstream>
#include <string>
#include <stdexcept>

class File
{
  private:
    std::string filename;
    std::fstream* fstream;
    bool _fileExists();
  public:
    File();
    File(std::string const & filename) : filename(filename) { }
    std::string& getFilename() const;
    void setFilename(std::string const& filename);
    void read();
};

bool File::_fileExists()
{
    this->fstream = new std::ifstream( filename.c_str() );
    if( !fstream )
    {
//        throw 
        return false;
    }
    else
    {
        return true;
    }
}

std::string& File::getFilename() const
{
    return this->filename;
}

void File::setFilename(std::string const& str) 
{
    this->filename = str;
}

/*
void File::read()
{
    this->_fileExists();
    while( fstream >> i )
    {
    {    
}
*/

