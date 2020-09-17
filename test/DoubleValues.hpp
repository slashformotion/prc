#ifndef ENIB_Double_Values_HPP
#define ENIB_Double_Values_HPP
#include <vector>
#include <string>
#include <algorithm>

namespace enib {

struct DoubleValues {

	std::vector<double> data;
	double limitLow;
	double limitHight;

	DoubleValues(std::vector<double> data, double min, double max) : data{std::move(data)}, limitLow{min}, limitHight{max} {}
};


inline
std::string
toString(DoubleValues & doubleValues) {
	std::string result = "| ";
	for(int i = 0; i<int(doubleValues.data.size()); i++) {
		result += std::to_string(doubleValues.data[i]);
		result += " | ";
	}
	result += "limitLow : " + std::to_string(doubleValues.limitLow) + " | limitHight : " + std::to_string(doubleValues.limitHight);
	return result;
}

inline
void
applyLimitBefore(DoubleValues & doubleValues, double value) {
	int pos = 0;
	// first we find value position in data
	for(int i = 0; i<int(doubleValues.data.size()); i++) {
		if(value == doubleValues.data[i]) {
			pos = i;
			break;
		}
	}
	// then we replace all concerned data by limitLow
	for(int i = 0; i<int(pos); i++) {
		doubleValues.data[i] = doubleValues.limitLow;
	}
}

inline
double
maxBetweenPos(DoubleValues & doubleValues, int indexStart, int indexEnd) {
	double max = 0.0;
	for(int i=indexStart; i<indexEnd; i++) {
		if(doubleValues.data[i]>max) {
			max = doubleValues.data[i];
		}
	}
	return max;
}


inline
double
increaseValuesBySquare(DoubleValues & doubleValues) {
	for(int i = 0; i<int(doubleValues.data.size()); i++) {
		doubleValues.data[i] *= doubleValues.data[i];
	}
	return maxBetweenPos(doubleValues, 0, int(doubleValues.data.size()));
}

} // end namespace

#endif
