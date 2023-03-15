#include <stdio.h>
#include <stdlib.h>

void states(int Enginestate,unsigned char AC,int vehiclespeed,int RTD,unsigned char ETC,int ETD){
	if(Enginestate == 0){
				printf("Engine state is off\n");
		}
	else
				printf("Engine state is on\n");

	if(AC == 0){
		printf("AC is off\n");
	}
	else
		printf("AC is on\n");

	printf("Vehicle speed is: %d \n",vehiclespeed);
	printf("Room Temperature is : %d \n",RTD);

	if(ETC == 0){
		printf("Engine Temperature Controller State is off \n");
	}
	else
		printf("Engine Temperature Controller State is on \n");

	printf("Engine Temperature is: %d \n",ETD);
}

void mainfunc(){
		int choice = choices();
		int vehiclespeed = 0 ;
		unsigned char ETC = 0;
		unsigned char AC = 0;
		float RTD = 35;
		float ETD = 90;
		int Enginestate = 0;


		while(choice == 2){
			printf("Engine is turned off\n");
			choice = choices();
		}
		if(choice == 3){
			printf("Quit the system");
			exit(0);
		}
		if(choice == 1){
			int choice1 ;
			while(choice1 != 1){
			int choice1 ;
			int Enginestate = 1;
			printf("\nEnter choice number: \n");
			printf("1.Turn off engine\n");
			printf("2.Set the traffic light color\n");
			printf("3.Set the room temperature\n");
			printf("4.Set the engine temperature\n");
			fflush(stdout);
			scanf("%d",&choice1);

			switch(choice1){
			case 1:
				mainfunc();
				continue;
			case 2 :
				char TLD ;
					printf("Enter Traffic light data (G,O,R) : \n");
					fflush(stdout);
					scanf("%s",&TLD);
					if(TLD == 'G'){
						printf("Vehicle speed is set to 100 km/hr \n");
						fflush(stdout);
						vehiclespeed = 100;

					}
					else if(TLD == 'O'){
						printf("Vehicle speed is set to 30 km/hr \n");
						fflush(stdout);
						vehiclespeed = 30;
					}
					else if(TLD == 'R'){
						printf("Vehicle speed is set to 0 km/hr \n");
						fflush(stdout);
						vehiclespeed = 0;
					}

					break;
			 case 3:
					printf("Enter Room Temperature Data number : \n");
								 fflush(stdout);
								 scanf("%d",&RTD);
								 if(RTD < 10){
									 printf("AC turned on and temperature set to 20 Degree \n");
									 AC = 1;
									 RTD = 20;
								 }
								 else if(RTD > 30){
									 printf("AC turned on and temperature set to 20 Degree \n");
									 AC = 1;
									 RTD = 20;
								 }
								 else{
									 printf("AC turned off");
								 }
								 break;
			 case 4:
				 printf("Enter Engine Temperature Data number : \n");
				 fflush(stdout);
				 scanf("%d",&ETD);
				 if(ETD < 100){
					 printf("Engine Temperature controller is on and temp set to 125 \n");
					 ETD = 125;
					 ETC = 1;
				 }
				 else if(ETD > 150){
					 printf("Engine Temperature controller is on and temp set to 125 \n");
					 ETD = 125;
					 ETC = 1;
				 }
				 else{
					 printf("Engine Temperature controller is off \n");
				 }
			}
			if(vehiclespeed == 30){
				AC = 1;
				RTD = (RTD * (1.25)) +1;
				ETC = 1;
				ETD = (ETD * (1.25)) +1;
			}

			states(Enginestate,AC,vehiclespeed,RTD,ETC,ETD);

		}
	}
}


int choices(){
	int choice;

	printf("Enter choice number : \n");
	printf("1.Turn on the vehicle engine\n");
	printf("2.Turn off the vehicle engine\n");
	printf("3.Quit the system\n");
	fflush(stdout);
	scanf("%d",&choice);
	return choice;
}

int main(void) {

	mainfunc();
}

