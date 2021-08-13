#pragma once

#include "SDL.h"

#include <string>

#include "LevelManager.hpp"

// Struct for colours
struct Colour {
	uint8_t r = 0x00;
	uint8_t g = 0x00;
	uint8_t b = 0x00;
	uint8_t a = 0xFF;

	Colour();
	Colour(uint8_t r, uint8_t g, uint8_t b);
	Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	Colour(const Colour& c);
	Colour(const Colour& c, uint8_t a);
};

void SDL_SetRenderDrawColor(SDL_Renderer* renderer, const Colour& colour);

void SDL_SetTextureColorMod(SDL_Texture* texture, const Colour& colour);

bool is_colliding(Tile& tile, float x, float y, uint8_t sprite_size);
bool is_colliding(float tile_x, float tile_y, float x, float y, uint8_t sprite_size);

bool is_on_tile(Tile& tile, float x, float y, uint8_t sprite_size);

std::string trim_precision(std::string string, uint8_t precision);