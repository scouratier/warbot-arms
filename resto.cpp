#include "common.h"

resto::resto(){
}

int	resto::DoLogic(){
	int			r2,g2,b2, r3,g3,b3;

	r2 = this->gameState_.GetRed();
	g2 = this->gameState_.GetGreen();
	b2 = this->gameState_.GetBlue();

	r3 = this->gameState2_.GetRed();
	g3 = this->gameState2_.GetGreen();
	b3 = this->gameState2_.GetBlue();

	this->target_ = "";
	this->spell_ = "";

	// select the right target
	if(g3 > 0 && g3 < 41){
		this->target_ = "raid"+IntToString(g3);
	}
	if(g3 > 40 && g3 < 46){
		this->target_ = "party"+IntToString(g3-40);
	}
	if(g3 == 128){
		this->target_ = "player";
	}

	if (b2 != 255)
	{ // on cooldown, no combat casting
	
		// cast the right spell
		switch (r3)
		{
			case 1:
			{
				this->spell_ = "Chain Heal";
				return 1;
			}
			case 2:
			{
				this->spell_ = "Lesser Healing Wave";
				return 1;
			}
		}
	}
	return 0;
}

void resto::CombatStart()
{
	this->SetCombat(1);
	printf("Combat set to %d\n",this->GetCombat());
	FullKeyPress('W');	// stop following
	FullKeyPress('3');	// windfury totematta
	//this->target_ = "/clearfocus";
}

void resto::CombatEnd()
{
	this->SetCombat(0);
	printf("Combat set to %d\n",this->GetCombat());
	FullKeyPress(VkKeyScan('='));	// following
	FullKeyPress('7');	// totem recal
}