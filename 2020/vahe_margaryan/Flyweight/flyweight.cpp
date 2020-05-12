#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <assert.h>

class Texture
{
public:
  Texture(const std::string& filepath)
    : filepath_(filepath)
  {
  }

  /*
  ** SOME TEXUTRE MANIPULATION FUNCTIONALITY
  */

  std::string getFilePath() const
  {
    return filepath_;
  }

private:
  std::string filepath_;
};

enum class E_CharacterType
{
  e_Villager = 0,
  e_Troop,
  e_Horseman
};

class CharacterSharedState
{
public:
  CharacterSharedState(const E_CharacterType type, const std::string& filepath)
    : type_(type)
    , texture_(filepath)
  {
  }

  E_CharacterType type_;
  Texture texture_;
};

enum class E_CharacterAction
{
  e_Free = 0,
  e_Building,
  e_Farming,
  e_Attacking,
  e_Protecting
};

enum class E_Target
{
  e_None = 0,
  e_Construction,
  e_Farm,
  e_Enemy
};

class CharacterUniqueState
{
public:
  CharacterUniqueState(E_CharacterAction action = E_CharacterAction::e_Free, E_Target target = E_Target::e_None)
    : action_(action)
    , target_(target)
  {
  }

  E_CharacterAction action_;
  E_Target target_;
};

class Character
{
public:
  Character(const CharacterSharedState* ss)
    : ss_(new CharacterSharedState(*ss))
  {
  }

  Character(const Character& other)
    : ss_(new CharacterSharedState(*other.ss_))
  {
  }

  ~Character()
  {
    delete ss_;
  }

  virtual void MakeAction(const CharacterUniqueState& us) const
  {
    std::string msg = "Character is ";

    switch (us.action_) {
    case E_CharacterAction::e_Attacking:
      msg += "attacking";
      break;
    case E_CharacterAction::e_Building:
      msg += "building";
      break;
    case E_CharacterAction::e_Protecting:
      msg += "protecting";
      break;
    case E_CharacterAction::e_Farming:
      msg += "farming";
      break;
    case E_CharacterAction::e_Free:
      msg += "free";
      std::cout << msg << std::endl;
      return;
    default:
      break;
    }

    msg += " ";

    switch (us.target_) {
    case E_Target::e_Construction:
      msg += "construction";
      break;
    case E_Target::e_Enemy:
      msg += "enemy";
      break;
    case E_Target::e_Farm:
      msg += "farm";
      break;
    case E_Target::e_None:
      msg += "nothing";
      break;
    default:
      break;
    }

    std::cout << msg << std::endl;
  }

private:
  CharacterSharedState* ss_;
};

class CharacterFactory
{
public:
  CharacterFactory(std::initializer_list<CharacterSharedState> sharedStates)
  {
    for (const auto& ss : sharedStates) {
      characters_.insert(std::make_pair(getKey(&ss), Character(&ss)));
    }
  }

  Character& GetCharacter(const CharacterSharedState& ss)
  {
    const std::string key = getKey(&ss);
    if (characters_.find(key) == characters_.end()) {
      std::cout << "Character is missing. Creating one." << std::endl;
      characters_.insert(std::make_pair(key, Character(&ss)));
    }
    else {
      std::cout << "Character is found. Using it." << std::endl;
    }
    return characters_.at(key);
  }

private:
  std::string getKey(const CharacterSharedState* ss)
  {
    return std::to_string((int)ss->type_) + "_" + ss->texture_.getFilePath();
  }

private:
  std::unordered_map<std::string, Character> characters_;
};

int main(int argc, char** argv)
{
  CharacterFactory* factory = new CharacterFactory({ {E_CharacterType::e_Villager, "res/french_villager.png"} });

  Character& village_man1 = factory->GetCharacter({ E_CharacterType::e_Villager, "res/french_villager.png" });
  Character& village_man2 = factory->GetCharacter({ E_CharacterType::e_Villager, "res/spanish_villager.png" });

  village_man1.MakeAction({ E_CharacterAction::e_Farming, E_Target::e_Farm });
  village_man2.MakeAction({ E_CharacterAction::e_Free, E_Target::e_None });

  Character& soldier = factory->GetCharacter({ E_CharacterType::e_Horseman, "res/french_horseman.png" });

  soldier.MakeAction({ E_CharacterAction::e_Protecting, E_Target::e_Farm });

  return 0;
}