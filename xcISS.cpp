//============================================================================
// Name        : xcISS.cpp
// Author      : Alexander Loo
// Version     : 1.0
// Created	   : May 28, 2019, 3:41 PM
// Description : Text based game in C++, Ansi-style
//============================================================================

#include "xcISS.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	str_gm();
	stg_cntr(cntr.name, cntr.desc, cntr.ia1, cntr.ia2, man.key, man.cbl, man.pc, cntr.key, cntr.cbl, cntr.pc);
}

void str_gm(){
string cmd1;
cout << endl;
cout << " BAMMMMMM!!!" << endl;
cout << " Waking up in a daze, you notice you're head is throbbing," <<endl;
cout << " after a moment you realize you've been knocked unconscious and don't know where you are." <<endl;
cout << " There is a lingering smell of brimstone in the air for some reason."<<endl;
cout << " Find out what happened or try to go back to business as usual."<< endl << endl;
cout << " These are some of the actions you could use to navigate around:" << endl;
cout << endl;
	cout << " |> look around/item		" << endl;
	cout << " |> get + (item name)		" << endl;
	cout << " |> drop + (item name)		" << endl;
	cout << " |> go + place/direction	" << endl;
	cout << " |> view command list		" << endl;
	cout << " |> quit					" << endl;
	cout << endl;
	cout << " What's your first move? ";
}

//EXIT**
void stg_exit(){
	cout <<" You open the hatch and find a space suit and an escape pod waiting for you with a set of instructions.\n";
	cout <<" Without a second to spare you suit up, and jump in the pod....\n";
	cout <<" As you look out the spherical pod, you could see the spinning gigantic mass of a station and all its glory\n";
	cout <<" AIRLOCK DISABLED\n";
	cout <<" .\n";
	cout <<" .\n";
	cout <<" .\n";
	cout <<" You take one more glance back and wonder how the heck you got here in the first place\n";
	cout <<" PRESSURE IN THE CHAMBER RELEASED\n";
	cout <<" .\n";
	cout <<" .\n";
	cout <<" .\n";
	cout <<" Eeehhhh who's cares? You're home free!\n";
	cout <<" HATCH CLOSED\n";
	cout <<" 3\n";
	cout <<" 2\n";
	cout <<" 1\n";
        cout <<" BLAST OFF!!"<<endl<<endl;
	cout <<" Hooray!!! You escaped the International Space Station. Congratulations!!!!"<<endl<<endl;
        exit(0);
}

//TOP**
void stg_tpfl(string n, string d, string i1, string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp){
		cout << "Last moves?" <<endl;
	getline(cin, cmd);

	if(cmd.substr(0, cmd.find(" ")-0 ) == "go" || cmd.substr(0, cmd.find(" ")-0 ) == "GO"){
		for(int i = cmd.rfind(" "); i < cmd.length(); ++i){
			if(cmd.at(cmd.rfind(" ")+1) == 'f' && cmd.at(cmd.rfind(" ")+2) == 'l'){
				cmd.erase(cmd.rfind(" "), 10);
				cmd = cmd.substr(cmd.rfind(" ")+1,cmd.length() );
			}
		}
		 if(cmd.substr(0, cmd.find(" ")-0 ) == "second"){
			stg_fl2(fl2.name, fl2.desc, fl2.ia1, fl2.ia2, man.key, man.cbl, man.pc, fl2.key, fl2.cbl, fl2.pc);
		}
		else{
			cout <<" You can't go to that floor from here."<<i1<<i2<<endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "look"){
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );

		if(cmd.substr(0, cmd.find(" ")-0 ) == "around"){
			lk_ar(n, d);
			if(sk==true)
				inr(key.rm_des);
			if(sc==true)
				inr(cable.rm_des);
			if(tpfl.pc==true)
				inr(pc.rm_des);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"){
			if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk ==true){
				cout << key.desc << endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc ==true){
				cout << cable.desc <<endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp ==true){
				cout << pc.desc <<endl;
			}
			else{
				cout << "That item isn't here."<<endl;
			}
		}
		else {
			cout << "Invalid look command." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "get"){
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk==true){
			man.key = true;
			tpfl.key = false;
			getting_item(key.name);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc==true){
			man.cbl = true;
			tpfl.cbl = false;
			getting_item(cable.name);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp==true){
			man.pc = true;
			tpfl.pc = false;
			getting_item(pc.name);
		}
		else {
			cout << "You can't get an item that isn't here." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "drop"){
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==true){
			man.key = false;
			tpfl.key = true;
			drop_item(key.name, n);
		}
		else if(cmd.substr(0, cmd.find(" ")-0 ) == "cable"&& c==true){
			man.cbl = false;
			tpfl.cbl = true;
			drop_item(cable.name, n);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==true){
			man.pc = false;
			tpfl.pc = true;
			drop_item(pc.name, n);
		}
		else {
			cout << "You can't drop an item that isn't in the inventory." << endl;
		}
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "inventory"){
		prt_it(k, c, p);
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "list"){
		prt_clst();
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "QUIT" || cmd.substr(0, cmd.find(" ")-0 ) == "quit"){
		exit();
	}

	else{
		cout <<" No command picked up try again."<<endl;
			stg_tpfl(tpfl.name, tpfl.desc, tpfl.ia1, tpfl.ia2, man.key, man.cbl, man.pc, tpfl.key, tpfl.cbl, tpfl.pc);
	}
		stg_tpfl(tpfl.name, tpfl.desc, tpfl.ia1, tpfl.ia2, man.key, man.cbl, man.pc, tpfl.key, tpfl.cbl, tpfl.pc);
}

