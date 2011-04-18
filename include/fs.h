#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

/* Complete later.
class FileException : public runtime_error
{
  public:
    FileException(std::string str) { }
};
*/

// Add path parsing abilities to distinguish /home/usr/ and foo.txt,
// recreate paths and abstract from platform dependent paths.
class FileDescriptor
{
  private:
    std::string filename, path;

  public:
    FileDescriptor(std::string str) : filename(str), path("") { }
    FileDescriptor(std::string filename, std::string path) : filename(filename), path(path) { }
    FileDescriptor(std::string& filename, std::string& path) : filename(filename), path(path) { }
    std::string filePath() const { return this->path + this->filename; }
    std::string fileName() const { return this->filename; }
};

// Be careful with loose streams (changing from read to write streams several times 
// may create lots of fstreams that are not taken care of. Be careful.
class File
{
  private:
    FileDescriptor* filed;
    std::ifstream* fstream;

  public:
    File();
    File(std::string& filename) : filed( new FileDescriptor(filename) ) { } 
    ~File() { delete filed; delete fstream; }
    std::string getFilename() const { this->filed->filePath(); }
    void setFilename(std::string& filename);
    bool _fileExists();
    std::ifstream* getIStream() { this->_fileExists(); return this->fstream; }
//    std::ofstream getOStream() const { this->fstream = new std::ofstream( this->filed->filePath().c_str() ); return *this->fstream; }
//    std::fstream& getFStream() { this->fstream = new std::fstream( this->filed->filePath().c_str() ); return *this->fstream; }
};

bool File::_fileExists()
{
    this->fstream = new std::ifstream( this->filed->filePath().c_str() );
    if( !fstream )
    {
        std::ostringstream oss;
        oss << "Failed to open file " << this->filed->filePath();
        throw std::runtime_error( oss.str() );
// check        throw std::runtime_error( "Failed to open file " + this->filed->filePath() );
        return false;
    }
    else
    {
        return true;
    }
}

void File::setFilename(std::string& str) 
{
    this->filed = new FileDescriptor( str );
}

