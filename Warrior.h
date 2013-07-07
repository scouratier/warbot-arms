class Warrior : public Player {
public:
	Warrior();

	int	DoLogic(Dots);

	int UpdateSpells(int,int,int);
	int UpdateBuffs(int,int,int);

	int ProcessInformationSelf();

	void CombatStart();
	void CombatEnd();

	
private:
	int bloodThirst;
	int whirlWind;
	int bloodRage;
	int mortalStrike;
	int berserkerRage;
	int overpower;
	int rampage;
	int execute;
	int intercept;
	int charge;
	int victoryRush;
	int deathWish;
	int sweepingStrikes;
	int bladeStorm;
	int rend;
	int shieldSlam;
	int concBlow;
	int shockWave;
	int devastate;	
	int ragingBlow;
	int recklessness;
	int innerRage;
	int cleave;
	int engragedRegeneration;
	int heroicThrow;
	int heroicStrike;

	int battleShout;
	int bloodSurge;
	int commandingShout;
	int hiRage;
	int midRage;
};