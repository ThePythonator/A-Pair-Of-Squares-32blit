#pragma once

//#include "engine/api.hpp"
//#include "engine/engine.hpp"
//#include "engine/input.hpp"
#include "graphics/sprite.hpp"
#include "graphics/surface.hpp"

class Spritesheet {
public:
	Spritesheet();
	Spritesheet(blit::Surface* screen, blit::Surface* spritesheet, uint8_t sprite_size = 16, uint8_t scale = 1);

	void sprite(uint16_t index, float x, float y);
	void sprite(uint16_t index, float x, float y, float scale);

	void sprite(uint16_t index, float x, float y, float angle, blit::Point& center, blit::SpriteTransform flip);
	void sprite(uint16_t index, float x, float y, float scale, float angle, blit::Point& center, blit::SpriteTransform flip);

	void sprite_scaled(uint16_t index, float x, float y);

	void sprite_scaled(uint16_t index, float x, float y, float angle, blit::Point& center, blit::SpriteTransform flip);

	void rect(blit::Rect& src_rect, float x, float y);
	void rect(blit::Rect& src_rect, float x, float y, float scale);

	void rect_scaled(blit::Rect& src_rect, float x, float y);

	void set_alpha(uint8_t alpha);


	float get_scale();
	uint8_t get_alpha();

	uint8_t get_sprite_size();

private:
	blit::Surface* screen = NULL;

	blit::Surface* spritesheet = NULL;

	int w, h;
	uint8_t rows, columns;

	uint8_t sprite_size;

	uint8_t scale;
};