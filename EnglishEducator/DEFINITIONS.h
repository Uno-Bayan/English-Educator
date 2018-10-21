#pragma once

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

#define SPLASH_STATE_SHOW_TIME 7.5
#define TEXT_APPEARANCE_TIME 100
#define BACKGROUND_CHANGE_TIME 100

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/Menu/Main Menu Background.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/Menu/Gameplay_Background.png"

// Main Menu Buttons
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/Menu/Play.png"
#define QUIT_BUTTON_FILEPATH "Resources/res/Menu/Quit.png"

// Start Menu Background and Buttons
#define START_MENU_BUTTON_BACKGROUND_FILEPATH "Resources/res/Menu/Main Menu Sprite Background.png"
#define START_MENU_GRAMMAR_BUTTON_FILEPATH "Resources/res/Menu/Start Menu/GrammarExercises.png"
#define START_MENU_VOCABULARY_BUTTON_FILEPATH "Resources/res/Menu/Start Menu/VocabularyExercises.png"
#define START_MENU_OLYMPIAD_BUTTON_FILEPATH "Resources/res/Menu/Start Menu/Olympiad.png"

#define LAND_FILEPATH "Resources/res/Land.png"

#define STICK_FRAME_1_FILEPATH "Resources/res/Characters/Main-1.png"
#define STICK_FRAME_2_FILEPATH "Resources/res/Characters/Main-2.png"
#define STICK_FRAME_3_FILEPATH "Resources/res/Characters/Main-3.png"
#define STICK_FRAME_4_FILEPATH "Resources/res/Characters/Main-4.png"

// Teacher Frames
#define TEACHER_FRAME_1_FILEPATH "Resources/res/Characters/EllenBaker/EllenBaker1.png"
#define TEACHER_FRAME_2_FILEPATH "Resources/res/Characters/EllenBaker/EllenBaker2.png"
#define TEACHER_FRAME_3_FILEPATH "Resources/res/Characters/EllenBaker/EllenBaker3.png"
#define TEACHER_FRAME_4_FILEPATH "Resources/res/Characters/EllenBaker/EllenBaker4.png"
#define TEACHER_FRAME_5_FILEPATH "Resources/res/Characters/EllenBaker/EllenBaker5.png"
#define TEACHER_FRAME_6_FILEPATH "Resources/res/Characters/EllenBaker/EllenBaker6.png"
#define TEACHER_FRAME_7_FILEPATH "Resources/res/Characters/EllenBaker/EllenBaker7.png"
#define TEACHER_FRAME_8_FILEPATH "Resources/res/Characters/EllenBaker/EllenBaker8.png"
#define TEACHER_FRAME_9_FILEPATH "Resources/res/Characters/EllenBaker/EllenBaker9.png"
#define TEXT_BOX_FILEPATH "Resources/res/Characters/EllenBaker/Text Box.png"

// Topic Sprites
#define SIMPLE_PRESENT_FILEPATH "Resources/res/Characters/EllenBaker/Topics/Simple Present.png"
#define SIMPLE_PRESENT_2_FILEPATH "Resources/res/Characters/EllenBaker/Topics/Simple Present 2.png"
#define SIMPLE_PAST_FILEPATH "Resources/res/Characters/EllenBaker/Topics/Simple Past.png"
#define SIMPLE_PAST_2_FILEPATH "Resources/res/Characters/EllenBaker/Topics/Simple Past 2.png"
#define SIMPLE_FUTURE_FILEPATH "Resources/res/Characters/EllenBaker/Topics/Simple Future.png"
#define FUTURE_CONTINUOUS_FILEPATH "Resources/res/Characters/EllenBaker/Topics/Future Continuous.png"

// Random Sprites
#define ANSWER_TEXTURE_FILEPATH "Resources/res/QandA/Answer.png"

#define TEACHER_ANIMATION_DURATION 0.20

// Fonts
#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"
#define KGHAPPY_FONT_FILEPATH "Resources/fonts/KGHAPPY.ttf"
#define WUNDERLAND_FONT_FILEPATH "Resources/fonts/Im Wunderland Italic.otf"
#define SUGAR_FONT_FILEPATH "Resources/fonts/No Added Sugar.otf"

#define ANSWER_CHARACTER_SIZE 24

#define MAIN_CHARACTER_STATE_STILL 1
#define MAIN_CHARACTER_STATE_WALKING 2
#define MAIN_CHARACTER_STATE_RUNNING 3

enum GrammarStates
{
	eNone,
	eSimplePresent,
	eSimplePresent2,
	eSimplePast,
	eSimplePast2,
	eSimpleFuture,
	eFutureContinuous
};

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};