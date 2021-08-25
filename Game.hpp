#pragma once

#include <stdio.h>
#include <string>
#include <array>


#include "graphics/surface.hpp"


#include "Player.hpp"
#include "Spritesheet.hpp"
#include "InputManager.hpp"
#include "ParticleManager.hpp"
#include "TimerManager.hpp"
#include "Bezier.hpp"
#include "TextManager.hpp"
//#include "Utilities.hpp"
#include "LevelManager.hpp"

#include "Assets.hpp"


// Game class

class Game {
public:
	Game();

	void init();

	void update(float dt);
	void render();

private:

	void load_data();

	// Update and render functions for each state
	void update_menu_intro(float dt);
	void render_menu_intro();

	void update_menu_title(float dt);
	void render_menu_title();

	void update_menu_settings(float dt);
	void render_menu_settings();

	void update_menu_level_select(float dt);
	void render_menu_level_select();

	void update_game_running(float dt);
	void render_game_running();

	/*void update_game_paused(float dt);
	void render_game_paused();*/

	void update_game_end(float dt);
	void render_game_end();

	// Setup functions for each state
	void setup_menu_intro();
	void setup_menu_title();
	void setup_menu_settings();
	void setup_menu_level_select();
	void setup_game_running();
	//void setup_game_paused();
	void setup_game_end();

	// Transition functions
	void render_fade_in_rect(float delay);
	void render_fade_out_rect(float delay);

	std::pair<float, float> get_bezier_text_positions();

	// Utility functions
	void handle_menu_shape_particles();
	ImageParticle create_menu_shape_particle();

	ImageParticle create_game_finish_particle(float x, float y, uint8_t id);

	void fill_menu_shape_particle(uint8_t count);
	void setup_menu_shape_particles();

	bool level_is_completed();


	enum class GameState {
		MENU_INTRO,
		MENU_TITLE,
		MENU_SETTINGS,

		MENU_LEVEL_SELECT,

		GAME_RUNNING,
		//GAME_PAUSED,
		GAME_END
	};


	// Variables

	// Game state
	GameState game_state = GameState::MENU_INTRO;

	// Input handler
	InputHandler input_handler;

	// Particle handler
	struct {
		ParticleHandler back, front, spare;
	} particle_handlers;

	// Timer handler
	TimerHandler timer_handler;

	// Player
	Player player;

	// Camera
	//Camera camera;

	// Level handler
	LevelHandler level_handler;


	// State/data variables

	bool running = false;

	uint8_t option_selected = 0;
	bool option_confirmed = false;

	uint8_t menu_shape_particle_count = 0;

	struct {
		bool audio_music = true;
		bool audio_sfx = true;
	} settings;

	// Images
	blit::Surface spritesheet;
};