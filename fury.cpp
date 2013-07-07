#include "common.h"

Fury::Fury(){
	this->bloodThirst='2';
	this->whirlWind='.';
	this->mortalStrike='2';
	this->berserkerRage='z';
	this->overpower='4';
	this->rampage='c';
	this->execute='5';
	this->intercept='.';
	this->charge='1';
	this->victoryRush='=';
	this->heroicStrike='=';
	this->battleShout='0';
	this->sweepingStrikes='.';
	this->bladeStorm='.';
	this->dragonRoar='r';
	this->colossusSmash='f';
	this->wildStrike='4'; 
	this->ragingBlow='3';
	this->skullBanner='-';
	this->recklessness='8';
	this->bloodBath='7';
	this->trinket='9';
}

int Fury::inCombat(int in)
{
	if ( in & 0x01 )
	{
		return 1;
	}
	return 0;
}

int Fury::DoMove(Dots in){
	int				r1,g1,b1;
	int				combat=0;
	r1 = GetRValue( in.allDots_[0].color_ );
	g1 = GetGValue( in.allDots_[0].color_ );
	b1 = GetBValue( in.allDots_[0].color_ );
	
	combat = this->inCombat( g1 );
	if ( combat )
	{
		FullKeyPress(VkKeyScan( ';' ));
		FullKeyPress(VkKeyScan( ',' ));
	}
	else
		FullKeyPress(VkKeyScan( 'l' ));

	return 1;
}

int	Fury::DoLogic(Dots in){
	this->nextKey = '.';
	int				r1,g1,b1, r2,g2,b2, r3,g3,b3;
	

	// Ability cooldown tracking
	
	r2 = GetRValue( in.allDots_[1].color_ );
	g2 = GetGValue( in.allDots_[1].color_ );
	b2 = GetBValue( in.allDots_[1].color_ );
	r3 = GetRValue( in.allDots_[2].color_ );
	g3 = GetGValue( in.allDots_[2].color_ );
	b3 = GetBValue( in.allDots_[2].color_ );

	
		// Suck up the ability timers
		this->UpdateSpells(r2,g2,b2);
		if ( this->nextKey != '.' )
			FullKeyPress(VkKeyScan( this->nextKey ));



	return 0;
}

int Fury::UpdateSpells(int in1,int in2,int in3){
	if (in3 & 0x01)
	{
		this->nextKey = this->heroicStrike;
		return 1;
	}

	if (in1 & 0x08)
	{
		this->nextKey = this->berserkerRage;
		return 1;
	}

	if (in1 & 0x01)
	{
		this->nextKey = this->bloodThirst;
		return 1;
	}

	if (in1 & 0x02)
	{
		this->nextKey = this->whirlWind;
		return 1;
	}

	if (in3 & 0x80)
	{
		this->nextKey = this->wildStrike;
		return 1;
	}

	if (in1 & 0x10)
	{
		this->nextKey = this->ragingBlow;
		return 1;
	}

	if (in1 & 0x20)
	{
		this->nextKey = this->execute;
		return 1;
	}

	if (in1 & 0x40)
	{
		this->nextKey = this->bloodBath;
		return 1;
	}

	if (in1 & 0x80)
	{
		this->nextKey = this->victoryRush;
		return 1;
	}

	if (in2 & 0x01)
	{
		this->nextKey = this->colossusSmash;
		return 1;
	}

	if (in2 & 0x04)
	{
		this->nextKey = this->recklessness;
		return 1;
	}

	if (in2 & 0x08)
	{
		this->nextKey = this->skullBanner;
		return 1;
	}

	if (in2 & 0x20)
	{
		this->nextKey = this->battleShout;
		return 1;
	}

	if (in2 & 0x40)
	{
		this->nextKey = this->heroicThrow;
		return 1;
	}

	if (in2 & 0x80)
	{
		this->nextKey = this->dragonRoar;
		return 1;
	}

	return 1;
}

void Fury::CombatStart()
{
	this->SetCombat(1);
	printf("Combat set to %d\n",this->GetCombat());
	FullKeyPress(VkKeyScan('w'));	// stop following
	this->target_ = "party1target";
	//this->spell_ = "attack";
}

void Fury::CombatEnd()
{
	this->SetCombat(0);
	printf("Combat set to %d\n",this->GetCombat());
	FullKeyPress(VkKeyScan('='));	// following
}