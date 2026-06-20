#ifndef __PF_GAME_H__
#define __PF_GAME_H__

#include <stdint.h>
#include "app.h"

#include "pf_pig.h"

class pig_fury_game
{
public:
	pig_fury_game() = default;
	~pig_fury_game() = default;
	void init();
	void update();
	void render();
	void pig_attack(pf_char_dir dir);

private:
	pf_pig pig_;
};

void pf_game_init();
void pf_game_update();
void pf_game_render();
void pf_pig_atk(pf_char_dir dir);

#endif //__PF_GAME_H__
