/*Ahmed B. Qureshi 700636758
 * Operating Systems
 * HashTable */

#include <string>
#include <iostream>
#include "HashTable.h"
#include <iomanip>
using namespace std;



void Menu()
{
	cout<<"WELCOME TO NIRVANA HILTON\n"<<endl;
	cout<<"1.PRINT\n2.LIST\n3.CHECK_IN\n4.CHECK_OUT\n5.LOCATE\n6.QUIT\n[0 for menu]\nEnter: "<<endl;
}

int main()
{
	/** Create a Hashtable */
	HashTable2 Table;


	Table.insert("Adames_Winter", 1, Table.HashArray);
	Table.insert("Adams_Carl", 2, Table.HashArray);
	Table.insert("Alummootil_Tony", 3, Table.HashArray);
	Table.insert("Barreca_Nancy", 4, Table.HashArray);
	Table.insert("Bristol_Phillip", 5, Table.HashArray);
	Table.insert("Cardiello_Brian", 6, Table.HashArray);
	Table.insert("Chung_Darren", 7, Table.HashArray);
	Table.insert("Concepcion_Diony", 8, Table.HashArray);
	Table.insert("Cui_Hui_Liang", 9, Table.HashArray);
	Table.insert("David_Bunmi", 10, Table.HashArray);
	Table.insert("Dilawari_Shonila", 11, Table.HashArray);
	Table.insert("Ehrlinger_Frederick", 12, Table.HashArray);
	Table.insert("Famodimu_Gideon", 13, Table.HashArray);
	Table.insert("Glynn_Debra", 14, Table.HashArray);
	Table.insert("Inoa_Jose", 15, Table.HashArray);
	Table.insert("Lam_Shirley", 16, Table.HashArray);
	Table.insert("Lau_KaKin", 17, Table.HashArray);
	Table.insert("Matos_Fanny", 18, Table.HashArray);
	Table.insert("Meyer_Richard", 19, Table.HashArray);
	Table.insert("Nunez_Gregory", 20, Table.HashArray);

	Table.insert("Richardson_Enerolisa", 21, Table.HashArray);
	Table.insert("Rodriquez_Dennis", 22, Table.HashArray);
	Table.insert("Saleem_Amir", 23, Table.HashArray);
	Table.insert("Salzman_Brian", 24, Table.HashArray);
	Table.insert("Siddiqui_Moudud", 25, Table.HashArray);
	Table.insert("Smith_Mellinda", 26, Table.HashArray);
	Table.insert("Tessema_Yikum", 27, Table.HashArray);
	Table.insert("Michael_Yodit", 28, Table.HashArray);
	Table.insert("Akron_Jennifer", 29, Table.HashArray);
	Table.insert("Arraiza_Esperanza", 30, Table.HashArray);
	Table.insert("Chin_Li-Ching", 31, Table.HashArray);
	Table.insert("Chong_Kevin", 32, Table.HashArray);
	Table.insert("Delva_Edson", 33, Table.HashArray);
	Table.insert("Hughes_John", 34, Table.HashArray);
	Table.insert("Abraham_Mathews", 35, Table.HashArray);
	Table.insert("Alvarez_Marjorie", 36, Table.HashArray);
	Table.insert("Bennettson_Christine", 37, Table.HashArray);
	Table.insert("Cameau_Hans", 38, Table.HashArray);
	Table.insert("Corbett_Dennis", 39, Table.HashArray);
	Table.insert("Critchlow_Amenia", 40, Table.HashArray);

	Table.insert("Diaz_Brendaly", 41, Table.HashArray);
	Table.insert("Escalante_Martin", 42, Table.HashArray);
	Table.insert("Fleury_Melinda", 43, Table.HashArray);
	Table.insert("Ford_Thomas", 44, Table.HashArray);
	Table.insert("Josefsberg_Richard", 45, Table.HashArray);
	Table.insert("Kelly_James", 46, Table.HashArray);
	Table.insert("Langebek_Michele", 47, Table.HashArray);
	Table.insert("Myrthil_Jean", 48, Table.HashArray);
	Table.insert("Nasser_Muhammed", 49, Table.HashArray);
	Table.insert("Nguyen_Linh", 50, Table.HashArray);
	Table.insert("Niefeld_Tracy", 51, Table.HashArray);
	Table.insert("Padilla_Karl", 52, Table.HashArray);
	Table.insert("Scneider_Ross", 53, Table.HashArray);
	Table.insert("Jackson_Ltanya", 54, Table.HashArray);
	Table.insert("John_Susan", 55, Table.HashArray);
	Table.insert("Kutschera_Thomas", 56, Table.HashArray);
	Table.insert("Lada_Anna", 57, Table.HashArray);
	Table.insert("Makkar_Vibhor", 58, Table.HashArray);
	Table.insert("Rodriguez_Jessica", 59, Table.HashArray);
	Table.insert("Sewell_Andrew", 60, Table.HashArray);

	Table.insert("Thorne_Peter", 61, Table.HashArray);
	Table.insert("Shah_Syed", 62, Table.HashArray);
	Table.insert("Small_Tracy", 63, Table.HashArray);
	Table.insert("Steiner_Jared", 64, Table.HashArray);
	Table.insert("Tierney_Jeremy", 65, Table.HashArray);
	Table.insert("Tsai_James", 66, Table.HashArray);
	Table.insert("Wallace_Lorna", 67, Table.HashArray);
	Table.insert("Williams_William", 68, Table.HashArray);
	Table.insert("Yair_Yeud", 69, Table.HashArray);
	Table.insert("Atique_Kazi", 70, Table.HashArray);
	Table.insert("Burke_Grace-Ann", 71, Table.HashArray);
	Table.insert("Farook_Mohammed", 72, Table.HashArray);
	Table.insert("Feng_Feng_Nian", 73, Table.HashArray);
	Table.insert("Hong_Robert", 74, Table.HashArray);
	Table.insert("James_Christopher", 75, Table.HashArray);
	Table.insert("Lopez_Emmanuel", 76, Table.HashArray);
	Table.insert("Mathew_Jiji", 77, Table.HashArray);
	Table.insert("Naseer_Muhammed", 78, Table.HashArray);
	Table.insert("Resmini_James", 79, Table.HashArray);
	Table.insert("Rommel_Gerald", 80, Table.HashArray);

	Table.insert("Abraham_Mathews", 81, Table.HashArray);
	Table.insert("Barger_Christopher", 82, Table.HashArray);
	Table.insert("Farrell_Daniel", 83, Table.HashArray);
	Table.insert("Hubbard_Kwame", 84, Table.HashArray);
	Table.insert("Mathew_Jiji", 85, Table.HashArray);
	Table.insert("Nguyen_Linh", 86, Table.HashArray);
	Table.insert("Foster_Kevin", 87, Table.HashArray);
	Table.insert("Weedy_Mark_David", 88, Table.HashArray);
	Table.insert("Fields_Janet", 89, Table.HashArray);
	Table.insert("Mayall_John", 90, Table.HashArray);
	Table.insert("Haley_Roger", 91, Table.HashArray);
	Table.insert("Mix_Gary", 92, Table.HashArray);
	Table.insert("Goodman_Eric", 93, Table.HashArray);
	Table.insert("Johnson_Carol", 94, Table.HashArray);
	Table.insert("Fisher_Eddie", 95, Table.HashArray);
	Table.insert("Farmer_Jim", 96, Table.HashArray);
	Table.insert("Minor_Sharon", 97, Table.HashArray);
	Table.insert("Iacono_Lynn", 98, Table.HashArray);
	Table.insert("Bernstein_Leonard", 99, Table.HashArray);
	Table.insert("Mehta_Zubin", 100, Table.HashArray);

	bool sentinel = true;
	Menu();

	while(sentinel)
	{
		int selection = -1;
		cin>>selection;



		switch (selection)
		{
		/* Menu */
		case 0:
		{
			Menu(); cout<<"\nEnter: "<<endl;

			break;
		}

		/* PRINT */
		case 1:
		{

			cout<<left<<setw(25)<<setfill(Table.Separator)<<"          Name     ";
			cout<<left<<setw(10)<<setfill(Table.Separator)<<"|RoomNo   |";
			cout<<left<<setw(10)<<setfill(Table.Separator)<<"Fwd_Chain|";
			cout<<left<<setw(10)<<setfill(Table.Separator)<<"Bwd_Chain|";
			cout<<left<<setw(10)<<setfill(Table.Separator)<<"Fullcode  "<<endl;
			Table.toString(Table.HashArray);
			cout<<"Enter: "<<endl;
			break;
		}

		/* LIST */
		case 2:
		{
			cout<<Table.printTagTable(Table.HashArray)<<"\nEnter: "<<endl;
			break;
		}
		/* CHECK_IN */
		case 3:
		{
			string name = "";
			int room = 0;
			int roomPlaceHolder = 0;

			/* If Table is not full it works */
			if(!Table.isFull())
			{
				cout<<"What is your name? \nEnter: "<<endl;

				cin>>name;

				/* No duplicate name-checker requested */

				cout<<"Which room do you prefer sir? \nEnter: "<<endl;
				/* Checks for duplicate rooms */
				int roomPlaceHolderHolder = 0;
				bool loopy2 = false;
				while (loopy2 == false)
				{
					try
					{
						cin>>roomPlaceHolderHolder;
						loopy2 = true;
					}
					catch(exception e){
						cout<<"Room is invalid. Try again. "<<"\nEnter: "<<endl;
					}
				}

				roomPlaceHolder = roomPlaceHolderHolder;
				/* If there is no duplicate */
				if(!Table.DuplicateRoom(roomPlaceHolder))
				{
					room = roomPlaceHolder;
				}
				/* else assigns a random room number*/
				else
				{
					int randomRoom = 1;
					while(Table.DuplicateRoom(randomRoom))
					{
						randomRoom++;
					}
					room = randomRoom;
				}

				Table.insert(name, room, Table.HashArray);
				cout<<"Enjoy! Your room number is "<<room<<"\nEnter: "<<endl;

			}
			else
			{
				cout<<"Sorry, all the rooms are full. \nEnter: "<<endl;
			}
			break;
		}
		/* CHECK_OUT */
		case 4:
		{
			string name = "";
			if(!Table.isEmpty())
			{
				cout<<"Who do you want to check out? \nEnter: "<<endl;
				cin>>name;
				int roomSearch = Table.search(name);
				/* Remember that roomSearch refers to the index */
				if(roomSearch == -1)
				{
					cout<<name<<" is already checked out. \nEnter: "<<endl;
				}
				else
				{
					Table.remove(name, roomSearch);
					cout<<name<<" has been checked out \nEnter: "<<endl;

				}
			}
			else
			{
				cout<<"The hotel is empty. \nEnter: "<<endl;
			}


			break;
		}
		/* LOCATE */
		case 5:
		{
			string name = "";

			cout<<"Who are you looking for? "<<"Enter: "<<endl;
			cin>>name;

			int roomSearch = Table.search(name);
			/* Remember that roomSearch refers to the index */
			if(roomSearch != -1)
			{
				cout<<name<<" resides in room "<<Table.HashArray[roomSearch].RoomNo<<"\nEnter: "<<endl;

			}
			else
			{
				cout<<name<<" is not there. \nEnter: "<<endl;

			}
			break;
		}
		/* QUIT */
		case 6:
		{
			cout<<"Thank you for visiting Nirvana Hotel! Good bye."<<endl;
			cout<<"Unsuccessful Probes: "<<Table.UnsuccessfulProbes<<endl;
			cout<<"Successful Probes: "<<Table.SuccessfulProbes<<endl;
			cout<<"Total Probes: "<<Table.UnsuccessfulProbes + Table.SuccessfulProbes<<endl;
			cout<<"Collisions: "<<Table.collisions<<endl;

			sentinel = false;
			break;
		}
		//		default:
		//		{
		//			cout<<"Incorrect option. Try again. \nEnter: "<<endl;
		//			break;
		//		}

		}
	}



	//	("Ahmed", 1, Table.HashArray);
	//	("Ahmed", 2, Table.HashArray);
	//	("Ahmed", 3, Table.HashArray);
	//	("Ahmed", 1, Table.HashArray);
	//	("poop", 2, Table.HashArray);
	//	Table.remove("Ahmed", probes);
	//	("Dogman", 4, Table.HashArray);
	//	("Dogman", 5, Table.HashArray);

	//	("Dogman", 6, Table.HashArray);


	//	cout << Table.toString(Table.HashArray) << endl;
	/* Call probes inside here and put it into the search function
	 * using pointers somehow */
	//	cout << "search Ahmed: " << Table.search("Ahmed", probes) << endl;
	//	cout << "Tag Table" << Table.printTagTable(Table.HashArray) << endl;

	//Numbers should be adjusted after something is removed.
	//line 359
	//fix remove function
	//make sure distinct names are inputted (?)
	//Number inputs in menu must only be numbers
	//String inputs in menu must only be strings

	//Remove destructors if they keep bothering you
	//Program doesn't work when name is in ALL CAPS
	//Putting a comma in a name gives errors
	//--UNCOMMENTING LINE 380 GIVES ERROR!! FIXED REMOVE FUNCTION by tweaking toString
	//search should mention the amount of probes in the app


	return 0;
	/*Cannot forget return 0*/
}

