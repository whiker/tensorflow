// core/graph/graph_def_builder.h
// core/graph/graph_def_builder.cc
class GraphDefBuilder {
	Graph    graph_
	Status   status_
	Options  opts_
	
	explicit GraphDefBuilder(
		OpRegistryInterface* op_reg = OpRegistry::Global()
	)   : graph_(op_reg), opts_(&graph_, &status_) {}
	
	Options& opts() { return opts_; }
}


// GraphDefBuilder的内嵌类
class Options {
	Graph*   graph_
	Status*  status_
	string   name_, device_
	
	vector<Node*>  control_inputs_
	
	vector< pair<string, AttrValue> >  attrs_
	
	Node* FinalizeBuilder(NodeBuilder* builder);
}


// core/framework/attr_value.proto
message AttrValue {
	
}