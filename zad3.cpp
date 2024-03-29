#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>

using namespace std;

class Chempion
{

public:

	static vector<Chempion*> Team;

	Chempion(string first_ch, string last_ch, int weight_ch, int height_ch)
	{
		first_Name = first_ch; //firstname
		last_Name = last_ch;  //lastname
		weight = weight_ch;
		height = height_ch;
		skills.push_back("Attack");
		skills.push_back("Hiding");
		skills.push_back("Sneaking");
		skills.push_back("Just Power");
		skills.push_back("Offensive");

		Team.push_back(this);
	}

	Chempion(const Chempion &chempion)
	{
		first_Name = chempion.first_Name;
		last_Name = chempion.last_Name;
		weight = chempion.weight;
		height = chempion.height;
		skills = chempion.skills;
	}

	string write_first_Name()
	{
		return first_Name;
	}

	string write_last_Name()
	{
		return last_Name;
	}

	void change_last_Name(string last)//lastname
	{
		last_Name = last;
	}
	void change_first_Name(string first) //firstname
	{
		first_Name = first;
	}
	void change_height(int h) //height
	{
		height = h;
	}
	void change_weight(int wei)//weight
	{
		height = wei;
	}

	void add_Skill(string s)//skill
	{
		skills.push_back(s);
	}
	string showInfo()
	{

		ostringstream we;
		we << weight;
		ostringstream he;
		he << height;
		string skillsToReturn = "\n";
		for (int i = 0; i < skills.size(); i++)
		{
			skillsToReturn += skills[i] + "\n";
		}
		return "Chempion list :" + first_Name + " " + last_Name + "\nweight: " + we.str() + "\nheight: " + he.str() + "\nskills: " + skillsToReturn;


	}
private:
	int weight;
	int height;
	string first_Name;
	string last_Name;
	vector<string>skills;
};

vector<Chempion*> Chempion::Team;

class Team
{

	static int max_player_in_teamfight;
	static int created_team;
	string team_name;

public:
	vector<Chempion*> player_in_team;

	Team(string t)
	{
		team_name = t;

		for (int i = (created_team * 5); i < max_player_in_teamfight + (5 * created_team); i++)
		{
			player_in_team.push_back(Chempion::Team[i]);
		}
		created_team++;
	}

	Team(const Team &t)
	{
		team_name = t.team_name;
		player_in_team = t.player_in_team;
	}

	void change_team_name(string tn)
	{
		team_name = tn;
	}

	string write_team()
	{
		string return_to;
		return_to +=  team_name + "! \nPlayers: ";

		for (int i = 0; i < player_in_team.size(); i++)
		{
			return_to += "\n" + player_in_team[i]->write_first_Name() + " " + player_in_team[i]->write_last_Name();

		}

		return return_to;
	}
};

int Team::max_player_in_teamfight = 5;
int Team::created_team = 0;

int main()
{

	Chempion p1("Tony", "Stark", 90, 190);
	Chempion p2("Virginia Pepper", "Potts", 103, 199);
	Chempion p3("James", "Rhodes", 79, 176);
	Chempion p4("Howard", "Stark", 89, 189);
	Chempion p5("Bruce", "Banner", 120, 204);
	Chempion p6("Natasha", "Romanoff", 102, 187);
	Chempion p7("Ho", "Yinsen", 115, 193);
	Chempion p8("J.A.R", "V.I.S", 91, 189);
	Chempion p9("Nick", "Fury", 92, 193);
	Chempion p10("Anton", "Vanko", 88, 178);


	Team team_1("Team fight I");
	Team team_2("Team fight II");
	Team team_3 = team_2;
	team_3.change_team_name("Team fight III");

	cout << team_1.write_team() << endl << endl;
	cout << team_2.write_team() << endl << endl;
	cout << team_3.write_team() << endl << endl;
	cout << team_1.write_team() << endl << endl;
	cout << team_2.write_team() << endl << endl;
	cout << team_3.write_team() << endl << endl;


	return 0;
}