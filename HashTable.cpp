/*Ahmed B. Qureshi 700636758
 * Operating Systems
 * HashTable */

/*To include .h you need to right click on the project
and then go to Properties/VC++ Directories/General/Include Directories*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "HashTable.h"
using namespace std;

struct rowItem
{
	rowItem() : name(""), RoomNo(0), Fwd_Chain(0), Bwd_Chain(0), Fullcode(0) { }
	string name;
	int RoomNo;
	int Fwd_Chain;
	int Bwd_Chain;
	int Fullcode;
};

/* Converts an integer to string */
string HashTable2::intToString(int number)
{
	stringstream stream;
	stream << number;
	string String = stream.str();
	return String;
}

/** Constructor */
/* NO DESTRUCTOR IS USED FOR ARRAY */
HashTable2::HashTable2()
{
	population = 0;
	Separator = ' ';
	Width = 20;

	collisions = 0;
	SuccessfulProbes = 0;
	UnsuccessfulProbes = 0;

	/* We already initialized the HashArray in the .h so no
	need to mention it again here. */

	/* Initializing the table depending on the column.
	Remember that you cannot change a number to a string
	so easily in C++ by doing [a number] + "". */


	/* Loop Initialization */
	for (int x = 0; x < 114; x++)
	{
		/* Name and RoomNo */
		HashArray[x].name = "";

		/* FwdChn */
		int FwdValue = x + 1;
		HashArray[x].Fwd_Chain = FwdValue;

		/* BwdChn */
		int BwdValue = x - 1;
		HashArray[x].Bwd_Chain = BwdValue;

		/* Fullcode */
		HashArray[x].Fullcode = 0;

	} /* End For Loop */

	/* Empty Chain Name */
	HashArray[0].name = "Empty";

	/* FwdChn The last value */
	HashArray[113].Fwd_Chain = -1;

	/* BwdChn first value */
	HashArray[0].Bwd_Chain = 113;

	/* BwdChn second value */
	HashArray[1].Bwd_Chain = -1;



} /* End HashTable:HashTable */


/* Destructor */
//HashTable::~HashTable()
//{
//	delete[] HashArray;
//} /* End Destructor */

/* To fix table columns */
void HashTable2::printTable(int x, rowItem HashArray[], int& width)
{
	//cout.width(3);

	/* Only if it's occupied or the first element */
	if (HashArray[x].Fullcode==1 || x == 0)
	{
		cout<<left<< setw(25) << setfill(Separator)<< HashArray[x].name;
	}

	else{cout<<left<< setw(25) << setfill(Separator) << "";}
	cout<<left<< setw(10) << setfill(Separator) << HashArray[x].RoomNo;
	cout<<left<< setw(10) << setfill(Separator) << HashArray[x].Fwd_Chain;
	cout<<left<< setw(10) << setfill(Separator) << HashArray[x].Bwd_Chain;
	cout<<left<< setw(10) << setfill(Separator) << HashArray[x].Fullcode<<endl;
}

/* toString */
//string HashTable2::toString(rowItem HashArray[])
//{
//	string collection = " Name \t| RmNo \t| FC \t| BC \t| FCDE \t|\n";
//	for (int x = 0; x < 114; x++)
//	{
//		/* Putting this if statement to fix the error on line 380 */
//		if (HashArray[x].Fullcode == 1)
//		{
//			collection += HashArray[x].name + " \t| ";
//		}
//		else {collection += " \t| ";}
//		collection += intToString(HashArray[x].RoomNo) + " \t| ";
//		collection += intToString(HashArray[x].Fwd_Chain) + " \t| ";
//		collection += intToString(HashArray[x].Bwd_Chain) + " \t| ";
//		collection += intToString(HashArray[x].Fullcode) + " \t|\n";
//	}
//	return collection;
//}

/* new toString using the printTable Function to fix the column spaces */
void HashTable2::toString(rowItem HashArray[])
{
	for(int x = 0; x < 114; x++)
	{



		printTable(x, HashArray, Width);


	}

}



