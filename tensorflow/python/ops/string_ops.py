"""String Ops."""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from tensorflow.python.framework import ops
from tensorflow.python.framework import tensor_util
from tensorflow.python.ops import common_shapes
from tensorflow.python.ops import gen_string_ops
# pylint: disable=wildcard-import,undefined-variable
from tensorflow.python.ops.gen_string_ops import *

ops.NoGradient("StringToHashBucket")

ops.RegisterShape("StringToHashBucket")(common_shapes.unchanged_shape)
