#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int maxx = 7;//definiujemy maksimum jako stała (zmieniona z 8 na 7)
int lab[8][8]; // globalna zmienna (żeby była dostępna dla funkcji decideMove i main)

// struktura, w której przechowuje koordynaty
struct Coords {
	int x;
	int y;
}; 

// funkcja, której zadaniem jest wybranie koordynatów, na które należy się przemieścić
// funkcja wybiera pole na podstawie priorytetu (im niższa liczba na polu tym priorytet wyższy)
Coords decideMove(int x, int y) {
	Coords finalCoords = { x, y };
    // wysoki priorytet żeby zawsze był wyższy od pól w labiryncie (dla k=n max: n*2)
	int prio = 9999999;

	// sprawdz 4 pola w pionie i poziomie od (x,y) i porównaj je z priorytetem
    // dla każdego pola sprawdź też czy nie jest on 1 (ściana)
    // dla każdego pola sprawdź też warunki brzegowe (czy pole nie będzie poza labiryntem)
	if ( (x < maxx) && (lab[x+1][y] != 1) ){
		if (lab[x+1][y] < prio) {
			finalCoords.x = x+1;
			finalCoords.y = y;
			prio = lab[x+1][y];
		}
	}
	if ( (y < maxx) && (lab[x][y+1] != 1) ){
		if (lab[x][y+1] < prio) {
			finalCoords.x = x;
			finalCoords.y = y+1;
			prio = lab[x][y+1];
		}
	}
	if ( (x > 0) && (lab[x-1][y] != 1) ){
		if (lab[x-1][y] < prio) {
			finalCoords.x = x-1;
			finalCoords.y = y;
			prio = lab[x-1][y];
		}
	}
	if ( (y > 0) && (lab[x][y-1] != 1) ){
		if (lab[x][y-1] < prio) {
			finalCoords.x = x;
			finalCoords.y = y-1;
			prio = lab[x][y-1];
		}
	}
	// cout << finalCoords.x << finalCoords.y << prio;
	return finalCoords;
}

int main(){
	Coords coords = { 0, 0 };
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
			cout << " wyszedłeś z labiryntu " << endl;
			
				for(int i=0;i<8;i++){//wczytywanie labiryntu z pliku --> cat labirynt(nazwa pliku)| ./a.out
					for(int j=0;j<8;j++){
						cout << lab[i][j] << " ";
						// if (lab[i][j]==8) lab[i][j]=0;
					}
					cout << endl;
				}
			exit (0);
		}

		// zwiększ liczbe odwiedzonego pole o 2 (oznacz ile razy pole zostało odwiedzone)
		lab[x][y] += 2;
        // sprawdź, na które pole należy się przemieścić
		coords = decideMove(x, y);
		// przypisz nowe koordynaty
		x = coords.x;
		y = coords.y;

		for(int i=0;i<8;i++){//wczytywanie labiryntu z pliku
			for(int j=0;j<8;j++){
				cout << lab[i][j] << " ";
			}
			cout << endl;
		}
        // wypisz iteracje i bieżące koordynaty
		cout << "k: " << k << "  x = " << x << " y = " << y << endl;
	}
}
