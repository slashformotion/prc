#ifndef ENIB_Double_Values_HPP
#define ENIB_Double_Values_HPP
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

namespace enib {

template<typename T>
struct NumberValue {
    
	std::vector<T> data;
	T limitLow;
	T limitHight;

	
};
template <typename T> 
inline
std::string
toString(NumberValue<T> & nValues) {
	std::string result = "| ";
	for(int i = 0; i<int(nValues.data.size()); i++) {
		result += std::to_string(nValues.data[i]);
		result += " | ";
	}
	result += "limitLow : " + std::to_string(nValues.limitLow) + " | limitHight : " + std::to_string(nValues.limitHight);
	return result;
}

template <typename T> 
inline
void
applyLimitBefore(NumberValue<T> & nValues, double value) {
	int pos = 0;
	// first we find value position in data
	for(int i = 0; i<int(nValues.data.size()); i++) {
		if(value == nValues.data[i]) {
			pos = i;
			break;
		}
	}
	// then we replace all concerned data by limitLow
	for(int i = 0; i<int(pos); i++) {
		nValues.data[i] = nValues.limitLow;
	}
}

template<typename T>
inline
double
maxBetweenPos(NumberValue<T> & nValues, int indexStart, int indexEnd) {
	double max = 0.0;
	for(int i=indexStart; i<indexEnd; i++) {
		if(nValues.data[i]>max) {
			max = nValues.data[i];
		}
	}
	return max;
}


template<typename T>
inline
double
increaseValuesBySquare(NumberValue<T> & nValues) {
	for(int i = 0; i<int(nValues.data.size()); i++) {
		nValues.data[i] *= nValues.data[i];
	}
	return maxBetweenPos(nValues, 0, int(nValues.data.size()));
}

template<typename T>
inline
double
increaseValuesByNLog(NumberValue<T> & nValues) {
	for(int i = 0; i<int(nValues.data.size()); i++) {
		nValues.data[i] = std::max(nValues.data[i], float(std::log(nValues.data[i]))); // here we use cmath logarithm function
	}
	return maxBetweenPos(nValues, 0, int(nValues.data.size()));
}

} // end namespace
#endif
