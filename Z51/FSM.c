#include <stdio.h>

//Different states of machine

typedef enum{
	POWER_ON_STATE,
	INITIAL__MODE_STATE,
	CALIBRATION_MODE_STATE,
	ONLINE_MODE_STATE
}eSystemState;

//Different events in machine

typedef enum{
	rxd_short,
	rxd_txd_short,
	no_pin_short
}eSystemEvent;

eSystemState Initial_Mode_Handler(void){
	return INITIAL__MODE_STATE;
}

eSystemState Calibration_Mode_Handler(void){
	return CALIBRATION_MODE_STATE;
}

eSystemState Online_Mode_Handler(void){
	return ONLINE_MODE_STATE;
}

int main(int argc, char *argv[])
{
	eSystemState eNextState = POWER_ON_STATE;
	eSystemEvent eNewEvent;

	while(1)
	{
		eSystemEvent eNewEvent = ReadEvent();

		switch(eNextState){
			case POWER_ON_STATE:
			{
				if(rxd_txd_short == eNewEvent)
				{
					eNextState = Calibration_Mode_Handler();
				}
				else if(rxd_short == eNewEvent)
				{
					eNextState = Initial_Mode_Handler();
				}
				else if(no_pin_short == eNewEvent)
				{
					eNextState = Online_Mode_Handler();
				}
			}
			break;
			case CALIBRATION_MODE_STATE:
			{
				if( no_pin_short == eNewEvent)
				{
					eNextState = Online_Mode_Handler();
				}
			}
			break;
			case ONLINE_MODE_STATE:
			{
				if( rxd_short == eNextState ){
					eNextState = Initial_Mode_Handler();
				}
			}
			break;

			default:
				break;
		}
	}

	return 0;
}


// From March - 148 + 23 .