//SECOND**
void stg_fl2(string n, string d, string i1, string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp){
		cout << "What's next?" <<endl;
	getline(cin, cmd);

	if(cmd.substr(0, cmd.find(" ")-0 ) == "go" || cmd.substr(0, cmd.find(" ")-0 ) == "GO"){
		for(int i = cmd.rfind(" "); i < cmd.length(); ++i){
			if(cmd.at(cmd.rfind(" ")+1) == 'f' && cmd.at(cmd.rfind(" ")+2) == 'l'){
				cmd.erase(cmd.rfind(" "), 10);
				cmd = cmd.substr(cmd.rfind(" ")+1,cmd.length() );
			}
		}
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "door"){

			if(man.key == true){
				stg_tpfl(tpfl.name, tpfl.desc, tpfl.ia1, tpfl.ia2, man.key, man.cbl, man.pc, tpfl.key, tpfl.cbl, tpfl.pc);
			}
			else{
				cout << i1 <<endl<<endl;
			}
		}
		else if(cmd.substr(0, cmd.find(" ")-0 ) == "first"){
			stg_fl1(fl1.name, fl1.desc, fl1.ia1, fl1.ia2, man.key, man.cbl, man.pc, fl1.key, fl1.cbl, fl1.pc);
		}
		else{
			cout <<" You can't go to that floor from here."<<i1<<i2<<endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "look"){
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );

		if(cmd.substr(0, cmd.find(" ")-0 ) == "around"){
			lk_ar(n, d);
			if(sk==true)
				inr(key.rm_des);
			if(sc==true)
				inr(cable.rm_des);
			if(sp==true)
				inr(pc.rm_des);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"){
			if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk ==true){
				cout << key.desc << endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc ==true){
				cout << cable.desc <<endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp ==true){
				cout << pc.desc <<endl;
			}
			else{
				cout << "That item isn't here."<<endl;
			}
		}
		else {
			cout << "Invalid look command." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "get"){
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk==true){
			man.key = true;
			fl2.key = false;
			getting_item(key.name);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc==true){
			man.cbl = true;
			fl2.cbl = false;
			getting_item(cable.name);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp==true){
			man.pc = true;
			fl2.pc = false;
			getting_item(pc.name);
		}
		else {
			cout << "You can't get an item that isn't here." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "drop"){
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==true){
			man.key = false;
			fl2.key = true;
			drop_item(key.name, n);
		}
		else if(cmd.substr(0, cmd.find(" ")-0 ) == "cable"&& c==true){
			man.cbl = false;
			fl2.cbl = true;
			drop_item(cable.name, n);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==true){
			man.pc = false;
			fl2.pc = true;
			drop_item(pc.name, n);
		}
		else {
			cout << "You can't drop an item that isn't in the inventory." << endl;
		}
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "inventory"){
		prt_it(k, c, p);
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "list"){
		prt_clst();
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "QUIT" || cmd.substr(0, cmd.find(" ")-0 ) == "quit"){
		exit();
	}

	else{
		cout <<" No command picked up try again."<<endl;
			stg_fl2(fl2.name, fl2.desc, fl2.ia1, fl2.ia2, man.key, man.cbl, man.pc, fl2.key, fl2.cbl, fl2.pc);
	}
		stg_fl2(fl2.name, fl2.desc, fl2.ia1, fl2.ia2, man.key, man.cbl, man.pc, fl2.key, fl2.cbl, fl2.pc);
}

