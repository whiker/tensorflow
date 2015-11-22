// core/framework/op.h
// core/framework/op.cc
class OpRegistryInterface {
	virtual const OpDef* LookUp(
		const string& op_type_name, Status* status
	) = 0;
}

class OpRegistry : OpRegistryInterface {
	mutex mu_  // 保护成员变量的线程安全
	
	std::unordered_map<string, OpDef*>  registry_  GUARDED_BY(mu_)
	
	OpRegistry* Global() {
		static OpRegistry* g_op_r = new OpRegistry;
		return g_op_r;
	}
	
	void Register(std::function<OpDef(void)> func) {
		if (initialized_) {
			OpDef opd = func();
			Status RegisterAlreadyLocked(opd) {
				std::unique_ptr<OpDef> copy( new OpDef(opd) );
				gtl::InsertIfNotPresent( &registry_, opd.name(), copy.get() );
				return Status::OK();
			};
		}
		else
			deferred_.push_back(func);
	}
	
	const OpDef* LookUp(const string& op_type_name, Status* status) {
		mutex_lock lock(mu_);
		CallDeferred();
		OpDef* opd = gtl::FindWithDefault(&registry_, op_type_name, nullptr);
		return opd
	}
}

// core/framework/op_def.proto
message OpDef {
	string name
	
	message ArgDef {
		string    name
		DateType  type
		string    type_attr
		string    number_attr
	}
	
	repeated ArgDef  input_arg, output_arg
}