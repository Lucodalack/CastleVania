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
		
		int x, y, width, height, type,id = 0;
		myfile >> id;
		myfile >> type;
		myfile >> x;
		myfile >> y;
		myfile >> width;
		myfile >> height;
		if (type>10&&type<23)
		_listObject[i] =getObject(type,x,y,width,height);
		
		

		myfile >> x;
		myfile >> y;
		myfile >> width;
		myfile >> height;
		if (type <= 10 || type >= 23){
			_listObject[i] = getObject(type, x, y, width, height);
		}
		_listObject[i]->_id = id;
	}
}
 Quadtree* Quadtree::getCurrentQuadtree(){
	if (_currentQuadtree == 0){
		_currentQuadtree = new Quadtree();
		_currentQuadtree->load();
	}
	return _currentQuadtree;
}
 GObject* Quadtree::getObject(int type, int x, int y, int width, int height)
 {
	 GObject* tamp=0;
	 switch (type){
	 case TypeGame::Enemy_Bat: tamp = new Bat(x, y, width, height); break;
	 case TypeGame::Ground_Brick: tamp = new Bricks(x, y, width, height); break;
	 case TypeGame::Enemy_Spearguard: tamp = new Spearguard(x, y, width, height); break;
	 case TypeGame::Enemy_Ghost: tamp = new Ghost(x, y, width, height); break;
	 }
	 return tamp;
 }


 