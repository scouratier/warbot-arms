class Fury : public Player {
public:
	Fury();

	int	DoLogic(Dots);
	int DoMove(Dots);

	int UpdateSpells(int,int,int);
	int inCombat(int);
	int Following(int);
	int Mounted(int);
	int forcedFollowing(int);

	void CombatStart();
	void CombatEnd();

	
private:
	char bloodThirst;
	char whirlWind;
	char bloodRage;
	char mortalStrike;
	char berserkerRage;
	char overpower;
	char rampage;
	char execute;
	char intercept;
	char charge;
	char victoryRush;
	char deathWish;
	char sweepingStrikes;
	char bladeStorm;
	char rend;
	char shieldSlam;
	char concBlow;
	char shockWave;
	char devastate;	
	char ragingBlow;
	char recklessness;
	char innerRage;
	char cleave;
	char engragedRegeneration;
	char heroicThrow;
	char heroicStrike;
	char wildStrike;
	char colossusSmash;
	char skullBanner;
	char dragonRoar;
	char bloodBath;
	char battleShout;
	char trinket;

	char nextKey;
};