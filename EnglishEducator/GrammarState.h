#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "EllenBaker.h"
#include "QandA.h"
#include <fstream>
#include <string>

namespace EnglishEducator
{
	class GrammarState : public State
	{
	public:
		
		GrammarState(GameDataRef _data);
		
		void Init();

		void HandleInput();

		void Update(float dt);

		int GetGrammarState();

		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;

		EllenBaker *ellenBaker;

		QandA *qAndA;

		sf::Clock _clock;

		int _grammarState = 0;
	};
}