#include "timer.h" //include the timer header
#include "insertion.h" //include the insertion program

Timer::Timer(int inputSize) //constructor
{
	this->arraySize = inputSize;
    this->quick.total = -1;
    this->quick.sort = -1;
    this->quick.totalRank = -1;
    this->quick.sortRank = -1;
    this->quick.label = "Quick";
	this->heap.total = -1;
	this->heap.sort = -1;
	this->heap.totalRank = -1;
	this->heap.sortRank = -1;
	this->heap.label = "Heap";
    this->merge.total = -1;
    this->merge.sort = -1;
	this->merge.totalRank = -1;
	this->merge.sortRank = -1;
	this->merge.label = "Merge";
    this->insertion.total = -1;
    this->insertion.sort = -1;
	this->insertion.totalRank = -1;
	this->insertion.sortRank = -1;
	this->insertion.label = "Insertion";
    this->bubble.total = -1;
    this->bubble.sort = -1;
	this->bubble.totalRank = -1;
	this->bubble.sortRank = -1;
	this->bubble.label = "Bubble";
	this->rankArray = new Algorithm[5];
}

void Timer::updateTimes(int totalTime, int sortTime, string sortType)
{
	if(sortType.compare("Quick") == 0)
	{
		
		this->quick.total = totalTime;
		this->quick.sort = sortTime;
	}
	else if(sortType.compare("Heap") == 0)
	{
		this->heap.total = totalTime;
		this->heap.sort = sortTime;
	}
	else if(sortType.compare("Merge") == 0)
	{
		this->merge.total = totalTime;
		this->merge.sort = sortTime;
	}
	else if(sortType.compare("Insertion") == 0)
	{
		this->insertion.total = totalTime;
		this->insertion.sort = sortTime;
	}
	else if(sortType.compare("Bubble") == 0)
	{
		this->bubble.total = totalTime;
		this->bubble.sort = sortTime;
	}
	rankArray[0] = quick;
	rankArray[1] = heap;
	rankArray[2] = merge;
	rankArray[3] = insertion;
	rankArray[4] = bubble;
}

void Timer::rank(int flag2)
{	
	Insertion totalInsertionObject;
	Insertion sortInsertionObject;

	int* totalRankIntArray = nullptr;
	int* sortRankIntArray = nullptr;
	totalRankIntArray = new int[5];
	sortRankIntArray = new int[5];

	for(int i = 0; i < 5; i++)
	{
		totalRankIntArray[i] = this->rankArray[i].total;
	}
	
	for(int i = 0; i < 5; i++)
	{
		sortRankIntArray[i] = this->rankArray[i].sort;
	}

    totalInsertionObject.initialize(5, totalRankIntArray);
    sortInsertionObject.initialize(5, sortRankIntArray);

    totalInsertionObject.insertionSort();
    sortInsertionObject.insertionSort();

    totalRankIntArray = totalInsertionObject.insertionSortReturn();
    sortRankIntArray = sortInsertionObject.insertionSortReturn();

	for(int i = 0; i < 5; i++)
	{
		if(rankArray[i].total != -1 || rankArray[i].sort != -1)
		{
			for(int j = 0; j < 5; j++)
			{
				if(totalRankIntArray[j] == rankArray[i].total)
				{
					rankArray[i].totalRank = j+1;
				}
				if(sortRankIntArray[j] == rankArray[i].sort)
				{
					rankArray[i].sortRank = j+1;
				}
			}
		}
	}

	if(flag2 == 2)
	{
		string fileOutName =  "Rankings" + to_string(arraySize) + ".txt";
		cout << "See " << fileOutName << endl;
		ofstream outFileVar; //file variable for saving
		outFileVar.open(fileOutName); //open a file called RandomNumberArraySizeN.txt
		if(outFileVar.is_open()) //check file is open
		{
			for(int i = 0; i < 5; i++)
			{
				outFileVar << "* " << rankArray[i].label << " Sort Stats." << endl;
				if(rankArray[i].sort != -1)
				{
					outFileVar << "- Time to sort: " << rankArray[i].sort << " microseconds." << endl;
				}
				if(rankArray[i].total != -1)
				{
					outFileVar << "- Time to run entire algorithm: " << rankArray[i].total << " microseconds." << endl;
				}
				if(rankArray[i].sortRank != -1 || rankArray[i].totalRank != -1)
				{
					outFileVar << "- Sorting Rank: " << rankArray[i].sortRank << "." << endl;
					outFileVar << "- Total Rank: " << rankArray[i].totalRank << "." << endl;
				}
				else
				{
					outFileVar << "! The algorithm has not been run yet." << endl;
				}
			}
			outFileVar.close(); //close file
		}
		else //else file is closed
		{
			cout << "File called \"output.txt\" can not be opened for writing!\n";
		}
	}

	for(int i = 0; i < 5; i++)
	{
		cout << "* " << rankArray[i].label << " Sort Stats." << endl;
		if(rankArray[i].sort != -1)
		{
			cout << "- Time to sort: " << rankArray[i].sort << " microseconds." << endl;
		}
		if(rankArray[i].total != -1)
		{
			cout << "- Time to run entire algorithm: " << rankArray[i].total << " microseconds." << endl;
		}
		if(rankArray[i].sortRank != -1 || rankArray[i].totalRank != -1)
		{
			cout << "- Sorting Rank: " << rankArray[i].sortRank << "." << endl;
			cout << "- Total Rank: " << rankArray[i].totalRank << "." << endl;
		}
		else
		{
			cout << "! The algorithm has not been run yet." << endl;
		}
	}
}