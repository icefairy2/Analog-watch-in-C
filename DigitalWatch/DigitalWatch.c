#include <stdio.h>
#include <windows.h>
#include <time.h>
#define WATCH_SIZE 27

//sets in the location of the big watch needle based on the hour number
void bigNeedleDirection(char** watch, int hour) {
	int i, j, index;

	//the length of the big needle is based on the size of the watch
	int lengthDiff = WATCH_SIZE / 10 + 1;

	//how many pixels per column will be colored in case of an angle
	int step = (WATCH_SIZE / 2) / (WATCH_SIZE / 4);
	int stepcopy;

	//will set the big needle of the watch according to the hour
	switch (hour) {
	case 1:
		index = WATCH_SIZE / 2 + 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 - 1; i > lengthDiff; i--) {
			watch[i][index] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index++;
				stepcopy = step;
			}
		}
		break;
	case 2:
		index = WATCH_SIZE / 2 - 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE - lengthDiff; i++) {
			watch[index][i] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index--;
				stepcopy = step;
			}
		}
		break;
	case 3:
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE - lengthDiff; i++) {
			watch[WATCH_SIZE / 2][i] = '*';
		}
		break;
	case 4:
		index = WATCH_SIZE / 2 + 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE - lengthDiff; i++) {
			watch[index][i] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index++;
				stepcopy = step;
			}
		}
		break;
	case 5:
		index = WATCH_SIZE / 2 + 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE - lengthDiff; i++) {
			watch[i][index] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index++;
				stepcopy = step;
			}
		}
		break;
	case 6:
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE - lengthDiff; i++) {
			watch[i][WATCH_SIZE / 2] = '*';
		}
		break;
	case 7:
		index = WATCH_SIZE / 2 - 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE - lengthDiff; i++) {
			watch[i][index] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index--;
				stepcopy = step;
			}
		}
		break;
	case 8:
		index = WATCH_SIZE / 2 + 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 - 1; i > lengthDiff; i--) {
			watch[index][i] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index++;
				stepcopy = step;
			}
		}
		break;
	case 9:
		for (i = lengthDiff; i < WATCH_SIZE / 2; i++) {
			watch[WATCH_SIZE / 2][i] = '*';
		}
		break;
	case 10:
		index = WATCH_SIZE / 2 - 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 - 1; i > lengthDiff; i--) {
			watch[index][i] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index--;
				stepcopy = step;
			}
		}
		break;
	case 11:
		index = WATCH_SIZE / 2 - 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 - 1; i > lengthDiff; i--) {
			watch[i][index] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index--;
				stepcopy = step;
			}
		}
		break;
	case 12:
		for (i = lengthDiff; i < WATCH_SIZE / 2; i++) {
			watch[i][WATCH_SIZE / 2] = '*';
		}
		break;
	}
}

