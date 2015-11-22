// core/graph/node_builder.h
// core/graph/node_builder.cc
class NodeBuilder {
	NodeDefBuilder   def_builder_;
	vector<NodeOut>  inputs_;
	vector<Node*>    control_inputs_;
}


// NodeBuilder的内嵌
struct NodeOut {
	string    name
	int       index
	DataType  dt
	Node*     node
}