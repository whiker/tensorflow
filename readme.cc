class ArraySlice {
	typedef array_slice_internal::ArraySliceImpl<T> Impl;
	Impl  impl_;
}

class TensorShape {
	gtl::InlinedVector<int64, 4>  dim_sizes_;
}

class Tensor {
	DataType       type_;
	TensorShape    shape_;
	TensorBuffer*  buf_;
}