//FIRST**
void stg_fl1(string n, string d, string i1, string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp){
	cout << "What's next?" <<endl;
	getline(cin, cmd);

	if(cmd.substr(0, cmd.find(" ")-0 ) == "go" || cmd.substr(0, cmd.find(" ")-0 ) == "GO"){
		for(int i = cmd.rfind(" "); i < cmd.length(); ++i){
			if(cmd.at(cmd.rfind(" ")+1) == 'f' && cmd.at(cmd.rfind(" ")+2) == 'l'){
				cmd.erase(cmd.rfind(" "), 10);
				cmd = cmd.substr(cmd.rfind(" ")+1,cmd.length() );
			}
		}
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "center"
			||cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "control"){
			stg_cntr(cntr.name, cntr.desc, cntr.ia1, cntr.ia2, man.key, man.cbl, man.pc, cntr.key, cntr.cbl, cntr.pc);
		}
		else if(cmd.substr(0, cmd.find(" ")-0 ) == "second"){
			stg_fl2(fl2.name, fl2.desc, fl2.ia1, fl2.ia2, man.key, man.cbl, man.pc, fl2.key, fl2.cbl, fl2.pc);
		}
		else{
			cout <<" You can't go to that floor from here."<<i1<<i2<<endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "look"){
		//cmd = cmd.substr(sp_one+1, cmd.length());
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );
		cout << cmd <<endl<<endl;

		if(cmd.substr(0, cmd.find(" ")-0 ) == "around"){
			lk_ar(n, d);
			if(sk==true)
				inr(key.rm_des);
			if(sc==true)
				inr(cable.rm_des);
			if(sp==true)
				inr(pc.rm_des);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"){
			if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk ==true){
				cout << key.desc << endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc ==true){
				cout << cable.desc <<endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp ==true){
				cout << pc.desc <<endl;
			}
			else{
				cout << "That item isn't here."<<endl;
			}
		}
		else {
			cout << "Invalid look command." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "get"){
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk==true){
			man.key = true;
			fl1.key = false;
			getting_item(key.name);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc==true){
			man.cbl = true;
			fl1.cbl = false;
			getting_item(cable.name);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp==true){
			man.pc = true;
			fl1.pc = false;
			getting_item(pc.name);
		}
		else {
			cout << "You can't get an item that isn't here." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "drop"){
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==true){
			man.key = false;
			fl1.key = true;
			drop_item(key.name, n);
		}
		else if(cmd.substr(0, cmd.find(" ")-0 ) == "cable"&& c==true){
			man.cbl = false;
			fl1.cbl = true;
			drop_item(cable.name, n);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==true){
			man.pc = false;
			fl1.pc = true;
			drop_item(pc.name, n);
		}
		else {
			cout << "You can't drop an item that isn't in the inventory." << endl;
		}
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "inventory"){
		prt_it(k, c, p);
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "list"){
		prt_clst();
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "QUIT" || cmd.substr(0, cmd.find(" ")-0 ) == "quit"){
		exit();
	}

	else{
		cout <<" No command picked up try again."<<endl;
			stg_fl1(fl1.name, fl1.desc, fl1.ia1, fl1.ia2, man.key, man.cbl, man.pc, fl1.key, fl1.cbl, fl1.pc);
	}
		stg_fl1(fl1.name, fl1.desc, fl1.ia1, fl1.ia2, man.key, man.cbl, man.pc, fl1.key, fl1.cbl, fl1.pc);
}

