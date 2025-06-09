//DT Nesimi

#ifndef PLAYERH
#define PLAYERH
class player
{
public:

	player();
	~player();
	void DrawPlayer();
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight();
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() { return x; }
	int getY() { return y; }
	void removeLife() { lives--; }

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
	ALLEGRO_BITMAP* reimu;

};
#endif
