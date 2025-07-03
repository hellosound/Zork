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
	
	//Constructor declaration
	Entity(const std::string& name, const std::string& description, EntityType type);

	//Destructor declaration
	virtual ~Entity();

	virtual void Update();

	//Getter functions
	const std::string& GetName() const;
	const std::string& GetDescription()const;
	EntityType GetType() const;

	//Functions to dinamically add and remove entities on other Entities.
	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);
	
	const std::list<Entity*>& GetContents() const;

protected:

	std::string name;
	std::string description;
	EntityType type;
	std::list<Entity*> contains;
};
	

