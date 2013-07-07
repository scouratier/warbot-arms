class Spec 
{
public:
	Spec();
	int GetCombat();
	int	SetCombat( int );
	int	InCombat();

	void SampleDots();
	void ShowDots();

	string	MyTarget();
	string	MySpell();

protected:
	int	combat_;
	string	target_;
	string	spell_;
};