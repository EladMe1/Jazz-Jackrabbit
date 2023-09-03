#include "StaticObject.h"

StaticObject::StaticObject()
{
}

StaticObject::StaticObject(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:GameObject(texture,pos,size)
{
}
