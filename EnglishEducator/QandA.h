#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"
#include "String"
#include <fstream>
#include <iostream>

namespace EnglishEducator
{
	class QandA
	{
	public:
		QandA(GameDataRef data, int grammarState);

		void Update();
		void AdvanceQandA();

		const sf::Sprite &GetA1Sprite() const;
		const sf::Sprite &GetA2Sprite() const;
		const sf::Sprite &GetA3Sprite() const;
		const sf::Sprite &GetA4Sprite() const;
		const std::string &GetCorrectAnswer() const;

		void IncrementScore();

		void MakeAnswersAppear(bool trueOrFalse);
		void Draw();

		~QandA();

	private:
		GameDataRef _data;

		sf::Text _question;
		std::string _questionText;
		sf::Text _a1;
		std::string _a1Text;
		sf::Text _a2;
		std::string _a2Text;
		sf::Text _a3;
		std::string _a3Text;
		sf::Text _a4;
		std::string _a4Text;
		sf::Text _correctAnswer;
		std::string _correctAnswerText;

		int _questionCounter = 0;
		int _correctAnswerCounter = 0;

		sf::Sprite _a1sp;
		sf::Sprite _a2sp;
		sf::Sprite _a3sp;
		sf::Sprite _a4sp;

		bool _makeAnswersAppear = false;

		int _grammarState;

		friend class GrammarState;
	};
}