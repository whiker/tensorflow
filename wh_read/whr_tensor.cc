// core/public/tensor.h
// core/framework/tensor.cc
class Tensor {
	DataType       type_;
	TensorShape    shape_;
	TensorBuffer*  buf_;
}


// core/public/tensor_shape.h
// core/framework/tensor_shape.cc
class TensorShape {
	gtl::InlinedVector<int64, 4>  dim_sizes_;
	int64                         num_elements_;
	
	explicit TensorShape(gtl::ArraySlice<int64> dim_sizes);
	void set_dim(int d, int64 size);
	int dims() const { return dim_sizes_.size(); }  // 返回有多少个维度
	
	int64 dim_size(int d) const { return dim_sizes_[d]; }
	
	gtl::ArraySlice<int64> dim_sizes() const { return dim_sizes_; }
	
	void AddDim(int64 size) {
		dim_sizes_.push_back(size);
		num_elements_ *= size;
	}
}

class TensorShapeIter {
	const TensorShape*  shape_;
	int                 d_;      // 第d_维
	
	void operator++() { ++d_; }
	
	TensorShapeDim operator*() { return TensorShapeDim(shape_->dim_size(d_)); }
	struct TensorShapeDim {
		TensorShapeDim(int64 s) :size(s) {}
		int size;
	}
}


// core/lib/gtl/array_slice.h
class ArraySlice {
	typedef array_slice_internal::ArraySliceImpl<T> Impl;
	
	Impl  impl_;
}


// core/lib/gtl/array_slice_internal.h
class ArraySliceImpl<T>
	: ArraySliceImplBase<T>;

class ArraySliceImplBase<T> {
	typedef T* pointer;
	
	pointer    ptr_;
	size_type  length_;
}