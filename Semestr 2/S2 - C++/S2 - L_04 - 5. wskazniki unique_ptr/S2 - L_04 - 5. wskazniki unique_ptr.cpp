#include<iostream>
#include<memory>

class Complex
{
    public:
        float mRe;
        float mIm;
        Complex(float re, float im) : mRe(re), mIm(im)
        {
            std::cout << "Creating Complex: mRe = " << mRe << ", mIm = " << mIm << std::endl;
        }

        ~Complex()
        {
            std::cout << "Destroying Complex: mRe = " << mRe << ", mIm = " << mIm << std::endl;
        }
};

int main()
{
    // Complex* pComplex = new Complex(1, 2);
    // pComplex = new Complex(3, 4);

    // delete pComplex;

    Complex* complex = new Complex(1, 2);
    std::unique_ptr<Complex> upComplex(complex);
//    upComplex = std::make_unique<Complex>(3, 4);

    std::unique_ptr<Complex> upComplex2(complex);
}