#define X	5	
#define X2	17
#define X3	29
#define Y	25

class Dot
{
public:
	Dot();

	void Sample();

	void ShowDot();
	void MakeHDC();

	int	GetRed();
	int	GetGreen();
	int	GetBlue();

private:
	HDC hdc_;
	COLORREF dot_;

	COLORREF red_;
	COLORREF green_;
	COLORREF blue_;
};