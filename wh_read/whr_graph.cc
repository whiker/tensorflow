// core/graph/graph.h
class Node {
	int          id_,  cost_id_
	EdgeSet      in_edges_   // 入边
	EdgeSet      out_edges_  // 出边
	Properties*  props_
}

class Edge {
	Node*  src,  dst  // 2个端点
	int    id_
	
	int  src_output_  // src端生产的数据的数目
	int  dst_input_   // src端消费的数据的数目
}

class EdgeSet {
	// ptrs_[0]即this, ptrs_[1]指向set<Edge*>
	const void* ptrs_[2];
	
	set<Edge*>* get_set() {
		return (ptrs_[0] == this) ? ptrs_[1] : nullptr;
	}
}

class Graph {
	
}