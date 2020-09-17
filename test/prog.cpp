
#include "DoubleValues.hpp"
#include "FloatValues.hpp"
#include <iostream>

void testInitAndDisplay();
void testapplyLimitBefore();
void testIncreaseValues();
void testmaxBetweenPos();

int main() {
	std::cout<<"~~~~~ Program Start ~~~~~"<<"\n";
	testInitAndDisplay();
	testapplyLimitBefore();
	testIncreaseValues();
	testmaxBetweenPos();
	std::cout<<"\n~~~~~ Program End ~~~~~"<<"\n";
	return 0;
}

void testInitAndDisplay() {
	std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
	enib::DoubleValues a{{-8.3, -4.2, -2.1, 4.3, 11.4, 17.0}, 4.5, 11.9};
	std::cout << enib::toString(a) << "\n";
	
	enib::FloatValues b{{-7.5f, -3.6f, -3.0f, 5.7f, 10.3f, 14.5f}, 3.4f, 12.1f};
	std::cout << enib::toString(b) << "\n";
}

void testapplyLimitBefore() {
	std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
	enib::DoubleValues a{{-8.3, -4.2, -2.1, 4.3, 11.4, 17.0}, 4.5, 11.9};
	std::cout << enib::toString(a) << "\n";
	enib::applyLimitBefore(a, 4.8);
	std::cout << enib::toString(a) << "\n";

	enib::FloatValues b{{-7.5f, -3.6f, -3.0f, 5.7f, 10.3f, 14.5f}, 3.4f, 12.1f};
	std::cout << enib::toString(b) << "\n";
	enib::applyLimitBefore(b, 5.7f);
	std::cout << enib::toString(b) << "\n";
}

void testIncreaseValues() {
	std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
	enib::DoubleValues a{{-8.3, -4.2, -2.1, 4.3, 11.4, 17.0}, 4.5, 11.9};
	std::cout << enib::toString(a) << "\n";
	enib::increaseValuesBySquare(a);
	std::cout << enib::toString(a) << "\n";
	
	enib::FloatValues b{{-7.5f, -3.6f, -3.0f, 5.7f, 10.3f, 14.5f}, 3.4f, 12.1f};
	std::cout << enib::toString(b) << "\n";
	enib::increaseValuesBySquare(b);
	std::cout << enib::toString(b) << "\n";
	
	enib::FloatValues c{{-7.5f, -3.6f, -3.0f, 5.7f, 10.3f, 14.5f}, 3.4f, 12.1f};
	std::cout << enib::toString(c) << "\n";
	enib::increaseValuesByNLog(c);
	std::cout << enib::toString(c) << "\n";
}

void testmaxBetweenPos() {
	std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
	int indexStart=2;
	int indexEnd=5;

	enib::DoubleValues a{{-8.3, -4.2, -2.1, 4.3, 11.4, 17.0}, 4.5, 11.9};
	std::cout << enib::toString(a) << "\n";
	std::cout << "Max betwenn index " << indexStart << " and " << indexEnd << " is : " << enib::maxBetweenPos(a, indexStart, indexEnd) << "\n";
	
	enib::FloatValues b{{-7.5f, -3.6f, -3.0f, 5.7f, 10.3f, 14.5f}, 3.4f, 12.1f};
	std::cout << enib::toString(b) << "\n";
	std::cout << "Max betwenn index " << indexStart << " and " << indexEnd << " is : " << enib::maxBetweenPos(b, indexStart, indexEnd) << "\n";
}
