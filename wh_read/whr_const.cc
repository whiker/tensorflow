// cc/ops/const_op.cc
Node* Const(gtl::ArraySlice<T> t, const TensorShape& shape,
			GraphDefBuilder::Options& opts)
{
	NodeBuilder node_b(
		opts.GetNameForOp(OpName()) ,
		OpName, opts.op_registry()  );
	
	const DataType dt = DataTypeToEnum<TYPE>::v();
	node_b.Attr("dtype", dt);
	
	if ( t.size() == 1 ) {
		TensorProto proto;
		proto.set_dtype(dt);
		shape.AsProto( proto.mutalbe_tensor_shape() );
		node_b.Attr("value", proto);
	}
	else {
		Tensor tensor(dt, shape);
		std::copy_n( t.data(), t.size(), tensor.flat<TYPE>().data );
		node_b.Attr("value", tensor);
	}
	
	return opts.FinalizeBuilder(&node_b);
}