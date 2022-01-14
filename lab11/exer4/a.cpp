#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int maxx = 8;//definiujemy maksimum jako stałą
int lab[8][8];

struct Coords {
	int x;
	int y;
	int prio;
};

Coords decideMove(int x, int y) {
	Coords finalCoords = { x, y, 9999999 };

	if ( (x < maxx) && (lab[x+1][y] != 1) ){
		if (lab[x+1][y] < finalCoords.prio) {
			finalCoords.x = x+1;
			finalCoords.y = y;
			finalCoords.prio = lab[x+1][y];
		}
	}
	if ( (y < maxx) && (lab[x][y+1] != 1) ){
		if (lab[x][y+1] < finalCoords.prio) {
			finalCoords.x = x;
			finalCoords.y = y+1;
			finalCoords.prio = lab[x][y+1];
		}
	}
	if ( (x > 0) && (lab[x-1][y] != 1) ){
		if (lab[x-1][y] < finalCoords.prio) {
			finalCoords.x = x-1;
			finalCoords.y = y;
			finalCoords.prio = lab[x-1][y];
		}
	}
	if ( (y > 0) && (lab[x][y-1]==0) ){
		if (lab[x][y-1] < finalCoords.prio) {
			finalCoords.x = x;
			finalCoords.y = y-1;
			finalCoords.prio = lab[x][y-1];
		}
	}
	cout << finalCoords.x << finalCoords.y << finalCoords.prio;
	return finalCoords;
}

int main(){
	Coords coords = { 0, 0, 0 };
	for(int i=0;i<8;i++){//wczytywanie labiryntu z pliku
		for(int j=0;j<8;j++){

			cin >> lab[i][j];
			// cout << lab[i][j] << " ";
		}
		// cout << endl;
	}
	int x=0,y=0;//pozycja gracza

	for(int k=0;k<40;k++){//przechodzenie przez labirynt
		if ((x == 3) && (y == 7)){
			cout << " wyszedłeś z labiryntu ";
			
				for(int i=0;i<8;i++){//wczytywanie labiryntu z pliku --> cat labirynt(nazwa pliku)| ./a.out
					for(int j=0;j<8;j++){
						cout << lab[i][j] << " ";
						// if (lab[i][j]==8) lab[i][j]=0;
					}
					cout << endl;
				}
			exit (0);
		}

		lab[x][y] += 4;// oznaczenie chodzącego pionka
		coords = decideMove(x, y);
		x = coords.x;
		y = coords.y;
		/*
		if ((x < maxx)&&(lab[x+1][y]==0)){
			x++;
		}
		else if ((y < maxx)&&(lab[x][y+1]==0)){
			y++;
		}
		else if ((x > 0)&&(lab[x-1][y]==0)){
			x--;
		}
		else if ((y > 0)&&(lab[x][y-1]==0)){
			y--;
		}
		else {
			cout << "brak wyjscia" << endl;
		
			if ((x < maxx)&&(lab[x+1][y]==4)){
				x++;
			}
			else if ((y < maxx)&&(lab[x][y+1]==4)){
				y++;
			}
			else if ((x > 0)&&(lab[x-1][y]==4)){
				x--;
			}
			else if ((y > 0)&&(lab[x][y-1]==4)){
				y--;
			}
			else {
				cout << "brak wyjscia" << endl;
			}
		
			if ((x == 3) && (y == 7)){
				cout << " wyszedłeś z labiryntu ";
			}
		}
		*/

		for(int i=0;i<8;i++){//wczytywanie labiryntu z pliku
			for(int j=0;j<8;j++){
				cout << lab[i][j] << " ";
			}
			cout << endl;
		}

		cout << "k: " << k << "  x = " << x << " y = " << y << endl;
	}
}
