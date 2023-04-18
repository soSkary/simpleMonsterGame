#include "random.h"

#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>

class Potion
{
public:
    enum Type
    {
        health,
        strength,
        poison,
        max_types
    };
    enum Effect
    {
        small,
        medium,
        large,
        max_effect
    };
private:
// an two-dimensional array to hold the values of the different potions
   static constexpr std::array<std::array<const int, static_cast<int>(max_effect)>, static_cast<int>(max_types)> m_value {
     { { 2, 2, 5 },
       { 1, 1, 1 },
       { -1,-1,-1 } }
   };
   Type m_type{};
   Effect m_effect{};
    
    

public:
    Potion (Type type, Effect effect) : m_type{type}, m_effect{effect}
    {}
    int getValue() const
    {
        return m_value[static_cast<int>(m_type)][static_cast<int>(m_effect)];
    }
    Type getType() const
    {
        return m_type;
    }
    Effect getEffect() const
    {
        return m_effect;
    }
    static Potion getRandomPotion()
    {
        int type{ Random::get(0, static_cast<int>(max_types) - 1) };
        int effect{ Random::get(0, static_cast<int>(max_effect) - 1) };
        return Potion{ static_cast<Type>(type), static_cast<Effect>(effect) };
    }
    friend std::ostream& operator<<(std::ostream& out, Potion potion)
    {
        switch (potion.m_type)
        {
        case Effect::small: out << "small "; break;
        case Effect::medium: out << "medium "; break;
        case Effect::large: out << "large "; break;
        default: out << "error, unknown potion size; "; break;
        }
        switch (potion.m_type)
        {
        case Type::health: out << "health "; break;
        case Type::strength: out << "strength "; break;
        case Type::poison: out << "poison "; break;
        default: out << "error, unknown potion type; "; break;
        }
        out << "potion";
        return out;
    }
};

class Creature
{

protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

public:
    Creature(std::string_view name, char symbol, int health, int damage, int gold)
        : m_name{ name },
        m_symbol{ symbol },
        m_health{ health },
        m_damage{ damage },
        m_gold{ gold }
    {}


    std::string_view getName()  { return m_name; }
    char getSymbol() const      { return m_symbol; }
    int getHealth() const       { return m_health; }
    int getDamage() const       { return m_damage; }
    int getGold() const         { return m_gold; }

    void reduceHealth(int health)   { m_health -= health; }
    bool isDead() const             { return m_health <= 0; }
    void addGold(int gold)          { m_gold += gold; }

};

class Player : public Creature
{
private:
    int m_level{ 1 };

public:
    Player (std::string_view name): Creature{name, '@', 10, 1, 0}
    {
    }
    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }
    int getLevel()
    {
        return m_level;
    }
    void drinkPotion(const Potion& potion)
    {
        if (potion.Potion::getType() == Potion::Type::strength)
            m_damage += potion.Potion::getValue();
        else if (potion.Potion::getType() == Potion::Type::health || potion.Potion::getType() == Potion::Type::poison)
            m_health += potion.getValue();
        else
            std::cout << "Error... Unknown potion type.\n";
    }
};

class Monster : public Creature
{

public:
    enum class Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

private:
    static const Creature& getDefaultCreature(Type type)
    {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
          { {"dragon", 'D', 20, 4, 100},
            {"orc", 'o', 4, 2, 25},
            {"slime", 's', 1, 1, 10} }
        };
        return monsterData.at(static_cast<std::size_t>(type));
    }
public:
    Monster(Type type) : Creature { getDefaultCreature(type)}
    {}
    static Monster getRandomMonster()
    {
        int number{ Random::get(1, 100) };
        if (number < 51)
            return Monster{ Monster::Type::slime };
        else if (number > 80)
            return Monster{ Monster::Type::dragon };
        else
            return Monster{ Monster::Type::orc };
    }
};



// a simple function to remove extra characters from 
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Player createPlayer()
{
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;

    Player p{ playerName };
    std::cout << "Welcome, " << p.getName() << ".\n";

    std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";
    return p;

}
char getUserInput()
{
    char c{};
    while (true)
    {
        std::cin >> c;
        ignoreLine();
        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
        }
        else break;
    }
    return c;
}
bool monsterEncounter(Player& p)
{
    Monster m{ Monster::getRandomMonster()};
    std::cout << "\nYou have encountered a " << m.getName() << '(' << m.getSymbol() << ")\n";
    
    while (true)
    {
        std::cout << "\n(F)ight, (R)un or (Q)uit?:";
        char input{ getUserInput() };
        if (input == 'r' || input == 'R')
        {
            if (Random::get(0, 1))
            {
                p.reduceHealth(m.getDamage());
                std::cout << "You failed to flee.\n" << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
                if (p.isDead())
                {
                    std::cout << "You died!\n";
                    return false;
                }
                continue;
            }
            std::cout << "You fled succesfully and currently have " << p.getGold() << " gold.\n";
            return true;
        }
        else if (input == 'f' || input == 'F')
        {
            m.reduceHealth(p.getDamage());
            std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
            if (m.isDead())
            {
                p.addGold(m.getGold());
                std::cout << "\nThe " << m.getName() << " died and you got " << m.getGold() << " gold.\n";
                p.levelUp();
                std::cout << "\nYou leveled up to level " << p.getLevel() << " and now have " << p.getGold() << " gold. \n" <<
                    "You now do " << p.getDamage() << " damage.\n";
                Potion potion{ Potion::getRandomPotion() };
                while (true)
                {
                    std::cout << "\nYou found a potion. Drink it (y/n)? (q to quit the game)";
                    char inputP{ getUserInput() };
                    if (inputP == 'y' || inputP == 'Y')
                    {
                        std::cout << "You drank a " << potion << ".\n";
                        p.drinkPotion(potion);
                        break;
                    }
                    else if (inputP == 'n' || inputP == 'N')
                    {
                        std::cout << "You didn't drink the potion. It was a " << potion << ".\n";
                        break;
                    }
                    else if (inputP == 'q' || inputP == 'Q')
                        return false;
                    else
                        std::cout << "Wrong input, please input y for YES, n for NO, q for QUIT!\n";
                }
                return true;
            }

            p.reduceHealth(m.getDamage());
            std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
            if (p.isDead())
            {
                std::cout << "You died!\n";
                return false;
            }

        }
        else if (input == 'q' || input == 'Q')
            return false;
        else
            std::cout << "Wrong input, please type r to RUN, f to FIGHT, q to QUIT.\n";
    }

}
bool fightOrFlight(Player& p)
{
    bool playing {true};
    while (playing)
    {
        std::cout << '\n';

        if (p.getLevel() >= 20)
            return true;
        else
        {

            if (monsterEncounter(p))
                continue;
            else
                break;
        }
    }
    return false;
}

int main()
{
    Player p{ createPlayer()};
    if (fightOrFlight(p))
    {
        std::cout << "\n\nYou are a winner! You gathered a total of " << p.getGold() << " gold!" <<
            "\nNice work!\n";
    }
    else
    {
        std::cout << "\n\n" << p.getName() << " died / quit at level " << p.getLevel() << " with " << p.getGold() << " gold!" <<
            "\nToo bad " << p.getName() << " can't keep it...\n";
    }
    return 0;
}
