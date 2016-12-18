
#define QUADTREE_REF "quad.txt"
#define OBJECT_REF "object.txt"

#include "Rect.h"
#include "Quadnode.h"
#include "GObject.h"
#include "Simon.h"

#include "Bat.h"
#include "Spearguard.h"
#include "Bricks.h"
#include "Ghost.h"
#include "MedusaHead.h"
#include "BonePillar.h"

#include "Brickhidden.h"
#include "Brickmoving.h"
#include "Fireandle.h"
#include "Firetower.h"
#include "Stair.h"
#include "Stairs.h"
#include "Door.h"
#include "Trap.h"

#include "Axe.h"
#include "BigHeart.h"
#include "Cross.h"
#include "DoubleShot.h"
#include "HolyWater.h"
#include "Item.h"
#include "ItemNone.h"
#include "Knife.h"
#include "MoneyBag.h"
#include "MorningStar.h"
#include "Roast.h"
#include "Rosary.h"
#include "SmallHeart.h"
#include "SpiritBall.h"
#include "StopWatch.h"

#include "DeathPlace.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
class Quadtree{
private:
	GObject** _listObject;
	static Quadtree* _currentQuadtree;
public:
	Quadtree();
	~Quadtree();
	QuadNode* _root;
	static Quadtree* getCurrentQuadtree();
	void load();
	void loadObject();
	GObject* getObject(int type, int x, int y, int width, int height,bool left=true);
};