#include "gcs.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

GCS::GCS(char const * const name) :
name{strcpy(new char[strlen(name) + 1], name)}
{
}

GCS::~GCS()
{
	delete [] name;
	name = nullptr;
}

GCS& GCS::operator=(const GCS& gcs)
{
	this->name = strcpy(new char[strlen(gcs.name) + 1], gcs.name);
	return *this;
}

GCS::GCS(const GCS& source)
{
	this->name = strcpy(new char[strlen(source.name) + 1], source.name);
}

void GCS::setName(char const * const name)
{
	if(this->name != nullptr){delete [] this->name; this->name = nullptr;}
	if(name == nullptr){this->name = nullptr;}
	if(name != nullptr){ 
		this->name = strcpy(new char[strlen(name) + 1], this->name);
	}
	
}

bool operator<(const GCS& gcs1, const GCS& gcs2)
{
	if(strcmp(gcs1.name, gcs2.name) < 0)
		return true;

	return false;
}

bool operator==(const GCS& gcs1, const GCS& gcs2)
{
	return (strcmp(gcs1.name, gcs2.name) == 0);
}

ostream& operator<<(ostream& out, const GCS& gcs)
{
	out <<  gcs.name ;

	return out;
}
