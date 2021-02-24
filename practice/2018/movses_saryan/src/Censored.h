#pragma once
#include <unordered_map>

#include "SpidermanClasses.h"

template<class Hero>
class Censored : public Hero
{
	using BadToGoodWords_t = std::unordered_map<std::string, std::string>;
public:
	template<class... Args>
	Censored(Args&&... args) : Hero(std::forward<Args>(args)...)
	{
	}
	virtual std::string lifeBeforeSuperpower() override
	{
		std::string s = this->Hero::lifeBeforeSuperpower();
		perephrase(s);
		return s;
	}
	virtual std::string gettingSuperpower() override
	{
		std::string s = this->Hero::gettingSuperpower();
		perephrase(s);
		return s;
	}
	virtual std::string saveWorld() override
	{
		std::string s = this->Hero::saveWorld();
		perephrase(s);
		return s;
	}
public:
	void addBadWord(const std::string& badWord, const std::string& goodWord)
	{
		auto hint = dict.find(badWord);
		if (hint == dict.end())
		{
			dict.insert(hint, std::make_pair(badWord, goodWord));
		}
	}
private:
	void perephrase(std::string& s)
	{
		for (auto&& el : dict)
		{
			auto start_pos = s.find(el.first);
			if (start_pos != std::string::npos)
			{
				s.replace(start_pos, el.first.length(), el.second);
			}
		}
	}
private:
	static BadToGoodWords_t dict;
	static bool initialized;
};

template<class Hero>
bool Censored<Hero>::initialized = false;

template<class Hero>
typename Censored<Hero>::BadToGoodWords_t Censored<Hero>::dict = { { "fucking", "######"}, {"shit", "looser"} };