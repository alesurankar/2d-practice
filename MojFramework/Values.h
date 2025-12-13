#pragma once
#include <string>
#include <vector>

class Values
{
public:
	Values() = default;
	void TakeValue(std::string value);
	std::string GetValue() const;
private:
	std::vector<std::string> values;
};