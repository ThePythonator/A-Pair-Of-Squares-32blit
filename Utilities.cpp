#include "Utilities.hpp"

Colour::Colour() {

}

Colour::Colour(uint8_t r, uint8_t g, uint8_t b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

Colour::Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Colour::Colour(const Colour& c) {
	r = c.r;
	g = c.g;
	b = c.b;
	a = c.a;
}

Colour::Colour(const Colour& c, uint8_t a) {
	r = c.r;
	g = c.g;
	b = c.b;
	this->a = a;
}


//void SDL_SetRenderDrawColor(SDL_Renderer* renderer, const Colour& colour) {
//	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
//}
//
//void SDL_SetTextureColorMod(SDL_Texture* texture, const Colour& colour) {
//	SDL_SetTextureColorMod(texture, colour.r, colour.g, colour.b);
//}




std::string trim_precision(std::string string, uint8_t precision) {
	// Trim string to precision
	return string.substr(0, string.find('.') + precision + 1);
}