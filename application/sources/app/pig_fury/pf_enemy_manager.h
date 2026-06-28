#ifndef __PF_ENEMY_MANAGER_H__
#define __PF_ENEMY_MANAGER_H__

#include "pf_enemy.h"
#include "pf_wolf_basic.h"

#define PF_GAME_MAX_ENEMY 8
#define PF_GAME_MAX_WOLF_BASIC 1

class pf_enemy_manager {
public:
	pf_enemy_manager() = default;
	~pf_enemy_manager() = default;

	void init();
	void update();
	void render();

	void spawm_enemy();
	void remove_enemy();

	// Getters
	pf_enemy *get_enemy(uint8_t index);
	uint8_t get_enemy_count() const { return enemy_count_; }

private:
	pf_wolf_basic wolves_[PF_GAME_MAX_WOLF_BASIC];
	pf_enemy *enemies_[PF_GAME_MAX_ENEMY];
	uint8_t enemy_count_;
};

#endif // __PF_ENEMY_MANAGER_H__