#ifndef __PF_WOLF_H__
#define __PF_WOLF_H__

#include <stdint.h>

#include "app.h"

#include "pf_char.h"

#define WOLF_MAX_HP			1
#define WOLF_UPDATE_SPEED	2

enum pf_wolf_st : uint8_t
{
	PF_WOLF_ST_SPAWN,
	PF_WOLF_ST_MOVE,
	PF_WOLF_ST_ATTACK,
	PF_WOLF_ST_HIT,
	PF_WOLF_ST_DEAD,
};

class pf_wolf : public pf_char
{
public:
	pf_wolf() = default;
	~pf_wolf() override = default;

	void init() override;
	void update() override;
	void render() override;

	void attack();
	void take_damage();

	// getter
	uint8_t get_hp() const { return hp_; }
	pf_wolf_st get_st() const { return st_; }
	bool is_active() const { return active_; }

	// setter
	void set_hp(uint8_t hp) { hp_ = hp; }
	void set_st(pf_wolf_st st) { st_ = st; }
	void set_active(bool active) { active_ = active; }

private:
	void update_st();
	void update_move();
	void update_attack();
	void render_st();
	void render_attack();

	uint8_t hp_;
	uint8_t move_speed_;
	bool active_;
	pf_wolf_st st_;
};

#endif // __PF_WOLF_H__