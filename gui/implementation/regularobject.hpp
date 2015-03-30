#pragma once

#include "../object.hpp"

#include <string>
#include <map>

#include <4u/la/vec.hpp>
#include <4u/la/mat.hpp>

#include "../action.hpp"

namespace gui
{
class RegularObject : public virtual Object
{
private:
	std::string id;
	
	const Container *parent = nullptr;
	std::map<std::string,std::string> attrib;
	
	vec2 bounds = nullvec2;
	vec2 position = nullvec2;
	
	bool visible = false;
	
public:
	RegularObject();
	virtual ~RegularObject();
	
	virtual void setId(const std::string &s) override;
	virtual std::string getId() const override;
	
	virtual void setBounds(const vec2 &b) override;
	virtual void setPosition(const vec2 &p) override;
	
	virtual vec2 getBounds() const override;
	virtual vec2 getPosition() const override;
	
	virtual void setParent(const Container *c) override;
	virtual const Container *getParent() const override;
	
	virtual void setAttribute(const std::string &key, const std::string &value) override;
	virtual std::string getAttribute(const std::string &key) const override;
	
	virtual void setVisibility(bool v) override;
	virtual bool getVisibility() const override;
};
}
