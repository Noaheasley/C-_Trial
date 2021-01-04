#include "Character.h"

Character::Character()
{
	m_health = 100;
	m_damage = 10;
}

Character::Character(float health, float damage)
{
	m_health = health;
	m_damage = damage;
}

void Character::attack(Character* other)
{
	other->takeDamage(getDamage());
}

void Character::heal(Character* other)
{
	other->healDamage(5);
}

float Character::takeDamage(float damageAmount)
{
	m_health -= damageAmount;
	return damageAmount;
}

float Character::healDamage(float healthGained)
{
	m_health += healthGained;
	return healthGained;
}
