/*
 * File:   xcISS.hpp
 * Author: Alexander Loo
 *
 * Created on June 7, 2019, 10:44 AM
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>

void str_gm(); void pt_clst(); void lk_ar(std::string x, std::string y);
void inr(std::string ri);
void prt_clst();
void prt_it(bool i1, bool i2, bool i3);
void getting_item(std::string s);
void drop_item(std::string i, std::string r);
void stg_tpfl(std::string n, std::string d, std::string i1, std::string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp);
void stg_fl2(std::string n, std::string d, std::string i1, std::string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp);
void stg_fl1(std::string n, std::string d, std::string i1, std::string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp);
void stg_exit();
void stg_cntr(std::string n, std::string d, std::string i1, std::string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp);
void stg_bfl(std::string n, std::string d, std::string i1, std::string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp);
void exit();

std::string cmd;
int sp_one = cmd.find(" ");

class inventory{
	public:
		bool key;
		bool cbl;
		bool pc;
};
inventory man{false,false,false};

/*
 * desc - description
 * ia1 - interaction1
 * ia2 - interaction2
 * cbl - cable
 */
class stage{
	public:
		std::string name;
		std::string desc;
		std::string ia1;
		std::string ia2;
		bool key;
		bool cbl;
		bool pc;
};
stage tpfl{"* Observatory *",
	" You look around and there are windows as far as eyes could see. Apparently you've been inside the International Space Station this whole time.",
	" ",
	" ",
	false,false,true};
stage fl2{"*  Second floor *",
	" This room looks very similar to the previous ones but there's something different, like an opening door on the ceiling.",
	" Looks like the top floor is locked. Upon closer inspection, there happens to be key card slot next to this ceiling door",
	" ",
	false,false,false};
stage fl1{"* First floor *",
	" You're in another room with 4 walls and there's \"Space X\" plastered all over the walls",
	" ",
	" ",
	false,false,false};
stage ex_htch{"* Escape hatch *",
	" You're SO close to leaving you could almost smell it! Though you could definitely smell brimstone in the air.",
	" ",
	" ",
	false,false,false};
stage cntr{"* Control Center *",
	" You find yourself in a cushioned room with 4 walls, one of which has a window in the center, and the other is a really big door",
	" It's a thick metal door with a 3\"double-paned window and a sign reading \"Warning airlock zone, enter with caution.\"\n",
	" Peering out the small oval window you find yourself looking into a dark nothingness, until your eyes fix upon a circular shape in the center of the void. \n While squinting, your vision recovers and focuses on the planet Earth. Looks like your not in Kansas anymore!",
	false,true,false};
stage bfl{"* Base floor *",
	" I guess you hit rock bottom, or just bottom of whatever you're in.",
	" ",
	" ",
	true,false,false};

class item{
	public:
		std::string name;
		std::string desc;
		std::string rm_des;

		void it_des(){

		}
		//std::string itm_get; make function here for these two
		//itm_drop; Refer to cable
		bool got;
		bool drop;
};
item key{" Key",
	" Looks like the same keys you get from a hotel counter.",
	" There's a shiny key floating in the air, This may come in handy.",
	false,false};
item cable{" Cable",
	" Black ethernet cable with \"Boring Co.\" embossed on the side.",
	" Seems like you're spinning around a cable in the air, or is it spinning around you??",
	false,false};
item pc{" Laptop",
	" Commercial grade laptop.",
	" There happens to be a laptop floating in the air, looks like this could be your lucky day.",
	false,false};
