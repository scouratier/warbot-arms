class resto : public Spec {
public:
	resto();

	int	DoLogic();

	void CombatStart();
	void CombatEnd();

private:
	Dot		gameState_;
	Dot		gameState2_;
};