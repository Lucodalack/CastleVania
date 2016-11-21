#include"Rect.h"
#include"GObject.h"
#include <vector>
using namespace std;
class QuadNode{
private:
	
public:
	QuadNode* _nodeTL;
	QuadNode* _nodeTR;
	QuadNode* _nodeBL;
	QuadNode* _nodeBR;

	vector<GObject*> listObject;
	int id;
	Rect* bound;
	QuadNode();
	~QuadNode();
};