
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
	GObject* getObject(int type, int x, int y, int width, int height);
};