# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dog_msgs:msg/MotorState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'q'
# Member 'dq'
# Member 'ddq'
# Member 'tau'
# Member 'cur'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MotorState(type):
    """Metaclass of message 'MotorState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('dog_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'dog_msgs.msg.MotorState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MotorState(metaclass=Metaclass_MotorState):
    """Message class 'MotorState'."""

    __slots__ = [
        '_q',
        '_dq',
        '_ddq',
        '_tau',
        '_cur',
    ]

    _fields_and_field_types = {
        'q': 'double[12]',
        'dq': 'double[12]',
        'ddq': 'double[12]',
        'tau': 'double[12]',
        'cur': 'double[12]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 12),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 12),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 12),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 12),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 12),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'q' not in kwargs:
            self.q = numpy.zeros(12, dtype=numpy.float64)
        else:
            self.q = kwargs.get('q')
        if 'dq' not in kwargs:
            self.dq = numpy.zeros(12, dtype=numpy.float64)
        else:
            self.dq = kwargs.get('dq')
        if 'ddq' not in kwargs:
            self.ddq = numpy.zeros(12, dtype=numpy.float64)
        else:
            self.ddq = kwargs.get('ddq')
        if 'tau' not in kwargs:
            self.tau = numpy.zeros(12, dtype=numpy.float64)
        else:
            self.tau = kwargs.get('tau')
        if 'cur' not in kwargs:
            self.cur = numpy.zeros(12, dtype=numpy.float64)
        else:
            self.cur = kwargs.get('cur')

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if any(self.q != other.q):
            return False
        if any(self.dq != other.dq):
            return False
        if any(self.ddq != other.ddq):
            return False
        if any(self.tau != other.tau):
            return False
        if any(self.cur != other.cur):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def q(self):
        """Message field 'q'."""
        return self._q

    @q.setter
    def q(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'q' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 12, \
                "The 'q' numpy.ndarray() must have a size of 12"
            self._q = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 12 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'q' field must be a set or sequence with length 12 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._q = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def dq(self):
        """Message field 'dq'."""
        return self._dq

    @dq.setter
    def dq(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'dq' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 12, \
                "The 'dq' numpy.ndarray() must have a size of 12"
            self._dq = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 12 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'dq' field must be a set or sequence with length 12 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._dq = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def ddq(self):
        """Message field 'ddq'."""
        return self._ddq

    @ddq.setter
    def ddq(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'ddq' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 12, \
                "The 'ddq' numpy.ndarray() must have a size of 12"
            self._ddq = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 12 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'ddq' field must be a set or sequence with length 12 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._ddq = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def tau(self):
        """Message field 'tau'."""
        return self._tau

    @tau.setter
    def tau(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'tau' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 12, \
                "The 'tau' numpy.ndarray() must have a size of 12"
            self._tau = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 12 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'tau' field must be a set or sequence with length 12 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._tau = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def cur(self):
        """Message field 'cur'."""
        return self._cur

    @cur.setter
    def cur(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'cur' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 12, \
                "The 'cur' numpy.ndarray() must have a size of 12"
            self._cur = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 12 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'cur' field must be a set or sequence with length 12 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._cur = numpy.array(value, dtype=numpy.float64)
