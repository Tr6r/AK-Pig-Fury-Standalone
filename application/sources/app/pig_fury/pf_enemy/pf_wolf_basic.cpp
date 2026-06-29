#include "pf_wolf_basic.h"

void pf_wolf_basic::init(pf_char_dir dir) {
	if (dir == PF_CHAR_DIR_LEFT) pos_x_ = PF_WOLF_BASIC_SPAWN_LEFT_X;
	else pos_x_ = PF_WOLF_BASIC_SPAWN_RIGHT_X;
	pos_y_ = PF_WOLF_BASIC_POS_Y; 
	hp_ = PF_WOLF_BASIC_MAX_HP;
	st_ = PF_ENEMY_ST_SPAWN;
	width_ = PF_WOLF_BASIC_WIDTH;
	height_ = PF_WOLF_BASIC_HEIGHT;
	char_st_ = PF_CHAR_ST_IDLE;
	move_dur_tick_ = PF_WOLF_BASIC_MOVE_FRAME_TICK;
	dir_ = dir;
}

void pf_wolf_basic::update() {
	switch (st_) {
		case PF_ENEMY_ST_SPAWN:
		case PF_ENEMY_ST_MOVE: {
			update_move();
			break;
		}
		case PF_ENEMY_ST_HIT: {
			update_hit();
			break;
		}
		default:
			break;
	}
}

void pf_wolf_basic::update_hit() {
	hit_dur_tick_--;
	switch (hit_dur_tick_)
	{
		case 0: {
			st_ = PF_ENEMY_ST_MOVE;
			break;
		}
		case 3:
		case 2: {
			pos_y_ = pos_y_ + 2;
			break;
		}
		case 5:
		case 4: {
			pos_y_ = pos_y_ - 2;
			break; 
		}
		default:{
			st_ = PF_ENEMY_ST_MOVE;
			break;
		}
	}
	pos_x_ += (dir_ == PF_CHAR_DIR_LEFT) ? -1 : 1;
}

void pf_wolf_basic::update_move() {
	update_move_state();
	st_ = PF_ENEMY_ST_MOVE;
	switch (dir_) {
		case PF_CHAR_DIR_LEFT: {
			if (pos_x_ + PF_WOLF_BASIC_UPDATE_STEP_PIXEL >= PF_WOLF_BASIC_LIMITED_MOVE_LEFT) {
				st_ = PF_ENEMY_ST_ATTACK;
				return;
			}
			pos_x_ += PF_WOLF_BASIC_UPDATE_STEP_PIXEL;
			break;
		}
		case PF_CHAR_DIR_RIGHT: {
			if (pos_x_ - PF_WOLF_BASIC_UPDATE_STEP_PIXEL <= PF_WOLF_BASIC_LIMITED_MOVE_RIGHT) {
				st_ = PF_ENEMY_ST_ATTACK;
				return;
			}
			pos_x_ -= PF_WOLF_BASIC_UPDATE_STEP_PIXEL;
			break;
		}
		default:
			break;
	}
}

void pf_wolf_basic::render() {
	switch (st_)
	{
	case PF_ENEMY_ST_MOVE: {
		render_move();
		break;
	}
	case PF_ENEMY_ST_HIT: {
		render_hit();
		break;
	}
	case PF_ENEMY_ST_ATTACK: {
		render_move();
		break;
	}
	default:
		break;
	}
}

void pf_wolf_basic::render_hit() {
	if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_hit_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_hit_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
}

void pf_wolf_basic::render_move() {
	switch (move_st_) {
		case PF_WOLF_BASIC_MOVE_1 :{
			if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_run_1_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_run_1_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
			break;
		}
		case PF_WOLF_BASIC_MOVE_2 :{
			if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_run_2_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_run_2_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
			break;
		}
		case PF_WOLF_BASIC_MOVE_3 :{
			if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_run_3_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_run_3_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
			break;
		}
		case PF_WOLF_BASIC_MOVE_4 :{
			if (dir_ == PF_CHAR_DIR_LEFT) view_render.drawBitmap(pos_x_, pos_y_,wolf_run_4_left, PIG_WIDTH, PIG_HEIGHT, WHITE);
			else view_render.drawBitmap(pos_x_, pos_y_,wolf_run_4_right, PIG_WIDTH, PIG_HEIGHT, WHITE);
			break;
		}
		default:
			break;
	}
}

void pf_wolf_basic::attack() {

}

void pf_wolf_basic::take_damage() {
	if (st_ == PF_ENEMY_ST_HIT)
		return;
	hp_ --;
	hit_dur_tick_ = PF_WOLF_BASIC_HIT_FRAME_TICK;
	if (hp_ == 0) st_ = PF_ENEMY_ST_DEAD;
	else  st_ = PF_ENEMY_ST_HIT;
}
