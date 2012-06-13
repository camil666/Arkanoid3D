#pragma once
#include <vector>
#include <algorithm>
#include <string>

struct position{
	char name[201];
	long points;
};

class HallOfFame
{
private:
	FILE* handle;
	std::vector <position> positions;

	void writeFile();
	short readFile();

public:
	HallOfFame(void);
	~HallOfFame(void);
	void add(char* name, long points);
	bool checkIfWorthy(long points);
	std::vector <std::string> get();
};

