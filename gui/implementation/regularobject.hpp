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
	
	const Object *parent = nullptr;
	std::map<std::string,std::string> attrib;
	
	vec2 bounds = nullvec2;
	vec2 position = nullvec2;
	vec2 rel_bounds = nullvec2;
	vec2 rel_position = nullvec2;
	
	bool visible = false;
	
public:
	RegularObject();
	virtual ~RegularObject();
	
	virtual void setId(const std::string &s) override;
	virtual std::string getId() const override;
	
	virtual void setBounds(const vec2 &b) override;
	virtual void setPosition(const vec2 &p) override;
	virtual void setRelativeBounds(const vec2 &rb) override;
	virtual void setRelativePosition(const vec2 &rp) override;
	
	virtual vec2 getBounds() const override;
	virtual vec2 getPosition() const override;
	virtual vec2 getRelativeBounds() const override;
	virtual vec2 getRelativePosition() const override;
	virtual vec2 getOffsetBounds() const override;
	virtual vec2 getOffsetPosition() const override;
	
	virtual void setParent(const Object *c) override;
	virtual const Object *getParent() const override;
	
	virtual void setAttribute(const std::string &key, const std::string &value) override;
	virtual std::string getAttribute(const std::string &key) const override;
	
	virtual void setVisibility(bool v) override;
	virtual bool getVisibility() const override;
};
}
