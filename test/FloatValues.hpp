
#ifndef ENIB_Float_Values_HPP
#define ENIB_Float_Values_HPP
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

namespace enib {

struct FloatValues {

	std::vector<float> data;
	float limitLow;
	float limitHight;

	FloatValues(std::vector<float> data, float min, float max) : data{std::move(data)}, limitLow{min}, limitHight{max} {}
};


inline
std::string
toString(FloatValues & floatValues) {
	std::string result = "| ";
	for(int i = 0; i<int(floatValues.data.size()); i++) {
		result += std::to_string(floatValues.data[i]);
		result += " | ";
	}
	result += "limitLow : " + std::to_string(floatValues.limitLow) + " | limitHight : " + std::to_string(floatValues.limitHight);
	return result;
}

inline
void
applyLimitBefore(FloatValues & floatValues, float value) {
	int pos = 0;
	// first we find value position in data
	for(int i = 0; i<int(floatValues.data.size()); i++) {
		if(value == floatValues.data[i]) {
			pos = i;
			break;
		}
	}
	// then we replace all concerned data by limitLow
	for(int i = 0; i<int(pos); i++) {
		floatValues.data[i] = floatValues.limitLow;
	}
}

inline
double
maxBetweenPos(FloatValues & floatValues, int indexStart, int indexEnd) {
	double max = 0.0f;
	for(int i=indexStart; i<indexEnd; i++) {
		if(floatValues.data[i]>max) {
			max = floatValues.data[i];
		}
	}
	return max;
}

inline
double
increaseValuesBySquare(FloatValues & floatValues) {
	for(int i = 0; i<int(floatValues.data.size()); i++) {
		floatValues.data[i] *= floatValues.data[i];
	}
	return maxBetweenPos(floatValues, 0, int(floatValues.data.size()));
}

inline
double
increaseValuesByNLog(FloatValues & floatValues) {
	for(int i = 0; i<int(floatValues.data.size()); i++) {
		floatValues.data[i] = std::max(floatValues.data[i], float(std::log(floatValues.data[i]))); // here we use cmath logarithm function
	}
	return maxBetweenPos(floatValues, 0, int(floatValues.data.size()));
}

} // end namespace

#endif
