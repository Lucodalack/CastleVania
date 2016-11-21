#include "Quadtree.h"
Quadtree::Quadtree(){}
Quadtree::~Quadtree(){}
Quadtree* Quadtree::_currentQuadtree = 0;
void Quadtree :: load(){
	loadObject();
	ifstream myfile(QUADTREE_REF);
	vector<QuadNode*> list;
	while (!myfile.eof())
	{
		QuadNode* tamp = new QuadNode();
		myfile >> tamp->id;
		myfile >> tamp->bound->x;
		myfile >> tamp->bound->y;
		myfile >> tamp->bound->witdh;
		myfile >> tamp->bound->height;
		int count = 0;
		myfile >> count;
		for (int i = 0; i < count; i++){
			int id;
			myfile >> id;
			tamp->listObject.push_back(_listObject[id]);
		}
		list.push_back(tamp);
	}
	for each (QuadNode * b in list){
		if (b->id == 1){
			_root = b;
			continue;
		}
		int rootId = b->id / 10;
		for each(QuadNode* tamp in list){
			if (tamp->id == rootId){
				switch (b->id%10)
				{
					case 1:
						tamp->_nodeTL = b;
					break;
					case 2:
						tamp->_nodeTR = b;
						break;
					case 3:
						tamp->_nodeBL = b;
						break;
					case 4:
						tamp->_nodeBR = b;
						break;
				}
				break;
			}
		}
	}
}
void Quadtree::loadObject(){

	ifstream myfile(OBJECT_REF);
	int count = 0;
	myfile >> count;
	_listObject = new GObject*[count];
	for (int i = 0; i < count; i++){
		
		int x, y, width, height, type = 0;
		myfile >> type;
		myfile >> type;
		myfile >> x;
		myfile >> y;
		myfile >> width;
		myfile >> height;
		_listObject[i] = new GObject(type,x,y,width,height);
		int tamp;

		myfile >> tamp;
		myfile >> tamp;
		myfile >> tamp;
		myfile >> tamp;
	}
}
 Quadtree* Quadtree::getCurrentQuadtree(){
	if (_currentQuadtree == 0){
		_currentQuadtree = new Quadtree();
		_currentQuadtree->load();
	}
	return _currentQuadtree;
}