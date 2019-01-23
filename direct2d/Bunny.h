//  Header Datei f�r den Hasen
#pragma once
#include "Graphics.h"
#include "SpriteSheet.h"

class Bunny {

	Graphics* gfx;

	//	Das Bild mit den verschiedenen Hasen
	SpriteSheet* bunny;
	//	Das Bild mit den verschiedenen Hasen mit einer Karotte im Mund
	SpriteSheet* bunnyCarrot;
	//	Toter Hase
	SpriteSheet* deadBunny;
	//	Jump-Wolke
	SpriteSheet* puff;
	//	Wolke
	SpriteSheet* cloudy;
	//	Hitbox
	D2D1_RECT_F rect;

	//	Werte der Sprung-Wolke
	float puffi = 0;
	float puffiX, puffiY;

	double frame;			//	Die Ganzzahl davon steht f�r das jeweilige Bild von der Animation
	double bunnySpeed;		//	Die �nderungsrate der verschiedenen Animationsbilder
	float x, y;				//	Position
	float sizeX, sizeY;		//	Gr�sse
	double speedY;			//	Die momentane Fallgeschwindigkeit
	double height;			//	Die maximale H�he eines Sprunges
	bool dead = false;

	bool crouched = false;	//	Gibt an, ob der nach unten Pfeil geklickt wird (Hase f�llt schneller falls true)
	int crouchLatency = 3;	//	Relativ unn�tig...

	bool up = false;		//	Wird nicht mehr verwendet

	//	Die Wolke
	bool clouded = false;	//	Gibt an, ob der Hase sich auf einer Wolke befindet
	int cloudTimer;			//	Gibt an, wielange die Wolke noch h�lt

public:

	Bunny(Graphics * gfx);
	~Bunny();

	void showBunny(bool carrot);			//	Darstellen des Hasens
	void updateBunny(double speed);			//	Aktualisierung des Hasens
	void jump(double charge);				//	Der normale und doppel Sprung
	void jump(double charge, bool cloud);	//	Sprung, welcher von einem Pilz ausgel�st wurde
	void getClouded();						//	Der Hase steigt auf die Wolke
	void die();								//	Der Hase stirbt
	void crouch();							//	Crouched wird auf true gesetzt

	bool onGround();						//	True falls der Hase auf dem Boden ist						
	bool isDead();							//	True falls der Hase tot ist
	bool isCrouched();						//	True falls der Hase "crouched"
	bool isClouded();						//	True falls der Hase sich auf einer Wolke befindet

	D2D1_RECT_F returnPos();				//	R�ckgabe der Hitbox
	
	//void crouch();


};