#include "Spritesheet.hpp"

Spritesheet::Spritesheet() {
	w = h = 0;
	rows = columns = 0;

	sprite_size = 8;
	scale = 1;
}

Spritesheet::Spritesheet(Surface* screen, SpriteSheet* spritesheet, uint8_t sprite_size, uint8_t scale) {
	this->screen = screen;
	this->spritesheet = spritesheet;

	// Get width and height of spritesheet
	w = spritesheet->bounds.w;
	h = spritesheet->bounds.h;

	rows = h / sprite_size;
	columns = w / sprite_size;

	this->sprite_size = sprite_size;
	this->scale = scale;
}

void Spritesheet::sprite(uint16_t index, float x, float y) {
	// Render sprite at index from texture to screen
	Rect src_rect{ sprite_size * (index % columns), sprite_size * (index / columns), sprite_size, sprite_size };
	Point dst_point{ (int)x, (int)y };

	screen->blit_sprite(src_rect, dst_point)
}

void Spritesheet::sprite(uint16_t index, float x, float y, float scale) {
	// Render sprite at index from texture to screen
	SDL_Rect src_rect{ sprite_size * (index % columns), sprite_size * (index / columns), sprite_size, sprite_size };
	SDL_Rect dst_rect{ (int)(x * scale), (int)(y * scale), sprite_size * scale, sprite_size * scale };

	screen->stretch_blit_sprite(src_rect, dst_rect)
}

void Spritesheet::sprite(uint16_t index, float x, float y, float angle, Point& center, SpriteTransform flip) {
	// Render sprite at index from texture to screen
	SDL_Rect src_rect{ sprite_size * (index % columns), sprite_size * (index / columns), sprite_size, sprite_size };
	SDL_Rect dst_rect{ (int)x, (int)y, sprite_size, sprite_size };

	if (center != NULL) {
		center->x *= scale;
		center->y *= scale;
	}

	//SDL_RenderCopyEx(renderer, spritesheet_texture, &src_rect, &dst_rect, angle, center, flip);
}

void Spritesheet::sprite(uint16_t index, float x, float y, float scale, float angle, Point& center, SpriteTransform flip) {
	// Render sprite at index from texture to screen
	SDL_Rect src_rect{ sprite_size * (index % columns), sprite_size * (index / columns), sprite_size, sprite_size };
	SDL_Rect dst_rect{ (int)(x * scale), (int)(y * scale), sprite_size * scale, sprite_size * scale };

	// Note: possible issue here, if center != NULL, the value at that address is altered, i.e. it's modified globally, not just locally
	if (center != NULL) {
		center->x *= scale;
		center->y *= scale;
	}

	//SDL_RenderCopyEx(renderer, spritesheet_texture, &src_rect, &dst_rect, angle, center, flip);
}

void Spritesheet::sprite_scaled(uint16_t index, float x, float y) {
	// Render sprite at index from texture to screen
	sprite(index, x, y, scale);
}

void Spritesheet::sprite_scaled(uint16_t index, float x, float y, float angle, Point& center, SpriteTransform flip) {
	// Render sprite at index from texture to screen
	sprite(index, x, y, scale, angle, center, flip);
}

void Spritesheet::rect(Rect& src_rect, float x, float y) {
	Point dst_point{ (int)x, (int)y };

	screen->blit_sprite(src_rect, dst_point);
}

void Spritesheet::rect(Rect& src_rect, float x, float y, float scale) {
	Rect dst_rect{ (int)(x * scale), (int)(y * scale), src_rect->w * scale, src_rect->h * scale };

	screen->blit_sprite(src_rect, dst_rect);
}

void Spritesheet::rect_scaled(Rect& src_rect, float x, float y) {
	rect(src_rect, x, y, scale);
}


void Spritesheet::set_alpha(uint8_t alpha)
{
	// Set texture alpha
	spritesheet->alpha = alpha;
}


float Spritesheet::get_scale() {
	return scale;
}

uint8_t Spritesheet::get_alpha() {
	return spritesheet->alpha;
}

uint8_t Spritesheet::get_sprite_size() {
	return sprite_size;
}
