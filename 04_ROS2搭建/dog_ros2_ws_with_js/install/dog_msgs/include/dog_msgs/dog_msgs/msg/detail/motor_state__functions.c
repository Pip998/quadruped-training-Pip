// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dog_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice
#include "dog_msgs/msg/detail/motor_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
dog_msgs__msg__MotorState__init(dog_msgs__msg__MotorState * msg)
{
  if (!msg) {
    return false;
  }
  // q
  // dq
  // ddq
  // tau
  // cur
  return true;
}

void
dog_msgs__msg__MotorState__fini(dog_msgs__msg__MotorState * msg)
{
  if (!msg) {
    return;
  }
  // q
  // dq
  // ddq
  // tau
  // cur
}

bool
dog_msgs__msg__MotorState__are_equal(const dog_msgs__msg__MotorState * lhs, const dog_msgs__msg__MotorState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // q
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->q[i] != rhs->q[i]) {
      return false;
    }
  }
  // dq
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->dq[i] != rhs->dq[i]) {
      return false;
    }
  }
  // ddq
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->ddq[i] != rhs->ddq[i]) {
      return false;
    }
  }
  // tau
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->tau[i] != rhs->tau[i]) {
      return false;
    }
  }
  // cur
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->cur[i] != rhs->cur[i]) {
      return false;
    }
  }
  return true;
}

bool
dog_msgs__msg__MotorState__copy(
  const dog_msgs__msg__MotorState * input,
  dog_msgs__msg__MotorState * output)
{
  if (!input || !output) {
    return false;
  }
  // q
  for (size_t i = 0; i < 12; ++i) {
    output->q[i] = input->q[i];
  }
  // dq
  for (size_t i = 0; i < 12; ++i) {
    output->dq[i] = input->dq[i];
  }
  // ddq
  for (size_t i = 0; i < 12; ++i) {
    output->ddq[i] = input->ddq[i];
  }
  // tau
  for (size_t i = 0; i < 12; ++i) {
    output->tau[i] = input->tau[i];
  }
  // cur
  for (size_t i = 0; i < 12; ++i) {
    output->cur[i] = input->cur[i];
  }
  return true;
}

dog_msgs__msg__MotorState *
dog_msgs__msg__MotorState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__msg__MotorState * msg = (dog_msgs__msg__MotorState *)allocator.allocate(sizeof(dog_msgs__msg__MotorState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dog_msgs__msg__MotorState));
  bool success = dog_msgs__msg__MotorState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dog_msgs__msg__MotorState__destroy(dog_msgs__msg__MotorState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dog_msgs__msg__MotorState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dog_msgs__msg__MotorState__Sequence__init(dog_msgs__msg__MotorState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__msg__MotorState * data = NULL;

  if (size) {
    data = (dog_msgs__msg__MotorState *)allocator.zero_allocate(size, sizeof(dog_msgs__msg__MotorState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dog_msgs__msg__MotorState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dog_msgs__msg__MotorState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
dog_msgs__msg__MotorState__Sequence__fini(dog_msgs__msg__MotorState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dog_msgs__msg__MotorState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

dog_msgs__msg__MotorState__Sequence *
dog_msgs__msg__MotorState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_msgs__msg__MotorState__Sequence * array = (dog_msgs__msg__MotorState__Sequence *)allocator.allocate(sizeof(dog_msgs__msg__MotorState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dog_msgs__msg__MotorState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dog_msgs__msg__MotorState__Sequence__destroy(dog_msgs__msg__MotorState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dog_msgs__msg__MotorState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dog_msgs__msg__MotorState__Sequence__are_equal(const dog_msgs__msg__MotorState__Sequence * lhs, const dog_msgs__msg__MotorState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dog_msgs__msg__MotorState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dog_msgs__msg__MotorState__Sequence__copy(
  const dog_msgs__msg__MotorState__Sequence * input,
  dog_msgs__msg__MotorState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dog_msgs__msg__MotorState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dog_msgs__msg__MotorState * data =
      (dog_msgs__msg__MotorState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dog_msgs__msg__MotorState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dog_msgs__msg__MotorState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dog_msgs__msg__MotorState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
