#include"Quadnode.h"
QuadNode::QuadNode(){
	bound = new Rect();
}
QuadNode::~QuadNode(){}
bool QuadNode::IsContain(){

	return !(Simon::getCurrentSimon()->_x + SIMON_WIDTH < bound->x ||
		Simon::getCurrentSimon()->_y + SIMON_HEIGHT < bound->y ||
		Simon::getCurrentSimon()->_x > bound->x + bound->witdh ||
		Simon::getCurrentSimon()->_y > bound->y + bound->height);
}
void QuadNode::Retrieve(vector<GObject*>& listGObject){
	if (_nodeTL){
		if (_nodeTL->IsContain())
			_nodeTL->Retrieve(listGObject);
		if (_nodeTR->IsContain())
			_nodeTR->Retrieve(listGObject);
		if (_nodeBL->IsContain())
			_nodeBL->Retrieve(listGObject);
		if (_nodeBR->IsContain())
			_nodeBR->Retrieve(listGObject);
	}
	if (this->IsContain()){
		for each(GObject* tamp in listObject){
			int count = 0;
			for each(GObject* object in listGObject){
				if (object->_id == tamp->_id) count++;
			}
			if (count==0)
			listGObject.push_back(tamp);
		}
	}
}