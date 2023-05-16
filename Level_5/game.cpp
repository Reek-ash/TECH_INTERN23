#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward declaration of classes
class Character;
class Warrior;
class Archer;
class Mage;

// Ability class
class Ability
{
protected:
    string name;
    int damage;
    int manaCost;

public:
    Ability(const string &name, int damage, int manaCost) : name(name), damage(damage), manaCost(manaCost) {}

    virtual void execute(Character *character) = 0;

    string getName() const
    {
        return name;
    }

    int getManaCost() const
    {
        return manaCost;
    }
};

// Character class
class Character
{
protected:
    string name;
    int health;
    int level;

public:
    Character(const string &name, int health, int level) : name(name), health(health), level(level) {}

    virtual void useAbility(Ability *ability) = 0;

    void reduceHealth(int amount)
    {
        health -= amount;
    }

    void increaseHealth(int amount)
    {
        health += amount;
    }

    int getHealth() const
    {
        return health;
    }

    virtual void displayStatus()
    {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
    }
};

// Warrior class
class Warrior : public Character
{
public:
    Warrior(const string &name, int health, int level) : Character(name, health, level) {}

    void useAbility(Ability *ability) override
    {
        if (ability->getManaCost() > 0)
        {
            cout << "Warrior " << name << " uses ability: " << ability->getName() << endl;
            ability->execute(this);
        }
        else
        {
            cout << "Warrior " << name << " cannot use ability: " << ability->getName() << endl;
        }
    }
};

// Archer class
class Archer : public Character
{
public:
    Archer(const string &name, int health, int level) : Character(name, health, level) {}

    void useAbility(Ability *ability) override
    {
        if (ability->getManaCost() > 0)
        {
            cout << "Archer " << name << " uses ability: " << ability->getName() << endl;
            ability->execute(this);
        }
        else
        {
            cout << "Archer " << name << " cannot use ability: " << ability->getName() << endl;
        }
    }
};

// Mage class
class Mage : public Character
{
public:
    Mage(const string &name, int health, int level) : Character(name, health, level) {}

    void useAbility(Ability *ability) override
    {
        cout << "Mage " << name << " uses ability: " << ability->getName() << endl;
        ability->execute(this);
    }
};

// Concrete Ability classes
class SlashAbility : public Ability
{
public:
    SlashAbility() : Ability("Slash", 50, 10) {}

    void execute(Character *character) override
    {
        character->reduceHealth(damage);
    }
};

class FireballAbility : public Ability
{
public:
    FireballAbility() : Ability("Fireball", 80, 20) {}

    void execute(Character *character) override
    {
        character->reduceHealth(damage);
    }
};

class HealAbility : public Ability
{
public:
    HealAbility() : Ability("Heal", -50, 30) {}

    void execute(Character *character) override
    {
        character->increaseHealth(damage);
    }
};

int main()
{
    // Create characters
    vector<Character *> characters;
    characters.push_back(new Warrior("Warrior 1", 100, 1));
    characters.push_back(new Archer("Archer 1", 80, 1));
    characters.push_back(new Mage("Mage 1", 70, 1));
    // Create abilities
    vector<Ability *> abilities;
    abilities.push_back(new SlashAbility());
    abilities.push_back(new FireballAbility());
    abilities.push_back(new HealAbility());

    // Game loop
    int currentPlayerIndex = 0;
    bool gameOver = false;

    while (!gameOver)
    {
        Character *currentPlayer = characters[currentPlayerIndex];
        Ability *selectedAbility = nullptr;

        // Display current player's status
        currentPlayer->displayStatus();

        // Display available abilities
        cout << "Available Abilities:" << endl;
        for (int i = 0; i < abilities.size(); ++i)
        {
            cout << i + 1 << ". " << abilities[i]->getName() << " (Mana Cost: " << abilities[i]->getManaCost() << ")" << endl;
        }

        // Select ability
        int abilityIndex;
        cout << "Select an ability (1-" << abilities.size() << "): ";
        cin >> abilityIndex;
        abilityIndex--;

        if (abilityIndex >= 0 && abilityIndex < abilities.size())
        {
            selectedAbility = abilities[abilityIndex];
        }
        else
        {
            cout << "Invalid ability selection!" << endl;
            continue;
        }

        // Use ability
        currentPlayer->useAbility(selectedAbility);

        // Check if game over
        for (Character *character : characters)
        {
            if (character->getHealth() <= 0)
            {
                gameOver = true;
                break;
            }
        }

        // Switch to next player
        currentPlayerIndex = (currentPlayerIndex + 1) % characters.size();

        // Empty input buffer
        cin.ignore();
        cout << endl;
    }

    // Display final status
    cout << "Game Over!" << endl;
    for (Character *character : characters)
    {
        character->displayStatus();
        delete character;
    }

    // Clean up abilities
    for (Ability *ability : abilities)
    {
        delete ability;
    }

    return 0;
}