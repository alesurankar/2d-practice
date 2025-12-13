#include "Values.h"
#include <utility>

void Values::TakeValue(std::string value_in)
{
	//values.emplace_back(std::move(value_in));
	value = std::move(value_in);
}

std::string Values::GetValue() const
{
	return value;
	//std::string result;
	//for (const auto& v : values) {
	//	result += v;
	//}
	//return result;
}