/* Tag Table */
string HashTable2::printTagTable(rowItem HashArray[])
{
	string collection = " \nRoomNo \t| HashNo\n";
	for (int x = 0; x < 114; x++)
	{
		/* Collects it only if it's not empty */
		if(HashArray[x].Fullcode == 1)
		{
			/* RoomNo and HashNo */
			collection += intToString(HashArray[x].RoomNo) + " \t| ";
			collection += intToString(x) + " \t|\n";
		}
	}
	return collection;
}

/* Hashing Function */
int HashTable2::hashing(string key)
{
	int result = 0;
	for (int x = 0; x < key.length(); x++)
	{
		result += key[x];
		/* Takes the sum of the Ascii values
		 * of the characters in the name */
	}
	return (result*key.length()) % 112 + 1;
	/* We add 1 so that we cannot
	 * get 0 as an answer. Also kept
	 * it within 112 since 1 will be
	 * added to it. Don't want it to
	 * get out of range. */
}

/* Insert Function */
void HashTable2::insert(string Name, int requestedRoomNo, rowItem HashArray[])
{
	/* Hashes the name */
	int rowNo = hashing(Name);

	/* Checks if spot is open */
	if (HashArray[rowNo].Fullcode == 0)
	{

		/* Set Name */
		HashArray[rowNo].name = Name;

		/* Set RoomNo */
		HashArray[rowNo].RoomNo = requestedRoomNo;

		/* Set FC */
		HashArray[rowNo].Fwd_Chain = 0;

		/* Set BC */
		HashArray[rowNo].Bwd_Chain = 0;

		/* Set FullCode */
		HashArray[rowNo].Fullcode = 1;

		/* Empty Chain and the ones around must change */

		/* Prev row FC*/
		/* If it doesn't have empty chain
		 * behind it */
		if (rowNo != 1)
		{
			if (HashArray[rowNo - 1].Fullcode == 0)
			{
				HashArray[rowNo - 1].Fwd_Chain++;
			}
		}

		/* Next row BC */
		/* If it's not the last row */
		if (rowNo != 113)
		{
			if (HashArray[rowNo + 1].Fullcode == 0)
			{
				HashArray[rowNo + 1].Bwd_Chain--;
			}
		}
	}
	/* If occupied by a native */

	else
	{
		collisions++;
		/* Use a while loop to find the
		 * next fwd_Chain.fwd_Chain etc
		 * if needed to. */
		while (HashArray[rowNo].Fwd_Chain != 0)
		{
			rowNo = HashArray[rowNo].Fwd_Chain;
		}
		int oldRowNo = rowNo;
		/* First HOLD the information of the taken spot
		 * so that it can redirect you here. */


		/* Uses Empty Chain to check the first empty spot */
		rowNo = HashArray[0].Fwd_Chain;

		/* Set Name */
		HashArray[rowNo].name = Name;

		/* Set RoomNo */
		HashArray[rowNo].RoomNo = requestedRoomNo;

		/* Set FC */
		HashArray[rowNo].Fwd_Chain = 0;

		/* Set BC */
		HashArray[rowNo].Bwd_Chain = 0;

		/* Set FullCode */
		HashArray[rowNo].Fullcode = 1;

		/* Empty Chain and the ones around must change */

		/* Prev row FC*/
		/* If it doesn't have empty chain
		 * behind it */
		if (rowNo != 1)
		{
			if (HashArray[rowNo - 1].Fullcode == 0)
			{
				HashArray[rowNo - 1].Fwd_Chain++;
			}
		}

		/* Next row BC */
		/* If it's not the last row */
		if (rowNo != 113)
		{
			if (HashArray[rowNo + 1].Fullcode == 0)
			{
				HashArray[rowNo + 1].Bwd_Chain--;
			}
		}

		/* If it's the second row it has to
		 * equal -1. */
		if (rowNo == 1)
		{
			if (HashArray[rowNo + 1].Fullcode == 0)
			{
				HashArray[rowNo + 1].Bwd_Chain = -1;
			}
		}

		/* Set OldRowNo to point its FwdChain to here and the BwdChn
		 * of the new one to the OldRowNo */
		HashArray[oldRowNo].Fwd_Chain = rowNo;
		HashArray[rowNo].Bwd_Chain = oldRowNo;

	}

	/* Empty Chain Update */
	int index = 1;
	/* index starts at 1 since
	 * empty chain does not count*/
	int newFwdChn;
	int newBwdChn;
	bool isOccupied = false;
	/* FwdChn update */
	while (isOccupied == false)
	{
		if (HashArray[index].Fullcode == 0)
		{
			isOccupied = true;
		}
		else
		{
			index++;
		}
	}
	HashArray[0].Fwd_Chain = index;
	/* Also the empty chain's first open spot's backward chain
	 * should equal to -1. Make sure the index is within range */
	int holdIndex = HashArray[0].Fwd_Chain;
	if (holdIndex > 0 && holdIndex < 114)
	{
		HashArray[holdIndex].Bwd_Chain = -1;
	}

	population++;
} /* End Insert */