//CENTER**
void stg_cntr(string n, string d, string i1, string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp){

	cout << "what now?" <<endl;
	getline(cin, cmd);

	if(cmd.substr(0, cmd.find(" ")-0 ) == "go" || cmd.substr(0, cmd.find(" ")-0 ) == "GO"){
		for(int i = cmd.rfind(" "); i < cmd.length(); ++i){
			if(cmd.at(cmd.rfind(" ")+1) == 'f' && cmd.at(cmd.rfind(" ")+2) == 'l'){
				cmd.erase(cmd.rfind(" "), 10);
				cmd = cmd.substr(cmd.rfind(" ")+1,cmd.length() );
			}
		}
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "door"){
			cout << i1 <<endl;
			if(k == true && c == true && p == true){
				stg_exit();
			}
			else{
				cout << " You don't have the necessary items, but there's a small panel by the door with a ethernet port and a key card slot." <<endl<<endl;
			}
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "window"){
			cout << i2  <<endl;
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "base"){
			stg_bfl(bfl.name, bfl.desc, bfl.ia1, bfl.ia2, man.key, man.cbl, man.pc, bfl.key, bfl.cbl, bfl.pc);
		}
		else if(cmd.substr(0, cmd.find(" ")-0 ) == "first"){
			stg_fl1(fl1.name, fl1.desc, fl1.ia1, fl1.ia2, man.key, man.cbl, man.pc, fl1.key, fl1.cbl, fl1.pc);
		}
		else{
			cout <<" You can't go to that floor from here."<<endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "look"){
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );
		if(cmd.substr(0, cmd.find(" ")-0 ) == "around"){
			lk_ar(n, d);
			if(sk==true)
				inr(key.rm_des);
			if(sc==true)
				inr(cable.rm_des);
			if(sp==true)
				inr(pc.rm_des);
		}

		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"){
			if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk ==true){
				cout << key.desc << endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc ==true){
				cout << cable.desc <<endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp ==true){
				cout << pc.desc <<endl;
			}
			else{
				cout << "That item isn't here."<<endl;
			}
		}
		else {
			cout << "Invalid look command." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "get"){
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk==true){
			man.key = true;
			cntr.key = false;
			getting_item(key.name);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc==true){
			man.cbl = true;
			cntr.cbl = false;
			getting_item(cable.name);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp==true){
			man.pc = true;
			cntr.pc = false;
			getting_item(pc.name);
		}
		else {
			cout << "You can't get an item that isn't here." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "drop"){
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==true){
			man.key = false;
			cntr.key = true;
			drop_item(key.name, n);
		}
		else if(cmd.substr(0, cmd.find(" ")-0 ) == "cable"&& c==true){
			man.cbl = false;
			cntr.cbl = true;
			drop_item(cable.name, n);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==true){
			man.pc = false;
			cntr.pc = true;
			drop_item(pc.name, n);
		}
		else {
			cout << "You can't drop an item that isn't in the inventory." << endl;
		}
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "inventory"){
		prt_it(k, c, p);
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "list"){
		prt_clst();
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "QUIT" || cmd.substr(0, cmd.find(" ")-0 ) == "quit"){
		exit();
	}

	else{
		cout <<" No command picked up try again."<<endl;
		stg_cntr(cntr.name, cntr.desc, cntr.ia1, cntr.ia2, man.key, man.cbl, man.pc, cntr.key, cntr.cbl, cntr.pc);
	}
	cout <<endl;
	stg_cntr(cntr.name, cntr.desc, cntr.ia1, cntr.ia2, man.key, man.cbl, man.pc, cntr.key, cntr.cbl, cntr.pc);
}

