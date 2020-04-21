#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>

void saveName(std::ofstream &filename,const std::string &str);
void getPos(const std::string &str,int max, int &p1);
std::string removePrefix(std::string str,int p1, int p2);

int main()
{

	std::ifstream listSongs("/home/andy/.config/cmus/lib.pl");
	std::ofstream outPut("/home/andy/bin/cmus/temp", std::ios::out | std::ios::trunc);
	int bufferMax = 0;
	int pos1, pos2;
	pos1 =0;
	pos2 =0;
	std::string buffer;
	if (listSongs.fail())
	{
		std::cout << "Failed to open lib.pl";
	}

	while (!listSongs.eof())
	{
		std::getline(listSongs,buffer);
		std::string temp = "";
		bufferMax = buffer.length();
		pos2 = bufferMax;
		getPos(buffer,bufferMax,pos1);

		//std::cout << "P1 = " << pos1 << " P2 = " << pos2 << std::endl;
		if (bufferMax == 0)
			bufferMax = 128;

		std::string returnValue = removePrefix(buffer,pos1,pos2);
		
		saveName(outPut, returnValue);
		
	}

	listSongs.close();
	outPut.close();
} 

void getPos(const std::string &str,int max, int &p1)
{
	for (int k = 1; k< max; k++)
	{
		if (str[k] == '/')
		{
			p1 = k;
		}
	
	}
	p1++;
}

std::string removePrefix(std::string str,int p1, int p2)
{
	int index = 0;
	char cStr[p2-p1+1];
	std::ostringstream os;

	while (p1 < p2)
	{
		cStr[index]= str[p1];
		p1++;
		index++;
	}
	cStr[index] = '\0';
	os << cStr;
	return os.str();
}

void saveName(std::ofstream &filename,const std::string &str)
{
	filename << str << std::endl;
}

