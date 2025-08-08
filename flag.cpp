module;
#include <cmath>
#include <string>
import image;

export module flag;

export enum flagtyp
{
    japan,
    austria,
    nigeria
};

export class flagIllustrator
{
public:
    // Constructors
    flagIllustrator() : _image() {}
    
    flagIllustrator(int row, int col) : _image(row, col) {}
    
    ~flagIllustrator() {}
    
    // Accessor function
    void illustrateFlag(flagtyp type)
    {
        switch (type)
        {
            case japan:
                drawJapanFlag();
                break;
            case austria:
                drawAustriaFlag();
                break;
            case nigeria:
                drawNigeriaFlag();
                break;
        }
    }
    
    // Delegate to ujimage's toPPM
    std::string toPPM() const
    {
        return _image.toPPM();
    }

private:
//compodition
    ujimage _image; 

    void drawJapanFlag()
    {
        // White background with red circle in center
        int centerX = _image.getCols() / 2;
        int centerY = _image.getRows() / 2;
        int radius = std::min(_image.getRows(), _image.getCols()) / 3;
        
        for (int i = 0; i < _image.getRows(); i++)
        {
            for (int j = 0; j < _image.getCols(); j++)
            {
                // Calculate distance from center
                double distance = std::sqrt(std::pow(i - centerY, 2) + std::pow(j - centerX, 2));
                if (distance <= radius)
					// Red circle
                    _image.setPixel(i, j, {255, 0, 0}); 
                else
                    _image.setPixel(i, j, {255, 255, 255}); // White background
            }
        }
    }
    
    void drawAustriaFlag()
    {
        // Three horizontal stripes
        int stripeHeight = _image.getRows() / 3;
        
        for (int i = 0; i < _image.getRows(); i++)
        {
            for (int j = 0; j < _image.getCols(); j++)
            {
                if (i < stripeHeight || i >= 2 * stripeHeight)
                    _image.setPixel(i, j, {255, 0, 0}); // Red
                else
                    _image.setPixel(i, j, {255, 255, 255}); // White
            }
        }
    }
    
    void drawNigeriaFlag()
    {
        // Three vertical stripes
        int stripeWidth = _image.getCols() / 3;
        
        for (int i = 0; i < _image.getRows(); i++)
        {
            for (int j = 0; j < _image.getCols(); j++)
            {
                if (j < stripeWidth || j >= 2 * stripeWidth)
                    _image.setPixel(i, j, {0, 128, 0}); // Green
                else
                    _image.setPixel(i, j, {255, 255, 255}); // White
            }
        }
    }
};