//BASE**
void stg_bfl(string n, string d, string i1, string i2, bool k, bool c, bool p, bool sk, bool sc, bool sp){
	cout << "Now what?" <<endl;
	getline(cin, cmd);

	if(cmd.substr(0, cmd.find(" ")-0 ) == "go" || cmd.substr(0, cmd.find(" ")-0 ) == "GO"){

		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "center"
			||cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "control"){
			stg_cntr(cntr.name, cntr.desc, cntr.ia1, cntr.ia2, man.key, man.cbl, man.pc, cntr.key, cntr.cbl, cntr.pc);
		}
		else{
			cout <<" You can't go to that floor from here."<< i1<<i2<<endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "look"){
		//cmd = cmd.substr(sp_one+1, cmd.length());
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );
		cout << cmd <<endl<<endl;

		if(cmd.substr(0, cmd.find(" ")-0 ) == "around"){
			lk_ar(n, d);
			if(sk==true)
				inr(key.rm_des);
			if(sc==true)
				inr(cable.rm_des);
			if(sp==true)
				inr(pc.rm_des);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"
				 || cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"){
			if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk ==true){
				cout << key.desc << endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc ==true){
				cout << cable.desc <<endl;
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp ==true){
				cout << pc.desc <<endl;
			}
			else{
				cout << "That item isn't here."<<endl;
			}
		}
		else {
			cout << "Invalid look command." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "get"){
		cout << cmd <<endl<<endl;
		if(cmd.substr(0, cmd.find(" ")-0 ) == "get"){
			if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==false && sk==true){
				man.key = true;
				bfl.key = false;
				getting_item(key.name);
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==false && sc==true){
				man.cbl = true;
				bfl.cbl = false;
				getting_item(cable.name);
			}
			else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==false && sp==true){
				man.pc = true;
				bfl.pc = false;
				getting_item(pc.name);
			}
		}
		else {
			cout << "You can't get an item that isn't here." << endl;
		}
	}

		else if(cmd.substr(0, cmd.find(" ")-0 ) == "drop"){
		cmd = cmd.substr(cmd.find(" ")+1,cmd.length() );
		cout << cmd <<endl;
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==true){
			man.key = false;
			bfl.key = true;
			drop_item(key.name, n);
		}
		else if(cmd.substr(0, cmd.find(" ")-0 ) == "cable"&& c==true){
			man.cbl = false;
			bfl.cbl = true;
			drop_item(cable.name, n);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==true){
			man.pc = false;
			bfl.pc = true;
			drop_item(pc.name, n);
		}
		else {
			cout << "You can't drop an item that isn't in the inventory." << endl;
		}
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "drop"){
		if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "key"&& k==true && sk==false){
			drop_item(key.name, n);

		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "cable"&& c==true && sc==false){
			drop_item(cable.name, n);
		}
		else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "laptop"&& p==true && sp==false){
			drop_item(pc.name, n);
		}
		else {
			cout << "You can't drop an item that isn't in the inventory." << endl;
		}
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "inventory"){
		prt_it(man.key, man.cbl, man.pc);
	}

	else if(cmd.substr(cmd.rfind(" ")+1, (cmd.length()-cmd.rfind(" ")) ) == "list"){
		prt_clst();
	}

	else if(cmd.substr(0, cmd.find(" ")-0 ) == "QUIT" || cmd.substr(0, cmd.find(" ")-0 ) == "quit"){
		exit();
	}

	else{
		cout <<" No command picked up try again."<<endl;
			stg_bfl(bfl.name, bfl.desc, bfl.ia1, bfl.ia2, man.key, man.cbl, man.pc, bfl.key, bfl.cbl, bfl.pc);
	}
		stg_bfl(bfl.name, bfl.desc, bfl.ia1, bfl.ia2, man.key, man.cbl, man.pc, bfl.key, bfl.cbl, bfl.pc);
}

void lk_ar(string x, string y){
	cout << x << endl;
	cout << y << endl;
}
void inr(string ri){
	cout << ri << endl;
}

void getting_item(string s){
	cout << s <<" has been put in your inventory."<<endl<<endl;
}
void drop_item(string i, string r){
	cout << i <<" has been dropped in the "<< r <<".\n"<<endl;
}
void prt_it(bool i1, bool i2, bool i3){
	if(i1 == true||i2 == true||i3 == true){
	cout << " You have a: "<<endl<<endl;
		if(i1 == true)
			cout <<" * " << key.name <<endl<<endl;
		if(i2 == true)
			cout <<" * " << cable.name <<endl<<endl;
		if(i3 == true)
			cout <<" * " << pc.name <<endl<<endl;
	cout <<" in your inventory."<<endl<<endl;
	}
	else{
		cout <<" You don't have anything in your inventory yet.\n";
	}
}
void prt_clst(){
	cout << " If you're having difficulties entering a command, Try using all lower case words." << endl;
	cout << " Here is a list of useful commands:" << endl<<endl;
	cout << " |> check inventory"				<< endl;
	cout << " |> go to + floor_level"				<<endl;
	cout << " |> get the + (item name)"			<<endl;
	cout << " |> drop the + (item name)"			<<endl;
}

void exit(){
cout << endl;
cout << "You left the game, try again later!" << endl;
cout << endl;
	exit(0);
}
