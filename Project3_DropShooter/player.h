//DT Nesimi

#ifndef PLAYERH
#define PLAYERH
class player
{
public:

	player();
	~player();
	void DrawPlayer();
	void MoveLeft();
	void MoveRight();
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() { return x; }
	int getY() { return y; }
	void removeLife() { lives--; }
	float getAngle() { return angle; }

	int getLives() { return lives; }	// returns lives for lives check
	void increaseScore() { score++; }	//increases score :]
	int getScore() { return score; }	//returns score!
private:
	int x;
	int y;
	int lives;
	int boundx;
	int boundy;
	int score;
	float angle = 0;
	float decorAngle = 0;

	ALLEGRO_BITMAP* reimu;
	ALLEGRO_BITMAP* yinyang;

	ALLEGRO_BITMAP* giantseal;
	ALLEGRO_BITMAP* giantseal;
	ALLEGRO_BITMAP* giantseal;


};
#endif
