#include "stdafx.h"
#include "GrammarState.h"
#include "QandA.h"

namespace EnglishEducator
{
	std::ifstream inFile;

	QandA::QandA(GameDataRef data, int stateNum) : _data(data)
	{
		GrammarState grammarState(_data);
		_grammarState = stateNum;

		_data->assets.LoadFont("Sugar Font", SUGAR_FONT_FILEPATH);

		_data->assets.LoadTexture("Answer Texture", ANSWER_TEXTURE_FILEPATH);

		_a1sp.setTexture(_data->assets.GetTexture("Answer Texture"));
		_a2sp.setTexture(_data->assets.GetTexture("Answer Texture"));
		_a3sp.setTexture(_data->assets.GetTexture("Answer Texture"));
		_a4sp.setTexture(_data->assets.GetTexture("Answer Texture"));

		_a1sp.setPosition(sf::Vector2f(450, 600));
		_a2sp.setPosition(sf::Vector2f(650, 600));
		_a3sp.setPosition(sf::Vector2f(450, 660));
		_a4sp.setPosition(sf::Vector2f(650, 660));

		_question.setFont(_data->assets.GetFont("Sugar Font"));
		_a1.setFont(_data->assets.GetFont("Sugar Font"));
		_a2.setFont(_data->assets.GetFont("Sugar Font"));
		_a3.setFont(_data->assets.GetFont("Sugar Font"));
		_a4.setFont(_data->assets.GetFont("Sugar Font"));
		_correctAnswer.setFont(_data->assets.GetFont("Sugar Font"));

		_question.setCharacterSize(48);
		_a1.setCharacterSize(ANSWER_CHARACTER_SIZE);
		_a2.setCharacterSize(ANSWER_CHARACTER_SIZE);
		_a3.setCharacterSize(ANSWER_CHARACTER_SIZE);
		_a4.setCharacterSize(ANSWER_CHARACTER_SIZE);
		_correctAnswer.setCharacterSize(48);

		_question.setFillColor(sf::Color::Black);
		_a1.setFillColor(sf::Color::Black);
		_a2.setFillColor(sf::Color::Black);
		_a3.setFillColor(sf::Color::Black);
		_a4.setFillColor(sf::Color::Black);
		_correctAnswer.setFillColor(sf::Color::Red);

		_question.setPosition(sf::Vector2f(350, 100));
		_a1.setPosition(sf::Vector2f(490, 610));
		_a2.setPosition(sf::Vector2f(690, 610));
		_a3.setPosition(sf::Vector2f(490, 670));
		_a4.setPosition(sf::Vector2f(690, 670));
		_correctAnswer.setPosition(sf::Vector2f(690, 200));
		std::cout << "Score is: " << _correctAnswerCounter << std::endl;

		switch (_grammarState)
		{
		case 0:

			break;
		case 1:
			inFile.open("Resources/Q&A/Grammar/Simple Present.txt");
			break;
		case 2:
			inFile.open("Resources/Q&A/Grammar/Simple Present 2.txt");
			break;
		case 3:
			inFile.open("Resources/Q&A/Grammar/Simple Past.txt");
			break;
		case 4:
			inFile.open("Resources/Q&A/Grammar/Simple Past 2.txt");
			break;
		case 5:
			inFile.open("Resources/Q&A/Grammar/Simple Future.txt");
			break;
		case 6:
			inFile.open("Resources/Q&A/Grammar/Future Continuous.txt");
			break;
		}

		if (inFile.fail())
		{
			std::cout << "Can't open file" << std::endl;
		}
	}

	void QandA::Update()
	{
		
	}

	void QandA::AdvanceQandA()
	{
		_questionCounter++;
		
		std::getline(inFile, _questionText);
		if (_questionText == "")
		{
			std::getline(inFile, _questionText);
		}
		std::cout << "Question text: " + _questionText << "\nQuestion Length: " << _questionText.length() << std::endl;
		if (_questionText.length() > 100)
		{
			_question.setCharacterSize(24);
		}
		else if (_questionText.length() > 60)
		{
			_question.setCharacterSize(32);
		}
		else
		{
			_question.setCharacterSize(48);
		}
		
		inFile >> _a1Text;
		std::cout << "a1 text: " + _a1Text << std::endl;
		inFile >> _a2Text;
		std::cout << "a2 text: " + _a2Text << std::endl;
		inFile >> _a3Text;
		std::cout << "a3 text: " + _a3Text << std::endl;
		inFile >> _a4Text;
		std::cout << "a4 text: " + _a4Text << std::endl;
		inFile >> _correctAnswerText;
		std::cout << "Correct Answer: " + _correctAnswerText << std::endl;

		_question.setString(_questionText);
		_a1.setString(_a1Text);
		_a2.setString(_a2Text);
		_a3.setString(_a3Text);
		_a4.setString(_a4Text);

		_correctAnswer.setString(std::to_string(_correctAnswerCounter) + "/15");
	}

	void QandA::IncrementScore()
	{
		_correctAnswerCounter++;
	}

	void QandA::MakeAnswersAppear(bool trueOrFalse)
	{
		_makeAnswersAppear = trueOrFalse;
	}

	void QandA::Draw()
	{
		if (_makeAnswersAppear == true)
		{
			_data->window.draw(_a1sp);
			_data->window.draw(_a2sp);
			_data->window.draw(_a3sp);
			_data->window.draw(_a4sp);
			_data->window.draw(_correctAnswer);

			_data->window.draw(_question);
			_data->window.draw(_a1);
			_data->window.draw(_a2);
			_data->window.draw(_a3);
			_data->window.draw(_a4);
		}
	}

	const sf::Sprite &QandA::GetA1Sprite() const
	{
		return _a1sp;
	}

	const sf::Sprite &QandA::GetA2Sprite() const
	{
		return _a2sp;

	}

	const sf::Sprite &QandA::GetA3Sprite() const
	{
		return _a3sp;
	}

	const sf::Sprite &QandA::GetA4Sprite() const
	{
		return _a4sp;
	}

	QandA::~QandA()
	{
		inFile.close();
	}
}