#pragma once
#include <string>
#include <list>
class Entity
{
public:
	enum EntityType
	{
		ROOM,
		EXIT,
		HUMAN,
		ENEMY,
		ITEM
	};

	Entity(const std::string& name, const std::string& description, EntityType type, const std::list<Entity>& contains);

	virtual void Update();

protected:

	std::string name;
	std::string description;
	EntityType type;
	std::list<Entity> contains;
};
	

