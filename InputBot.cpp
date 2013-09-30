#include "common.h"



void main(void){
	Dots			dots;
	Sleep(4000);
	
	Fury			me;

	MyInput			input;
	GameTimer		input_timer;
	GameTimer		dots_timer;

	printf("Input Bot v2.1\n");
	// fills in values for the timer.
	input_timer.savetick();
	dots_timer.savetick();
	double keybt;
	double dotst;

	dots.MakeHDC();
	dots.ShowAndSampleDots();
	while(1){
		// so we don't take 100% cpu
		Sleep(1);
		input_timer.tick();
		dots_timer.tick();
		keybt = input_timer.time_span;
		dotst = dots_timer.time_span;
		if (keybt > 0.3)
		{
			input_timer.savetick();
			me.DoMove(dots);
		}
		if (dotst > 0.01)
		{
			dots_timer.savetick();
			dots.ShowAndSampleDots();
  			me.DoLogic(dots);		
			input.DoInputs(me);
		}
	}
}