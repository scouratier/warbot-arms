#include "common.h"

Spec::Spec(){
	this->combat_ = 0;
	this->target_ = "";
	this->spell_ = "";
}
string	Spec::MyTarget(){
	return this->target_;
}

string	Spec::MySpell(){
	return this->spell_;
}

int		Spec::InCombat(){
	return this->combat_;
}

int		Spec::GetCombat(){
	return 1;
}

int		Spec::SetCombat( int in ){
	return 1;
}