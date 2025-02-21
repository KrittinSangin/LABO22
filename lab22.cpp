#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();

	};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)+(-1)*(imag*c.imag),(real*c.imag)+(imag*c.real));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double imtimes = real * c.real + imag * c.imag;
	double immag = -real*c.imag + imag * c.real;
	double abs = (c.real*c.real + c.imag * c.imag);
	return ComplexNumber(imtimes/abs,immag/abs);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real && imag == c.imag)return true;
	else{
		return false;
	}



}


double ComplexNumber::abs(){
	double abs = sqrt((real*real + imag *imag));
	return (abs);
}

double ComplexNumber::angle(){
	return (atan2 (imag,real) * 180 / M_PI);
}

ComplexNumber operator+(double s, const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}
ComplexNumber operator-(double s, const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}
ComplexNumber operator*(double s, const ComplexNumber &c){
	return ComplexNumber(s*c.real,s*c.imag);
}

ComplexNumber operator/(int s, const ComplexNumber &c){
	return ComplexNumber((s*c.real)/(c.real*c.real + c.imag * c.imag),-s*c.imag/(c.real*c.real + c.imag * c.imag));
}
ComplexNumber operator==(int s, const ComplexNumber &c){
    if(s == c.real && s == c.imag){
        return true;
    }else{
        return false;
    }
	
}
ostream & operator<<(ostream &os, const ComplexNumber &E){
    if(E.real == 0){
        if(E.imag == 0)  return os << 0;
        return os << E.imag <<"i";
    }else if(E.imag == 0){
        return os << E.real;
    }else if( E.real == 0 && E.imag == 0){
        return os << 0;
    }
	if(E.imag > 0){
	return os << E.real << "+" << E.imag <<"i";
	}
	else{
	    if(E.imag == 0)  return os << 0;
		return os << E.real << E.imag <<"i";
	}
    
}

