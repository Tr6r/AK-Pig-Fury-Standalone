#ifndef __PF_GAME_H__
#define __PF_GAME_H__

#include <stdint.h>
#include "app.h"

class pig_fury_game
{
public:
	pig_fury_game() = default;
	~pig_fury_game() = default;
	void init();
	void process();
private:
};

#endif //__PF_GAME_H__
