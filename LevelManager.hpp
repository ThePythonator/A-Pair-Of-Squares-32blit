#pragma once

#include <vector>

#include "Spritesheet.hpp"
//#include "Player.hpp"
#include "Orb.hpp"
#include "Spike.hpp"

// Struct header generated for the tmx files
#pragma pack(push,1)
struct TMX {
	char head[4];
	uint16_t header_length;
	uint16_t flags;
	uint16_t empty_tile;
	uint16_t width;
	uint16_t height;
	uint16_t layers;
	uint8_t data[];
};
#pragma pack(pop)

class Camera {
public:
	Camera();
	Camera(float x, float y, float ratio = 1.0f, uint16_t screen_mid_x = 0, uint16_t screen_mid_y = 0);

	void update(float dt, float player_x, float player_y);

	float get_view_x(float x);
	float get_view_y(float y);

private:
	float x = 0.0f;
	float y = 0.0f;

	float ratio = 1.0f;

	uint16_t screen_mid_x = 0;
	uint16_t screen_mid_y = 0;
};

class Tile {
public:
	Tile();
	Tile(uint16_t sprite_index, uint16_t x, uint16_t y);

	void render(Spritesheet& spritesheet);
	void render(Spritesheet& spritesheet, Camera& camera);

	uint16_t get_x();
	uint16_t get_y();

private:
	uint16_t sprite_index;
	uint16_t x, y;
};

class LevelHandler {
public:
	uint16_t level_spawn_pink_x, level_spawn_pink_y, level_spawn_blue_x, level_spawn_blue_y;
	uint16_t level_finish_blue_x, level_finish_blue_y, level_finish_pink_x, level_finish_pink_y;

	LevelHandler();
	LevelHandler(uint8_t sprite_size);

	void load_level(const uint8_t level_data[]);

	//void update(Player& player, float dt);


	void render(Spritesheet& spritesheet);
	//void render(Spritesheet& spritesheet, Camera& camera);

	uint8_t handle_orb_collisions(float x, float y, uint8_t type);
	bool handle_spike_collisions(float x, float y);

	std::vector<Tile> get_tiles();
	//std::vector<Orb> get_orbs();

	uint8_t get_sprite_size();

private:
	std::vector<Tile> tiles;
	std::vector<Orb> orbs;
	std::vector<Spike> spikes;

	uint8_t sprite_size;
};

// TODO: add method of loading tmx data into Level


bool is_colliding(Tile& tile, float x, float y, uint8_t sprite_size);
bool is_colliding(float tile_x, float tile_y, float x, float y, uint8_t sprite_size);

bool is_on_tile(Tile& tile, float x, float y, uint8_t sprite_size);


Spike::SpikeDirection parse_spike_id(uint16_t spike_id);