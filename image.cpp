module;
#include <sstream>
#include <cmath>
#include <string>

export module image;

export struct rgbcolor
{
    int red;
    int green;
    int blue;
};

export class ujimage
{
public:
  // Default constructor chains to parameterized constructor
    ujimage() : ujimage(0, 0) {}

    // Parameterized constructor
    ujimage(int row, int col) : _rows(row), _cols(col), _image(nullptr)
    {
        if (row > 0 && col > 0) {
            alloc(row, col);
        }
    }

    // Copy constructor chains to parameterized constructor
    ujimage(const ujimage& copy) : ujimage(copy._rows, copy._cols)
    {
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                _image[i][j] = copy._image[i][j];
    }
    //destructor
    ~ujimage()
    {
        dealloc();
    }
    //mutator
    void setPixel(int row, int col, rgbcolor color)
    {
        if (row >= 0 && row < _rows && col >= 0 && col < _cols)
            _image[row][col] = color;
    }
    
    std::string toPPM() const
    {
        std::stringstream ss;
        // Header
        ss << "P3\n" << _cols << " " << _rows << "\n255\n";
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                ss << _image[i][j].red << " "
                   << _image[i][j].green << " "
                   << _image[i][j].blue << " ";
            }
            ss << "\n";
        }
        return ss.str();
    }
    
    // Accessor methods for rows and cols
    int getRows() const { return _rows; }
    int getCols() const { return _cols; }

protected:
    // Allocates memory
    void alloc(int row, int col)
    {
        _rows = row;
        _cols = col;
        _image = new rgbcolor*[row];
        for (int i = 0; i < row; i++)
        {
            _image[i] = new rgbcolor[col];
            for (int j = 0; j < col; j++)
            {
                _image[i][j] = {255, 255, 255}; // Initialize to white
            }
        }
    }
    
    // Deallocates memory
    void dealloc()
    {
        if (_image)
        {
            for (int i = 0; i < _rows; i++)
                delete[] _image[i];
            delete[] _image;
            _image = nullptr;
        }
        _rows = 0;
        _cols = 0;
    }
    
    rgbcolor** _image;
    int _rows;
    int _cols;
};
