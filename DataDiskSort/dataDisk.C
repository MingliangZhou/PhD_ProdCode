#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct dataBase
{
	string site;
	string keyWord;
	string fileName;
	double size;
	bool tagRef;
	bool tagMch;
};

const int linesIn = 3359;
int linesMed;
int linesOut;
dataBase dataIn[10000]; 
dataBase dataMed[10000];
dataBase dataOut[10000]; 

int read()
{
	string line;
	char num[100];
	ifstream fIn;
	fIn.open ("input.txt");
	if(fIn.is_open())
	{
		//while(!fIn.eof());
		for(int i=0; i<linesIn; i++)
		{
			fIn>>dataIn[i].site;
			fIn>>dataIn[i].keyWord;
			fIn>>dataIn[i].fileName;
			fIn>>num;
			dataIn[i].size = atof(num)/1000000000000;
			getline(fIn,line);
		}
		fIn.close();
	}
	else cout<<"Unable to open input file"<<endl;

	return 0;
}

int match(string strIn)
{
	linesMed = 0;
	for(int i=0; i<linesIn; i++)
	{
		if((dataIn[i].fileName.find(strIn)!=std::string::npos))
		{
			dataMed[linesMed].site = dataIn[i].site;
			dataMed[linesMed].fileName = dataIn[i].fileName;
			dataMed[linesMed].size = dataIn[i].size;
			linesMed++;
		}
	}

	return 0;
}

int shorten()
{
	linesOut = 0;
	dataBase dataRef;

	for(int i=0; i<linesMed; i++) dataMed[i].tagRef = false;
	for(int i=0; i<linesMed; i++)
	{
		if(dataMed[i].tagRef) continue;
		dataRef.site = dataMed[i].site;
		dataRef.fileName = dataMed[i].fileName;
		dataOut[linesOut].size = 0;

		for(int j=i; j<linesMed; j++)
		{
			dataMed[j].tagMch = true;
			for(unsigned int k=0; k<dataRef.fileName.size(); k++)
			{
				if(k>=dataMed[j].fileName.size()) continue;
				if(!dataMed[j].tagMch) continue;
				if(dataRef.fileName[k] == dataMed[j].fileName[k]) {}
				else if(isdigit(dataRef.fileName[k]) && isdigit(dataMed[j].fileName[k]))
				{
					dataRef.fileName[k] = '*';
				}
				else if(dataRef.fileName[k]=='*' && isdigit(dataMed[j].fileName[k])) {}
				else dataMed[j].tagMch = false;
			}
			if(dataMed[j].site.compare(dataRef.site)!=0) dataMed[j].tagMch = false;
			if(dataMed[j].tagMch)
			{
				dataOut[linesOut].size += dataMed[j].size;
				dataMed[j].tagRef = true;
			}
		}

		dataOut[linesOut].fileName = dataRef.fileName;
		dataOut[linesOut].site = dataRef.site;
		
		int length;
		length = dataOut[linesOut].fileName.size();
		for(int j=0; j<length; j++)
		{
			if(dataOut[linesOut].fileName[j]!='*') continue;
			else if(dataOut[linesOut].fileName[j+1]=='*' || isdigit(dataOut[linesOut].fileName[j+1]))
			{
				dataOut[linesOut].fileName.erase(j+1,1);
				j--;
				length--;
			}
		}
		length = dataOut[linesOut].fileName.size();
		for(int j=length-1; j>=1; j--)
		{
			if(dataOut[linesOut].fileName[j]!='*') continue;
			else if(dataOut[linesOut].fileName[j-1]=='*' || isdigit(dataOut[linesOut].fileName[j-1]))
			{
				dataOut[linesOut].fileName.erase(j-1,1);
			}
		}
		
		linesOut++;
	}

	return 0;
}

int write()
{
	ofstream fOut ("output.txt");

	for(int i=0; i<linesOut; i++)
	{
		cout<<"| "<<dataOut[i].fileName<<" | "<<dataOut[i].site<<" |"<<endl;
	}

	if(fOut.is_open())
	{
		for(int i=0; i<linesMed; i++)
		{
			fOut<<"| "<<dataMed[i].fileName<<" | "<<dataMed[i].site<<" |"<<endl;
		}
		fOut<<endl;
		for(int i=0; i<linesOut; i++)
		{
			fOut<<"| "<<dataOut[i].fileName<<" | "<<dataOut[i].site<<" |"<<endl;
		}
	}
	else cout<<"Unable to open output file"<<endl;

	return 0;
}

void dataDisk()
{
	read();
	
	string strKey[100];
	bool found;
	int iF=0;
	for(int i=0; i<linesIn; i++)
	{
		found = false;
		if((dataIn[i].keyWord.find("group")!=std::string::npos)) continue;
		if((dataIn[i].keyWord.find("user")!=std::string::npos)) continue;
		for(int j=0; j<iF+1; j++)
		{
			if(found) break;
			if(dataIn[i].keyWord.compare(strKey[j])==0) found = true;
		}
		if(!found)
		{
			strKey[iF] = dataIn[i].keyWord;
			iF++;
		}
	}

	sort(strKey,strKey+iF);
	//for(int i=0; i<iF; i++) cout<<strKey[i]<<endl;

	ofstream fOut ("output.txt");
	for(int i=0; i<iF; i++)
	{
		match(strKey[i]);
		shorten();
		fOut<<"---++ "<<strKey[i]<<endl;
		fOut<<"| *expression* | *size [TB]* | *disk* | *responsible* |"<<endl;
		if(fOut.is_open())
		{
			for(int i=0; i<linesOut; i++)
			{
				fOut<<"| "<<dataOut[i].fileName<<" | "<<setprecision(3)<<dataOut[i].size<<" | "<<dataOut[i].site<<" | "<<" |"<<endl;
				cout<<"| "<<dataOut[i].fileName<<" | "<<setprecision(3)<<dataOut[i].size<<" | "<<dataOut[i].site<<" | "<<" |"<<endl;
			}
		}
		else cout<<"Unable to open output file"<<endl;
		fOut<<endl;
	}
}

