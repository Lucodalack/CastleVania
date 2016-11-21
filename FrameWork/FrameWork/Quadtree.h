
#define QUADTREE_REF "quad.txt"
#define OBJECT_REF "object.txt"

#include "Rect.h"
#include "Quadnode.h"
#include "GObject.h"

#include <string>
#include <iostream>
#include <fstream>
class Quadtree{
private:
	QuadNode* _root;
	GObject** _listObject;
	static Quadtree* _currentQuadtree;
public:
	Quadtree();
	~Quadtree();
	static Quadtree* getCurrentQuadtree();
	void load();
	void loadObject();
};