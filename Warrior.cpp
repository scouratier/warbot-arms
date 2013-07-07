#include "common.h"

Warrior::Warrior(){
	this->bloodThirst=0;
	this->whirlWind=0;
	this->bloodRage=0;
	this->mortalStrike=0;
	this->berserkerRage=0;
	this->overpower=0;
	this->rampage=0;
	this->execute=0;
	this->intercept=0;
	this->charge=0;
	this->victoryRush=0;
	this->deathWish=0;
	this->battleShout=0;
	this->hiRage=0;
	this->sweepingStrikes=0;
	this->bladeStorm=0;
	this->rend=0;
	this->shieldSlam=0;
	this->concBlow=0;
	this->shockWave=0;
	this->devastate=0;
}

int	Warrior::DoLogic(Dots in){

	this->nextKey_ = '.';
	int				r1,g1,b1, r2,g2,b2, r3,g3,b3;

	// This is the ability Counter
	r1 = in.GetR1();
	g1 = in.GetG1();
	b1 = in.GetB1();

	// Not used at the moment
	r2 = in.GetR2();
	g2 = in.GetG2();
	b2 = in.GetB2();

	// This is for unit info (not used much for warriors)
	r3 = in.GetR3();
	g3 = in.GetG3();
	b3 = in.GetB3();

	this->target_ = "";
	this->spell_ = "";

	if (this->InCombat())
	{ 
		this->target_ = "target";
		// Suck up the ability timers
		this->UpdateSpells(r2,g2,b2);
		this->UpdateBuffs(r3,g3,b3);
		this->ProcessInformationSelf();
	}

	if (b1 == 1)
	{
		if (!this->InCombat()){
			this->CombatStart();
		}
	}
	else
	{
		if (b1 == 2)
		{
			if (this->InCombat()){
				this->CombatEnd();
			}
		}
	}
	return 0;
}

int Warrior::UpdateSpells(int in1,int in2,int in3){

	this->bloodThirst=0;
	this->whirlWind=0;
	this->bloodRage=0;
	this->mortalStrike=0; 
	this->berserkerRage=0;
	this->overpower=0;
	this->rampage=0;
	this->execute=0;
	this->intercept=0;
	this->charge=0;
	this->victoryRush=0;
	this->deathWish=0;
	this->sweepingStrikes=0;
	this->bladeStorm=0;
	this->rend=0;
	this->shieldSlam=0;
	this->concBlow=0;
	this->shockWave=0;
	this->devastate=0;
	this->ragingBlow=0;
	this->recklessness=0;
	this->innerRage=0;
	this->cleave=0;
	this->engragedRegeneration=0;
	this->heroicThrow=0;
	this->heroicStrike=0;

	if (in1 & 0x01)
		this->bloodThirst = 1;

	if (in1 & 0x02)
		this->whirlWind = 1;

	if (in1 & 0x04)
		this->bloodRage = 1;

	if (in1 & 0x08)
		this->berserkerRage = 1;

	if (in1 & 0x10)
		this->ragingBlow = 1;

	if (in1 & 0x20)
		this->execute = 1;

	if (in1 & 0x40)
		this->deathWish = 1;

	if (in1 & 0x80)
		this->victoryRush = 1;

	if (in2 & 0x04)
		this->recklessness = 1;

	if (in2 & 0x08)
		this->innerRage = 1;

	if (in2 & 0x20)
		this->engragedRegeneration = 1;

	if (in2 & 0x40)
		this->heroicThrow = 1;

	if (in2 & 0x80)
		this->shockWave = 1;

	if (in3 & 0x01)
		this->devastate = 1;

	return 1;
}

int Warrior::UpdateBuffs(int rin, int gin, int bin){
	this->battleShout = 0;
	this->bloodSurge = 0;
	this->midRage = 0;
	this->hiRage = 0;
	this->heroicStrike = 0;
	this->innerRage = 0;

	if ( rin & 0x01 )
		this->battleShout = 1;

	if ( rin & 0x02 )
	{
		this->midRage = 1;
		this->heroicStrike = 1;
	}

	if ( rin & 0x04 )
	{
		this->hiRage = 1;
		this->innerRage = 1;
	}

	if ( rin & 0x08 )
		this->bloodSurge = 1;

	return 1;
}

int Warrior::ProcessInformationSelf(){
	
	if (this->victoryRush)
	{
		this->spell_ = "Victory Rush";
		return 1;
	}

	if (this->battleShout)
	{
		this->spell_ = "Battle Shout";
		return 1;
	}

	if (this->bloodThirst)
	{
		this->spell_ = "Bloodthirst";
		return 1;
	}

	if (this->bloodSurge)
	{
		this->spell_ = "Slam";
		return 1;
	}

	if (this->ragingBlow)
	{
		this->spell_ = "Raging Blow";
		return 1;
	}

	if (this->berserkerRage)
	{
		this->spell_ = "Berserker Rage";
		return 1;
	}



	if (this->recklessness)
	{
		this->spell_ = "Recklessness";
		return 1;
	}

	if (this->engragedRegeneration)
	{
		this->spell_ = "Enraged Regeneration";
		return 1;
	}



	if (this->heroicThrow)
	{
		this->spell_ = "Heroic Throw";
		return 1;
	}

	if (this->bladeStorm)
	{
		this->spell_ = "Bladestorm";
		return 1;
	}
	if (this->execute)
	{
		this->spell_ = "Execute";
		return 1;
	}

	if (this->heroicStrike)
	{
		this->spell_ = "Heroic Strike";
		return 1;
	}

	if (this->cleave)
	{
		this->spell_ = "Cleave";
		return 1;
	}
	
	if (this->overpower)
	{
		this->spell_ = "Overpower";
		return 1;
	}
	
	if (this->rend)
	{
		this->spell_ = "Rend";
		return 1;
	}
	if (this->deathWish)
	{
		this->spell_ = "Death Wish";
		return 1;
	}
	
	if (this->concBlow)
	{
		this->spell_ = "Concussion Blow";
		return 1;
	}

	if (this->shockWave)
	{
		this->spell_ = "Shockwave";
		return 1;
	}
	if (this->mortalStrike)
	{
		this->spell_ = "Mortal Strike";
		return 1;
	}
	if (this->shieldSlam)
	{
		this->spell_ = "Shield Slam";
		return 1;
	}

	if (this->sweepingStrikes)
	{
		this->spell_ = "Sweeping Strikes";
		return 1;
	}
	if (this->bloodRage)
	{
		this->spell_ = "Bloodrage";
		return 1;
	}
	if (this->whirlWind)
	{
		this->spell_ = "Whirlwind";
		return 1;
	}
	if (this->devastate)
	{
		this->spell_ = "Devastate";
		return 1;
	}

	if (this->hiRage)
	{
		this->spell_ = "Inner Rage";
		return 1;
	}


	if (this->intercept)
	{
		this->spell_ = "";
		return 1;
	}
	if (this->charge)
	{
		this->spell_ = "";
		return 1;
	}

	this->spell_ = "";
	this->target_ = "";
	return 0;
}

void Warrior::CombatStart()
{
	this->SetCombat(1);
	printf("Combat set to %d\n",this->GetCombat());
	FullKeyPress(VkKeyScan('w'));	// stop following
	this->target_ = "party1target";
	//this->spell_ = "attack";
}

void Warrior::CombatEnd()
{
	this->SetCombat(0);
	printf("Combat set to %d\n",this->GetCombat());
	FullKeyPress(VkKeyScan('='));	// following
}