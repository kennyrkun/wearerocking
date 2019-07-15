#ifndef CHARACTER_HPP
#define CHARACTER_HP

#include "SettingsParser.hpp"

#include <string>
#include <map>

class Character
{
public:
	bool saveToFile();
	bool loadFromFile();

	std::map<std::string, int> stats;

	struct CharacterStats
	{
		int health;
		int maxHealth;

		int armourClass;

		int speed;
		int maxSpeed;

		int visionRange;
		
		const int strength = 10;
		int strengthModifier;

		const int dexterity = 10;
		int dexterityModifier;

		const int constitution = 10;
		int constitutionModifier;

		const int intelligence = 10;
		int intelligenceModifier;

		const int wisdom = 10;
		int wisdomModifier;

		const int charisma = 10;
		int charismaModifier;

		const int strength = 10;

		struct Skills
		{
			int acrobatics;
			int animalHandling;
			int arcana;
			int athletics;
			int deception;
			int history;
			int insight;
			int intimidation;
			int investigation;
			int medicine;
			int nature;
			int perception;
			int performance;
			int persuasion;
			int religion;
			int sleightofhand;
			int stealth;
			int survival;
		} skills;

		int passivePerception = 10 + skills.perception;

	} _stats;
};

#endif // !CHARACTER_HPP