#pragma once

#include <string>

#include "object.hpp"

namespace gui 
{
class Label : public Object
{
public:
	virtual void setText(const std::wstring &str) = 0;
	virtual std::wstring getText() const = 0;
};
}