/* Search */
/* Mentions how many probes it took */
int HashTable2::search(string name)
{
	/* Hashes the name */
	int rowNo = hashing(name);

	/* Cheap way to do it but it works */
	//	for(int x = 0; x < 114; x++)
	//	{
	//		probes++;
	//
	//		if(HashArray[x].name == name && HashArray[x].Fullcode == 1)
	//		{
	//			SuccessfulProbes++;
	//			return x;
	//		}
	//		else
	//		{
	//			UnsuccessfulProbes++;
	//		}
	//	}
	//	return -1;

	if (HashArray[rowNo].name == name)
	{
		SuccessfulProbes++;
		return rowNo;
		/*First match is correct*/
	}
	/* It will check via while loop */
	else
	{
		UnsuccessfulProbes++;
		/* Setting probes to 1 since it checked
		 * once before coming to this phase */
		//rowNo = HashArray[rowNo].Fwd_Chain;

		while (HashArray[rowNo].Fwd_Chain != 0)
		{

			if (HashArray[rowNo].name == name)
			{
				SuccessfulProbes++;
				return rowNo;
				/*Found it!*/
			}
			UnsuccessfulProbes++;
			rowNo = HashArray[rowNo].Fwd_Chain;

		}

		/* Checking last possible spot */
		if (HashArray[rowNo].name == name)
		{
			SuccessfulProbes++;
			return rowNo;
		}
		else {
			UnsuccessfulProbes++;
			return -1;
			/* Not here */
		}


	}
	return -1;
}/* End Search Function */

