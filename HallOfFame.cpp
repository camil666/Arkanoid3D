#include "HallOfFame.h"
#include <stdlib.h>

bool sortPositions (position i, position j) { return ((i.points) > (j.points)); }

HallOfFame::HallOfFame(void)
{
}


HallOfFame::~HallOfFame(void)
{
}

void HallOfFame::writeFile()
{
	handle = fopen("halloffame.list", "w");
	for(short i=0; i<positions.size(); i++)
	{
		if(i==0)
		{
			fprintf(handle, "%s\n%d", positions[i].name, positions[i].points);
		}
		else
		{
			fprintf(handle, "\n%s\n%d", positions[i].name, positions[i].points);
		}
	}
	fclose(handle);
}

short HallOfFame::readFile()
{
	handle = fopen("halloffame.list", "r");
	if (!handle)  return -1;
	int state = 1;
	while(!feof(handle))
	{
		char buffer[20];
		position pos;
		pos.name[0] = '\0';
		pos.points = 0;
		fgets(buffer, 20, handle);
		buffer[strlen(buffer)-1]='\0';
		strcpy(pos.name, buffer);
		fgets(buffer, 20, handle);
		pos.points = atoi(buffer);
		positions.push_back(pos);
	}
	fclose(handle);
	return 1;
}

void HallOfFame::add(char* name, long points)
{
	readFile();
	position pos;
	strcpy(pos.name, name);
	pos.points = points;
	positions.push_back(pos);
	std::sort(positions.begin(), positions.end(), sortPositions);
	if(positions.size()>10)
	{
		positions.pop_back();
	}
	writeFile();
}

bool HallOfFame::checkIfWorthy(long points)
{
	short state = readFile();
	if (state==-1) return true;
	if (positions.size()<10) return true;
	return positions[9].points < points;
}

std::vector <std::string> HallOfFame::get()
{
	short state = readFile();
	std::vector <std::string> retVector;
	if (state==-1)
	{
		retVector.push_back("No entries so far...");
		return retVector;
	}
	for(short i=0; i<positions.size(); i++)
	{
		char buffer[20];
		std::string pos;
		pos = "";
		itoa(i+1, buffer, 10);
		pos+=buffer;
		pos+=". ";
		pos+=positions[i].name;
		pos+=" pts: ";
		itoa(positions[i].points, buffer, 10);
		pos+=buffer;
		retVector.push_back(pos);
	}
	return retVector;
}