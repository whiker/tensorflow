// core/graph/graph_def_builder.h
// core/graph/graph_def_builder.cc
class GraphDefBuilder {
	
}

// GraphDefBuilder的内嵌类
class Options {
	Graph*   graph_;
	Status*  status_;
	string   name_, device_;
	vector<Node*>  control_inputs_;
	vector<pair<string, AttrValue>  attrs_;
}


// core/framework/attr_value.proto
message AttrValue {
	
}