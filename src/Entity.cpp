#include "Entity.h"
#include <algorithm>
#include <iostream>

Entity::Entity(const std::string& name, const std::string& description, EntityType type)
	:name(name), description(description), type(type)
{
}

//---------------------------------------------------------------------------------------------------------------
void Entity::Update()
{
}

//---------------------------------------------------------------------------------------------------------------
const std::string& Entity::GetName() const
{
	return name;
}

//---------------------------------------------------------------------------------------------------------------
const std::string& Entity::GetDescription() const
{
	return description;
}

//---------------------------------------------------------------------------------------------------------------
Entity::EntityType Entity::GetType() const
{
	return type;
}

//---------------------------------------------------------------------------------------------------------------
void Entity::AddEntity(Entity* entity)
{
	contains.push_back(entity);
}

//---------------------------------------------------------------------------------------------------------------
void Entity::RemoveEntity(Entity* entity)
{
	contains.remove(entity);
}

//---------------------------------------------------------------------------------------------------------------
const std::list<Entity*>& Entity::GetContents() const  
{  
   return contains;  
}

//---------------------------------------------------------------------------------------------------------------

Entity::~Entity()
{
	for (Entity* e : contains)
	{
		delete e;
	}
}

//---------------------------------------------------------------------------------------------------------------
