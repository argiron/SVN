#pragma once 

#ifndef ALGOBASE_POINTS_H
#define ALGOBASE_POINTS_H

#include "MathHelp.h"

namespace AlgoBase {

template<class T>
class TPoint {
public:
	//Constructors
	TPoint() : x(T()), y(T()) {}
	TPoint(T x, T y) : x(x), y(y) {}

	//Operators
	bool operator==(const TPoint& rhs) const {
		return	(static_cast<double>(abs(x-rhs.x)) < std::numeric_limits<float>::epsilon()) &&
				(static_cast<double>(abs(y-rhs.y)) < std::numeric_limits<float>::epsilon());
	}

	bool operator!=(const TPoint& rhs) const {
		return !(*this == rhs);
	}

	TPoint operator+(const TPoint& rhs) {
		return TPoint(x + rhs.x, y + rhs.y);
	}

	TPoint operator-(const TPoint& rhs) {
		return TPoint(x - rhs.x, y - rhs.y);
	}

	//Distances
	T SqrDistance() const {
		return AlgoBase::sqr(x) + AlgoBase::sqr(y);
	}

	T Distance() const {
		return sqrt(SqrDistance());
	}

	T x;
	T y;
};

}	//End namespace AlgoBase

typedef AlgoBase::TPoint<int>		IntPoint;
typedef AlgoBase::TPoint<double>	DblPoint;

#endif // !ALGOBASE_POINTS_H