/* Remove */
bool HashTable2::remove(string key, int index)
{
	/* First search if it is there.
	 * If it it isn't, then it's
	 * already not there. */
	int oldIndex = index;

	/* If it's not the first element */
	if (HashArray[index].Bwd_Chain != 0)
	{
		/* If it's not the first element in its chain */


		/* Check which one matches the key in the chain */
		//				while(HashArray[index].name != key)
		//				{
		//					index = HashArray[index].Fwd_Chain;
		//				}
		//				oldIndex = index;
		/* Refers to the index which equals to the one found */

		/* If it has an element afterwards then change the
				next element to have a BC equal to its own BC */
		if (HashArray[oldIndex].Fwd_Chain != 0)
		{
			int Hold = HashArray[oldIndex].Fwd_Chain;
			HashArray[Hold].Bwd_Chain = HashArray[oldIndex].Bwd_Chain;
		}

		/* Set the previous element's FC to its own FC */
		int Hold2 = HashArray[oldIndex].Bwd_Chain;
		HashArray[Hold2].Fwd_Chain = HashArray[oldIndex].Fwd_Chain;

		/* Set everything to default */
		/* name */
		HashArray[index].name = "";

		/* Fwd_Chain */
		/* Check next open spot */
		int OpenSpot = 0;
		while(HashArray[OpenSpot].Fullcode != 0 && OpenSpot != 113)
		{
			OpenSpot++;
		}
		HashArray[index].Fwd_Chain = OpenSpot;
		/* If last possible index */
		if(index == 113)
		{
			HashArray[113].Fwd_Chain = -1;
		}

		/* Bwd_Chain */
		HashArray[index].Bwd_Chain = index-1;
		/* If first spot */
		if(index == 1)
		{
			HashArray[index].Bwd_Chain = -1;
		}

		/* Fullcode */
		HashArray[index].Fullcode = 1;

		/* RoomNo */
		HashArray[index].RoomNo = 0;

		/* Update spot before and after in empty chain */
		/* Next guy's Bwd_Chain*/
		if(index != 113)
		{
			int nextEmpty =	HashArray[index].Fwd_Chain;
			HashArray[nextEmpty].Bwd_Chain = index;
		}
		/* Previous guy's Fwd_Chain*/
		/* Doesn't matter if previous element is empty chain */

		int prevEmpty = HashArray[index].Bwd_Chain;
		HashArray[prevEmpty].Fwd_Chain = index;



	}
	/* If it is the first element in its chain */
	else {

		/* If it's first element in its chain */

		/* Set everything to default */
		/* name */
		HashArray[index].name = "";

		/* Fwd_Chain */
		/* Check next open spot */
		int OpenSpot = 0;
		while(HashArray[OpenSpot].Fullcode != 0 && OpenSpot != 113)
		{
			OpenSpot++;
		}
		HashArray[index].Fwd_Chain = OpenSpot;
		/* If last possible index */
		if(index == 113)
		{
			HashArray[113].Fwd_Chain = -1;
		}

		/* Bwd_Chain */
		HashArray[index].Bwd_Chain = index-1;
		/* If first spot */
		if(index == 1)
		{
			HashArray[index].Bwd_Chain = -1;
		}

		/* Fullcode */
		HashArray[index].Fullcode = 1;

		/* RoomNo */
		HashArray[index].RoomNo = 0;

		/* Update spot before and after in empty chain */
		/* Next guy's Bwd_Chain*/
		if(index != 113)
		{
			int nextEmpty =	HashArray[index].Fwd_Chain;
			HashArray[nextEmpty].Bwd_Chain = index;
		}
		/* Previous guy's Fwd_Chain*/
		/* Doesn't matter if previous element is empty chain */

		int prevEmpty = HashArray[index].Bwd_Chain;
		HashArray[prevEmpty].Fwd_Chain = index;


	}

	/* Empty Chain Update */
	int indexEmpty = 1;
	/* index starts at 1 since
	 * empty chain does not count*/
	int newFwdChn;
	int newBwdChn;
	bool isOccupied = false;
	while (isOccupied == false)
	{
		if (HashArray[indexEmpty].Fullcode == 0)
		{
			isOccupied = true;
		}
		else
		{
			indexEmpty++;
		}
	}
	HashArray[0].Fwd_Chain = indexEmpty;
	/* Also the empty chain's first open spot's backward chain
	 * should equal to -1. Make sure the index is within range */
	int holdIndex = HashArray[0].Fwd_Chain;
	if (holdIndex > 0 && holdIndex < 114)
	{
		HashArray[holdIndex].Bwd_Chain = -1;
	}

	/* Set deleted spot's FwdChn to be equal to the next available spot*/
	int loop = oldIndex+1;
	while(HashArray[loop].Fullcode != 0)
	{
		loop++;
	}
	HashArray[oldIndex].Fwd_Chain = loop;

	/* Set any index who's BC value is -1 to set its BC equal to the old index*/
	int loop2 = oldIndex+1;
	while(HashArray[loop2].Fullcode != 0)
	{
		loop2++;
	}
	if(HashArray[loop2].Bwd_Chain == -1)
	{
		HashArray[loop2].Bwd_Chain = oldIndex;
	}

	else
	{
		return false;
		/* Not found */
	}


	population--;

	return false;
}

bool HashTable2::isFull()
{
	if(population == 100)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool HashTable2::isEmpty()
{
	if(population == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool HashTable2::DuplicateRoom(int RoomNo)
{
	for(int x = 0; x < 114; x++)
	{
		if(HashArray[x].RoomNo == RoomNo)
		{
			return true;
		}
	}
	return false;
}
