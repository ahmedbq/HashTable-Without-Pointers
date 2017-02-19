/*Ahmed B. Qureshi 700636758
 * Operating Systems
 * HashTable */

#include <string>
#include <sstream>
#include <iomanip>
#ifndef HashTable_h
#define HashTable_h
using namespace std;

class HashTable2
{
private:
	string HashTable2::intToString(int number);

	/** Have to refer to string this way */

public:
	HashTable2();

	struct rowItem
	{
		rowItem() : name(""), RoomNo(0), Fwd_Chain(0), Bwd_Chain(0), Fullcode(0) { }   // default Constructor
		string name;
		int RoomNo;
		int Fwd_Chain;
		int Bwd_Chain;
		int Fullcode;
	};

	/* This struct allows for multiple different types in the
	* same array. */

	/* Variables */
	rowItem HashArray[114];
	int population;

	int SuccessfulProbes;
	int UnsuccessfulProbes;
	int collisions;

	/* For table formatting */
	char Separator;
	int Width;

	/* Functions */
	void HashTable2::insert(string Name, int requestedRoomNo, rowItem HashArray[]);

	void HashTable2::printTable(int x, rowItem HashArray[], int& width);
	//string HashTable2::toString(rowItem HashArray[]);
	void HashTable2::toString(rowItem HashArray[]);


	int HashTable2::hashing(string key);
	int HashTable2::search(string name);
	bool HashTable2::remove(string key, int index);
	string HashTable2::printTagTable(rowItem HashArray[]);
	void Menu();
	bool HashTable2::isFull();
	bool HashTable2::isEmpty();
	bool HashTable2::DuplicateRoom(int RoomNo);

};

#endif
