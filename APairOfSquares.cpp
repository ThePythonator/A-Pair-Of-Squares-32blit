#include "APairOfSquares.hpp"

// Create game
Game game;

void init() {
	// Run game
	game.init();
}


void render(uint32_t time) {
	// Render game
	game.render();
}


void update(uint32_t time) {
	float dt = 0.01f;

	// Update input handler (updates all key states etc)
	//input_handler.update();


	// Delegate to InputHandler
	//input_handler.handle_sdl_event(sdl_event);

	// Update game
	game.update(dt);
}
