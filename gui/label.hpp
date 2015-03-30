#pragma once

#include <string>

#include "object.hpp"
#include "text.hpp"

namespace gui 
{
class Label : public virtual Object, public virtual Text
{
public:
	virtual ~Label() {}
};
}