//sets in the location of the big watch needle based on the hour number
void smallNeedleDirection(char** watch, int minute) {
	int i;
	int index;

	int step;
	int stepcopy;

	switch (minute) {
	case 0:
		for (i = 0; i < WATCH_SIZE / 2; i++) {
			watch[i][WATCH_SIZE / 2] = '*';
		}
		break;
	case 7:
		for (i = 0; i < WATCH_SIZE / 2 - 1; i++) {
			watch[i][WATCH_SIZE - 1 - i] = '*';
		}
		break;
	case 15:
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE; i++) {
			watch[WATCH_SIZE / 2][i] = '*';
		}
		break;
	case 23:
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE; i++) {
			watch[i][i] = '*';
		}
		break;
	case 30:
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE; i++) {
			watch[i][WATCH_SIZE / 2] = '*';
		}
		break;
	case 37:
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE; i++) {
			watch[i][WATCH_SIZE - 1 - i] = '*';
		}
		break;
	case 45:
		for (i = 0; i < WATCH_SIZE / 2; i++) {
			watch[WATCH_SIZE / 2][i] = '*';
		}
		break;
	case 53:
		for (i = 0; i < WATCH_SIZE / 2 - 1; i++) {
			watch[i][i] = '*';
		}
		break;
	}

	if (minute > 0 && minute < 7) {
		step = (WATCH_SIZE / 2) / minute;
		index = WATCH_SIZE / 2 + 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 - 1; i >= 0; i--) {
			watch[i][index] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index++;
				stepcopy = step;
			}
		}
	}
	else if (minute > 7 && minute < 15) {
		step = (WATCH_SIZE / 2) / (15 - minute);
		index = WATCH_SIZE / 2 - 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE; i++) {
			watch[index][i] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index--;
				stepcopy = step;
			}
		}
	}
	else if (minute > 15 && minute < 23) {
		step = (WATCH_SIZE / 2) / (minute - 15);
		index = WATCH_SIZE / 2 + 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE; i++) {
			watch[index][i] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index++;
				stepcopy = step;
			}
		}
	}
	else if (minute > 23 && minute < 30) {
		step = (WATCH_SIZE / 2) / (30 - minute);
		index = WATCH_SIZE / 2 + 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE; i++) {
			watch[i][index] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index++;
				stepcopy = step;
			}
		}
	}
	else if (minute > 30 && minute < 37) {
		step = (WATCH_SIZE / 2) / (minute - 30);
		index = WATCH_SIZE / 2 - 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 + 1; i < WATCH_SIZE; i++) {
			watch[i][index] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index--;
				stepcopy = step;
			}
		}
	}
	else if (minute > 37 && minute < 45) {
		step = (WATCH_SIZE / 2) / (45 - minute);
		index = WATCH_SIZE / 2 + 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 - 1; i > 0; i--) {
			watch[index][i] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index++;
				stepcopy = step;
			}
		}
	}
	else if (minute > 45 && minute < 53) {
		step = (WATCH_SIZE / 2) / (minute - 45);
		index = WATCH_SIZE / 2 - 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 - 1; i > 0; i--) {
			watch[index][i] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index--;
				stepcopy = step;
			}
		}
	}
	else if (minute > 53 && minute < 60) {
		step = (WATCH_SIZE / 2) / (60 - minute);
		index = WATCH_SIZE / 2 - 1;
		stepcopy = step;
		for (i = WATCH_SIZE / 2 - 1; i > 0; i--) {
			watch[i][index] = '*';
			stepcopy--;
			if (stepcopy == 0) {
				index--;
				stepcopy = step;
			}
		}
	}
}

//prints out the watch
void draw(char** watch) {
	for (int i = 0; i < WATCH_SIZE; i++) {
		for (int j = 0; j < WATCH_SIZE; j++) {
			printf("%c", watch[i][j]);
		}
		printf("\n");
	}
}

//clears the watch needles
void clearWatch(char** watch) {
	//initializing watch to spaces
	for (int i = 0; i < WATCH_SIZE; i++) {
		for (int j = 0; j < WATCH_SIZE; j++) {
			watch[i][j] = ' ';
		}
	}

	//put in the middle of the watch
	watch[WATCH_SIZE / 2][WATCH_SIZE / 2] = '0';
}

int main() {
	char** watch;

	//dynamically allocating memory for the watch
	watch = (char**)malloc(WATCH_SIZE * sizeof(char*));
	for (int i = 0; i < WATCH_SIZE; i++) {
		watch[i] = (char*)malloc(WATCH_SIZE * sizeof(char));
	}

	//initializing
	clearWatch(watch);	

	while (1) {
		struct tm newtime;
		time_t now = time(0);

		localtime_s(&newtime, &now);
		
		//set the needles
		bigNeedleDirection(watch, newtime.tm_hour % 12);

		smallNeedleDirection(watch, newtime.tm_min);

		//print the watch
		draw(watch);

		printf("The time is: %02d:%02d:%02d\n", newtime.tm_hour, newtime.tm_min, newtime.tm_sec);

		Sleep(10000);
		system("cls");
		clearWatch(watch);
	}

	_getch();
	return 0;
}
