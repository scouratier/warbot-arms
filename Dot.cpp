#include "common.h"

Dot::Dot()
{
	this->dot_ = RGB(255,255,255);

	this->red_ = RGB(255,0,0);
	this->green_ = RGB(0,255,0);
	this->blue_ = RGB(0,0,255);
}

void Dot::MakeHDC(){
	this->hdc_ = CreateDC("DISPLAY",NULL,NULL,NULL);
}

// Draws 4 dots around the sampling dot
void Dot::ShowDot(){
	SetPixel( this->hdc_ , X-1 , Y   , this->green_ );
	SetPixel( this->hdc_ , X   , Y-1 , this->green_ );
	SetPixel( this->hdc_ , X+1 , Y   , this->green_ );
	SetPixel( this->hdc_ , X   , Y+1 , this->green_ );
}

void Dot::Sample(){
	this->dot_ = GetPixel(this->hdc_,X,Y);
}

int	Dot::GetRed(){
	return GetRValue(this->dot_);
}

int	Dot::GetGreen(){
	return GetGValue(this->dot_);
}

int	Dot::GetBlue(){
	return GetBValue(this->dot_);
}