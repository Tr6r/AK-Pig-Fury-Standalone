#ifndef __PIG_FURY_GAME_H__
#define __PIG_FURY_GAME_H__

#include <stdint.h>
#include "app.h"

class PigFuryGame
{
public:
    PigFuryGame() = default;
    ~PigFuryGame() = default;
    void init();
    void process();
private:
};

#endif //__PIG_FURY_GAME_H__
