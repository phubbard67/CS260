#include "gcs.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

GCS::GCS(char const * const name)
{
}

GCS::~GCS()
{
}

GCS& GCS::operator=(const GCS& gcs)
{
	return *this;
}

GCS::GCS(const GCS& source)
{
}

void GCS::setName(char const * const name)
{
}

bool operator<(const GCS& gcs1, const GCS& gcs2)
{
	return false;
}

bool operator==(const GCS& gcs1, const GCS& gcs2)
{
	return false;
}

ostream& operator<<(ostream& out, const GCS& gcs)
{
	return out;
}
