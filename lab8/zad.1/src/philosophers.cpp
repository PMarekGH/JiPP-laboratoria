class Philosopher
{
	int id; //id filozofa

public:
	int zasoby[NSTOCK];	// 0 oznacza, że filozof nie korzysta z pliku i, a 1, że korzysta
	
	Fork *forks[NSTOCK][NPHIL][NPHIL];	// wskaźnik na tablicę forków

	//funkcja zapełniająca losowo zasoby
	void chooseStocks(){
		string s;
		for (int i=0; i < NSTOCK; i++){
			zasoby[i] = rand() % 2;
		}
	}
	
	//funkcja odpowiadająca za myślenie
	void think(){
		int x = 0;
		
		x = rand()%100;
 		usleep(x);
	}
	
	//funkcja jedzenie: blokuję wszystkie widelce, wpisuję się do pliku, odblokowuję widelce
	void eat(){
		for (int i = 0; i < NSTOCK; i++){
			if (zasoby[i] == 1){ 		//jeśli filozof chce dostępu do danego zasobu
				// przeglądamy tylko połowę tablicy
				for (int j = 0; j < id; j++){
					forks[i][id][j]->lock();
				}
				for (int j = id + 1; j < NPHIL; j++){
					forks[i][j][id]->lock();
				}
			}
		}

		//zapis swojego id do pliku
		fstream plik[NSTOCK];
		for (int i=0;i<NSTOCK;i++){
			
			if (zasoby[i]==1){
				string x;
				x=IntToString(i)+".temp";

				plik[i].open( x,  ios::out |ios::app);
				if( plik[i].good() == true )
				{
					plik[i]<<id<<endl;
				    plik[i].close();
				    cout << "Filozof " << id << " wpisał się do pliku " << i << endl;
				} else cout <<"brak dostępu";
			}
		}

		for (int i = 0; i < NSTOCK; i++){
			if (zasoby[i] == 1){ //jeśli filozof chce dostępu do danego zasobu
				// przeglądamy tylko połowę tablicy
				for (int j = 0; j < id; j++){
					forks[i][id][j]->unlock();
				}
				for (int j = id + 1; j < NPHIL; j++){
					forks[i][j][id]->unlock();
				}
			}
		}
	}

	//funkcja run: najpierw myśl przez losowy czas, potem zdobądź widelce, zjedz, oddaj widelce
	void run(){

		think();

		for (int i = 0; i < NSTOCK; i++){
			if (zasoby[i] == 1){ //jeśli filozof chce dostępu do danego zasobu
				// przeglądamy tylko połowę tablicy
				for (int j = 0; j < id; j++){
					forks[i][id][j]->getFork(id);
				}
				for (int j = id + 1; j < NPHIL; j++){
					forks[i][j][id]->getFork(id);
				}
			}
		}

		eat();

		for (int i = 0; i < NSTOCK; i++){
			if (zasoby[i] == 1){ //jeśli filozof chce dostępu do danego zasobu
				// przeglądamy tylko połowę tablicy
				for (int j = 0; j < id; j++){
					forks[i][id][j]->setDirty(true);
				}
				for (int j = id + 1; j < NPHIL; j++){
					forks[i][j][id]->setDirty(true);
				}
			}
		}
	}


	Philosopher() {}
	
	Philosopher(int id1, Fork fs[NSTOCK][NPHIL][NPHIL]) : id{id1} {
		for (int l = 0; l < NSTOCK; l++){
			for (int j = 0; j < NPHIL; j++){
				for (int k = 0; k <NPHIL; k++){
					forks[l][j][k] =&( fs[l][j][k]);
				}
			}
		}
	}
};